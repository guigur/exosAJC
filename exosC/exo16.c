/*
** Exo16
** Écrivez un programme qui demande la saisie de plusieurs mots, puis les affiche par ordre alphabétique. Utilisez l'allocation dynamique de mémoire uniquement (aucun tableau)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct link
{
  struct link* next;
  struct link* prev;
  int		 A;
};

void addLink(struct link* headElem, int A)
{
  struct link* newElem = calloc(sizeof(struct link), 1);
  struct link* nextElem = headElem->next;
  
  newElem->A = A;

  newElem->next = nextElem; // Set the newElmem "next" pointer to the next Elem
  newElem->prev = headElem; // Set the newElem "previous" pointer to the previous Elem
  if (nextElem != NULL)
    nextElem->prev = newElem; // Set the next Elem "previous" pointer to the created link
  headElem->next = newElem; // Set the previous Elem "next" pointer to the creaded link
}

void delLink(struct link** headElem)
{
  
  if ((*headElem)->next != NULL)
    {
      (*headElem)->next->prev = (*headElem)->prev;
    }
  if ((*headElem)->prev != NULL)
    {
      (*headElem)->prev->next = (*headElem)->next;
      
    }
  struct link* tmp = (*headElem);
  (*headElem) = (*headElem)->next;
  
  //headElem->A = NULL;
  free(tmp);
}

int	main()
{
  struct link* head = NULL;

  head = calloc(sizeof(struct link), 1);
  //  head->next = head;
  
  addLink(head, 1);
  
  addLink(head, 2);
  // delLink(&head);
  addLink(head, 3);

  //  delLink();
  //addLink(head, 2);
  //addLink(head, 3);
  
  //head  = calloc(sizeof(struct link), 1);
  //head->A = 2;

  /*
  head->next->next = calloc(sizeof(struct link), 1);
  head->next->next->A = 3;  
  */
    while(head != NULL)
    {
      printf("-----------\n");
      printf("head : %d\n", head->A);
      if (head->prev != NULL)
	printf("prev : %d\n", head->prev->A);
      if (head->next != NULL)
	printf("next : %d\n", head->next->A);
      
      head = head->next;
    }
  
  return (0);
}
