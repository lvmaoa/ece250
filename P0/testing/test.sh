#!/bin/bash

DIR=./testing/
NAME=test0

for i in {1..4}
do
    ./a.out < $DIR$NAME$i.in | diff $DIR$NAME$i.out -
    if [ $? -eq 0 ]; then
       echo OK
    else
       echo FAIL
    fi
done

