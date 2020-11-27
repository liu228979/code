# include<stdio.h>
# include<malloc.h>

typedef struct BTNode
{
	char data;
	struct BTNode * pLchild;
	struct BTNode * pRchild;
	
}NODE,*P;

struct BTNode * CreateBTree(void)
{
	P pA=(struct BTNode *)malloc(sizeof(struct BTNode));
	P pB=(struct BTNode *)malloc(sizeof(struct BTNode));
	P pC=(struct BTNode *)malloc(sizeof(struct BTNode));
	P pD=(struct BTNode *)malloc(sizeof(struct BTNode));
	P pE=(struct BTNode *)malloc(sizeof(struct BTNode));
	
	pA->data='A';
	pB->data='B';
	pC->data='C';
	pD->data='D';
	pE->data='E';
	
	pA->pLchild=pB;
	pA->pRchild=pC;
	pB->pLchild=NULL;
	pB->pRchild=NULL;
	pC->pLchild=pD;
	pC->pRchild=NULL;
	pD->pLchild=NULL;
	pD->pRchild=pE;
	pE->pLchild=pE->pRchild=NULL;
	
	return pA;
	 
}
void xianxu (struct BTNode *pT)
{
	if(pT!=NULL)
	{
	
		printf("%c\n",pT->data);
		
		if(NULL!=pT->pLchild)
		{
			xianxu(pT->pLchild);
		}
		if(NULL!=pT->pRchild)
		{
			xianxu(pT->pRchild);
		}
    }
    
}
void zhongxu (struct BTNode *pT)
{
	if(pT!=NULL)
	{
	
		
		
		if(NULL!=pT->pLchild)
		{
			zhongxu(pT->pLchild);
		}
		printf("%c\n",pT->data);
		if(NULL!=pT->pRchild)
		{
			zhongxu(pT->pRchild);
		}
		
    }
}
void houxu (struct BTNode *pT)
{
	if(pT!=NULL)
	{
	
		
		
		if(NULL!=pT->pLchild)
		{
			houxu(pT->pLchild);
		}
		if(NULL!=pT->pRchild)
		{
			houxu(pT->pRchild);
		}
	   printf("%c\n",pT->data);	
    }
}
int main(void)
{
	P pT=CreateBTree();
	xianxu(pT);
	printf("\n\n");	
	zhongxu(pT);
	printf("\n\n");
	houxu(pT);
	
	return 0;
 } 
