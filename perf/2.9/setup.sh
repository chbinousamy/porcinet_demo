# export or set SNORT2_BUILD and SNORT_PCAPS below
# set the app_detector_dir in odp.conf

[ -d "$SNORT2_BUILD" ] || SNORT2_BUILD=/home/snorty/snort2/snort-2.9.12/o3
[ -d "$SNORT_PCAPS" ] || SNORT_PCAPS=/home/snorty/ramdisk

snort=$SNORT2_BUILD/bin/snort
plugs=$SNORT2_BUILD/lib/snort_dynamicpreprocessor
engine=$SNORT2_BUILD/lib/snort_dynamicengine/libsf_engine.so

confs="decode stream inspect detect-min detect-max"
daq="--daq dump --daq-var load-mode=read-file --daq-var output=none"
args="--dynamic-preprocessor-lib-dir $plugs --dynamic-engine-lib $engine $daq -H -A console:test"
runt="Run time"

