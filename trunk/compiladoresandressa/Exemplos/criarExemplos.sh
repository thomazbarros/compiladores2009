#! /bin/bash

cd Exemplos

for i in `ls *.aia`
do
	../aia < $i > ${i%.aia}.c
done

exit 0

