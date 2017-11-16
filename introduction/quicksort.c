#include <stdio.h>

void swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

int partition(char s[], int a, int z)
{
  int i;
  int p = z;
  int firsthigh = a;

  for (i = a; i < z; i++)
    if (s[i] < s[p]) {
      swap(&s[i], &s[firsthigh]);
      firsthigh++;
    }

  swap(&s[p], &s[firsthigh]);

  return firsthigh;
}

void quicksort(char s[], int a, int z)
{
  int p; /* index of partition */
  if ((z - a) > 0) {
    p = partition(s, a, z);
    quicksort(s, a, p - 1);
    quicksort(s, p + 1, z);
  }
}

int main()
{
  char str[] = "thequickbrownfoxjumpsoverthelazydog";
  quicksort(str, 0, 34);

  printf("%s\n", str);
}
