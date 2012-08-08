/*
 *请编写程序，实现员工基本信息管理系统；
 *要求：
 *1. 员工信息包括姓名，性别，年龄，出生日期，入职日期，住址，联系方式；
 *2. 使用链表来创建、插入、删除和遍历；
 *
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct Lemployee{
	int number;
	
	struct Lemployee* next;
}Lnode, *Llist;

/*create*/
Llist createList()
{
	Llist L;
	L = (Llist)malloc(sizeof(Lnode));
	if(!L){
		printf("in create malloc error\n");
		exit(0);
	}
	L->next = NULL;
	L->number = 0;
	return L;
}

Llist insertNode(Llist L,int num)
{
	Llist s, p=L;
	s = (Llist)malloc(sizeof(Lnode));
	if(!s){
		printf("in insert malloc error\n");
		exit(0);
	}
	while(p->next){
		p = p->next;
	}
	p->next= s;
	s->number = num;
	s->next = NULL;
	return L;
}

Llist deleteNode(Llist L, int num)
{
	Llist p = L->next, q = L;
	while(p){
		if(p->number == num){
			q->next = p->next;
			return L;
		}
		q = p;
		p = p->next;
	}
	return L;
}

void printList(Llist L)
{
	Llist p;
	p = L->next;
	while(p){
		printf("%d\n",p->number);
		p = p->next;
	}
}


int main()
{
	Llist L;
	L = createList();
/*	int choice;
	pirntf("initialize finished!\n");
	pirntf("(1) insert \n");
	pirntf("(2) delete \n");
	pirntf("(3) print \n");
	pirntf("(0) exit \n");
	scanf("%d",choice);
	while(1){
		if(choice == 1){
		
		}
		if(choice == 2){
		
		}
		if(choice == 3){
		
		}
		if(choice == 0){
		
		}
	}*/
	insertNode(L,11);
	insertNode(L,22);
	insertNode(L,33);
	deleteNode(L,22);
	printList(L);
	return 0;
}
