/*
 *	一个文件中包含n个正整数，其中n=10的7次方；请编写程序，将文件中的数按升序排序。
 *	
 *	数据较大，使用快速排序
 *
 *	zhou_zhou@wistron.com Jul'25 2012
 */
#include <stdio.h>
int partition(int *data,int left,int right)
{
	int t = 0;
	t = data[left];
	while(left < right)
	{
		while(left < right && data[right] >= t)
			right--;
		data[left] = data[right];
		while(left < right && data[left] <= t)
			left++;
		data[right] = data[left];
	}
	data[left] = t;
	return left;
}

void sort(int *data,int left,int right)        
{
	if(left >= right)
		return ;
	int midd = 0;
	midd = partition(data,left,right);
	sort(data,left,midd-1);		//recursion递归
	sort(data,midd+1,right);
}

void fast_sort(int *data,int n)
{
	sort(data,0,n-1);
}

int main()
{
	int i;
	int data[]={19,65,32,5,56,74,96,62};
	fast_sort(data,sizeof(data)/sizeof(int));
	for( i = 0 ; i < sizeof(data)/sizeof(int); i++)
		printf("%d ",data[i]);
	printf("\n");
	return 0;
}
