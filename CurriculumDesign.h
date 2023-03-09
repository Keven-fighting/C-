#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//红河学院工学院人事信息1
typedef struct Information {
	int num;//编号number
	char name[20];//姓名
	char sex[20];//性别
	int age;//年龄
	char job[20];//职务
	char title[20];//职称title
	char pcs[20];//政治面貌 politicalStaus
	char ebg[20];//学历 education background
	char sort[20];//人员类别sort
}Information;//重命名为Information

//结点信息
typedef struct Node
{
	Information information;
	struct Node* next;
}Node;//重命名为Node


void welcome();//菜单界面

void inputInformation(Node* head);//1新增

void modifyInformation(Node* head);//2修改

void deleteInformation(Node* head);//3删除

void findInformation(Node* head);//4按编号查找

void countTitleInformation(Node* head);//5按职称统计

void countSexInformation(Node* head);//6性别统计

void printInformation(Node* head);//7打印

void saveInformation(Node* head);//将链表数据保存到文件中

void loadInformation(Node* head);//读取人员信息
