# include<stdio.h>
# include<malloc.h>

typedef struct Queue
{
	int * pBase;//��������ĵ�һ��Ԫ�ص�ַ 
	int front;//
	int rear;//
}QUEUE;

void init(QUEUE *);//��ʼ�� 
bool en_queue(QUEUE *,int);//��� 
void travers_queue(QUEUE *);//�������� 
bool full_queue(QUEUE *);//�ж϶����Ƿ��� 
bool out_queue(QUEUE *,int *);//���� 
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
		printf("���ӳɹ���Ԫ����%d \n",val);
	}
	else
	{
		printf("����ʧ��\n");
	}
	
	travers_queue(&Q);
	return 0;
}

void init(QUEUE *pQ)
{
	pQ->pBase=(int *)malloc(sizeof(int)*6);//��̬����6�����Ϳռ䣬�����׵�ַ�����ṹ��Q�е�pBASE��Ա����pBaseָ��������飻��pBaseΪ������ 
	pQ->front=0;//���е�һ��Ԫ�� 
	pQ->rear=0;//ĳЩ�����������һ��Ԫ�ص��¸�Ԫ�� 
	
}


bool en_queue(QUEUE *pQ,int val)
{
	if(full_queue(pQ))
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear]=val;//��val����r��λ�� �����������±�Ϊr��λ�� 
		pQ->rear=(pQ->rear+1)%6;//r ������һ��λ�ã���д����rֻ����0-6��Χ 
		
		return true;
	}
	
}

void travers_queue(QUEUE *pQ)
{
	int i=pQ->front;
	while(i!=pQ->rear)// ���������У�ֱ����r��F���� 
	{
		printf("%d \n",pQ->pBase[i]);//ֻ�ܷ���6��Ԫ�� 
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
