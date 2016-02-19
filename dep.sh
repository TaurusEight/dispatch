#!/bin/bash
# Time-stamp: <2016-02-05 15:37:31 dmendyke>

#
# dep.sh:  Generate the dependency file for source files
#

##
# Variables
dep=${1%.*}.d
obj=${1%.*}.o

##
# Command to create the dependency file
/usr/bin/g++ -std=c++11 -c -MM -MT ${obj} -MT ${dep} -MF ${dep} $1
