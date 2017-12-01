#define MAXV 1000

typedef struct {
  int weight[MAXV + 1][MAXV + 1];
  int nvertices;
} adjacency_matrix;

void floyd(adjacency_matrix *g)
{
  int i, j;
  int k;
  int through_k;

  for (k = 1; k <= g->nvertices; k++)
    for (i = 1; i <= g->nvertices; i++)
      for (j = 1; j <= g->nvertices; j++) {
        through_k = g->weight[i][k] + g->weight[k][j];
        if (through_k < g->weight[i][j])
          g->weight[i][j] = through_k;
      }
}
