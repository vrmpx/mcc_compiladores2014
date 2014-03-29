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

	$DCC <$f >&$OUT

	printf "Checking %s: " $filename
	if ! cmp -s $OUT "samples/"$filename.out ; then
		echo "----------------- FAIL -----------------"
		diff $OUT "samples/"$filename.out | tee $RESULTS/$filename.diff
		echo "----------------- FAIL -----------------"
	else
		echo "----------------- PASS -----------------"
	fi
done
