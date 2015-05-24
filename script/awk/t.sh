#!/bin/sh

num=$1;
awk -v val=$num -v val1=$num '{print $4 + val1 + val}' score.txt
