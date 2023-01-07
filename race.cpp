#include <iostream>
#include <thread>
#include <mutex>

const int NUM_THREADS = 2;
const int NUM_ITER = 20;

int counter = 0;
std::mutex counter_mutex;

void child()
{
    for (int i=0; i < NUM_ITER; i++) {
        counter_mutex.lock();
        counter++;
        counter_mutex.unlock();
    }
}

int main()
{
    std::thread* t[NUM_THREADS];

    for (int i=0; i < NUM_THREADS; i++) {
        t[i] = new std::thread(child);
    }

    for (int i=0; i < NUM_THREADS; i++) {
        t[i]->join();
    }

    std::cout << "counter = " << counter << std::endl;
}

