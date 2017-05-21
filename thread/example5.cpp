// example for thread::joinable
#include <iostream>       // std::cout
#include <thread>         // std::thread

void mythread() 
{
  // do stuff...
}

int main() 
{
  std::thread foo;
  std::thread bar(mythread);

  std::cout << "Joinable after construction:\n" << std::boolalpha;
  std::cout << "foo: " << foo.joinable() << '\n';
  std::cout << "bar: " << bar.joinable() << '\n';

  if (foo.joinable()) foo.join();
  if (bar.joinable()) bar.join();

  std::cout << "Joinable after joining:\n" << std::boolalpha;
  std::cout << "foo: " << foo.joinable() << '\n';
  std::cout << "bar: " << bar.joinable() << '\n';

  return 0;
}
