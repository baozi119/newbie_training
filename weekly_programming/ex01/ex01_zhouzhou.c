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
#include <string.h>
#define N 10000000
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
	int *data = NULL;
	clock_t start, finish;  
	double  duration;  
	FILE *fpR, *fpW;	

	data = (int *)malloc(N*sizeof(int)); 
	if(NULL == data){
		printf("malloc error");
		exit(1);
	}
	memset(data,0,N);

	printf("read number from numBase.txt...\n");
	if((fpR = fopen("numBase.txt","r")) == NULL){
		printf("cant't open numBase.txt");
		exit(0);
	}else{
		for(i=0;i<N;i++){	
			fscanf(fpR,"%d",(data+i));
		}
		fclose(fpR);
	}
	printf("Done! Total numbers: %d\nSorting...\n",N);

	start = clock();
	fast_sort(data,N);
	finish = clock();  
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  
	printf( "Sort time is %f seconds\nwriting numbers into sortNumber.txt...\n", duration );  

	if((fpW=fopen("sortNumber.txt","w"))==NULL){
		printf("cant't open sortNumber.txt");
		exit(0);
	}else{
		for(i = 0; i < N; i++)
			fprintf(fpW,"%d\n",*(data+i));
		fclose(fpW);
	}
	printf("Finish!!!\n");

	free(data);
	data=NULL;

	return 0;
}
