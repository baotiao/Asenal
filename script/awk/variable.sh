#!/bin/sh
name='czz'
list=`awk '$0 ~ /"$name"/ {print $0;}' file`
echo $list
echo $name
