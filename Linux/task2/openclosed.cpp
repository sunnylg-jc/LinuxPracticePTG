#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>

int main() {
	const char* message = "hello how are you are you fine";
	const char* filename1 = "Example1.txt";
	char buffer[1024];
	
	int fd = open(filename1,O_RDWR|O_CREAT,0777);
	ssize_t write_file = write(fd,message,strlen(message));
	if(write_file < 0) {
		std::cerr << "error! in writing the file check once!\n";
		return 1;
	}
	
	lseek(fd,0,SEEK_SET);
	
	ssize_t read_file = read(fd,buffer,sizeof(buffer)-1);
	if(read_file < 0) {
		std::cerr << "error! cant read the file!\n";
		return 1;
	}
	else {
		std::cout << "the bytes that read\n" << read_file;
		std::cout.write(buffer,strlen(buffer));
		std::cout << std::endl;
	}
	close(fd);
	
	int fd1 = open("Example2.txt",O_RDWR | O_TRUNC);
	ssize_t write_ex2 = write(fd1,buffer,strlen(buffer));
	close(fd1);
	
	return 0;
}

