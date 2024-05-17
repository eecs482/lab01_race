#include <iostream>
#include "thread.h"
#include "mutex.h"
#include "cpu.h"

#include <vector>

const int NUM_THREADS = 2;
const int NUM_ITER = 20;

int counter = 0;
mutex counter_mutex;

void child(uintptr_t) {
    for (int i=0; i < NUM_ITER; i++) {
        // counter_mutex.lock();
        counter++;
        // counter_mutex.unlock();
    }
}

void boot(uintptr_t){
    std::vector<thread> threads;

    for (int i = 0; i < NUM_THREADS; i++) {
        threads.push_back(thread(child,0));
    }

    for (auto &t : threads) {
        t.join();
    }
    std::cout << "counter = " << counter << std::endl;
}

int main() {
    cpu::boot(boot,0,0);

}
