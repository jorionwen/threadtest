#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

std::condition_variable cv;
std::mutex cv_m;
int i = 0;
bool done = false;

void waits()
{
   std::unique_lock<std::mutex> lk(cv_m);
   std::cout << "Waiting... \n";
   cv.wait(lk, []{return i == 1;});
   std::cout << "...finished waiting. i == 1\n";
   done = true;
}

void signals()
{
   std::this_thread::sleep_for(std::chrono::seconds(1));
   std::cout << "Notifying falsely...\n";
   cv.notify_one(); // waiting thread is notified with i == 0.
                    // cv.wait wakes up, checks i, and goes back to waiting

   std::unique_lock<std::mutex> lk(cv_m);
   i  = 1;
   while (!done) 
   {
       std::cout << "Notifying true change...\n";
       lk.unlock();
       cv.notify_one(); // waiting thread is notified with i == 1, cv.wait     returns
       std::this_thread::sleep_for(std::chrono::seconds(1));
       lk.lock();
   }
}

int main()
{
   std::thread t1(waits), t2(signals);
   t1.join(); 
   t2.join();
   return 0;
}
