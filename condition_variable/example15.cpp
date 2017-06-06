// condition_variable_any::notify_one
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex
#include <condition_variable> // std::condition_variable_any

std::mutex mtx;
std::condition_variable_any cv;

int cargo = 0;     // shared value by producers and consumers

void consumer () {
  mtx.lock();
  while (cargo==0) cv.wait(mtx);
  std::cout << cargo << '\n';
  cargo=0;
  mtx.unlock();
}

void producer (int id) {
  mtx.lock();
  cargo = id;
  cv.notify_one();
  mtx.unlock();
}

int main ()
{
std::thread consumers[10],producers[10];

// spawn 10 consumers and 10 producers:
for (int i=0; i<10; ++i) {
  consumers[i] = std::thread(consumer);
  producers[i] = std::thread(producer,i+1);
}

// join them back:
for (int i=0; i<10; ++i) {
  producers[i].join();
  consumers[i].join();
}

return 0;
}
