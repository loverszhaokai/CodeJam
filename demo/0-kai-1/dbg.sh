#!/bin/bash

if [ $# == 1 ]; then
	g++ sol.cc && ./a.out < $1 && emacs log.txt
else
	g++ sol.cc && ./a.out < ../input_example && emacs log.txt
fi
