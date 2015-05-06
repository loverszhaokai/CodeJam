#!/bin/bash

if [ $# == 1 ]; then
	g++ sol.cc && ./a.out < $1 
else
	g++ sol.cc && ./a.out < ../input_example 
fi
