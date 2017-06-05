# threadtest
多线程练习代码, 本repository是C++11多线程学习的示例代码，按照多线程的几个部分分文件夹放置，通过脚本文件编译执行文件。

使用方式，用户通过脚本compile.sh就会生成对应文件的Makefile文件，然后make编译，最后在执行程序查看结果。

## 目录结构

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

## 执行步骤：
   1. sh compile.sh example1.cpp   会生成对应example1.cpp的Makefile文件。
   2. make  会生成example1.cpp对应example1.o和example1。
   3. ./example1  执行查看结果。



