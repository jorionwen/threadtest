// packaged_task::get_future
#include <iostream>     // std::cout
#include <utility>      // std::move
#include <future>       // std::packaged_task, std::future
#include <thread>       // std::thread

// a simple task:
int triple (int x) { return x*3; }

int main ()
{
 std::packaged_task<int(int)> tsk (triple); // package task

 std::future<int> fut = tsk.get_future();
 tsk(33);
 std::cout << "The triple of 33 is " << fut.get() << ".\n";

 // re-use same task object:
 tsk.reset();
 fut = tsk.get_future();
 std::thread(std::move(tsk),99).detach();
 std::cout << "Thre triple of 99 is " << fut.get() << ".\n";

 return 0;
}
