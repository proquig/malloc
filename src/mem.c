/*
** mem.c for malloc in /home/proqui_g/rendu/PSU_2015_malloc/src
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Thu Feb 11 09:56:05 2016 Guillaume PROQUIN
** Last update Thu Feb 11 09:59:39 2016 Guillaume PROQUIN
*/

#include "malloc.h"

extern void	*INIT;

t_mem		*find_mem(size_t size)
{
  t_mem		*mem;

  mem = INIT;
  while (mem && !(mem->free && mem->size > size))
    mem = mem->next;
  return (mem);
}

t_mem		*init_mem(size_t size)
{
  t_mem		*mem;
  t_mem		*tmp;

  mem = sbrk(0);
  if (sbrk(sizeof(t_mem) + size) == (void*) -1)
    return (NULL);
  mem->size = size;
  mem->free = 0;
  tmp = INIT;
  while (tmp && tmp->next)
    tmp = tmp->next;
  mem->prev = tmp;
  if (tmp)
    tmp->next = mem;
  mem->next = NULL;
  mem->ptr = (void*)mem + sizeof(t_mem);
  if (!INIT)
    INIT = mem;
  return (mem);
}
