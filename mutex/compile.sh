#!/bin/bash

if [ "$1" = "" ]
then
    echo "please input cpp file!!!"
    return
elif [ ! -f "$1" ]
then
    echo "this cpp file not exist!!!"
    return
fi

INPUT=`echo $1 | awk '{split($0,a,".");print a[1]}'`

val="all:${INPUT}\n\n"
val=${val}"CC=g++\n"
val=${val}"CPPFLAGS=-Wall -std=c++11 -ggdb\n"
val=${val}"LDFLAGS=-pthread\n\n"
val=${val}"${INPUT}:${INPUT}.o\n\t"
val=${val}'$(CC) $(LDFLAGS) -o $@ $^'
val=${val}"\n\n${INPUT}.o:$1\n\t"
val=${val}'$(CC) $(CPPFLAGS) -o $@ -c $^'
val=${val}"\n\n\n.PHONY:\n"
val=${val}"\tclean\n\n"
val=${val}"clean:\n"
val=${val}"\trm ${INPUT}.o ${INPUT}"

echo ${val} > Makefile


