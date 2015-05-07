#!/bin/bash

if [ $# == 1 ]; then
	g++ sol.cc -DDBG && ./a.out < $1 && emacs log.txt
else
	g++ sol.cc -DDBG && ./a.out < ../input_example && emacs log.txt
fi
