#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *minha_funcao(void *arg)
{
    int *arg_int = (int*)arg;
    printf("Hello %d\n", *arg_int);

    return NULL;
}

int main()
{
    pthread_t threads[5];
    int       thread_ids[5] = {0, 1, 2, 3, 4};

    for(int i = 0; i < 5; i++){
        pthread_create(&threads[i], NULL, minha_funcao, &thread_ids[i]);
    }

    for(int i = 0; i < 5; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Fim\n");
    
    return 0;
}
