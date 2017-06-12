// promise::operator=
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <future>         // std::promise, std::future

std::promise<int> prom;

void print_global_promise () {
  std::future<int> fut = prom.get_future();
  int x = fut.get();
  std::cout << "value: " << x << '\n';
}

int main ()
{
  std::thread th1 (print_global_promise);
  prom.set_value (10);
  th1.join();

  prom = std::promise<int>();    // reset, by move-assigning a new promise

  std::thread th2 (print_global_promise);
  prom.set_value (20);
  th2.join();

  return 0;
}
