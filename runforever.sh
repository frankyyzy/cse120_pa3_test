#!/bin/bash
alloc=`balance | grep 'units' | sed 's/.*Remaining allocation for cs120... was.//;s/.units//;s/\...//'`

if [ $alloc -ge 100 ]
then
echo 'good'
fi

echo "Starting Autorun..."
counter=0
while [ $counter -le 50 ] && [ $alloc -ge 190 ]
do
  echo "allocation is $alloc, let's run some more tests "
	((counter++))
	echo "**Script counter:  $counter**"
  ./test 1
  ./test 2
  ./test 3
  ./test 4
  ./test 5
  ./test 6
  ./test 7
  ./test 8
  ./test 9
  alloc=`balance | grep 'units' | sed 's/.*Remaining allocation for cs120... was.//;s/.units//;s/\...//'`
done

echo "**Script ran $counter times**"
