
echo "=====[ Building V8 ]====="
python ./tools/dev/v8gen.py x64.release -vv -- '
is_debug = false
v8_enable_i18n_support= false
v8_use_snapshot = true
v8_use_external_startup_data = true
v8_static_library = true
strip_debug_info = true
symbol_level=0
libcxx_abi_unstable = false
v8_enable_pointer_compression=false
'
ninja -C out.gn/x64.release -t clean
ninja -C out.gn/x64.release wee8

node ./puerts/genBlobHeader.js "osx 64" out.gn/x64.release/snapshot_blob.bin

rm -rf ./puerts/output

mkdir -p ./puerts/output/Lib/macOS
cp out.gn/x64.release/obj/libwee8.a ./puerts/output/Lib/macOS/
cp -r ./include ./puerts/output/
mv ./puerts/output/include ./puerts/output/Inc
mkdir -p ./puerts/output/Inc/Blob/macOS
cp SnapshotBlob.h ./puerts/output/Inc/Blob/macOS/
rm -rf ./SnapshotBlob.h