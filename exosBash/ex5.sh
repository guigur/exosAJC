#!/bin/bash
# guigur 13/01/2020

appreciation(){
    if  [ $1 -ge 16 ] && [ $1 -le 20 ]
    then
	echo "très bien"
    elif [ $1 -ge 14 ] && [ $1 -lt 16 ]
    then
	echo "bien"
    elif [ $1 -ge 12 ] && [ $1 -lt 14 ]
    then
	echo "assez bien"
    elif [ $1 -ge 10 ] && [ $1 -lt 12 ]
    then
	echo "moyen"
    elif [ $1 -ge 0 ] && [ $1 -lt 10 ]
    then
	echo "insuffisant"    
    fi 
}

if [ "$#" -lt 1 ]
then
    echo "saisir la note"
    read val
else
    val=$1
fi

appreciation $val
