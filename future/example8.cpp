// uses_allocator example
#include <iostream>
#include <memory>
#include <vector>

int main() {
 typedef std::vector<int> Container;
 typedef std::allocator<int> Allocator;

 if (std::uses_allocator<Container,Allocator>::value) {
   Allocator alloc;
   Container foo (5,10,alloc);
   for (auto x:foo) std::cout << x << ' ';
 }
 std::cout << '\n';
 return 0;
}
