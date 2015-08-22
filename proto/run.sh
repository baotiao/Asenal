#!/bin/sh


g++ message.pb.cc message.pb.h cli.cc -std=c++11 -lprotobuf -o cli
g++ message.pb.cc message.pb.h srv.cc -std=c++11 -lprotobuf -o srv
