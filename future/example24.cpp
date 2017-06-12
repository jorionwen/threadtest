// std::future_category example:
#include <iostream>     // std::cerr
#include <future>       // std::promise, std::future_error, std::future_category

  int main ()
  {
    std::promise<int> prom;

    try {
      prom.get_future();
      prom.get_future();   // throws a std::future_error of the future category
    }
    catch (std::future_error& e) {
      if (e.code().category() == std::future_category())
      std::cerr << "future_error of the future category thrown\n";
    }

    return 0;
  }
