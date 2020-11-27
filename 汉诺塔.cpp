# include<stdio.h>

int val=0;

void hannuota(int n,char A,char B,char C  )
{
	
	/*如果1ge盘子
	     直接将A柱子上的盘子从A移动到C
	  否则
	      先将A柱子上的n-1个盘子借助C柱子移动到B
		  直接将最后一个盘子从A移动到C
		  最后将B柱子上的n-1个盘子借助A移动到C 
	*/ 
	if(1==n)
	{
		printf("1将编号为%d的盘子直接从%c柱子移动到%c柱子\n",n,A,C);
	 } 
	 else
	 {
	 	hannuota(n-1,A,C,B);
	 	
		printf("2将编号为%d的盘子直接从%c柱子移动到%c柱子\n",n,A,C);
	 	
	 	hannuota(n-1,B,A,C);
	 
	 }
	
}
int main(void)
{
    char ch1= 'A',ch2='B',ch3='C';
	int n;
	printf("请输入移动的盘子个数：");
	scanf("%d",&n);	
	hannuota(n,'A','B','C');//传递char类型数据用单引号
//	printf("总共移动的次数是%d ",val); 
	return 0;
 } 
