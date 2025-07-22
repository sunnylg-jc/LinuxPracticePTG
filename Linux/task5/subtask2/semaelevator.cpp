#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t elevator;
void* person(void* arg) {
    int* pid = (int*) arg;
    int id = *pid;
    sem_wait(&elevator);
    std::cout << "Person " << id << " entered elevator." << std::endl;
    sleep(3);
    std::cout << "Person " << id << " exited elevator." << std::endl;
    sem_post(&elevator);
    return nullptr;
}
int main() {
    sem_init(&elevator, 0, 2);
    pthread_t people[5];
    int ids[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        pthread_create(&people[i], NULL, person, &ids[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(people[i], NULL);
    }
    sem_destroy(&elevator);
    return 0;
}

