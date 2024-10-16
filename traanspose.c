#include<stdio.h>

int matTup[100][3];
int count = 0;

convSparse(int rows,int cols,int matrix[100][100]){
  for(int i = 0;i<rows;i++){
    for(int j =0 ;j<cols;j++){
      if(matrix[i][j] != 0){
        count++;
        matTup[count][0] = i;
        matTup[count][1] = j;
        matTup[count][2] = matrix[i][j];
      }
    }
  }
  matTup[0][0] = rows;
  matTup[0][1] = cols;
  matTup[0][2] = count;

  
}

void printTup(int count,int matrix[100][3]){
  for(int i = 0;i<count+1;i++){
    printf(" %d | %d | %d \n",matrix[i][0],matrix[i][1],matrix[i][2]);
  }
}

void tsp(int matrix[100][3],int count){
  int trans[100][3];
  for(int i = 0;i<count+1;i++){
    trans[i][0] = matrix[i][1];
    trans[i][1] = matrix[i][0];
    trans[i][2] = matrix[i][2];
  }

  for(int i = 0;i<count+1;i++){
    printf(" %d | %d | %d \n",trans[i][0],trans[i][1],trans[i][2]);
  }
}

int main(){
  int rows,cols;
  printf("Enter the numer of rows : ");
  scanf("%d",&rows);
  printf("Enter the number of cols : ");
  scanf("%d",&cols);

  int matrix[100][100];
  for(int i = 0;i<rows;i++){
    for (int j = 0;j<cols;j++){
      printf("Element %d%d : ",i,j);
      scanf("%d",&matrix[i][j]);
    }
  }

convSparse(rows,cols,matrix);
tsp(matTup,count);




  return 0;
}