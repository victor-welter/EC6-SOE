#include <stdio.h>
#include <pthread.h>

// Função que será executada pela thread criada
void *funcaoThread(void *arg) {
    float *arc_valor = (float *)arg;

    printf("Thread criada. %f \n", *arc_valor);
    
    return NULL;
}

int main() {
    pthread_t thread; // Declaração da variável de thread

    float valor = 3.14;

    // Criação da thread
    pthread_create(&thread, NULL, funcaoThread, &valor);

    pthread_join(thread, NULL); // Aguarda a thread criada terminar

    // Mensagem de fim da thread principal
    printf("A thread criada terminou.\n");

    return 0;
}