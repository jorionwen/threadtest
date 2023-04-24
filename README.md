# threadtest

Multithreading practice code, this repository is C++11 multithreading learning sample code, according to several parts of the multithreading folder placement, through the script file compilation file execution.

In this way, the user generates the Makefile file of the corresponding file through the script compile.sh, and then makes the compilation, and finally sees the result in the execution program.

## catalogue

    /-------
       |______.git
       |______thread
       |    |_____compile.sh
       |    |_____example.cpp
       |    |...
       |
       |______mutex
       |    |_____compile.sh
       |    |_____example.cpp
       |    |...
       |...

## exec step：

      1. sh compile.sh example1.cpp generates the Makefile that corresponds to example1.cpp.
      2. make generates example1.cpp for example1.o and example1.
      3. ./example1 View the result.



