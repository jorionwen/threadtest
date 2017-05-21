// example for thread::operator=
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

void pause_thread(int n) 
{
  std::this_thread::sleep_for (std::chrono::seconds(n));
  std::cout << "pause of " << n << " seconds ended\n";
}

int main() 
{
  std::thread threads[5];                         // default-constructed threads

  std::cout << "Spawning 5 threads...\n";
  for (int i=0; i<5; ++i)
    threads[i] = std::thread(pause_thread,i+1);   // move-assign threads

  std::cout << "Done spawning threads. Now waiting for them to join:\n";
  for (int i=0; i<5; ++i)
    threads[i].join();

  std::cout << "All threads joined!\n";

  return 0;
}
