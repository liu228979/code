# include<stdio.h>
# include<malloc.h>
//���ܣ����Խṹ��ָ�룬���о�����洢��ʽ 
typedef struct Node
{
	int data;
	struct Node *pNext; 
}NODE,*PNODE;

int main(void)
{
    PNODE PHead=(PNODE)malloc(sizeof(NODE));//��̬��������ͷ��� 
	printf("����ͷ����ַ��%p\n", PHead);//�������ͷ����ַ 

	
	PNODE pTail=PHead;//����β��㣬����ͷ����ַ����β��㣬��β���ָ��ͷ��� 
    printf("����β����ַ��%p\n", pTail);//���β����ַ �������ͷ����ַһ�£���Ϊ β���ָ��ͷ���
		
	pTail->pNext=NULL;//���β����ָ���� 
	printf("β���ָ�����ַ��%p\n", pTail->pNext);//β���ָ�������0x00000000000�� 
	printf("����β����ַ��%p\n", pTail);//��������Ľ����Ȼ��ͷ����ַһ�¡�
	/*
	    ��⣺
		       Ҳ����˵�����Ը��ṹ��ָ�� struct Node *PNODE
		       �䱾��������������洢�ռ䣺
			                              1���ṹ��ָ�뱾�������еĿռ䣬�������struct Node * ���͵�ַ
										  2��Ϊ�ṹ���Ա struct Node *pNext������Ŀռ䣬������������¸����ĵ�ַ
										  3��Ϊ�ṹ���Ա int data ������Ŀռ䣬����������� 
	
	*/ 
	
	PNODE pNew =(PNODE)malloc(sizeof(NODE));//�����½�� 
	printf("����½���ַ��%p\n", pNew);//����½���ַ 
	pNew->data=1;//���½��������ֵ1
	
	 
	pTail->pNext=pNew;//���½���ַд��β���ָ����
	printf("β���ָ�����ַ��%p\n", pTail->pNext);
	printf("����β����ַ��%p\n", pTail);
	
	
	pNew->pNext=NULL;//���½��ָ������� �����½����Ϊβ�ڵ� 
	printf("����½��ָ�����ַ��%p\n", pNew->pNext);
	
	pTail=pNew;// Ҳ����ptail ��Ϊ�м�ڵ㣬pnew��Ϊβ������ptail���档 
	
	printf("���β����ַ��%p\n", pTail);
	
	
//	printf("%x", &pHead);
    
    
	return 0; 
}
