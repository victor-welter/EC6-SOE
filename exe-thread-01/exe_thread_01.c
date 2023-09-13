#include <stdio.h>
#include <pthread.h>

// Função que será executada pela thread criada
void *funcaoThread(void *arg) {
    printf("Thread criada.\n");
    
    return NULL;
}

int main() {
    pthread_t thread; // Declaração da variável de thread

    // Criação da thread
    pthread_create(&thread, NULL, funcaoThread, NULL);

    pthread_join(thread, NULL); // Aguarda a thread criada terminar

    // Mensagem de fim da thread principal
    printf("A thread criada terminou.\n");

    return 0;
}