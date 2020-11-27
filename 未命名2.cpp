# include<stdio.h>
# include<malloc.h> 

void edit(int *a,int b)
{
    int i;
    int j=9;
  for(i=0;i<b;i++)
 {
 	*a+=j;
 	a++;
 	
  } 
 // free(a);
}
int main(void)
{  
    int len;
    printf("输入数组长度\n",len);
    scanf("%d",&len);
    int j=0;
    int *arr = (int*)malloc(4*len); 
    int i;
    for(i=0;i<len;i++)
    {	
        arr[i]=j;
      j++;
        
	}
	for(i=0;i<len;i++)
	{
	
       printf("%d\n",arr[i]);
	}
	printf("\n\n\n");
	edit(arr,len);
	
	for(i=0;i<len;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
 } 
