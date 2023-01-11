#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

const int NUM_THREADS = 2;
const int NUM_ITER = 20;

int counter = 0;
std::mutex counter_mutex;

void child() {
    for (int i=0; i < NUM_ITER; i++) {
        counter_mutex.lock();
        counter++;
        counter_mutex.unlock();
    }
}

int main() {
    std::vector<std::thread> threads;

    for (int i=0; i < NUM_THREADS; i++) {
        threads.emplace_back(child);
        // This is an equivalent and simpler way to write
        // threads.push_back(thread(child));
    }

    for (auto &t : threads) {
        t.join();
    }

    std::cout << "counter = " << counter << std::endl;
}

