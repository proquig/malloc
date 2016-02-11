/*
** malloc.c for malloc in /home/jacque_x/rendu/PSU_2015_malloc/src
** 
** Made by JACQUET Vincent
** Login   <jacque_x@epitech.net>
** 
** Started on  Tue Feb  2 11:28:49 2016 JACQUET Vincent
** Last update Thu Feb 11 10:07:01 2016 Guillaume PROQUIN
*/

#include "malloc.h"

void	*INIT = NULL;

void		*malloc(size_t size)
{
  t_mem		*mem;

  if (!INIT)
    mem = init_mem(size);
  else
    if(!(mem = find_mem(size)))
      mem = init_mem(size);
    else
      mem->free = 0;
  if (!mem)
    return (NULL);
  return (mem->ptr);
}

void		free(void *ptr)
{
  t_mem		*mem;

  mem = INIT;
  while (mem)
    {
      if (ptr == (void*)mem + sizeof(t_mem))
	{
	  mem->free = 1;
	  if (!mem->next)
	    {
	      if (mem->prev)
		mem->prev->next = NULL;
	      else
		INIT = NULL;
	      brk(mem);
	      mem = NULL;
	    }
	  return ;
	}
      if (mem)
	mem = mem->next;
    }
}

void	*realloc(void *ptr, size_t size)
{
  t_mem	*mem;
  t_mem	*tmp;

  tmp = INIT;
  if (!ptr)
    return (malloc(size));
  if (!size)
    {
      free(ptr);
      return (NULL);
    }
  while (tmp)
    {
      if (ptr == (void*)tmp + sizeof(t_mem))
	{
	  mem = malloc(size);
	  memcpy(mem, ptr, tmp->size);
	  free(ptr);
	  ptr = mem;
	  return (ptr);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

void		show_alloc_mem()
{
  t_mem		*mem;

  printf("break : %p\n", sbrk(0));
  mem = INIT;
  while (mem)
    {
      printf("%p - %p : %zu bytes\n", mem, (void*)mem + mem->size, mem->size);
      mem = mem->next;
    }
}
