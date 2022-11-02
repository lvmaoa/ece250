#!/bin/bash

DIR=./testing/
NAME=test0

for i in {1..2}
do
    ./a.out < $DIR$NAME$i.in | diff $DIR$NAME$i.out -
    if [ $? -eq 0 ]; then
       echo OK
    else
       echo FAIL
    fi
done

./a.out < ./testing/test04.in | diff ./testing/test04.out -
if [ $? -eq 0 ]; then
   echo OK
else
   echo FAIL
fi

./a.out < ./testing/test06.in | diff ./testing/test06.out -
if [ $? -eq 0 ]; then
   echo OK
else
   echo FAIL
fi

