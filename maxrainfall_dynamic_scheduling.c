/* OpenMP Program example for Dynamic Scheduling.

Question : 4 sensors record rainfall in 4 cities over 4 days. Provided the amount of rainfall in each sensor,
every day, Write an OMP program using scheduling to find the maxumum rainfall recorded
among the sensors in each day.

*/

#include<stdio.h>
#include<omp.h>

int main(int argc, char** argv){
int s1[4],s2[4],s3[4],s4[4];
for (int i=0;i<4;i++) {
printf("Sensor Details for Day %d :- \n",i+1);
printf("Sensor 1 = ");
scanf("%d",&s1[i]);
printf("Sensor 2 = ");
scanf("%d",&s2[i]);
printf("Sensor 3 = ");
scanf("%d",&s3[i]);
printf("Sensor 4 = ");
scanf("%d",&s4[i]);
}
#pragma omp parallel num_threads(3)
{
#pragma omp for schedule(dynamic,4)
for (int j=0;j<4;j++) {
int max = 0;
if (s1[j]>max)
max=s1[j];
if (s2[j]>max)
max=s2[j];
if (s3[j]>max)
max=s3[j];
if (s4[j]>max)
max=s4[j];
printf("Max Rainfall of Day = %d \n",max);
}
printf("iteration run by thread %d \n",omp_get_thread_num());
}
}
