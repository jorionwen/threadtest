// unique_lock::mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock, std::defer_lock

class MyMutex : public std::mutex {
  int _id;
public:
  MyMutex (int id) : _id(id) {}
  int id() {return _id;}
};

MyMutex mtx (101);

void print_ids (int id) {
  std::unique_lock<MyMutex> lck (mtx);
  std::cout << "thread #" << id << " locked mutex " << lck.mutex()->id() << '\n';
}

int main ()
{
  std::thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i)
    threads[i] = std::thread(print_ids,i+1);

  for (auto& th : threads) th.join();

  return 0;
}
