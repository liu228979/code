# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
 
typedef struct Node
 {
 	int data;//数据域 
 	struct Node *pNext;//指针域 
 }NODE,*PNODE; //NODE等价于struct Node; *PNODE等价于struct Node * 
 
void traverse_list(PNODE pHead); //遍历并输出链表 
PNODE create_list(void);//创建一个链表
bool is_empty(PNODE pHead);//判断链表是否为空 
int length(PNODE); //求链表长度 
bool insert(PNODE,int,int);
bool delete_list(PNODE,int,int*);
void sort(PNODE);//链表排序 

 
 
int main(void)
{
	int len=0;
	PNODE pHead =NULL;//等价于struct Node *pHead=NULL; 
    pHead =create_list(); //创建一个非循环单链表，并将该链表的头结点的地址赋给pHead;
	if(is_empty(pHead))
	
	      printf("链表空\n");
	   else
	   traverse_list(pHead);//遍历输出链表
	   
    printf("链表长度是：%d\n",len=length(pHead)); 
    sort(pHead);
    traverse_list(pHead);
	return 0;
 } 
 
 
 
PNODE create_list(void)
 {
 	int len;//存放有效结点个数
	int i;
	int val;//临时存放用户输入的结点的值 
	PNODE PHead=(PNODE)malloc(sizeof(NODE));//生成头结点 //不存放有效数据 
	if(NULL==PHead)
	{
		printf("内存分配失败，程序终止！\n");
		exit(-1);
	}
	PNODE pTail=PHead;// pTail指向头结点 
	pTail->pNext=NULL;// 头结点指针域清空 
 	printf("请输入你要生成的链表节点个数：len=");
	scanf("%d",&len); 
	for(int i=0; i<len;i++)
	{
		printf("请输入第%d个节点的值:",i+1);
		scanf("%d",&val);
		PNODE pNew =(PNODE)malloc(sizeof(NODE));// 每循环一次造出一个新结点 
		
    	if(NULL==pNew)
    	{
		printf("内存分配失败，程序终止！\n");
		exit(-1);
	    }
	    pNew->data=val;//将 临时数据放入新结点的数据域 
	    pTail->pNext=pNew;//新建结构体指针指向新生成结点的指针域，即永远指向尾结点 //挂在尾结点后面 
	    pNew->pNext=NULL;//新结点的指针域为空//新结点变为尾结点 
	    pTail=pNew;// pTail指向新节点 
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
