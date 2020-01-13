#!/bin/bash
# guigur 13/01/2020

result=1
echo "Saisir une valeur :"
read valeur

for ((i=0; i<$valeur; i++))
do
    result=$(($valeur*$result))
    echo $result
done

echo "$valeur^$valeur=$result"

