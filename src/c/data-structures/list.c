#include "data-structures/list.h"  // Include public declarations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** C-code for double linked list of heap-allocated strings.
 */

void init(struct list *l)
{
  l->head = NULL;
  l->tail = NULL;
  l->size = 0;
}

void insert(struct list *l, char *str)
{
  struct node *n = (struct node *)malloc(sizeof(struct node));
  // Allocate memory for n->data and copy the string
  // to avoid unexpected behaviour and ensure that
  // each node has its own copy of the string.
  // If str is a local variable or dynamically allocated elsewhere,
  // modifying or freeing str outside this function could lead to unexpected behavior.
  n->data = strdup(str);
  n->next = NULL;
  if (!l->head)
  {
    n->prev = NULL;
    l->head = n;
    l->tail = n;
  }
  else
  {
    n->prev = l->tail;
    l->tail->next = n;
    l->tail = n;
  }

  l->size++;
}

void erase(struct list *l, char *str)
{
  struct node *n = l->head;
  while (n != NULL)
  {
    // Found a match
    if (strcmp(n->data, str) == 0)
    {
      // If the node is in the head
      if (n == l->head)
      {
        printf("erasing head %s \n", n->data);
        l->head = n->next;
        if (l->head)
        {
          l->head->prev = NULL;
        }
        else
        {
          l->tail = NULL;
        }
        // If the node is in the tail
      }
      else if (n == l->tail)
      {
        printf("erasing tale %s \n", n->data);

        l->tail = n->prev;

        if (l->tail)
        {
          l->tail->next = NULL;
        }
        else
        {
          l->head = NULL;
        }
        // If the node is in the middle
      }
      else
      {
        n->prev->next = n->next;
        n->next->prev = n->prev;
      }
      // Free allocated string memory
      free(n->data);
      // Free node
      free(n);
      l->size--;
      return;
    }

    n = n->next;
  }
}

int find(struct list *l, char *str)
{
  struct node *n = l->head;

  while (n != NULL)
  {
    if (strcmp(n->data, str) == 0)
    {
      printf("found the char %s \n", n->data);
      return 1;
    }
    n = n->next;
  }
  return 0;
}

void print(struct list *l)
{
  struct node *n = l->head;

  while (n != NULL)
  {
    printf("%s ", n->data);
    n = n->next;
  }

  if (l->head)
    printf("head: %s \n", l->head->data);
  else
    printf("List is empty\n");
}

void destroy(struct list *l)
{
  struct node *n = l->head;

  while (n != NULL)
  {
    struct node *next = n->next;
    free(n->data);
    free(n);
    n = next;
  }
  l->head = NULL;
  l->tail = NULL;
  l->size = 0;
}