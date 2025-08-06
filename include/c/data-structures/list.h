#ifndef LIST_H
#define LIST_H

struct node {
  char *data;
  struct node *next;
  struct node *prev;
};

struct list {
  struct node *head;
  struct node *tail;
  int size;
};

void init(struct list *l);
void insert(struct list *l, char *str);
void erase(struct list *l, char *str);
int find(struct list *l, char *str);
void print(struct list *l);
void destroy(struct list *l);

#endif // LIST_H