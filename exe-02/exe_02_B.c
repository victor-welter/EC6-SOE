#include <stdio.h>
#include <unistd.h>

int main()
{

    /* Processo filho */
    printf(
        "Processo filho tem ID %d e pai %d\n", 
        getpid(), 
        getppid()
    );

    return 0;
}
