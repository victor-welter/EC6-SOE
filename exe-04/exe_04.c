#include <pthread.h>
#include <stdio.h>

void *minha_funcao(void *arg)
{
    float *arg_float = (float*)arg;
    printf("Oi thread %f\n", *arg_float);
    return NULL;
}

int main()
{
    pthread_t minha_thread;
    float meu_arg = 7.7;

    pthread_create(&minha_thread, NULL, minha_funcao, &meu_arg);

    pthread_join(minha_thread, NULL);
    printf("Fim\n");

    return 0;
}
