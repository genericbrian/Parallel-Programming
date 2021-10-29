// OpenMP Program using looping parallelism to find the primes in the first N numbers

#include <stdio.h>
#include <omp.h>
int main ()
{
 int nthreads = 4;
 int n;
 omp_set_num_threads(nthreads);
 printf("Enter n = ");
 scanf("%d",&n);
 #pragma omp parallel
 {
 int id = omp_get_thread_num();
 int i,j,count=0,c;
 printf("The Prime Numbers till %d are: ", n);
 if (n<2)
 printf("No Primes \n");
 else{
 for (i=2;i<=n;i +){
 c=0;
 for(j=2;j<=i;j +){
 if (i%j =0)
 c +;
 }
 if (c =1) {
 printf("%d, ", i);
 count +;
 }
 }

 }
 printf("Number of Prime Numbers = %d \n", count);
 printf(" with %d threads having thread ID : %d \n",omp_get_num_threads(),
omp_get_thread_num());
 }
 printf("all done, with hopefully %d threads\n",nthreads);
}
