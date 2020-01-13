#!/bin/bash
# guigur 13/01/2020

ok=-1

while [ $ok -lt 0 ]
      do
	  echo "saisir une note : "
	  read note

	  if [ $note = "q" ]
	  then
	      ok=1
	  elif  [ $note -ge 16 ] && [ $note -le 20 ]
	  then
	      echo "très bien"
	      ok=1
	  elif [ $note -ge 14 ] && [ $note -lt 16 ]
	  then
	      echo "bien"
	      ok=1
	  elif [ $note -ge 12 ] && [ $note -lt 14 ]
	  then
	      echo "assez bien"
	      ok=1
	  elif [ $note -ge 10 ] && [ $note -lt 12 ]
	  then
	      echo "moyen"
	      ok=1
	  elif [ $note -ge 0 ] && [ $note -lt 10 ]
	  then
	      echo "insuffisant"
	      ok=1
	  fi
done
