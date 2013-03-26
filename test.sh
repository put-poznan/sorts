#!/bin/sh

SORTS=$*
TYPES='random reversed sorted vshaped'
DATA='data'
OUT='out'

rm -r $OUT
mkdir $OUT

for t in $TYPES
do
  for sorting in $SORTS
  do
    echo -n "Testing $sorting: "
    for i in $(ls $DATA/$t)
    do
      from=$(date +%s%N)
      ./$sorting $i < $DATA/$t/$i 2>&1
      echo $i $(echo "$(date +%s%N) - $from" | bc) >> ./$OUT/${t}_$sorting
    done
    echo "Done"
  done
done

