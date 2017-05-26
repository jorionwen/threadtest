#include <iostream>
#include <utility>
#include <atomic>

struct A { int a[100]; };
struct B { int x, y; };
int main()
{
   std::cout << std::boolalpha
           << "std::atomic<A> is lock free? "
           << std::atomic<A>{}.is_lock_free() << '\n'
           << "std::atomic<B> is lock free? "
           << std::atomic<B>{}.is_lock_free() << '\n';
    return 0;
}
