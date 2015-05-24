#!/usr/bin/env perl
use Encode;
$string = decode('gbk', "陈宗志");
print length($string);
print encode('gbk', substr($string, 0, 3));

