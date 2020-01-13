#!/bin/bash
# guigur 13/01/2020
#Créer un script dans lequel deux nombres opérandes et un signe opérateur (+-*/) devront être donnés en paramètres, ou saisis. Le script doit réaliser l'opération souhaitée.
#Le calcul devra être fait à l'aide d'une fonction calcul ().

calcul()
{
    val=$(("$1 $2 $3"))
    echo "$1 $2 $3"
    echo $val
}

checkDigit()
{
    if [[ $1 = [0-9] ]]
    then
	return
    else
	echo "$nb1 n'est pas un nombre"
	exit
    fi
}

checkNbr()
{
    foo=$1
    for (( i=0; i<${#foo}; i++ ))
    do
	checkDigit "${foo:$i:1}"
    done    
}

checkOperator()
{
    if [[ $1 = [+*/-] ]]
    then
	return
    else
	echo "$1 n'est pas un opérteur accepté"
	echo "Seuls + * / - sont autorisés"
	exit
    fi
}

echo "nombre1 opérateur nombre2"
read nb1
checkNbr "$nb1"
read op
checkOperator "$op"
read nb2
checkNbr "$nb2"
calcul "$nb1" "$op" "$nb2"
