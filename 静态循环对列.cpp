# include<stdio.h>
# include<malloc.h>

typedef struct Queue
{
	int * pBase;//保存数组的第一个元素地址 
	int front;//
	int rear;//
}QUEUE;

void init(QUEUE *);//初始化 
bool en_queue(QUEUE *,int);//入队 
void travers_queue(QUEUE *);//遍历队列 
bool full_queue(QUEUE *);//判断队列是否满 
bool out_queue(QUEUE *,int *);//出队 
bool empt(QUEUE *);

int main(void)
{
	int val;
	QUEUE Q;
	init(&Q);
	en_queue(&Q,1);
	en_queue(&Q,2);
	en_queue(&Q,3);
	en_queue(&Q,4);
	en_queue(&Q,5);
	en_queue(&Q,6);
	travers_queue(&Q);
	//out_queue(&Q,&val);
	if(out_queue(&Q,&val))
	{
		printf("出队成功，元素是%d \n",val);
	}
	else
	{
		printf("出队失败\n");
	}
	
	travers_queue(&Q);
	return 0;
}

void init(QUEUE *pQ)
{
	pQ->pBase=(int *)malloc(sizeof(int)*6);//动态分配6个整型空间，并将首地址发给结构体Q中的pBASE成员，即pBase指向这个数组；即pBase为数组名 
	pQ->front=0;//对列第一个元素 
	pQ->rear=0;//某些场合下是最后一个元素的下个元素 
	
}


bool en_queue(QUEUE *pQ,int val)
{
	if(full_queue(pQ))
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear]=val;//将val放入r的位置 即放入数组下标为r的位置 
		pQ->rear=(pQ->rear+1)%6;//r 移向下一个位置，此写法是r只能在0-6范围 
		
		return true;
	}
	
}

void travers_queue(QUEUE *pQ)
{
	int i=pQ->front;
	while(i!=pQ->rear)// 遍历整队列，直至人r和F相邻 
	{
		printf("%d \n",pQ->pBase[i]);//只能放入6个元素 
		i=(i+1)%6; 
	}
	
}

bool full_queue(QUEUE *pQ)
{
	if((pQ->rear+1)%6==pQ->front)
	 return true;
	else
	 return false; 
}

bool out_queue(QUEUE *pQ,int *val)
{
	if(empt(pQ))
	{
		return false;
	}
	else
	{
		*val=pQ->pBase[pQ->front];
		pQ->front=(pQ->front+1)%6;
	}
}
bool empt(QUEUE *pQ)
{
	if(pQ->front==pQ->rear)
	 return true;
	else
	 return false;
}
