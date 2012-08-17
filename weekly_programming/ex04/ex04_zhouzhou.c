/*
file name: isort1.c
purpose: 
	插入排序：
		PS：同时跟选择排序，冒泡排序做简单对比。
	要求：
	1. 编写插入排序算法，并尝试优化;
	2. 思考并验证影响程序性能的因素，列出程序（优化前/优化后）耗用的平均时间，分析造成差异的因素；
		A:sort1, 2, 3比较，减少函数调用与元素移动以缩短时间。
	3. 如果“测试数据”分别为“随机数”/“相等数”/“递增数”，在数据量相同的条件下，其耗用的时间如何？
		A：	-------------------------------------
			|			|随机数	|相等数	|递增数	|
			-------------------------------------
			|isot1		|O(N2)	|O(N)	|O(N)	|
			-------------------------------------
			|isot2		|O(N2)	|O(N)	|O(N)	|
			-------------------------------------
			|isot3		|O(N2)	|O(N)	|O(N)	|
			-------------------------------------
			|selection	|O(N2)	|O(N2)	|O(N2)	|
			-------------------------------------
			|bubbling	|O(N2)	|O(N)	|O(N)	|
			-------------------------------------
	4. gcc优化选项会造成性能的差异吗？为什么？
		A：会。当arrary_number为20000时测试结果如下，函数内联有效果。
				-------------------------	
				|		|无优化	|-O2	|
				-------------------------
				|isot1	|1.47s	|0.19s	|
				-------------------------
				|isot2	|1.27s	|0.19s	|
				-------------------------

	参考《编程珠玑（第2版）》,ch11.1-插入排序
creator: Dinghua Zhou
create time: 2012-08-17

modify history:

notes:
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10000
#define LEN (N-1)*1.0

void swap(int *num1, int*num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void insert_sort1(int arr[], int len)
{
	int i, j, temp;
	for(i=1; i<len; i++){
		for(j=i; j>0&&arr[j]<arr[j-1]; j--){	
			swap(&arr[j],&arr[j-1]);
		}
	}
}

void insert_sort2(int arr[], int len)
{
	int i, j, temp;
	for(i=1; i<len; i++){
		for(j=i; j>0&&arr[j]<arr[j-1]; j--){
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
		}
	}
}

void insert_sort3(int arr[], int len)
{
	int i, j, temp;
	for(i=1; i<len; i++){
		temp=arr[i];
		for(j=i; j>0&&temp<arr[j-1]; j--){
				arr[j]=arr[j-1];
		}
		arr[j]=temp;
	}
}

void selection_sort(int *arr, int len)
{
	int i, j, temp;
	for(i=0; i<len-1; i++){
		for(j=i+1; j<len; j++){
			if(arr[j]<arr[i]){
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
}

void bubbling_sort(int *arr, int len)
{
	int i, j, temp;
	bool flag;
	for(i=0; i<len-1; i++){
		flag = true;
		for(j=0; j<len-1-i; j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=false;
			}
		}
		if(flag)	//if no exchange, arrary is asscending sorted
			return;
	}
}

void print_array(int *arr, int len)
{
	int i;
	for(i=0;i<N;i++){
		printf("%8d",arr[i]);
		if((i+1)%10==0)
			printf("\n");
	}
}

int main()
{
	int i, arr[N] ={0};
	clock_t start, finish;  
	double  duration; 
	srand((unsigned)time(NULL));

//-------------------------------------------------
	for(i = 0; i < N; i++)
		arr[i]=1+(int)(LEN*rand()/(RAND_MAX+1.0));
	start = clock();
	insert_sort1(arr,N);
	finish = clock();  
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "insert sort1 time is %f seconds\n", duration );  
//-------------------------------------------------
	for(i = 0; i < N; i++)
		arr[i]=1+(int)(LEN*rand()/(RAND_MAX+1.0));
	start = clock();
	insert_sort2(arr,N);
	finish = clock();  
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "insert sort2 time is %f seconds\n", duration );
//-------------------------------------------------
	for(i = 0; i < N; i++)
		arr[i]=1+(int)(LEN*rand()/(RAND_MAX+1.0));
	start = clock();
	insert_sort3(arr,N);
	finish = clock();  
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "insert sort3 time is %f seconds\n", duration );
//-------------------------------------------------
	for(i = 0; i < N; i++)
		arr[i]=1+(int)(LEN*rand()/(RAND_MAX+1.0));
	start = clock();
	selection_sort(arr,N);
	finish = clock();  
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "selection sort time is %f seconds\n", duration );  
//-------------------------------------------------
	for(i = 0; i < N; i++)
		arr[i]=1+(int)(LEN*rand()/(RAND_MAX+1.0));
	start = clock();
	bubbling_sort(arr,N);
	finish = clock();  
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf( "bubbling sort time is %f seconds\n", duration );  

	//print_array(arr, N);
	return 0;
}
