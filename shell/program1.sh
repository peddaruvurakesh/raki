#!/bin/bash
echo "hello world"
read -p " Enter input " n1
if [ $n1 -gt 0 ]; then
	echo "positive"
elif [ $n1 -eq 0 ];
then
	echo " equal "
else
	echo " negative "
fi
echo " printing " $n1
