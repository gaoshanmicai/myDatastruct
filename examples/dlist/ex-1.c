/*****************************************************************************
*                                                                            *
*  ex-1.c                                                                    *
*  ======                                                                    *
*                                                                            *
*  Description: Illustrates using a doubly-linked list (see Chapter 5).      *
*                                                                            *
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

/*****************************************************************************
*                                                                            *
*  ------------------------------ print_list ------------------------------  *
*                                                                            *
*****************************************************************************/

void print_list(const DList *list) {

DListElmt          *element;

int                *data,
                   i;

/*****************************************************************************
*                                                                            *
*  Display the doubly-linked list.                                           *
*                                                                            *
*****************************************************************************/

fprintf(stdout, "List size is %d\n", dlist_size(list));

i = 0;
element = dlist_head(list);

while (1) {

   data = dlist_data(element);
   fprintf(stdout, "list[%03d]=%03d\n", i, *data);

   i++;

   if (dlist_is_tail(element))
      break;
   else
      element = dlist_next(element);

}

return;

}

/*****************************************************************************
*                                                                            *
*  --------------------------------- main ---------------------------------  *
*                                                                            *
*****************************************************************************/

int main(int argc, char **argv) {

DList              list;
DListElmt          *element;

int                *data,
                   i;

/*****************************************************************************
*                                                                            *
*  Initialize the doubly-linked list.                                        *
*                                                                            *
*****************************************************************************/

printf("this is the Demo for Dlinklist\n");
dlist_init(&list, free);

/*****************************************************************************
*                                                                            *
*  Perform some doubly-linked list operations.                               *
*                                                                            *
*****************************************************************************/

element = dlist_head(&list);

for (i = 10; i > 0; i--) {

   if ((data = (int *)malloc(sizeof(int))) == NULL)
      return 1;

   *data = i;

   if (dlist_ins_prev(&list, dlist_head(&list), data) != 0)
      return 1;

}

print_list(&list);

element = dlist_head(&list);

for (i = 0; i < 8; i++)
   element = dlist_next(element);

data = dlist_data(element);
fprintf(stdout, "Removing an element after the one containing %03d\n", *data);

if (dlist_remove(&list, element, (void **)&data) != 0)
   return 1;

print_list(&list);

fprintf(stdout, "Inserting 011 at the tail of the list\n");

*data = 11;
if (dlist_ins_next(&list, dlist_tail(&list), data) != 0)
   return 1;

print_list(&list);

fprintf(stdout, "Removing an element at the tail of the list\n");

element = dlist_tail(&list);
if (dlist_remove(&list, element, (void **)&data) != 0)
   return 1;

print_list(&list);

fprintf(stdout, "Inserting 012 just before the tail of the list\n");

*data = 12;
if (dlist_ins_prev(&list, dlist_tail(&list), data) != 0)
   return 1;

print_list(&list);

fprintf(stdout, "Iterating and removing the fourth element\n");

element = dlist_head(&list);
element = dlist_next(element);
element = dlist_prev(element);
element = dlist_next(element);
element = dlist_prev(element);
element = dlist_next(element);
element = dlist_next(element);
element = dlist_next(element);

if (dlist_remove(&list, element, (void **)&data) != 0)
   return 1;

print_list(&list);

fprintf(stdout, "Inserting 013 before the first element\n");

*data = 13;
if (dlist_ins_prev(&list, dlist_head(&list), data) != 0)
   return 1;

print_list(&list);

fprintf(stdout, "Removing an element at the head of the list\n");

if (dlist_remove(&list, dlist_head(&list), (void **)&data) != 0)
   return 1;

print_list(&list);

fprintf(stdout, "Inserting 014 just after the head of the list\n");
*data = 14;

if (dlist_ins_next(&list, dlist_head(&list), data) != 0)
   return 1;

print_list(&list);

fprintf(stdout, "Inserting 015 two elements after the head of the list\n");

if ((data = (int *)malloc(sizeof(int))) == NULL)
   return 1;

*data = 15;
element = dlist_head(&list);
element = dlist_next(element);

if (dlist_ins_next(&list, element, data) != 0)
   return 1;

print_list(&list);

i = dlist_is_head(dlist_head(&list));
fprintf(stdout, "Testing dlist_is_head...Value=%d (1=OK)\n", i);
i = dlist_is_head(dlist_tail(&list));
fprintf(stdout, "Testing dlist_is_head...Value=%d (0=OK)\n", i);
i = dlist_is_tail(dlist_tail(&list));
fprintf(stdout, "Testing dlist_is_tail...Value=%d (1=OK)\n", i);
i = dlist_is_tail(dlist_head(&list));
fprintf(stdout, "Testing dlist_is_tail...Value=%d (0=OK)\n", i);

/*****************************************************************************
*                                                                            *
*  Destroy the doubly-linked list.                                           *
*                                                                            *
*****************************************************************************/

fprintf(stdout, "Destroying the list\n");
dlist_destroy(&list);

return 0;

}
