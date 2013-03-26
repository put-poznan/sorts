#!/bin/sh

PREFIX=data
COUNT=50
STEP=5000

mkdir -p $PREFIX/sorted
mkdir -p $PREFIX/reversed
mkdir -p $PREFIX/random
mkdir -p $PREFIX/vshaped

for i in $(seq 1 $COUNT);
do
  i=$(($i * $STEP))
  seq 1 $i                          > $PREFIX/sorted/$i
  cat $PREFIX/sorted/$i  | sort -rn > $PREFIX/reversed/$i
  cat $PREFIX/sorted/$i  | sort -R  > $PREFIX/random/$i
  seq 1 $(($i/2))                   > $PREFIX/vshaped/$i
  cat $PREFIX/vshaped/$i | sort -rn >> $PREFIX/vshaped/$i
done
