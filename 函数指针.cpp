# include<stdio.h>
int add(int ,int );
int main(void)
{
	int *p1[10];//ָ������ ���������10��ָ��int�������ݵ�ָ�� 
	int (*p2)[10];//ָ�����飬*p2��ָ�����10��int�������ݵ�һ�����飬
			//������û�����֣�Ϊ�������� 
	 
	
	
	int (*fptr)(int,int);//���庯��ָ��fptr����ָ��ָ��һ����������ڵ�ַ��
	                     //���ҿ��Է��� int�� 
   						// 
   	int res; 			//��int��int����ʾ ָ���������ָ��������int�����ĺ�����
	
	fptr=add;			//��add������ڵ�ַ��ֵ��fptrָ�룬��fptrָ����add���� 
	res=(*fptr)(1,2);   // �ȼ���fptr(1,2) 
	printf("a+b=%d\n",res); 
	return 0;
}
int add(int a,int b)
{
	return a+b; 
} 
