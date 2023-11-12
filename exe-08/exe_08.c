#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define ITERATIONS  100
#define BUFFER_SIZE  10

int buffer[BUFFER_SIZE];
int buffer_index = 0;

pthread_mutex_t mutex;

sem_t sem_empty;
sem_t sem_full;

void *produtora(void *arg)
{
    int it = ITERATIONS;
    while(it--){
        /* Produz o item: não é crítico */
        int item = it;
        printf("Produziu %d\n", item);

        /* Não acessa com buffer cheio */
        sem_wait(&sem_empty);

        /* Entrar em região crítica */
        pthread_mutex_lock(&mutex);

        /* Acessa buffer */
        buffer[buffer_index] = item;
        buffer_index++;

        /* Sair de região crítica*/
        pthread_mutex_unlock(&mutex);

        sem_post(&sem_full);
    }

    return NULL;
}

void *consumidora(void *arg)
{
    int it = ITERATIONS;
    while(it--){
        /* Não acessa com buffer vazio */
        sem_wait(&sem_full);

        /* Entrar em região crítica */
        pthread_mutex_lock(&mutex);

        /* Acessa buffer */
        buffer_index--;
        int item = buffer[buffer_index];

        /* Sair de região crítica*/
        pthread_mutex_unlock(&mutex);

        sem_post(&sem_empty);

        /* Consome: não é crítico */
        printf("Consumiu %d\n", item);
    }

    return NULL;
}

int main()
{
    pthread_t threads[2];

    pthread_mutex_init(&mutex, NULL);
    sem_init(&sem_empty, 0, BUFFER_SIZE);
    sem_init(&sem_full, 0, 0);

    pthread_create(&threads[0], NULL, produtora, NULL);
    pthread_create(&threads[1], NULL, consumidora, NULL);

    for(int i = 0; i < 2; i++){
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem_full);
    sem_destroy(&sem_empty);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}