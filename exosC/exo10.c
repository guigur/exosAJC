/*
** Exo 10
*/

#include <stdio.h>

int	main()
{
  int*	ptr = NULL;
  int	entier = 1;
  int*	addr = &entier;

  printf("ptr : %d\n", ptr);
  printf("&ptr :%d\n", &ptr);
  printf("entier : %d\n", entier);
  printf("&entier : %d\n", &entier);
  printf("addr : %d\n", addr);
  printf("&addr : %d\n", &addr);
 
  return (0);
}

