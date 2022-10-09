#!/bin/bash

if [[ -f main ]]; then
    rm main
fi

problem_num=$1
echo "problem_num:${problem_num}"

cmake . -DPROBLEM_NUM=${problem_num} && make 
if [[ -f main ]]; then
    ./main
else
    echo "build failed"
fi
