#include <stdio.h>

#define SET_SIZE 100

typedef struct {
  int p[SET_SIZE + 1]; /* parent element */
  int size[SET_SIZE + 1]; /* qty of ele in subtree i */
  int n; /* qty of ele in set */
} set_union;

void set_union_init(set_union *s, int n)
{
  int i;

  for (i = 1; i <= n; i++) {
    s->p[i] = i;
    s->size[i] = 1;
  }

  s->n = n;
}

int find(set_union *s, int x)
{
  if (s->p[x] == x)
    return x;
  else
    return find(s, s->p[x]);
}

void union_sets(set_union *s, int s1, int s2)
{
  int r1, r2;

  r1 = find(s, s1);
  r2 = find(s, s2);

  if (r1 == r2)
    return;

  if (s->size[r1] >= s->size[r2]) {
    s->size[r1] = s->size[r1] + s->size[r2];
    s->p[r2] = r1;
  }
  else {
    s->size[r2] = s->size[r1] + s->size[r2];
    s->p[r1] = r2;
  }
}

int same_component(set_union *s, int s1, int s2)
{
  return find(s, s1) == find(s, s2);
}

int main(void)
{
  set_union *su;
  set_union_init(su, 7);

  union_sets(su, 4, 6);
  union_sets(su, 2, 7);
  union_sets(su, 4, 2);

  printf("parent of 7 is %d\n", find(su, 7));

  return 0;
}
