// atomic::operator=/operator T example:
#include <iostream>       // std::cout
#include <atomic>         // std::atomic
#include <thread>         // std::thread, std::this_thread::yield

std::atomic<int> foo(0);
std::atomic<int> bar(0);

void set_foo(int x) {
 foo = x;
}
void copy_foo_to_bar () {
 while (foo==0) std::this_thread::yield();
 bar = static_cast<int>(foo);
}
void print_bar() {
 while (bar==0) std::this_thread::yield();
 std::cout << "bar: " << bar << '\n';
}

int main ()
{
 std::thread first (print_bar);
 std::thread second (set_foo,10);
 std::thread third (copy_foo_to_bar);
 first.join();
 second.join();
 third.join();
 return 0;
}
