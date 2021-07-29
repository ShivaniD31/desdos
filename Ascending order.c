#include<stdio.h>
int ascend(int [],int );
int ascend(int a[],int n)
{
    int i,j,t=0;
    for( i=0;i<n;i++)
  {
    for( j=i+1;j<n;j++)
    if(a[i]>a[j])
   { t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
  } 
  printf("\nThe Ascending order is:");
  for(i=0;i<n;i++)
  {
      printf("%d\t",a[i]);
  }
  return 0;
}
int main()
{
    int n,i,arr[1000];
    printf("\nEnter no.of integers:");
    scanf("%d",&n);
    printf("\nEnter the integers:");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }
    ascend(arr,n);
    printf("\n");
    return 0;
}
