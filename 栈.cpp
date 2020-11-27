# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
 
typedef struct Node
 {
 	int data;//������ 
 	struct Node *pNext;//ָ���� 
 }NODE,*PNODE; //NODE�ȼ���struct Node; *PNODE�ȼ���struct Node *
 
typedef struct Stack 
 {
 	PNODE pTop;//ջ�� 
 	PNODE pBottom; //ջ�� 
 }STACK,*PSTACK;
  
void init(PSTACK);
void push(PSTACK,int);
void traverse(PSTACK); 
bool pop(PSTACK,int *); 
bool empt(PSTACK);//�ж�ջ�Ƿ�Ϊ�� 
void clear(PSTACK);//ɾ��ջ������Ԫ�أ�����ջ�ף�Ҳ����ֻɾ��ջԪ�أ�������ջҲ�ɵ��� 

 int main(void)
{
	STACK S; 
	int val;
	
	init(&S);//��ʼ��ջ
	push(&S,1);//ѹջ
	push(&S,2);
	push(&S,3);//ѹջ
	push(&S,4);
	traverse(&S);//������� 
	if(pop(&S,&val)) 
	{
		printf("��ջ�ɹ�����ջ��Ԫ����%d \n",val);
	}//��ջ
	else 
	{
		printf("��ջʧ��"); 
	 } 
	traverse(&S);
	clear(&S); 
	traverse(&S);
	return 0;
 } 
 
 void init(PSTACK pS)
 {
 	pS->pTop=(PNODE)malloc(sizeof(NODE));
 	if(NULL==pS->pTop)
 	{
 		printf("�ڴ����ʧ�ܣ�\n");
 		exit(-1);
	 }
	 else
	 {
	 	pS->pBottom=pS->pTop;
	 	pS->pTop->pNext=NULL; //pS->pBottom->pNext=NULL;�� ps��ָ��Ľڵ��ptop�����Ա������ָ��Ľڵ��ָ������� 
	 	
	 }
 	
 }
 
 void push(PSTACK pS,int val)
 {
 	PNODE pNew=(PNODE)malloc(sizeof(NODE));
 	pNew->data=val;
 	pNew->pNext=pS->pTop;//���ܸ�Ϊջ�� 
 	pS->pTop=pNew;
 }
 
 void traverse(PSTACK pS)
 {
 	PNODE p=pS->pTop;// ����ָ��p��ָ��ջ�� 
 	while (p!=pS->pBottom)
 	{
 		printf("%d ",p->data);//����дpS->pTop->data 
 		p=p->pNext;
	 }
	 printf("\n");
	 return;
 }
 
 bool pop(PSTACK pS,int *pval)
 {
 	if(empt(pS))
 	{
 		return false;
	 }
	 else
	 {
	 	PNODE r=pS->pTop;//����ָ�������ָ��ջ�� 
	 	*pval=r->data;
	 	pS->pTop=r->pNext;//��rָ��ջ��ָ����ĵ�ַ�����¸�Ԫ�صĵ�ַ��ֵ��ջ������ջ�������� 
	 	r=NULL;//��r�ĵ�ַ��� 
	 	return true;
	 }
 	
 }
 
 bool empt(PSTACK ps)
 {
 	if(ps->pTop==ps->pBottom)
 	  {
	     return true;
	   } 
 	  else
 	  
 	     return false;
 }
 
 void clear(PSTACK pS)
 {
 	if(empt(pS))
 	{
 		return;
	 }
	 else
	 {
 	   PNODE p=pS->pTop;//����ָ��pָ��ջ�� 
 	   PNODE q=NULL;//����qָ����ָ�� 
 	   while(p!=pS->pBottom)//���p��ָ��ջ�� 
 	   {
 	   	  q=p->pNext;//q�����¸�Ԫ�صĵ�ַ����������p��ָ�����ֵ����ջ��Ԫ�ص�ָ�����ֵ�����¸�Ԫ�صĵ�ַ 
 	   	  free(p);//ɾ��pָ���Ԫ�� 
 	   	  p=q;//���¸�Ԫ�صĵ�ַ��ֵ��p����p��ָ���µ�ջ��  
		}
		pS->pTop=pS->pBottom;
     }
 }
