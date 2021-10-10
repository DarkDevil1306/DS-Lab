/*Q1.Write a program in C to find the third largest from the given array of integers without sorting.
By 2020ITB028_RUPAYAN_THAKUR*/

#include<stdio.h>
#include<limits.h>
int main()
{
 printf("Enter the size of the array : ");
 int n;
 scanf( "%d",&n );
 int a[n];
 printf("Enter the elements of the array : \n");
 if(n<=2)
 {
 printf("--Invalid Input--");
 return 0;
 }
 for(int i=0 ; i<n ; i++ )
 {
 scanf("%d",&a[i]);
 }
 printf("---------------\n");
 int x , y , z;
 x = y = z = INT_MIN ;
 for(int i=0 ; i<n ; i++ )
 {
 if(x<a[i])
 {
 z=y; 
 y=x;
 x=a[i];
 }
 else if(y<a[i] && a[i]<x)
 {
 z=y;
 y=a[i];
 }
 else if(z<a[i] && a[i]<y)
 {
 z=a[i];
 }
 }
 printf("The 3rd highest element in the array : %d.\n", z );
 return 0;
} 
