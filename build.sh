#!/bin/bash

problem_num=$1
echo "problem_num:${problem_num}"

cmake . -DPROBLEM_NUM=${problem_num} && make 
./main