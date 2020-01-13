/*
** exo 9
*/

#include <stdlib.h>
#include <unistd.h>

int	putChar(char c)
{
  int	ret;
  
  ret = write(1, &c, 1);
  if (ret == -1)
    {
      exit(1);
    }
}

int	main(int argc, char **argv)
{
  int	lines = 0;
  int	stars = 1;

  if (argc < 2 || argc > 3)
    {
      return (1);
    }
  else
    {
      lines = atoi(argv[1]);
      if (argc >= 3)
	stars = atoi(argv[2]);
    }
  
  for(int i = 0; i != lines; i++)
    {

      for(int k = (lines - i) * stars; k != 0; k--)
	{
	  putChar(' ');
	}
      
      for(int j = 0; (j - 1) != (i + i) * stars; j++)
	{
	  putChar('*');
	}
      
       putChar('\n');
    }
  return (0);
}
