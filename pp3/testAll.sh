#!/bin/bash
DCC=./dcc
SAMPLES_DECAF=samples/*.decaf
RESULTS=tested

if [ ! -d $RESULTS ]; then
	mkdir $RESULTS
fi

for f in $SAMPLES_DECAF
do
	filename=$(basename "$f")
	extension="${filename##*.}"
	filename="${filename%.*}"
	OUT=$RESULTS"/"$filename.out

	$DCC < $f 2>$OUT
done
