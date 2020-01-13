/*
** Exo 14
** Créez un programme qui affiche les offsets des différents champs de la structure suivante, et expliquez les résultats
*/

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

struct		demo_fill 
{
  uint8_t	first;
  uint32_t	second;
  uint8_t	add;
  uint8_t	tab[4];
  char*		pointer;
  uint8_t	c1;
  uint8_t	c2;
  uint16_t	last;
};

int	main()
{ 
 
  printf("Offset -> first %d\n", offsetof(struct demo_fill, first));
  printf("Offset -> second %d\n", offsetof(struct demo_fill, second));
  printf("Offset -> add %d\n", offsetof(struct demo_fill, add));
  printf("Offset -> tab %d\n", offsetof(struct demo_fill, tab));
  printf("Offset -> pointer %d\n", offsetof(struct demo_fill, pointer));
  printf("Offset -> c1 %d\n", offsetof(struct demo_fill, c1));
  printf("Offset -> c2 %d\n", offsetof(struct demo_fill, c2));
  printf("Offset -> last %d\n", offsetof(struct demo_fill, last));
  
  return (0);
}
