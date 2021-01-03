#include <stdio.h>

int main(void){
  int matrixA[3][3];
  int matrixB[3][3];
  int matrixC[3][3];

  for(int i = 0; i < 3; i++){
    scanf("%d %d %d", &matrixA[i][0], &matrixA[i][1], &matrixA[i][2]);
  }

  for(int i = 0; i < 3; i++){
    scanf("%d %d %d", &matrixB[i][0], &matrixB[i][1], &matrixB[i][2]);
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      matrixC[i][j] = matrixA[i][0] * matrixB[0][j] + matrixA[i][1] * matrixB[1][j] + matrixA[i][2] * matrixB[2][j];
    }
  }

  for(int i = 0; i < 3; i++){
    printf("%5d %5d %5d\n", matrixC[i][0], matrixC[i][1], matrixC[i][2]);
  }

}