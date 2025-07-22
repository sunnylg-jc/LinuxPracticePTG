#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t tokens;
void* client(void* arg) {
    int* p = (int*)arg;
    int id = *p;
    sem_wait(&tokens);
    std::cout << "Client " << id << " got a token and is calling API." << std::endl;
    sleep(2);
    std::cout << "Client " << id << " finished API call and is returning token." << std::endl;
    sem_post(&tokens);
    return nullptr;
}

void* refill(void* arg) {
    (void)arg;
    while (1) {
        sleep(5);
        int current;
        sem_getvalue(&tokens, &current);
        int toAdd = 3 - current;
        for (int i = 0; i < toAdd; i++) {
            sem_post(&tokens);
        }
        std::cout << "Refilled tokens." << std::endl;
    }
    return nullptr;
}

int main() {
    sem_init(&tokens, 0, 3);
    pthread_t clients[5];
    int ids[5] = {1, 2, 3, 4, 5};
    pthread_t refillThread;
    pthread_create(&refillThread, NULL, refill, NULL);
    for (int i = 0; i < 5; i++) {
        pthread_create(&clients[i], NULL, client, &ids[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(clients[i], NULL);
    }
    sem_destroy(&tokens);
    return 0;
}

