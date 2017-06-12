// packaged_task construction / assignment
#include <iostream>     // std::cout
#include <utility>      // std::move
#include <future>       // std::packaged_task, std::future
#include <thread>       // std::thread

int main ()
{
 std::packaged_task<int(int)> foo;                          // default-constructed
 std::packaged_task<int(int)> bar ([](int x){return x*2;}); // initialized

 foo = std::move(bar);                                      // move-assignment

 std::future<int> ret = foo.get_future();  // get future
 std::thread(std::move(foo),10).detach();  // spawn thread and call task
 // ...
 int value = ret.get();                    // wait for the task to finish and get result
 std::cout << "The double of 10 is " << value << ".\n";

 return 0;
}
