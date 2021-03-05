set -eux

pwd

cp $RUST_LIB_FILE .
RUST_FILE=$(basename $RUST_LIB_FILE)
ar dv $RUST_FILE apple_versioning.o
ld -arch x86_64 -r -force_load ${RUST_FILE} -o $RUST_OBJ_FILE
rm $RUST_FILE
