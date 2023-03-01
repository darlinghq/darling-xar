SRCROOT=$(cd ../.. && pwd)
BUILT_PRODUCTS_DIR="$SRCROOT/gen"

if [ ! -e "$BUILT_PRODUCTS_DIR" ]; then
	mkdir -p "$BUILT_PRODUCTS_DIR"
fi

cd "$BUILT_PRODUCTS_DIR"

$SRCROOT/xar/configure


exit 0
