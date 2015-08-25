#!/bin/bash

if [ $# == 1 ]; then
	clang++ sol.cc && ./a.out < $1 
else
	clang++ sol.cc && ./a.out < ../input_example 
fi
