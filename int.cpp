# include<stdio.h>
int main(void)
{
	/*int *p=NULL;
	printf("%p\n",p); 

	
	int i=8;
	printf("%p\n",&i); 
	p=&i;
	printf("%d  %d\n",i,*p) ;
	printf("%d  %d\n",i,*p) ;
	*p=3;
	printf("%d  %d\n",i,*p);
	printf("%p %x\n",i,p); 
	printf("%p %p",i,*p);*/
	
	int a[5]={0};
	int i=sizeof(a);
	printf("%d",i);
	
	
	 
	return 0;
 } 
