/*
 *输入一个整数，求该整数的二进制表达中有多少个1，请编写程序实现。
 *例如输入10，由于其二进制表示为1010，有两个1，因此输出2。
 *
 *zhou_zhou@wistron.com		Aug 8'2012
 */

#include<stdio.h>

/*if it's a negetive, this cant work*/
int fun1(int num)
{
	int count = 0;
	while(num != 0){
		if(num%2 != 0)
			count++;
		num /= 2;
	}
	return count;
}

int fun2(int num)
{
	int count = 0, flag = 1, i;
	for(i=0;i<32;i++){
		if(flag&num)
			count++;
		flag<<=1;
	}
	return count;
}

int fun3(int num)
{
	int count = 0, flag = 1, i;
	while(flag){
		if(flag&num)
			count++;
		flag<<=1;
	}
	return count;
}

int fun4(int num)
{
	int count=0;
	while(num){
		num&=(num-1);
		count++;
	}
	return count;
}

int main()
{
	int num;
	printf("please enter a number ：");
	scanf("%d",&num);
	printf("fun 1 return %d\n",fun1(num));
	printf("fun 2 return %d\n",fun2(num));
	printf("fun 3 return %d\n",fun3(num));
	printf("fun 4 return %d\n",fun4(num));
	return 0;
}
