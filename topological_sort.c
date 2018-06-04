#include <stdio.h>
#include <windows.h>
 
int main(){ // Initializing of main function
    int i,j,k,n,a[10][10],indeg[10],flag[10],count=0; // Initializing variables
 
    printf("Enter the no of vertices:\n");
    scanf("%d",&n); // Get value of n
 
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++){                   // For every row of matrix
        printf("Enter row %d\n",i+1);   // Enter the value of the row
        for(j=0;j<n;j++)                // For every column of matrix
            scanf("%d",&a[i][j]);       // Get position value
    }
 
    for(i=0;i<n;i++){   
        indeg[i]=0;     // Initializing indeg and flag with 0 value
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
    system("pause");
    return 0;
}