#include<stdio.h>
#define MAX 100

void checkSparceMatrix(int rows,int cols,int matrix[MAX][MAX]){
  int zeroCount = 0;
  int totalElements = rows * cols;

  for(int i = 0;i<rows;i++){
    for(int j = 0;j<cols;j++){
      if(matrix[i][j] == 0){
        zeroCount++;
      }

      }
    }
    float sparsity = (float)zeroCount / totalElements * 100;

        if(zeroCount > totalElements/2){
          printf("The given matrix is a sparse matrix\n");
          printf("sparsity = %f",sparsity);
        }
        else{
          printf("The given matrix is not a sparse matrix\n");
        }
}


int main(){
  int rows,cols;
  printf("Enter the number of rows : ");
  scanf("%d",&rows);
  printf("Enter the number of cols : ");
  scanf("%d",&cols);

  int matrix[MAX][MAX];
  
  for(int i = 0;i<rows;i++){
    for(int j = 0;j<cols;j++){
      printf("Element %d%d : ",i,j);
      scanf("%d",&matrix[i][j]);
    }
  }

  checkSparceMatrix(rows,cols,matrix);
}