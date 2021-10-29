/* Prefix Sum program using openMP

Question : Assume we have a 100-inch sandwich to feed ten people • We know how many inches each
person wants - 3, 5, 2, 7, 28, 4, 3, 0, 8, 1
Apply prefix sum - distance concept for the above problem 
*/

#include<stdio.h>
#include<omp.h>
#include<math.h>

int highestPowerof2(int n){
 int res = 0,i;
 for (i=n; i>=1; i -)
 {
 if ((i & (i-1)) = 0)
 {
 res = i;
 break;
 }
 }
 return res;
}
int main(int argc, char** argv){

 int arr[]={3,5,2,7,28,4,3,0,8,1};

 int n=sizeof(arr)/sizeof(arr[0]);
 int output[n],i=1,j;
 double x=highestPowerof2(n);
 int y= (int)log2(x);
 int p=pow(2,y);
 int nthreads=n;
 omp_set_num_threads(nthreads);
 printf("n=%d",n);
 printf("\nx=%f",x);
 printf("\ny=%d",y);
 printf("\np=%d\n ",p);
 output[0]=arr[0];

 #pragma omp parallel for private(i)
 for(i=1;i =p;i +){
 for(j=i;j<n;j +){
 output[j]=arr[j]+arr[j-i];
 }
 for(j=0;j<n;j +){
 arr[j]=output[j];
 }
 i=(i*2)-1;
 int th_id=omp_get_thread_num();
 printf(" with %d threads having thread ID : %d \n",omp_get_num_threads(),
th_id);
}
 printf("\nThe measurements to cut sandwiches are:");

 for(i=0;i<10;i +)
 {
 printf(" %d ",arr[i]);
}
pri
