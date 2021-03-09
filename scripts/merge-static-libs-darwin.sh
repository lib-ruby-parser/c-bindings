set -eux

pwd

cp $RUSTLIB ./rust.lib
ar dv rust.lib apple_versioning.o
ld -arch x86_64 -r -force_load rust.lib -o rust.o

cp $CLIB ./c.lib
ld -arch x86_64 -r -force_load c.lib -o c.o

rm rust.lib
rm c.lib

ar -crs $OUTFILE rust.o c.o
rm rust.o
rm c.o
