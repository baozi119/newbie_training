/*
 *This create a data base.
 *
 *zhou_zhou@wistron.com
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#define N 100000000

//get random numbers, and put them into a file.
void createNumBase()
{
	int i;
	FILE *fp;

	if((fp=fopen("numBase.txt","w"))==NULL){
		printf("cant't open numBase.txt");
		exit(0);
	}else{
		srand((unsigned)time(NULL));
		for(i = 0; i < N; i++)
		{
			fprintf(fp,"%d\n",1+(int)(9999999.0*rand()/(RAND_MAX+1.0)));
		}
		fclose(fp);
	}	
} 

//show the numbers which in the file
void printNumBase()
{
	int i,j=0;
	int num[N];
	FILE *fp;	
	char line[8];
	if((fp = fopen("numBase.txt","r")) == NULL){
		printf("cant't open numBase.txt");
		exit(0);
	}else{
		for(i=0;i<N;i++){	
			fscanf(fp,"%d",&num[i]);
			printf("num[%d]=%d\n",i,num[i]);	
		}
		fclose(fp);
	}
} 

int main(){
	clock_t start, finish;  
	double  duration;  

	start = clock();
	createNumBase();
	finish = clock();  
	duration = (double)(finish - start) / CLOCKS_PER_SEC;  
	printf( "\nIt takes %f seconds to creat %d numbers.\n", duration, N );
	//printNumBase();	
	return 0;
}
