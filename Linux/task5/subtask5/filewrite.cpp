#include <iostream>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int fd;

void* write_file(void* arg) {
    int* p = (int*)arg;
    int id = *p;
    char line[50];

    for (int i = 1; i <= 5; i++) {
        int n = sprintf(line, "Thread %d writing line %d\n", id, i);
        pthread_mutex_lock(&lock);
        write(fd, line, n);
        pthread_mutex_unlock(&lock);
    }
    return nullptr;
}

int main() {
    fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    pthread_t threads[3];
    int ids[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], nullptr, write_file, &ids[i]);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], nullptr);
    }
    close(fd);
    pthread_mutex_destroy(&lock);
    std::cout << "Done writing!\n";
    return 0;
}

