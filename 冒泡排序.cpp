# include <stdio.h>

void sort(int *a,int len)
{
	int i,j;
	int t;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t; 
			}
			
		 } 
	} 
	
}
int main(void)
{
	int i;
	int a[5] ={9,8,7,6,5};
	for(i=0;i<5;i++)
	{  
	  printf("%d ",a[i]);
	}
	printf("\n\n");
	 sort(a,5);
	for(i=0;i<5;i++)
	{  
	  printf("%d ",a[i]);
	}
	return 0;
 } 
