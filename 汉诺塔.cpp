# include<stdio.h>

int val=0;

void hannuota(int n,char A,char B,char C  )
{
	
	/*���1ge����
	     ֱ�ӽ�A�����ϵ����Ӵ�A�ƶ���C
	  ����
	      �Ƚ�A�����ϵ�n-1�����ӽ���C�����ƶ���B
		  ֱ�ӽ����һ�����Ӵ�A�ƶ���C
		  ���B�����ϵ�n-1�����ӽ���A�ƶ���C 
	*/ 
	if(1==n)
	{
		printf("1�����Ϊ%d������ֱ�Ӵ�%c�����ƶ���%c����\n",n,A,C);
	 } 
	 else
	 {
	 	hannuota(n-1,A,C,B);
	 	
		printf("2�����Ϊ%d������ֱ�Ӵ�%c�����ƶ���%c����\n",n,A,C);
	 	
	 	hannuota(n-1,B,A,C);
	 
	 }
	
}
int main(void)
{
    char ch1= 'A',ch2='B',ch3='C';
	int n;
	printf("�������ƶ������Ӹ�����");
	scanf("%d",&n);	
	hannuota(n,'A','B','C');//����char���������õ�����
//	printf("�ܹ��ƶ��Ĵ�����%d ",val); 
	return 0;
 } 
