// unique_lock::operator= example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock

std::mutex mtx;           // mutex for critical section

void print_fifty (char c) {
  std::unique_lock<std::mutex> lck;         // default-constructed
  lck = std::unique_lock<std::mutex>(mtx);  // move-assigned
  for (int i=0; i<50; ++i) { std::cout << c; }
  std::cout << '\n';
}

int main ()
{
  std::thread th1 (print_fifty,'*');
  std::thread th2 (print_fifty,'$');

  th1.join();
  th2.join();

  return 0;
}
