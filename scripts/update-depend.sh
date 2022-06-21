#!/usr/bin/env bash

set -eu

echo '' > .depend

for filename in *.c; do
    [ -e "$filename" ] || continue
    objfile="${filename%.c}.o"

    $CC -DTEST_ENV -MT $objfile -MM $filename >> .depend
    echo "" >> .depend
done

$CC -MT "tests/runner" -MM "tests/runner.c" >> .depend
echo "" >> .depend

$CC -MT "benchmark/c-parser" -MM "benchmark/benchmark.c" >> .depend
echo "" >> .depend

sed 's/tests\/\.\.\///g' .depend > .depend-tmp
mv .depend-tmp .depend

sed 's/benchmark\/\.\.\///g' .depend > .depend-tmp
mv .depend-tmp .depend
