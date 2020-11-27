# include<stdio.h>
# include<malloc.h>
int len;

struct student{
	
	int age;
	float score;
	char name[100];
	
};
void input(struct student *parr)
{
	int i;
	printf("请输入学生个数：\n");
	printf("len=");
	scanf("%d",&len);
	
	for(i=0;i<len;i++)
	{
		printf("请输入%d个学生信息;",i+1);
		printf("name=");
		scanf("%s",&parr[i].name);
		printf("score=");
		scanf("%f",&parr[i].score) ; 
		printf("age=");
		scanf("%d",&parr[i].age);	 
	}
}
void output(struct student *parr)
{
	int j;
	for(j=0;j<len;j++)
	{
		printf("第%d名学生信息是：\n",j+1);
		printf("age=%d\n",parr[j].age);
		printf("name=%s\n",parr[j].name);
		printf("score=%f\n",parr[j].score);
		printf("\n\n"); 
	}
}
void sort(struct student *parr)
{
	int k,l;
	 struct student t;
	
	for(int k=0;k<len;k++)
	{
		for(l=0;l<len-k-1;l++)
		{
			if (parr[l].score>parr[l+1].score)
			t=parr[l];
			parr[l]=parr[l+1];
			parr[l+1]=t;
		}
	}
	
}
int main(void) 
{
	
	struct student *parr;
	parr=(struct student *)malloc(len*sizeof(struct student));
	
	input(parr);
    printf("\n\n\n");
    sort(parr);
    output(parr);  
    printf("\n\n\n");
}
