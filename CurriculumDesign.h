#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//���ѧԺ��ѧԺ������Ϣ1
typedef struct Information {
	int num;//���number
	char name[20];//����
	char sex[20];//�Ա�
	int age;//����
	char job[20];//ְ��
	char title[20];//ְ��title
	char pcs[20];//������ò politicalStaus
	char ebg[20];//ѧ�� education background
	char sort[20];//��Ա���sort
}Information;//������ΪInformation

//�����Ϣ
typedef struct Node
{
	Information information;
	struct Node* next;
}Node;//������ΪNode


void welcome();//�˵�����

void inputInformation(Node* head);//1����

void modifyInformation(Node* head);//2�޸�

void deleteInformation(Node* head);//3ɾ��

void findInformation(Node* head);//4����Ų���

void countTitleInformation(Node* head);//5��ְ��ͳ��

void countSexInformation(Node* head);//6�Ա�ͳ��

void printInformation(Node* head);//7��ӡ

void saveInformation(Node* head);//���������ݱ��浽�ļ���

void loadInformation(Node* head);//��ȡ��Ա��Ϣ
