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
	$DCC < $f >& $OUT
	if [ -f "samples/"$filename.out ] ; then
		diff -a "samples/"$filename.out $OUT > $RESULTS"/"$filename.diff
		if [ $? -ne 0 ] ; then
	  		echo $filename " differs"
		fi
	else 
		echo "No "$filename".out found"
	fi
done
