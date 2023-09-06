# include <stdio.h>
# include <unistd.h> 
# include <sys/wait.h> 

int main()
{
    int pid = fork();
    if(pid != 0) {
        // Processo pai
        waitpid(pid, NULL, 0);
        printf("Processo pai tem ID = %d e criou filho tem ID = %d\n", getpid(), pid);
    } else {
        // Processo filho
        printf("Processo filho tem PID = %d e pai tem ID = %d \n", getpid(), getppid());
    }

    return 0;
}
