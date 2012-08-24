/*
file name: isort1.c
purpose: 
	取样问题：

	生成小于n且没有重复的k个整数，并将生成的数据存放在txt文档中.
	其中n=10,000,000; k=5,000,000!

	参考《编程珠玑（第2版）》,ch12-取样问题
creator: Dinghua Zhou
create time: 2012-08-17

modify history:

notes:
	1. 当K接近N时需要考虑对位图法进行改进。
*/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#define BITSPERWORD 32  
#define SHIFT 5  
#define MASK 0x1F  
#define N 10000000
#define K 5000000
#define LEN (N-1)*1.0
#define LAYOUT 0

/*
void set(int i) {        a[i>>SHIFT] |=  (1<<(i & MASK)); }

void clr(int i) {        a[i>>SHIFT] &= ~(1<<(i & MASK)); }

int test(int i) { return a[i>>SHIFT] &   (1<<(i & MASK)); }
*/

//第一章中提到的位图法，不采用函数调用以缩短运行时间
void bit_map()
{
	int a[N/BITSPERWORD + 1] = {0};	//一定要初始化
	int i = 0, count = 0;
	srand((unsigned)time(NULL));
	while (count != K){
		i=(int)(LEN*rand()/(RAND_MAX+1.0));
		if(!(a[i>>SHIFT] & (1<<(i & MASK)))){
			a[i>>SHIFT] |=  (1<<(i & MASK));
			count ++;
		}
	}  
	for (i = 0; i < N; i++){
		if (a[i>>SHIFT] & (1<<(i & MASK))){
#if LAYOUT
			printf("%d\n", i);  
#endif
		}
	}
}

//书中提到的算法一
void genknuth()
{
	int i = 0, count = 0, m = K;
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++){
		if(( (  (int)(LEN*rand()/(RAND_MAX+1.0))    )%(N-i) ) < m){
#if LAYOUT
			printf("%d\n",i);
#endif
			m--;
		}
	}
}

int main()  
{
	clock_t start, finish;  
	double  duration;  

	start = clock();
	bit_map();
	finish = clock();  
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  
	printf( "%s takes %f seconds to creat %d numbers.\n\n","bit_map()", duration, K );

	start = clock();
	genknuth();
	finish = clock();  
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  
	printf( "%s takes %f seconds to creat %d numbers.\n\n","genknuth()", duration, K );


	return 0;  
} 
