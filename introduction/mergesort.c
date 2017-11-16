#include <stdio.h>

#define BUFSIZE 100

void merge(char s[], int low, int middle, int high)
{
  char buf[BUFSIZE];
  int i, j, k;

  i = low;
  j = middle + 1;
  k = 0;
  while(i <= middle && j <= high) {
    if (s[i] <= s[j])
      buf[k++] = s[i++];
    else
      buf[k++] = s[j++];
  }

  while (i <= middle)
    buf[k++] = s[i++];
  while (j <= high)
    buf[k++] = s[j++];

  for (i = low, k = 0; i <= high; i++, k++)
    s[i] = buf[k];
}

void msort(char s[], int low, int high)
{
  int i;
  int middle;

  if (low < high) {
    middle = (low + high) / 2;
    msort(s, low, middle);
    msort(s, middle + 1, high);
    merge(s, low, middle, high);
  }
}

int main()
{
  char str[] = "thequickbrownfoxjumpsoverthelazydog";
  int leng = 34;

  msort(str, 0, leng);

  printf("sorted: %s\n", str);

  return 0;
}
