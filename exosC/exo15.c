/**
 ** Exo 15
 ** Créer un programme qui reproduit le fonctionnement de l'utilitaire cut, en utilisant une version simplifiée et limitée des paramètres disponibles pour la commande réelle
 **/

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
  FILE		*file;
  char		*lineBuf = NULL;
  size_t	lineBufSize = 0;
  int		lineCount = 0;
  ssize_t	lineSize = 0;
  
  if ((file = fopen(argv[1], "r")) == NULL)
    {
      printf("File \"%s\" can't be open\n", argv[1]);
      return (1);
    }


  while ((lineSize = getline(&lineBuf, &lineBufSize, file)) >= 0)
  {
    printf("line[%06d]: chars=%06zd, buf size=%06zu, contents: %s", lineCount, lineSize, lineBufSize, lineBuf);  
    lineCount++;
  }

  free(lineBuf);
  fclose(file);

  return (0);
}
