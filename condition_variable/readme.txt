condition_variable例子中：
 
示例15 在vs2013 环境编译 和 ubuntu14.04 gcc 4.8.4 编译运行的结果有出入，自行练习。

示例17 在vs2013 环境编译运行没有问题， 但在 ubuntu14.04 gcc 4.8.4 编译报错，原因是gcc 4.8.4 condition_variable头文件中未实现notify_all_at_thread_exit函数； 本例在使用compile脚本生成Makefile会提示出来。