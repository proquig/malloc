/*
** malloc.h for malloc in /home/jacque_x/rendu/PSU_2015_malloc/include
** 
** Made by JACQUET Vincent
** Login   <jacque_x@epitech.net>
** 
** Started on  Tue Feb  2 11:34:03 2016 JACQUET Vincent
** Last update Thu Feb 11 09:53:13 2016 Guillaume PROQUIN
*/

#ifndef		__MALLOC_H__
#define		__MALLOC_H__

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

typedef struct	s_mem
{
  size_t	size;
  char		free;
  void		*ptr;
  struct s_mem	*next;
  struct s_mem	*prev;
}		t_mem;

t_mem		*find_mem(size_t size);
t_mem		*init_mem(size_t size);
void		*malloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		free(void *ptr);
void		show_alloc_mem();

#endif
