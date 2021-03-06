#include <stdlib.h>
#include <stdio.h>

struct link {
  char c;
  struct link *next;
};

struct link *
addLink(struct link *l, char c)
{
  struct link *p, *temp;

  p = malloc(sizeof(struct link));
  p->c = c;
  p->next = NULL;

  if (l == NULL)
    return p;
  else {
    temp = l;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = p;
    return l;
  }
}

void showList(struct link *l)
{
  if (l == NULL)
    return;

  printf("char: %c\n", l->c);

  showList(l->next);
}

int main(void)
{
  struct link *list = NULL;
  list = addLink(list, 'a');
  list = addLink(list, 'b');
  showList(list);
}
