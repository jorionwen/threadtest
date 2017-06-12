future例子中：
 
示例7、12 在vs2013 环境编译运行没有问题， 但在 ubuntu14.04 gcc 4.8.4 编译报错，原因是gcc 4.8.4 future头文件中未实现make_ready_at_thread_exit、set_value_at_thread_exit函数； 本例在使用compile脚本生成Makefile会提示出来。
