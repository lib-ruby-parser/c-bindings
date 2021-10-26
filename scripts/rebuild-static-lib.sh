#!/usr/bin/env bash

set -eux

mkdir -p objects && cd objects
$AR x ../libruby_parser_c.a
$LD --lto-O3 --relocatable *.o -o merged.o
$AR crus libruby_parser_c.a merged.o
cd ..
cp objects/libruby_parser_c.a .
rm -r objects
