/*
 *	一个文件中包含n个正整数，其中n=10的7次方；请编写程序，将文件中的数按升序排序。
 *	
 *	数据较大，使用快速排序
 *
 *	zhou_zhou@wistron.com Jul'25 2012
 */
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define N 1000000
#define RAND_UP 999999.0
//one sorting
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

//recursion
void sort(int *data,int left,int right)        
{
	if(left >= right)
		return ;
	int midd = 0;
	midd = partition(data,left,right);
	sort(data,left,midd-1);	
	sort(data,midd+1,right);
}

void fast_sort(int *data,int n)
{
	sort(data,0,n-1);
}

int main()
{
	int i,n;
	int data[N];
	clock_t start, finish;  
	double  duration;  
	srand((unsigned)time(NULL));

	////get random numbers between 1 and RAND_UP
	for(i = 0; i < N; i++)
	{
		data[i] = 1+(int)(RAND_UP*rand()/(RAND_MAX+1.0));	
		//printf("data[%d]=%d\n",i,data[i]);
	}	

	printf("total numbers: %ld\n",sizeof(data)/sizeof(int));
	start = clock();
	fast_sort(data,sizeof(data)/sizeof(int));
	finish = clock();  
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  

 	while(i!=0){
		printf("%8d",data[N-(i--)]);
		if(i%10==0)
			printf("\n");				
	}
	printf( "\nsort time is %f seconds\n", duration );  
	return 0;
}
