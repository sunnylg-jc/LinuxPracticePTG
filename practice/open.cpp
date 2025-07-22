#include<iostream>
#include<fcntl.h>
#include <unistd.h>
#include <cstring>

int main() {

const char* filename = "Example.txt";
const char* message = "hi hello namaste vanakkam\n";
char reader[1024];
int fr = open(filename,O_RDWR | O_CREAT, 0777);
ssize_t write_file = write(fr,message,strlen(message));
std::cout << "no of bytes written"<< write_file << std::endl;

lseek(fr,0,SEEK_SET);

ssize_t read_file = read(fr,reader,sizeof(reader));
std::cout  << "no of bytes read "<< read_file << std::endl;

close(fr);

int fr2 = open("Example2.txt",O_RDWR);
ssize_t ex2_write = write(fr2,reader,read_file);
close(fr2);
return 0;
}
