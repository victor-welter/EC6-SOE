#include <pthread.h>
#include <stdio.h>

void *minha_funcao(void *arg)
{
    printf("Oi thread\n");
    return NULL;
}

int main()
{
    pthread_t minha_thread;
    pthread_create(&minha_thread, NULL, minha_funcao, NULL);

    pthread_join(minha_thread, NULL);
    printf("Fim\n");

    return 0;
}
