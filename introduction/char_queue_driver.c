#include <stdio.h>
#include "char_queue.h"

int main(void)
{
  Queue *q;
  Job *j1, *j2;
  q = makeQueue();
  j1 = createJob('h');
  j2 = createJob('i');
  enqueue(q, j1);
  enqueue(q, j2);

  printf("first job: %c\n", dequeue(q)->c);
  printf("second job: %c\n", dequeue(q)->c);
  printf(dequeue(q) == NULL ? "queue empty\n" : "queue not empty\n");
}
