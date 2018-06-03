#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct graph
{
    int no_elements;
    int **ad_matrix;
};

void top_sort( int n, int **a )
{
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

void random_graph( struct graph *graph )
{
    int iterator_1;
    int iterator_2;
    int flag;
    
    graph -> no_elements = rand() % 99 + 1;
 
    graph -> ad_matrix = (int **)calloc(graph -> no_elements, sizeof(int));

    for( iterator_1 = 0; iterator_1 < graph -> no_elements; iterator_1++ ){
        graph -> ad_matrix[iterator_1] = (int *)calloc(graph -> no_elements, sizeof(int));
    }


    for( iterator_1 = 0; iterator_1 < graph -> no_elements ; iterator_1++ ){
      for( iterator_2 = graph -> no_elements; iterator_2 > 0; iterator_2++ ){
        flag  = rand() % 2;
        
        if(flag == 1){
          graph -> ad_matrix[iterator_1][iterator_2] = 1;

        }
      }
    }
}

void print_ad_mat( struct graph graph)
{
    int iterator_1;
    int iterator_2;

    for( iterator_1 = 0; iterator_1 < graph.no_elements / 2; iterator_1++){
        for( iterator_2 = graph.no_elements / 2; iterator_2 < graph.no_elements; iterator_2++ ){
          printf("%d ", graph.ad_matrix[iterator_1][iterator_1]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    struct graph graph;
    random_graph( &graph );
    system("pause");
    print_ad_mat(graph);
    top_sort(graph.no_elements, graph.ad_matrix);

    system("pause");
  return 0;

}