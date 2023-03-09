#define _CRT_SECURE_NO_WARNINGS 1
#include "CurriculumDesign.h"

int main() {
	//����ͷ��� 
	Node* head = malloc(sizeof(Node));
	head->next = NULL;
	loadInformation(head);

	while (1) {

		welcome();
		printf("��ѡ����\n");

		char c = _getch();

		switch (c)
		{
		case '1'://����������Ϣok
			inputInformation(head);
			break;
		case '2'://�޸�������Ϣok
			modifyInformation(head);
			break;
		case '3'://ɾ��������Ϣok
			deleteInformation(head);
			break;
		case '4'://����Ų���������Ϣok
			findInformation(head);
			break;
		case '5'://��ְ��ͳ��������Ϣ
			countTitleInformation(head);
			break;
		case '6'://���Ա�ͳ��������Ϣok
			countSexInformation(head);
			break;
		case '7'://��ӡok
			printInformation(head);
			break;
		case '8'://�˳�ϵͳ
			system("cls");
			printf("bye bye!\n");
			exit(0);
			break;
		default:
			printf("����������\n");
			break;
		}
	}

	return 0;
}

void welcome() {
	printf("*****************************************\n");
	printf("*\t���ѧԺ��ѧԺ���¹���ϵͳ\t*\n");
	printf("*****************************************\n");
	printf("*\t��ѡ�����б�\t\t\t*\n");
	printf("*****************************************\n");
	printf("*\t1.����������Ϣ\t\t\t*\n");
	printf("*\t2.�޸�������Ϣ\t\t\t*\n");
	printf("*\t3.ɾ��������Ϣ\t\t\t*\n");
	printf("*\t4.����Ų���������Ϣ\t\t*\n");
	printf("*\t5.��ְ��ͳ��������Ϣ\t\t*\n");
	printf("*\t6.���Ա�ͳ��������Ϣ\t\t*\n");
	printf("*\t7.��ӡ\t\t\t\t*\n");
	printf("*\t8.�˳�ϵͳ\t\t\t*\n");
	printf("*****************************************\n");
}

void inputInformation(Node* head) {
	//����ָ��ָ��ͷ��㣬���ڱ�������
	Node* fresh = malloc(sizeof(Node));
	fresh->next = NULL;
	printf("��������Ա�� ��� ���� �Ա� ���� ְ�� ְ�� ������ò ѧ�� ��Ա���\n");
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
	//����Ա���뵽β��
	move->next = fresh;

	saveInformation(head);//���������Ա��Ϣ�������ļ�
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void modifyInformation(Node* head) {
	printf("������Ҫ�޸���Ա�ı�ţ�");
	int num;
	scanf("%d", &num);
	Node* move = head->next;
	while (move != NULL) {
		if (num == move->information.num) {
			printf("��������Ա�ı�� ���� �Ա� ���� ְ�� ְ�� ������ò ѧ�� ��Ա���\n");
			scanf("%d", &move->information.num);
			scanf("%s", move->information.name);
			scanf("%s", move->information.sex);
			scanf("%d", &move->information.age);
			scanf("%s", move->information.job);
			scanf("%s", move->information.title);
			scanf("%s", move->information.pcs);
			scanf("%s", move->information.ebg);
			scanf("%s", move->information.sort);
			saveInformation(head);//���޸ĵ���Ϣ�־û�
			printf("�޸ĳɹ�\n");
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ���Ա��Ϣ\n");
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void deleteInformation(Node* head) {
	printf("������Ҫɾ������Ա���");
	int num = 0;
	scanf("%d", &num);

	Node* move = head;
	while (move->next != NULL) {

		if (move->next->information.num == num) {
			Node* temp = move->next;
			move->next = move->next->next;//ɾ�����ֻ��Ҫһ��
			free(temp);//���ǵý�ɾ���Ķ�̬�ռ��ͷ�
			temp = NULL;//�ͷź��漴ָ��NULL
			//ͬ�����ļ�
			saveInformation(head);//�־û�����
			printf("ɾ���ɹ�\n");
			//ɾ������
			system("pause");
			//��տ���̨
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("δ�ҵ�������Ϣ\n");
	//ɾ������
	system("pause");
	//��տ���̨
	system("cls");
}

void findInformation(Node* head) {
	printf("������Ҫ������Ա�ı�ţ�");
	int num;
	scanf("%d", &num);
	Node* move = head->next;
	while (move != NULL) {
		if (num == move->information.num) {
			printf("���:%d ����:%s �Ա�:%s ����:%d ְ��:%s ְ��:%s ������ò:%s ѧ��:%s ��Ա���:%s\n", move->information.num,
				move->information.name, move->information.sex, move->information.age, move->information.job,
				move->information.title, move->information.pcs, move->information.ebg, move->information.sort);
			//��ͣ����
			system("pause");
			//��տ���̨
			system("cls");
			return;//�ҵ�����Ա�����������
		}
		move = move->next;
	}
	printf("δ�ҵ�������Ϣ\n");
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void countTitleInformation(Node* head) {
	int teaAss = 0;//����
	int lecturer = 0;//��ʦ
	int assPro = 0;//������
	int professor = 0;//����
	char TeaAss[20] = "����";
	char Lecturer[20] = "��ʦ";
	char AssPro[20] = "������";
	char Professor[20] = "����";
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
	printf("���̣�%d\n", teaAss);
	printf("��ʦ��%d\n", lecturer);
	printf("�����ڣ�%d\n", assPro);
	printf("���ڣ�%d\n", professor);
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void countSexInformation(Node* head) {
	int man = 0;
	int woman = 0;
	char Man[20] = "��";
	char Woman[20] = "Ů";
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
	printf("�У�%d\n", man);
	printf("Ů��%d\n", woman);
	//printf("ѧ��������Ϊ:%d\n", count);
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void printInformation(Node* head) {
	Node* move = head->next;
	while (move != NULL) {
		printf("���:%d ����:%s �Ա�:%s ����:%d ְ��:%s ְ��:%s ������ò:%s ѧ��:%s ��Ա���:%s\n", move->information.num,
			move->information.name, move->information.sex,move->information.age, move->information.job,
			move->information.title, move->information.pcs,move->information.ebg, move->information.sort);
		move = move->next;
	}
	//��ͣ����
	system("pause");
	//��տ���̨
	system("cls");
}

void saveInformation(Node* head) {
	FILE* file = fopen("./information.info", "w");
	//�ж��ļ��Ƿ��ʧ��
	if (file == NULL) {
		printf("���ļ�ʧ��\n");
		return;
	}
	Node* move = head->next;
	while (move != NULL) {
		//���ṹ��д���ļ�
		if (fwrite(&move->information, sizeof(Information), 1, file) != 1) {
			printf("д��ʧ��\n");
			return;
		}
		move = move->next;
	}
	//�ر��ļ�
	fclose(file);
}

void loadInformation(Node* head) {
	//���ļ�
	FILE* file = fopen("./information.info", "r");
	
	if (!file) {
		printf("δ�ҵ���Ա�ļ���������ȡ\n");
		return;
	}
	//����һ�����
	Node* fresh = malloc(sizeof(Node)); 
	fresh->next = NULL;
	Node* move = head;
	while (fread(&fresh->information, sizeof(Information), 1, file) == 1) {
		move->next = fresh;
		move = fresh;
		fresh = malloc(sizeof(Node));
		fresh->next = NULL;
	}
	free(fresh); //���ඨ��һ��fresh��Ҫ�����ͷŵ�
	//�ر��ļ�
	fclose(file);
	printf("��ȡ�ɹ�\n");
}
