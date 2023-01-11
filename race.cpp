#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

const int NUM_THREADS = 2;
const int NUM_ITER = 20;

int counter = 0;
mutex counter_mutex;

void child() {
    for (int i=0; i < NUM_ITER; i++) {
        lock_guard<mutex> lock(counter_mutex); // RAII paradigm. std::lock_guard acquires the lock on construction and releases it on destruction
        // counter_mutex.lock(); Taken care of by RAII
        counter++;
        // counter_mutex.unlock(); Taken care of by RAII
    }
}

int main() {
    vector<thread> threads;

    for (int i=0; i < NUM_THREADS; i++) {
        threads.emplace_back(child);
        // This is an equivalent and simpler way to write
        // threads.push_back(thread(child));
    }

    for (auto &t : threads) {
        t.join();
    }

    cout << "counter = " << counter << endl;
}

