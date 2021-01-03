#include <stdio.h>
int main(void)
{
	double avg = 0.0;
  double var = 0.0;
  double sc1 = 0;
  double sc2 = 0;
  double sc3 = 0;

	printf("세 명의 학생의 점수를 입력하세요.\n");
	scanf("%lf %lf %lf", &sc1, &sc2, &sc3);
  avg = (sc1+sc2+sc3)/3;
  var = ((sc1-avg)*(sc1-avg) + (sc2-avg)*(sc2-avg) + (sc3-avg)*(sc3-avg))/3;

	printf("평균: %lf  분산: %lf \n", avg, var);

	return 0;
}

