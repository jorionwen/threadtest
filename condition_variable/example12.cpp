// condition_variable_any::wait (with predicate)
#include <iostream>           // std::cout
#include <thread>             // std::thread, std::this_thread::yield
#include <mutex>              // std::mutex
#include <condition_variable> // std::condition_variable_any

std::mutex mtx;
std::condition_variable_any cv;

int cargo = 0;
bool shipment_available() {return cargo!=0;}

void consume (int n) {
 for (int i=0; i<n; ++i) {
   mtx.lock();
   cv.wait(mtx,shipment_available);
   // consume:
   std::cout << cargo << '\n';
   cargo=0;
   mtx.unlock();
 }
}

int main ()
{
 std::thread consumer_thread (consume,10);

 // produce 10 items when needed:
 for (int i=0; i<10; ++i) {
   while (shipment_available()) std::this_thread::yield();
   mtx.lock();
   cargo = i+1;
   cv.notify_one();
   mtx.unlock();
 }

 consumer_thread.join();

 return 0;
}
