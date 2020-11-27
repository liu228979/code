# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
 
typedef struct Node
 {
 	int data;//数据域 
 	struct Node *pNext;//指针域 
 }NODE,*PNODE; //NODE等价于struct Node; *PNODE等价于struct Node *
 
typedef struct Stack 
 {
 	PNODE pTop;//栈顶 
 	PNODE pBottom; //栈底 
 }STACK,*PSTACK;
  
void init(PSTACK);
void push(PSTACK,int);
void traverse(PSTACK); 
bool pop(PSTACK,int *); 
bool empt(PSTACK);//判断栈是否为空 
void clear(PSTACK);//删除栈里所有元素，保留栈底；也就是只删除栈元素，而不把栈也干掉； 

 int main(void)
{
	STACK S; 
	int val;
	
	init(&S);//初始化栈
	push(&S,1);//压栈
	push(&S,2);
	push(&S,3);//压栈
	push(&S,4);
	traverse(&S);//遍历输出 
	if(pop(&S,&val)) 
	{
		printf("出栈成功，出栈的元素是%d \n",val);
	}//出栈
	else 
	{
		printf("出栈失败"); 
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
 		printf("内存分配失败！\n");
 		exit(-1);
	 }
	 else
	 {
	 	pS->pBottom=pS->pTop;
	 	pS->pTop->pNext=NULL; //pS->pBottom->pNext=NULL;将 ps所指向的节点的ptop这个成员，它所指向的节点的指针域清空 
	 	
	 }
 	
 }
 
 void push(PSTACK pS,int val)
 {
 	PNODE pNew=(PNODE)malloc(sizeof(NODE));
 	pNew->data=val;
 	pNew->pNext=pS->pTop;//不能改为栈底 
 	pS->pTop=pNew;
 }
 
 void traverse(PSTACK pS)
 {
 	PNODE p=pS->pTop;// 定义指针p，指向栈顶 
 	while (p!=pS->pBottom)
 	{
 		printf("%d ",p->data);//不能写pS->pTop->data 
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
	 	PNODE r=pS->pTop;//定义指针变量，指向栈顶 
	 	*pval=r->data;
	 	pS->pTop=r->pNext;//将r指向栈顶指针域的地址，即下个元素的地址赋值给栈顶，即栈顶向下移 
	 	r=NULL;//将r的地址清空 
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
 	   PNODE p=pS->pTop;//定义指针p指向栈顶 
 	   PNODE q=NULL;//定义q指针无指向 
 	   while(p!=pS->pBottom)//如果p不指向栈底 
 	   {
 	   	  q=p->pNext;//q保存下个元素的地址，即保存了p的指针域的值，即栈顶元素的指针域的值，即下个元素的地址 
 	   	  free(p);//删除p指向的元素 
 	   	  p=q;//将下个元素的地址赋值给p，即p又指向新的栈顶  
		}
		pS->pTop=pS->pBottom;
     }
 }
