/*
** malloc.h for malloc in /home/jacque_x/rendu/PSU_2015_malloc/include
** 
** Made by JACQUET Vincent
** Login   <jacque_x@epitech.net>
** 
** Started on  Tue Feb  2 11:34:03 2016 JACQUET Vincent
** Last update Wed Feb  3 15:01:35 2016 JACQUET Vincent
*/

#ifndef _MALLOC_H
#define _MALLOC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list *t_list;

struct s_list
{
  t_list	next;
  size_t	nb;
  int		bool;
};

void    *malloc(size_t size);
void    *realloc(void *ptr, size_t size);
void    free(void *ptr);
void    show_alloc_mem();

#endif
