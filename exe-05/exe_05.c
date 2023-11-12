#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *minha_funcao(void *arg)
{
    float *arg_float = (float*)arg;
    printf("Oi thread %f\n", *arg_float);

    float *variavel_da_thread = malloc(sizeof(float));  /* Não fica na pilha, vai para a heap */
    *variavel_da_thread = *arg_float * 2;

    return variavel_da_thread;
}

int main()
{
    pthread_t minha_thread;
    float meu_arg = 7.7;

    pthread_create(&minha_thread, NULL, minha_funcao, &meu_arg);

    float *meu_retorno;
    pthread_join(minha_thread, (void**)&meu_retorno);
    printf("Fim %f\n", *meu_retorno);
    free(meu_retorno);  /* Não esquecer de liberar a memória alocada na heap! */
    meu_retorno = NULL; /* E não esquecer de setar o ponteiro para NULL! */

    return 0;
}
