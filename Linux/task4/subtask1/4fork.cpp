#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();
    fork();

    printf("Hello: PID=%d, PPID=%d\n", getpid(), getppid());

    return 0;
}

