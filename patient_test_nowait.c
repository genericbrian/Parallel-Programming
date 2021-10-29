/* OpenMP program example that makes use of the nowait clause

Question : n Patients take 5 tests.
Test 1 is normal between values 20 and 30
Test 2 is normal between values 35.5 and 40
Test 3 is normal between values 12 and 15
Test 4 is normal between values 120 and 150
Test 5 is normal between values 80 and 120
Write and OMP program to check results using the nowait clause.

*/

#include<stdio.h>
#include<omp.h>

int main() {
int nthreads = 5;
omp_set_num_threads(nthreads);
int n;
printf("Enter the number of patients : ");
scanf("%d",&n);
float t1[n],t2[n],t3[n],t4[n],t5[n];
for (int i=0; i<n; i++){
printf("Enter the value of Test 1 for patient %d : ", i+1);
scanf("%f", &t1[i]);
printf("Enter the value of Test 2 for patient %d : ", i+1);
scanf("%f", &t2[i]);
printf("Enter the value of Test 3 for patient %d : ", i+1);
scanf("%f", &t3[i]);
printf("Enter the value of Test 4 for patient %d : ", i+1);
scanf("%f", &t4[i]);
printf("Enter the value of Test 5 for patient %d : ", i+1);
scanf("%f", &t5[i]);
}
#pragma omp parallel
{
#pragma omp for nowait
for (int i=0; i<n; i++) {
printf ("For Patient number %d :- \n", i+1);
#pragma omp critical
if (t1[i] =20 & t1[i] =30)
printf("Test 1 is normal \n");
else
printf("Test 1 is not normal \n");
if (t2[i] =35.5 & t2[i] =40)
printf("Test 2 is normal \n");
else
printf("Test 2 is not normal \n");
if (t3[i] =12 & t3[i] =15)
printf("Test 3 is normal \n");
else
printf("Test 3 is not normal \n");
if (t4[i] =120 & t4[i] =150)
printf("Test 4 is normal \n");
else
printf("Test 4 is not normal \n");
if (t5[i] =80 & t5[i] =120)
printf("Test 5 is normal \n");
else
printf("Test 5 is not normal \n");
printf("Iteration run by thread %d \n",omp_get_thread_num());
}
}
}
