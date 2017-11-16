#include <stdio.h>
#include <stdlib.h>

#define PQSIZE 50

typedef struct {
  char body[PQSIZE + 1]; /* PQ array */
  int n; /* qty Q elements */
} pq;

void bubble_up(pq *, int);
void bubble_down(pq *, int);
void swap(pq *, int, int);
void insert(pq *, char);

int parent(int n)
{
  if (n == 1)
    return (-1);
  else
    return n / 2;
}

int young_child(int n)
{
  return 2 * n;
}

int old_child(int n)
{
  return 2 * n + 1;
}

void insert(pq *q, char c)
{
  if (q->n >= PQSIZE)
    printf("]Error: Priority Queue Overflow inserting: %c\n", c);
  else {
    q->n++;
    q->body[q->n] = c;
    bubble_up(q, q->n);
  }
}

void bubble_up(pq *q, int k)
{
  int par;
  if ((par = parent(k)) == -1)
    return;

  if (q->body[par] > q->body[k]) {
    swap(q, k, par);
    bubble_up(q, par);
  }
}

void swap(pq *q, int k, int paren)
{
  char temp;
  temp = q->body[paren];
  q->body[paren] = q->body[k];
  q->body[k] = temp;
}

pq *make_heap(char s[], int n)
{
  int i;

  pq *q;
  q = malloc(sizeof(pq));

  q->n = 0;

  for (i = 0; i < n; i++)
    insert(q, s[i]);

  return q;
}

pq *make_heap_down(char s[], int n)
{
  pq *q;
  int i;

  q = malloc(sizeof(pq));
  q->n = n;

  for (i = 0; i < n; i++)
    q->body[i + 1] = s[i];

  for (i = n; i >= 1; i--)
    bubble_down(q, i);

  return q;
}

void bubble_down(pq *q, int k)
{
  int yc; /* child index */
  int i;
  int min_index;

  yc = young_child(k);
  min_index = k;

  for (i = 0; i <= 1; i++)
    if ((yc + i) <= q->n && q->body[min_index] > q->body[yc + i])
      min_index = yc + i;

  if (min_index != k) {
    swap(q, k, min_index);
    bubble_down(q, min_index);
  }
}

char extract_min(pq *q)
{
  int min = -1;

  if (q->n <= 0)
    printf("Error: empty priority queue");
  else {
    min = q->body[1];
    q->body[1] = q->body[q->n];
    q->n--;
    bubble_down(q, 1);
  }

  return min;
}

char *hsort(char s[], int n)
{
  int i;
  pq *q;

  q = make_heap_down(s, n);

  for (i = 0; i < n; i++)
    s[i] = extract_min(q);

  return s;
}

int main()
{
  int max = PQSIZE;
  char str[] = "bcaaadfe";
  int leng = 8;
  int i;

  pq *q = make_heap(str, leng);

  printf("PQ contains %d elements\n", q->n);

  i = leng;
  while (max--) {
    printf("%3d", PQSIZE - max);
  }
  printf("\n");
  while (i--) {
    printf("%3c", q->body[i + 1]);
  }
  printf("\n");

  hsort(str, leng);
  printf("heapsort result: %s\n", str);

  return 0;
}
