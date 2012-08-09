/*
 *请编写程序，实现员工基本信息管理系统；
 *要求：
 *1. 员工信息包括姓名，性别，年龄，出生日期，入职日期，住址，联系方式；
 *2. 使用链表来创建、插入、删除和遍历；
 *
 *zhou_zhou@wistron.com		Aug 9'2012
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAMELEN 20

typedef struct Lemployee{
	int number;
	char name[NAMELEN];
	char sex;
	struct Lemployee* next;
}Lnode, *Llist;

/*create*/
Llist createList()
{
	Llist L;
	if(!(L = (Llist)malloc(sizeof(Lnode)))){
		printf("in create malloc error\n");
		exit(0);
	}
	L->next = NULL;
	L->number = 0;
	strcpy(L->name,"\0");
	L->sex = '*';
	printf("create list success!\n");
	return L;
}

/*insert node in the end of the list*/
void insertNode(Llist L, int num, char name[], char sex)
{
	Llist s, p=L;
	if(!(s = (Llist)malloc(sizeof(Lnode)))){
		printf("in insert malloc error\n");
		exit(0);
	}
	while(p->next){
		p = p->next;
	}
	p->next= s;
	s->number = num;
	strncpy(s->name,name,strlen(name)-1);	//to ignore '\n'
	s->sex = sex;
	s->next = NULL;
	printf("insert success\n");
}

/*delete node by number*/
Llist deleteNode(Llist L, int num)
{
	Llist p = L->next, q = L;
	while(p){
		if(p->number == num){
			q->next = p->next;
			free(p);
			printf("delete success!\n");
			return;
		}
		q = p;
		p = p->next;
	}
	printf("there is no %d in list!\n",num);
	return;
}

/*print the list*/
void printList(Llist L)
{
	Llist p;
	p = L->next;
	while(p){
		printf("number:%d, name:%-10s, sex:%c\n",p->number, p->name, p->sex);
		p = p->next;
	}
}

void test()
{
	Llist L;
	L = createList();

	insertNode(L,11,"Li",'m');
	insertNode(L,22,"Zhao",'m');
	insertNode(L,33,"Sun",'w');
	deleteNode(L,22);
	deleteNode(L,44);
	printList(L);
}

int option()
{
	int opt;
	printf("(1) insert \n");
	printf("(2) delete \n");
	printf("(3) print \n");
	printf("(0) exit \n");
	printf("please enter option: ");
	scanf("%d",&opt);
	return opt;
}

int main()
{
	//test();
	system("clear");
	int num, choice, c;
	char name[NAMELEN];
	char sex;
	Llist L;
	L = createList();
	while(1){
		choice = option();
		if(choice == 1){
			system("clear");
			printf("please enter job number: ");
			scanf("%d",&num);
			printf("\nplease enter name: ");
			while ((c=getchar()) != '\n' && c != EOF);	//fflush() can't use in gcc
			fgets(name, NAMELEN, stdin);
			printf("\nplease enter sex: ");
			scanf("%c",&sex);
			insertNode(L,num,name,sex);
			continue;
		}
		if(choice == 2){
			system("clear");
			printf("please enter delete number: ");
			scanf("%d",&num);
			deleteNode(L,num);
			continue;
		}
		if(choice == 3){
			system("clear");
			printList(L);
			continue;
		}
		if(choice == 0){
			return 0;
		}
	}

	return 0;
}
