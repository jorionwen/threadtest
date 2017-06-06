#include <iostream>
#include <atomic>
#include <condition_variable>
#include <thread>
#include <chrono>
//using namespace std::chrono_literals;

std::condition_variable cv;
std::mutex cv_m;
int i;

void waits(int idx)
{
   std::unique_lock<std::mutex> lk(cv_m);
   if(cv.wait_for(lk, idx*std::chrono::milliseconds(100), []{return i == 1;})) 
       std::cerr << "Thread " << idx << " finished waiting. i == " << i << '\n';
   else
       std::cerr << "Thread " << idx << " timed out. i == " << i << '\n';
}

void signals()
{
   std::this_thread::sleep_for(std::chrono::milliseconds(120));
   std::cerr << "Notifying...\n";
   cv.notify_all();
   std::this_thread::sleep_for(std::chrono::milliseconds(100));
   {
       std::lock_guard<std::mutex> lk(cv_m);
       i = 1;
   }
   std::cerr << "Notifying again...\n";
   cv.notify_all();
}

int main()
{
   std::thread t1(waits, 1), t2(waits, 2), t3(waits, 3), t4(signals);
   t1.join(); t2.join(), t3.join(), t4.join();
   return 0;
}
