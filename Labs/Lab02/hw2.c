#include <stdio.h>

int main(void)
{
	float rad = 0.0;
	float pi = 3.14;
  float vol = 0.0;
  float area = 0.0;

	printf("구의 반지름 값을 입력하세요.\n");
	scanf("%f", &rad);
	vol = 4 * pi * rad * rad * rad / 3;
	area = 4.0 * pi * rad * rad;

	printf("부피: %f 겉넓이: %f \n", vol, area);
}

