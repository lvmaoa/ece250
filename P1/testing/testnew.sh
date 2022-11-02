#!/bin/bash

DIR=./testing/tests/
NAME=test0

for i in {1..9}
do
    ./a.out < $DIR$NAME$i.in | diff $DIR$NAME$i.out -
    if [ $? -eq 0 ]; then
       echo OK
    else
       echo FAIL
    fi
done

./a.out < ./testing/tests/test10.in | diff ./testing/tests/test10.out -
if [ $? -eq 0 ]; then
   echo OK
else
   echo FAIL
fi

