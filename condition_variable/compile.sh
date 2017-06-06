#!/bin/bash

if [ "$1" = "" ]
then
    echo "please input cpp file!!!"
    return
elif [ ! -f "$1" ]
then
    echo "this cpp file not exist!!!"
    return
elif [ "$1" = "example17.cpp" ]
then
    echo "note: example17.cpp May compile the report error!!!"
    echo "but The Makefile will still be generated!!!"
    echo "If the compilation is incorrect, use VS2013 surport c++11 compile!!!"
fi

INPUT=`echo $1 | awk '{split($0,a,".");print a[1]}'`

val="all:${INPUT}\n\n"
val=${val}"CC=g++\n"
val=${val}"CPPFLAGS=-Wall -std=c++11 -ggdb\n"
val=${val}"LDFLAGS=-pthread\n\n"
val=${val}"${INPUT}:${INPUT}.o\n\t"

if [ "$INPUT" = "example2" ]
then
   #echo "========================"
   val=${val}'$(CC) -o $@ $^ $(LDFLAGS)'
else
   #echo "!!!!!!!!!!!!!!!!!!!!!!!!"
   val=${val}'$(CC) $(LDFLAGS) -o $@ $^'
fi

val=${val}"\n\n${INPUT}.o:$1\n\t"
val=${val}'$(CC) $(CPPFLAGS) -o $@ -c $^'
val=${val}"\n\n\n.PHONY:\n"
val=${val}"\tclean\n\n"
val=${val}"clean:\n"
val=${val}"\trm ${INPUT}.o ${INPUT}"

echo ${val} > Makefile


