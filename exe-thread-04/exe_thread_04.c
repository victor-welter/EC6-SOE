#include <stdio.h>
#include <pthread.h>

// Função que será executada pela thread criada
void *funcaoThread(void *arg) {
    int *arc_valor = (int *)arg;

    printf("Thread %d criada.\n", *arc_valor);

    return NULL;
}

int main() {
    pthread_t threads[5]; // Declaração de um array de threads
    int thread_id[5] = {0, 1, 2, 3, 4};

    for(int i = 0; i < 5; i++) {
        // Criação da thread
        pthread_create(&threads[i], NULL, funcaoThread, &thread_id[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL); // Aguarda a thread criada terminar
    }

    // Mensagem de fim da thread principal
    printf("Todas as threads terminaram.\n");

    return 0;
}