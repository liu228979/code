# include<stdio.h>
# include<malloc.h>
//功能：测试结构体指针，和研究链表存储方式 
typedef struct Node
{
	int data;
	struct Node *pNext; 
}NODE,*PNODE;

int main(void)
{
    PNODE PHead=(PNODE)malloc(sizeof(NODE));//动态创建链表头结点 
	printf("链表头结点地址：%p\n", PHead);//输出链表头结点地址 

	
	PNODE pTail=PHead;//创建尾结点，并将头结点地址发给尾结点，即尾结点指向头结点 
    printf("链表尾结点地址：%p\n", pTail);//输出尾结点地址 ，这里和头结点地址一致，因为 尾结点指向头结点
		
	pTail->pNext=NULL;//清空尾结点的指针域 
	printf("尾结点指针域地址：%p\n", pTail->pNext);//尾结点指针域输出0x00000000000； 
	printf("链表尾结点地址：%p\n", pTail);//这里输出的结果依然和头结点地址一致。
	/*
	    理解：
		       也就是说创建以个结构体指针 struct Node *PNODE
		       其本身具有两个三个存储空间：
			                              1、结构体指针本身所具有的空间，用来存放struct Node * 类型地址
										  2、为结构体成员 struct Node *pNext所分配的空间，用来存放链表下个结点的地址
										  3、为结构体成员 int data 所分配的空间，用来存放数据 
	
	*/ 
	
	PNODE pNew =(PNODE)malloc(sizeof(NODE));//创建新结点 
	printf("输出新结点地址：%p\n", pNew);//输出新结点地址 
	pNew->data=1;//给新结点数据域赋值1
	
	 
	pTail->pNext=pNew;//将新结点地址写入尾结点指针域
	printf("尾结点指针域地址：%p\n", pTail->pNext);
	printf("链表尾结点地址：%p\n", pTail);
	
	
	pNew->pNext=NULL;//将新结点指针域清空 即将新结点作为尾节点 
	printf("输出新结点指针域地址：%p\n", pNew->pNext);
	
	pTail=pNew;// 也就是ptail 作为中间节点，pnew作为尾结点拆入ptail后面。 
	
	printf("输出尾结点地址：%p\n", pTail);
	
	
//	printf("%x", &pHead);
    
    
	return 0; 
}
