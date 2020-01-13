#!/bin/bash
# guigur 13/01/2020

ok=-1
nombreDeNotes=0
note=0
noteMoy=0

while [ $ok -lt 0 ]
      do
	  
	  echo "saisir une note : "
	  read note
	  if [ $note = "q" ]
	  then
	      ok=1
	      echo "nombre de notes : $nombreDeNotes"
	      noteMoy=$(($noteMoy / $nombreDeNotes))
	      echo "note moyenne : $noteMoy"
	  elif [ $note -gt 20 ] || [ $note -lt 0 ]
	  then
	      echo "note invalide"
	  else
	      nombreDeNotes=$(($nombreDeNotes + 1))
	      noteMoy=$(($noteMoy + $note))
	  fi
done
	  
if  [ $noteMoy -ge 16 ] && [ $noteMoy -le 20 ]
then
    echo "très bien"
elif [ $noteMoy -ge 14 ] && [ $noteMoy -lt 16 ]
then
    echo "bien"
elif [ $noteMoy -ge 12 ] && [ $noteMoy -lt 14 ]
then
    echo "assez bien"
elif [ $noteMoy -ge 10 ] && [ $noteMoy -lt 12 ]
then
    echo "moyen"
elif [ $noteMoy -ge 0 ] && [ $noteMoy -lt 10 ]
then
    echo "insuffisant"
fi
