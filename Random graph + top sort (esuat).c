#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PER_RANK 1
#define MAX_PER_RANK 5
#define MIN_RANKS 3    
#define MAX_RANKS 5
#define PERCENT 30    

struct graph{
    int no_elements;
    int **ad_matrix;
};

void top_sort( int n, int **a ){
    int i, j, k, indeg[10], flag[10], count=0;

    for(i=0;i<n;i++){
        indeg[i]=0;
        flag[i]=0;
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            indeg[i]=indeg[i]+a[j][i];

    printf("\nThe topological order is:");

    while(count<n){
        for(k=0;k<n;k++){
            if((indeg[k]==0) && (flag[k]==0)){
                printf("%d ",(k+1));
                flag [k]=1;
            }

            for(i=0;i<n;i++){
                if(a[i][k]==1)
                    indeg[k]--;
            }
        }

        count++;
    }

}

void random_graph( struct graph *graph ){
  int i, j, k,nodes = 0;
  srand (time (NULL));

  int ranks = MIN_RANKS + (rand () % (MAX_RANKS - MIN_RANKS + 1));

  graph -> no_elements = ranks;
  graph -> ad_matrix = (int**)calloc(graph -> no_elements, sizeof(int));

  for( i = 0; i < graph -> no_elements; i++ ){
    graph -> ad_matrix[i] = (int*)calloc( graph -> no_elements, sizeof(int) );
  }

  printf ("digraph ");
  for (i = 0; i < ranks; i++)
    {
     
      int new_nodes = MIN_PER_RANK + (rand () % (MAX_PER_RANK - MIN_PER_RANK + 1));

   
      for (j = 0; j < nodes; j++)
        for (k = 0; k < new_nodes; k++)
          if ( (rand () % 100) < PERCENT){
            graph -> ad_matrix[j][k + nodes] = 1;
          }

      nodes += new_nodes; 
    }
}

int main(){
    struct graph graph;
    random_graph( &graph );
    system("pause");
    top_sort(graph.no_elements, graph.ad_matrix);

  return 0;

}
