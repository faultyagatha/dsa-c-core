#ifndef STACK_H
#define STACK_H

#include <stddef.h> // for size_t

// Tag for type-safe variant values
typedef enum {
  TYPE_CHAR,
  TYPE_INT,
  TYPE_INT_FUNC_PTR,
  TYPE_FLOAT_FUNC_PTR
} TypeTag;

typedef void (*FuncPtr)();

// Variant allows storing different types
typedef struct {
  TypeTag type;
  union {
    char c;
    int i;
    FuncPtr f;
  } data;
} Variant;

struct stack {
  void *data;
  int size;
  int capacity;
  size_t elementSize; // should be sizeof(Variant)
};

// Function declarations
void init(struct stack *s, int initCapacity, size_t elementSize);
void freeStack(struct stack *s);
int push(struct stack *s, const void *elem);
int pop(struct stack *s, void *out);
int peek(struct stack *s, void *out);
int isEmpty(struct stack *s);

#endif // STACK_H