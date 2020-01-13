/*
** Exo 13
** Créez un programme qui enregistre une valeur dans l'entier access.four_bytes,  et affiche lecontenu de access.bytes[0] et access.bytes[1].
*/

#include <stdio.h>

union access
{
  int four_bytes;
  char bytes[4];
};

int	main()
{
  union access access;

  access.four_bytes = 42;
  printf("%d\n", access.bytes[0]);
  printf("%d\n", access.bytes[1]);
  return (0);
}
