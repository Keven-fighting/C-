#define _CRT_SECURE_NO_WARNINGS 1
#include "CurriculumDesign.h"

int main() {
	//创建头结点 
	Node* head = malloc(sizeof(Node));
	head->next = NULL;
	loadInformation(head);

	while (1) {

		welcome();
		printf("请选择功能\n");

		char c = _getch();

		switch (c)
		{
		case '1'://新增人事信息ok
			inputInformation(head);
			break;
		case '2'://修改人事信息ok
			modifyInformation(head);
			break;
		case '3'://删除人事信息ok
			deleteInformation(head);
			break;
		case '4'://按编号查找人事信息ok
			findInformation(head);
			break;
		case '5'://按职称统计人事信息
			countTitleInformation(head);
			break;
		case '6'://按性别统计人事信息ok
			countSexInformation(head);
			break;
		case '7'://打印ok
			printInformation(head);
			break;
		case '8'://退出系统
			system("cls");
			printf("bye bye!\n");
			exit(0);
			break;
		default:
			printf("请重新输入\n");
			break;
		}
	}

	return 0;
}

void welcome() {
	printf("*****************************************\n");
	printf("*\t红河学院工学院人事管理系统\t*\n");
	printf("*****************************************\n");
	printf("*\t请选择功能列表\t\t\t*\n");
	printf("*****************************************\n");
	printf("*\t1.新增人事信息\t\t\t*\n");
	printf("*\t2.修改人事信息\t\t\t*\n");
	printf("*\t3.删除人事信息\t\t\t*\n");
	printf("*\t4.按编号查找人事信息\t\t*\n");
	printf("*\t5.按职称统计人事信息\t\t*\n");
	printf("*\t6.按性别统计人事信息\t\t*\n");
	printf("*\t7.打印\t\t\t\t*\n");
	printf("*\t8.退出系统\t\t\t*\n");
	printf("*****************************************\n");
}

void inputInformation(Node* head) {
	//定义指针指向头结点，便于便利链表
	Node* fresh = malloc(sizeof(Node));
	fresh->next = NULL;
	printf("请输入人员的 编号 姓名 性别 年龄 职务 职称 政治面貌 学历 人员类别\n");
	scanf("%d",&fresh->information.num);
	scanf("%s",fresh->information.name);
	scanf("%s", fresh->information.sex);
	scanf("%d",&fresh->information.age);
	scanf("%s", fresh->information.job);
	scanf("%s", fresh->information.title);
	scanf("%s", fresh->information.pcs);
	scanf("%s",fresh->information.ebg);
	scanf("%s", fresh->information.sort);
	
	Node* move = head;
	while (move->next != NULL) {
		move = move->next;
	}
	//将人员插入到尾部
	move->next = fresh;

	saveInformation(head);//将输入的人员信息保存至文件
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
}

void modifyInformation(Node* head) {
	printf("请输入要修改人员的编号：");
	int num;
	scanf("%d", &num);
	Node* move = head->next;
	while (move != NULL) {
		if (num == move->information.num) {
			printf("请输入人员的编号 姓名 性别 年龄 职务 职称 政治面貌 学历 人员类别\n");
			scanf("%d", &move->information.num);
			scanf("%s", move->information.name);
			scanf("%s", move->information.sex);
			scanf("%d", &move->information.age);
			scanf("%s", move->information.job);
			scanf("%s", move->information.title);
			scanf("%s", move->information.pcs);
			scanf("%s", move->information.ebg);
			scanf("%s", move->information.sort);
			saveInformation(head);//将修改的信息持久化
			printf("修改成功\n");
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("未找到人员信息\n");
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
}

void deleteInformation(Node* head) {
	printf("请输入要删除的人员编号");
	int num = 0;
	scanf("%d", &num);

	Node* move = head;
	while (move->next != NULL) {

		if (move->next->information.num == num) {
			Node* temp = move->next;
			move->next = move->next->next;//删除结点只需要一句
			free(temp);//最后记得将删除的动态空间释放
			temp = NULL;//释放后随即指向NULL
			//同步到文件
			saveInformation(head);//持久化操作
			printf("删除成功\n");
			//删除程序
			system("pause");
			//清空控制台
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("未找到人事信息\n");
	//删除程序
	system("pause");
	//清空控制台
	system("cls");
}

void findInformation(Node* head) {
	printf("请输入要查找人员的编号：");
	int num;
	scanf("%d", &num);
	Node* move = head->next;
	while (move != NULL) {
		if (num == move->information.num) {
			printf("编号:%d 姓名:%s 性别:%s 年龄:%d 职务:%s 职称:%s 政治面貌:%s 学历:%s 人员类别:%s\n", move->information.num,
				move->information.name, move->information.sex, move->information.age, move->information.job,
				move->information.title, move->information.pcs, move->information.ebg, move->information.sort);
			//暂停程序
			system("pause");
			//清空控制台
			system("cls");
			return;//找到了人员跳出这个函数
		}
		move = move->next;
	}
	printf("未找到人事信息\n");
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
}

void countTitleInformation(Node* head) {
	int teaAss = 0;//助教
	int lecturer = 0;//讲师
	int assPro = 0;//副教授
	int professor = 0;//教授
	char TeaAss[20] = "助教";
	char Lecturer[20] = "讲师";
	char AssPro[20] = "副教授";
	char Professor[20] = "教授";
	Node* move = head->next;
	while (move != NULL) {
		if (strcmp(move->information.title, TeaAss) ==0) {
			teaAss++;
		}
		else if (strcmp(move->information.title, Lecturer) == 0) {
			lecturer++;
		}
		else if (strcmp(move->information.title, AssPro) == 0) {
			assPro++;
		}
		else if (strcmp(move->information.title,Professor) == 0) {
			professor++;
		}
		move = move->next;
	}
	printf("助教：%d\n", teaAss);
	printf("讲师：%d\n", lecturer);
	printf("副教授：%d\n", assPro);
	printf("教授：%d\n", professor);
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
}

void countSexInformation(Node* head) {
	int man = 0;
	int woman = 0;
	char Man[20] = "男";
	char Woman[20] = "女";
	Node* move = head->next;
	while (move != NULL) {
		if (strcmp(move->information.sex, Man) == 0){
			man++;
		}
		else if (strcmp(move->information.sex,Woman) == 0) {
			woman++;
		}
		move = move->next;
	}
	printf("男：%d\n", man);
	printf("女：%d\n", woman);
	//printf("学生总人数为:%d\n", count);
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
}

void printInformation(Node* head) {
	Node* move = head->next;
	while (move != NULL) {
		printf("编号:%d 姓名:%s 性别:%s 年龄:%d 职务:%s 职称:%s 政治面貌:%s 学历:%s 人员类别:%s\n", move->information.num,
			move->information.name, move->information.sex,move->information.age, move->information.job,
			move->information.title, move->information.pcs,move->information.ebg, move->information.sort);
		move = move->next;
	}
	//暂停程序
	system("pause");
	//清空控制台
	system("cls");
}

void saveInformation(Node* head) {
	FILE* file = fopen("./information.info", "w");
	//判断文件是否打开失败
	if (file == NULL) {
		printf("打开文件失败\n");
		return;
	}
	Node* move = head->next;
	while (move != NULL) {
		//将结构体写入文件
		if (fwrite(&move->information, sizeof(Information), 1, file) != 1) {
			printf("写入失败\n");
			return;
		}
		move = move->next;
	}
	//关闭文件
	fclose(file);
}

void loadInformation(Node* head) {
	//打开文件
	FILE* file = fopen("./information.info", "r");
	
	if (!file) {
		printf("未找到人员文件，跳过读取\n");
		return;
	}
	//创建一个结点
	Node* fresh = malloc(sizeof(Node)); 
	fresh->next = NULL;
	Node* move = head;
	while (fread(&fresh->information, sizeof(Information), 1, file) == 1) {
		move->next = fresh;
		move = fresh;
		fresh = malloc(sizeof(Node));
		fresh->next = NULL;
	}
	free(fresh); //最后多定义一个fresh，要将它释放掉
	//关闭文件
	fclose(file);
	printf("读取成功\n");
}
