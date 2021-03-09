set -eux

pwd

cp $RUSTLIB ./rust.lib
ld -arch x86_64 -r --whole-archive rust.lib -o rust.o

cp $CLIB ./c.lib
ld -arch x86_64 -r --whole-archive c.lib -o c.o

rm rust.lib
rm c.lib

ar -crs $OUTFILE rust.o c.o
rm rust.o
rm c.o
