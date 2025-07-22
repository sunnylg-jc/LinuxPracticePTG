#include<iostream>
#include<unistd.h>

int main() {
	pid_t pid = fork();
	std::cout << getpid() << std::endl;
	return 0;
}
