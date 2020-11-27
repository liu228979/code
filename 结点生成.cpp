# include<stdio.h>
/*
  链表分为；
      单链表
	  双链表：每个节点有两个指针域 
	  循环链表；能通过任何一个节点找到其他所有节点 
	  非循环链表 
*/

typedef struct Node
{
	int data;//数据域 
	struct Node * pNext;//指针域 
} NODE,*PNODE; //NODE等价于struct Node; *PNODE等价于struct Node * 
int main(void)
{
	
	
	return 0; 
} 
