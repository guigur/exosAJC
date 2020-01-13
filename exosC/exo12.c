/*
** Exo 12
** Écrivez un programme qui pacourt les éléments d'un tableau à l'aide de ses indices pour l'initialisation, puis à l'aide d'un pointeur pour l'affichage.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int	main()
{
  char	*tab;

  if ((tab = malloc(SIZE)) == NULL)
    {
      printf("error while allocating memory \n");
      return (1);
    }
  
  for (int i = 0; i < SIZE; i++)
    {
      tab[i] = i;
    }

  for (int i = 0; i < SIZE; i++)
    {
      printf("tab[i]: %d\n", *(tab + i));
    }

  free(tab);
  
  return (0);
}
