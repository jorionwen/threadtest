// future::valid
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <utility>        // std::move

int get_value() { return 10; }

int main ()
{
 std::future<int> foo,bar;
 foo = std::async (get_value);
 bar = std::move(foo);

 if (foo.valid())
   std::cout << "foo's value: " << foo.get() << '\n';
 else
   std::cout << "foo is not valid\n";

 if (bar.valid())
   std::cout << "bar's value: " << bar.get() << '\n';
 else
   std::cout << "bar is not valid\n";

 return 0;
}
