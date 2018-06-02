#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MIN_PER_RANK 1 
#define MAX_PER_RANK 5
#define MIN_RANKS 3    
#define MAX_RANKS 5
#define PERCENT 30     

int main (void)
{
  int i, j, k,nodes = 0;
  srand (time (NULL));

  int ranks = MIN_RANKS + (rand () % (MAX_RANKS - MIN_RANKS + 1));

  printf ("digraph {\n");
  for (i = 0; i < ranks; i++)
    {
      
      int new_nodes = MIN_PER_RANK + (rand () % (MAX_PER_RANK - MIN_PER_RANK + 1));

      
      for (j = 0; j < nodes; j++)
        for (k = 0; k < new_nodes; k++)
          if ( (rand () % 100) < PERCENT)
            printf ("  %d -> %d;\n", j, k + nodes); 

      nodes += new_nodes; 
    }
  printf ("}\n");
  system("pause");
  return 0;
}
