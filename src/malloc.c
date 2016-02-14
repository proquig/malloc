/*
** malloc.c for malloc in /home/jacque_x/rendu/PSU_2015_malloc/src
** 
** Made by JACQUET Vincent
** Login   <jacque_x@epitech.net>
** 
** Started on  Tue Feb  2 11:28:49 2016 JACQUET Vincent
** Last update Sat Feb 13 17:31:11 2016 Guillaume PROQUIN
*/

#include "malloc.h"

void	*INIT = NULL;

void		free(void *ptr)
{
  t_mem		*mem;

  mem = INIT;
  if (!ptr)
    return ;
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

void		*malloc(size_t size)
{
  t_mem		*mem;

  if (!size)
    return (NULL);
  if (!INIT)
    mem = init_mem(size);
  else
    if (!(mem = find_mem(size)))
      mem = init_mem(size);
    else
      mem->free = 0;
  if (!mem)
    return (NULL);
  return (mem->ptr);
}

void	*realloc(void *ptr, size_t size)
{
  t_mem	*mem;
  t_mem	*tmp;
  int	i;

  tmp = INIT;
  if (!ptr)
    return (malloc(size));
  if (!size)
    free(ptr);
  if (!size)
    return (NULL);
  while (tmp)
    {
      if (ptr == (void*)tmp + sizeof(t_mem))
	{
	  mem = malloc(size);
	  i = -1;
	  while (++i < (int)size)
	    ((char*)mem)[i] = ((char*)ptr)[i];
	  free(ptr);
	  return (ptr = mem);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

void	*calloc(size_t nmemb, size_t size)
{
  char	*ret;
  int	i;

  if (!nmemb || !size)
    return (NULL);
  ret = malloc(nmemb * size);
  i = -1;
  while (++i < (int)(nmemb * size))
    ret[i] = 0;
  return (ret);
}

void		show_alloc_mem()
{
  t_mem		*mem;

  printf("break : %p\n", sbrk(0));
  mem = INIT;
  while (mem)
    {
      printf("%p - %p : %zu bytes\n", \
	     mem->ptr, (void*)mem->ptr + mem->size, mem->size);
      mem = mem->next;
    }
}
