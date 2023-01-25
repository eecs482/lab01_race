#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <memory>

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
    std::vector<std::unique_ptr<std::thread>> threads;

    for (int i = 0; i < NUM_THREADS; i++) {
        threads.push_back(std::make_unique<std::thread>(child));
    }

    for (auto &t : threads) {
        t->join();
    }

    std::cout << "counter = " << counter << std::endl;
}
