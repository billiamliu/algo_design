typedef struct job {
  struct job *next;
  char c;
} Job;

typedef struct queue {
  struct job *head;
  struct job *tail;
} Queue;

Queue *makeQueue(void);
Job *createJob(char);
void enqueue(Queue *, Job *);
Job *dequeue(Queue *);

