#include <stdio.h>
#include <math.h>

int main(void){
  int num;
  float baseX, baseY;
  float comX, comY;
  float minX, minY;
  float minDist;
  
  scanf("%d %f %f", &num, &baseX, &baseY);

  
  for(int i = 0; i < num ; i++){
    scanf("%f %f", &comX, &comY);
    float distance = sqrt(pow(baseX-comX, 2) + pow(baseY-comY, 2));
    
    if(i == 0 || distance < minDist){
      minX = comX;
      minY = comY;
      minDist = distance;
    }
  }

  printf("The closest point from (%0.2f, %0.2f) is (%0.2f, %0.2f) and distance between them is %0.2f\n", baseX, baseY, minX, minY, minDist);

}