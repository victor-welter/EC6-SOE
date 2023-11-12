#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#define ITERATIONS  100
#define BUFFER_SIZE  10

int buffer[BUFFER_SIZE];
int buffer_index = 0;

std::mutex mutex;
std::condition_variable cond_empty;
std::condition_variable cond_full;

void produtora()
{
    int it = ITERATIONS;
    while (it--) {
        /* Produz o item: não é crítico */
        int item = it;
        std::cout << "Produziu " << item << std::endl;

        /* Não acessa com buffer cheio */
        std::unique_lock<std::mutex> lock(mutex);
        cond_empty.wait(lock, [] { return buffer_index < BUFFER_SIZE; });

        /* Acessa buffer */
        buffer[buffer_index] = item;
        buffer_index++;

        lock.unlock();
        cond_full.notify_one();
    }
}

void consumidora()
{
    int it = ITERATIONS;
    while (it--) {
        /* Não acessa com buffer vazio */
        std::unique_lock<std::mutex> lock(mutex);
        cond_full.wait(lock, [] { return buffer_index > 0; });

        /* Acessa buffer */
        buffer_index--;
        int item = buffer[buffer_index];

        lock.unlock();
        cond_empty.notify_one();

        /* Consome: não é crítico */
        std::cout << "Consumiu " << item << std::endl;
    }
}

int main()
{
    std::thread produtor(produtora);
    std::thread consumidor(consumidora);

    produtor.join();
    consumidor.join();

    return 0;
}
