# include <stdio.h>
# include <unistd.h> 
# include <sys/wait.h> 

int main()
{
    printf("Processo filho tem PID = %d e pai tem ID = %d \n", getpid(), getppid());
    
    return 0;
}
