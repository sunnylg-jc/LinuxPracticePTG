#include<iostream>
#include<unistd.h>

int main() {

pid_t pid = fork();

if(pid == 0) {
std::cout << "this is exclusive child block" << " PID is: " << getpid() << std::endl;
}
if(pid > 0) {
std::cout << "this is exclusive parent block" << " PPID is: " << getppid() << std::endl;
}


return 0;
}
