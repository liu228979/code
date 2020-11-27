# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
 
typedef struct Node
 {
 	int data;//������ 
 	struct Node *pNext;//ָ���� 
 }NODE,*PNODE; //NODE�ȼ���struct Node; *PNODE�ȼ���struct Node * 
 
void traverse_list(PNODE pHead); //������������� 
PNODE create_list(void);//����һ������
bool is_empty(PNODE pHead);//�ж������Ƿ�Ϊ�� 
int length(PNODE); //�������� 
bool insert(PNODE,int,int);
bool delete_list(PNODE,int,int*);
void sort(PNODE);//�������� 

 
 
int main(void)
{
	int len=0;
	PNODE pHead =NULL;//�ȼ���struct Node *pHead=NULL; 
    pHead =create_list(); //����һ����ѭ�������������������ͷ���ĵ�ַ����pHead;
	if(is_empty(pHead))
	
	      printf("�����\n");
	   else
	   traverse_list(pHead);//�����������
	   
    printf("�������ǣ�%d\n",len=length(pHead)); 
    sort(pHead);
    traverse_list(pHead);
	return 0;
 } 
 
 
 
PNODE create_list(void)
 {
 	int len;//�����Ч������
	int i;
	int val;//��ʱ����û�����Ľ���ֵ 
	PNODE PHead=(PNODE)malloc(sizeof(NODE));//����ͷ��� //�������Ч���� 
	if(NULL==PHead)
	{
		printf("�ڴ����ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	PNODE pTail=PHead;// pTailָ��ͷ��� 
	pTail->pNext=NULL;// ͷ���ָ������� 
 	printf("��������Ҫ���ɵ�����ڵ������len=");
	scanf("%d",&len); 
	for(int i=0; i<len;i++)
	{
		printf("�������%d���ڵ��ֵ:",i+1);
		scanf("%d",&val);
		PNODE pNew =(PNODE)malloc(sizeof(NODE));// ÿѭ��һ�����һ���½�� 
		
    	if(NULL==pNew)
    	{
		printf("�ڴ����ʧ�ܣ�������ֹ��\n");
		exit(-1);
	    }
	    pNew->data=val;//�� ��ʱ���ݷ����½��������� 
	    pTail->pNext=pNew;//�½��ṹ��ָ��ָ�������ɽ���ָ���򣬼���Զָ��β��� //����β������ 
	    pNew->pNext=NULL;//�½���ָ����Ϊ��//�½���Ϊβ��� 
	    pTail=pNew;// pTailָ���½ڵ� 
	 } 
	 return PHead;
 }
 
 
 void traverse_list(PNODE pHead)
 {
 	PNODE p=pHead->pNext;
 	while(NULL!=p)
 	{
 		printf("%d\n",p->data);
 		p=p->pNext;
 	}
 	printf("\n");
 	return ;
 }
 
 
 bool is_empty(PNODE pHead)
 {
 	if(NULL==pHead->pNext)
 	  return true;
 	  else
 	  return false;
 	
 }
 
 
 
 int length(PNODE pHead)
 {
 	PNODE p=pHead->pNext;
 	int len=0;
 	while(NULL!=p)
 	{
 		++len;
 		p=p->pNext;
	 }
	 return len;
 }
 
 void sort(PNODE pHead)
 {
 	int i, j , t;
	int len=length(pHead);
 	
 	PNODE p,q;
 	
	 for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)
	 {
	 	for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext)
	 	{
	 		if(p->data > q->data)
	 		{
	 			t=p->data;
	 			p->data=q->data;
	 			q->data=t;
			 }
		 }
	 	
	  } 
 	
 }
