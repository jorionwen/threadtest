#include <future>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <utility>
void worker(std::future<void>& output)
{
   std::packaged_task<void(bool&)> my_task{ [](bool& done) { done=true; } };

   auto result = my_task.get_future();
   bool done = false;

   my_task.make_ready_at_thread_exit(done); // execute task right away
   std::cout << "worker: done = " << std::boolalpha << done << std::endl;

   auto status = result.wait_for(std::chrono::seconds(0));
   if (status == std::future_status::timeout)
       std::cout << "worker: result is not ready yet" << std::endl;

   output = std::move(result);
}

int main()
{
   std::future<void> result;
   std::thread{worker, std::ref(result)}.join();
   auto status = result.wait_for(std::chrono::seconds(0));
   if (status == std::future_status::ready)
       std::cout << "main: result is ready" << std::endl;
}
