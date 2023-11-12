#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>

int main()
{
    int pid = fork();
    if(pid != 0){
        /* Processo pai */
        waitpid(pid, NULL, 0); /* Aguarda filho terminar */
        printf(
            "Processo pai tem ID %d e criou filho %d já finalizado\n", 
            getpid(), 
            pid
        );
    } else {
        /* Processo filho */
        execve("exe_2_B", NULL, NULL);
    }

    return 0;
}
