# include<stdio.h>
int add(int ,int );
int main(void)
{
	int *p1[10];//指针数组 ，其包含，10个指向int类型数据的指针 
	int (*p2)[10];//指针数组，*p2，指向包含10个int类型数据的一个数组，
			//且数组没有名字，为匿名数组 
	 
	
	
	int (*fptr)(int,int);//定义函数指针fptr，该指针指向一个函数的入口地址，
	                     //并且可以返回 int型 
   						// 
   	int res; 			//（int，int）表示 指针变量可以指向有两个int参数的函数。
	
	fptr=add;			//将add函数入口地址赋值给fptr指针，即fptr指向了add函数 
	res=(*fptr)(1,2);   // 等价于fptr(1,2) 
	printf("a+b=%d\n",res); 
	return 0;
}
int add(int a,int b)
{
	return a+b; 
} 
