#include "data-structures/list.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main()
{
  struct list l;
  init(&l);

  // Test: Insert items
  insert(&l, "hello");
  insert(&l, "world");
  insert(&l, "!");
  assert(l.size == 3);

  // Test: Print
  printf("After inserts:\n");
  print(&l); // Should print: hello world !

  // Test: Find existing and non-existing elements
  assert(find(&l, "world") == 1);
  assert(find(&l, "notfound") == 0);

  // Test: Erase an item in the middle
  erase(&l, "world");
  assert(find(&l, "world") == 0);
  assert(l.size == 2);

  // Test: Erase head
  erase(&l, "hello");
  assert(find(&l, "hello") == 0);
  assert(l.size == 1);

  // Test: Erase tail
  erase(&l, "!");
  assert(find(&l, "!") == 0);
  assert(l.size == 0);
  assert(l.head == NULL && l.tail == NULL);

  // Insert again to test destroy
  insert(&l, "clean");
  insert(&l, "up");
  destroy(&l);
  assert(l.size == 0);
  assert(l.head == NULL && l.tail == NULL);

  printf("\nAll tests passed!\n");
  return 0;
}
