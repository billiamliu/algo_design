#include <stdio.h>

#define MAXV 1000
#define MAXINT 9999

typedef struct {
  int y;
  int weight;
  struct edgenode *next;
} edgenode;

typedef struct {
  edgenode *edges[MAXV + 1];
  int degree[MAXV + 1];
  int nvertices;
  int nedges;
  int directed;
} graph;

void dijkstra(graph *g, int start)
{
  int i;
  edgenode *p;
  int intree[MAXV + 1];
  int distance[MAXV + 1];
  int v;
  int w;
  int weight;
  int dist;

  int parent[MAXV + 1];

  for (i = 1; i <= g->nvertices; i++) {
    intree[i] = 0;
    distance[i] = MAXINT;
    parent[i] = -1;
  }

  distance[start] = 0;
  v = start;

  while (intree[v] == 0) {
    intree[v] = 1;
    p = g->edges[v];
    while (p != NULL) {
      w = p->y;
      weight = p->weight;
      if (distance[w] > (distance[v] + weight)) {
        distance[w] = distance[v] + weight;
        parent[w] = v;
      }
      p = (edgenode *) p->next;
    }

    v = 1;
    dist = MAXINT;
    for (i = 1; i <= g->nvertices; i++)
      if ((intree[i] == 0) && (dist > distance[i])) {
        dist = distance[i];
        v = i;
      }
  }
}
