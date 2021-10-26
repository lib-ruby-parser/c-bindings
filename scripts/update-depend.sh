#!/usr/bin/env bash

set -eu

echo '' > .depend

for filename in *.c; do
    [ -e "$filename" ] || continue
    objfile="${filename%.c}.o"

    $CC -MT $objfile -MM $filename >> .depend
    echo "" >> .depend
done

$CC -MT "sizes" -MM "sizes.c" >> .depend
echo "" >> .depend

$CC -MT "tests/runner" -MM "tests/test.c" >> .depend
echo "" >> .depend

$CC -MT "benchmark/c-parser" -MM "benchmark/benchmark.c" >> .depend
echo "" >> .depend
