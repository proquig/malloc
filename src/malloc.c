/*
** malloc.c for malloc in /home/jacque_x/rendu/PSU_2015_malloc/src
** 
** Made by JACQUET Vincent
** Login   <jacque_x@epitech.net>
** 
** Started on  Tue Feb  2 11:28:49 2016 JACQUET Vincent
** Last update Wed Feb  3 15:15:14 2016 JACQUET Vincent
*/

#include "../include/malloc.h"

void	*malloc(size_t size)
{
  void		*ptr;

  ptr = sbrk(0);
  if ((sbrk(size)) == (void *) - 1)
    return (NULL);
  return (ptr);
}

void	*realloc(void *ptr, size_t size)
{
  return (NULL);
}

void	free(void *ptr)
{
  
}

void	show_alloc_mem()
{
  
}
