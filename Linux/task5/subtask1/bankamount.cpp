#include <iostream>
#include <pthread.h>
int bank_balance = 1000;
pthread_mutex_t balance_mutex = PTHREAD_MUTEX_INITIALIZER;
void* withdraw(void* arg) {
    int thread_id = *(int*)arg;
    pthread_mutex_lock(&balance_mutex);
    if (bank_balance >= 500) {
        bank_balance -= 500;
        std::cout << "Thread " << thread_id << ": Withdrawal successful. Balance = ₹" << bank_balance << std::endl;
    } else {
        std::cout << "Thread " << thread_id << ": Insufficient funds." << std::endl;
    }
    pthread_mutex_unlock(&balance_mutex);
    return nullptr;  // Thread finished
}

int main() {
    pthread_t threads[3];
    int thread_ids[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], nullptr, withdraw, (void*)&thread_ids[i]);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], nullptr);
    }
    pthread_mutex_destroy(&balance_mutex);
    std::cout << "Final balance: ₹" << bank_balance << std::endl;
    return 0;
}

