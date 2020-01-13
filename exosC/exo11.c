/*
** Exo 11
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <math.h>

#define PRECISION 0.000001

enum	triangles {Quelquonque, Rectangle, Isocele, IsoceleRectangle, Equilateral, Plat, IsocelePlat, Argent, Or };
//---------------------ok----------ok--------ok----------ok--------------ok---------
int	pythaExtraGore(float a, float b, float c)
{
  double arg1 = (a * a) + (b * b);
  double arg2 = (c * c);

  if ((arg1 <= (arg2 + PRECISION)) && (arg1 >= (arg2 - PRECISION)))
    {
      return (1);
    }
  return (0);
}

int	extraPlat(float a, float b, float c)
{
  double arg1 = a + b;
  double arg2 = c;
  
  if (arg1 == arg2)
    {
      return (1);
    }
  return (0);
}

int	checkIfRaplapla(float cote1, float cote2, float cote3)
{
  if (extraPlat(cote1, cote2, cote3) || extraPlat(cote2, cote3, cote1) || extraPlat(cote3, cote2, cote1))
    {
      return (1);
    }
  return (0);
}

int	checkRectangle(float cote1, float cote2, float cote3)
{
  if (pythaExtraGore(cote1, cote2, cote3) || pythaExtraGore(cote2, cote3, cote1) || pythaExtraGore(cote3, cote1, cote2))
    { 
      return (1);
    }
  return (0);
}

int	trianglator(float cote1, float cote2, float cote3)
{
  if (cote1 == cote2 || cote2 == cote3 || cote3 == cote1)
    {
      if (cote1 == cote2 && cote1 == cote3 )
	{
	  printf("Equilateral\n");
	  return (Equilateral);
	}
      else
	{
	  if (checkRectangle(cote1, cote2, cote3))
	    {
	      printf("Isocele Rectangle\n");
	      return (IsoceleRectangle);
	    }
	  else
	    {
	      if (checkIfRaplapla(cote1, cote2, cote2))
		{
		  printf("Isocele Plat\n");
		  return (IsocelePlat);
		}
	      else
		{
		  printf("Isocele\n");
		  return (Isocele);
		}
	    }
	}
    }
  else
    {
      if (checkRectangle(cote1, cote2, cote3))
	{
	  printf("Rectangle\n");
	  return (Rectangle);
	}
      else if (checkIfRaplapla(cote1, cote2, cote3))
	{ 
	  printf("Plat\n");
	  return (Plat);
	}
      else
	{
	    printf("Quelquonque\n");
	}
    }
  return (Quelquonque);
}

int	main()
{
  float	cote1 = 3;
  float	cote2 = 4;
  float	cote3 = 5;
  
  trianglator(cote1, cote2, cote3);
  return (0);
}
