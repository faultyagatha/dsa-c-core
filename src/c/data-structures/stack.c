#include "data-structures/stack.h" // Include public declarations
#include <stdlib.h>
#include <string.h>

void init(struct stack *s, int initCapacity, size_t elementSize)
{
  s->size = 0;
  s->capacity = initCapacity;
  s->elementSize = elementSize;
  s->data = malloc(initCapacity * elementSize);
}

void freeStack(struct stack *s)
{
  free(s->data);
  s->data = NULL;
  s->capacity = 0;
  s->size = 0;
  s->elementSize = 0;
}

int isEmpty(struct stack *s)
{
  return s->size == 0;
}

int push(struct stack *s, const void *elem)
{
  if (s->size >= s->capacity)
  {
    int newCapacity = s->capacity * 2;
    void *newData = realloc(s->data, newCapacity * s->elementSize);
    if (!newData)
      return -1;

    s->data = newData;
    s->capacity = newCapacity;
  }
  // Copy element into stack memory
  void *target = (char *)s->data + s->size * s->elementSize;
  memcpy(target, elem, s->elementSize);
  s->size++;
  return 0;
}

int pop(struct stack *s, void *out)
{
  if (isEmpty(s))
    return -1;
    
  s->size--;
  void *source = (char *)s->data + s->size * s->elementSize;
  memcpy(out, source, s->elementSize);
  return 0;
}

int peek(struct stack *s, void *out)
{
  if (isEmpty(s))
    return -1;
  void *source = (char *)s->data + (s->size - 1) * s->elementSize;
  memcpy(out, source, s->elementSize);
  return 0;
}