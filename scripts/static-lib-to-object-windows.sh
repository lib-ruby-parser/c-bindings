set -eux

pwd

cp $RUST_LIB_FILE .
RUST_FILE=$(basename $RUST_LIB_FILE)
link.exe ${RUST_FILE} /WHOLEARCHIVE /OUT:$RUST_OBJ_FILE
