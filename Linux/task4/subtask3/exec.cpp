#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();
    if (pid == 0) {
        std::cout << "\nexecl\n";
        execl("/bin/ls", "ls", "-l", nullptr);
    } else {
        wait(nullptr);
    }

    pid = fork();
    if (pid == 0) {
        std::cout << "\nexeclp\n";
        execlp("ls", "ls", "-l", nullptr);
    } else {
        wait(nullptr);
    }

    pid = fork();
    if (pid == 0) {
        std::cout << "\nexecv\n";
        char *args[] = {const_cast<char *>("ls"), const_cast<char *>("-l"), nullptr};
        execv("/bin/ls", args);
    } else {
        wait(nullptr);
    }

    pid = fork();
    if (pid == 0) {
        std::cout << "\nexecvp\n";
        char *args[] = {const_cast<char *>("ls"), const_cast<char *>("-l"), nullptr};
        execvp("ls", args);
    } else {
        wait(nullptr);
    }

    std::cout << "\ndone\n";
    return 0;
}

