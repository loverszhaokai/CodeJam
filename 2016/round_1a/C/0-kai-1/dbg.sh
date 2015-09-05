#!/bin/bash

if [ $# == 1 ]; then
	clang++ sol.cc -DDBG && ./a.out < $1 && emacs log.txt
else
	clang++ sol.cc -DDBG && ./a.out < ../input_example && emacs log.txt
fi
