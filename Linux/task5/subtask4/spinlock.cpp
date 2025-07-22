#include <iostream>
#include <pthread.h>
int counter = 0;    
pthread_spinlock_t spinlock;
void* increment(void* arg) {
    for (int i = 0; i < 50000; i++) {
        pthread_spin_lock(&spinlock);
        counter++;
        pthread_spin_unlock(&spinlock);
    }
    return NULL;
}
int main() {
    pthread_t threads[4];
    pthread_spin_init(&spinlock, 0);  // Initialize spinlock
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_spin_destroy(&spinlock);
    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}

