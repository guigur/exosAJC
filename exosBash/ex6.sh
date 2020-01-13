#!/bin/bash
65;5402;1c# guigur 13/01/2020
#Créer un script qui vous propose le menu suivant :
#1 - Vérifier l'existence d'un utilisateur
#2 - Connaître l'UID d'un utilisateur
#q - Quitter
#L'utilisateur devra être saisi, à l'aide d'une fonction. Son existence devra être vérifiée à l'aide d'une autre fonction

username=""

readUsername()
{
    echo "entrez le nom d'utilisateur"
    read username
}

checkIfExist()
{
    uid=$(id -u $username 2> /dev/null)
    if [ $uid ]
    then
	if [ $1 -eq 1 ]
	then
	    echo $uid
	else
	    echo "l'utilsateur exite"
	fi
    else
	echo "l'utisateur n'exsiste pas"
    fi
}

menu()
{
    echo "1 - Vérifier l'existence d'un utilisateur"
    echo "2 - Connaître l'UID d'un utilisateur"
    echo "q - Quitter"
    read menuEntry
    if [ $menuEntry = "1" ]
    then
	readUsername
	checkIfExist
    elif [ $menuEntry = "2" ]
    then
	readUsername
	checkIfExist "1"
    elif [ $menuEntry = "q" ]
    then
	return 0
    fi
}

menu
