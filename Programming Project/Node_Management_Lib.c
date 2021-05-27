#include "Node_Management_H.h"

//����ó ����� ����
int CTIF_List_Num = 0;

//����ó �����
CTIF* CTIF_List[Max_CTIF];

//����ó����Ʈ ����
void Create_CTIF() {
	CTIF* NewCTIF = (CTIF*)malloc(sizeof(CTIF));
	system("cls");
	printf("����ó ����Ʈ�� �̸��� �Է��ϼ���\n�Է� : ");
	scanf("%s", &NewCTIF->Name);
	NewCTIF->Top = 0;
	NewCTIF->List = (Node**)malloc(sizeof(Node*) * Max_List);
	CTIF_List[CTIF_List_Num++] = NewCTIF;
}

//����ó ����Ұ� �� á����
int IsCTIFListFull() {
	return (CTIF_List_Num == Max_CTIF);
}

//��� ����� & ��� ���� �Է� �ޱ�
Node* CreateNode() {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	system("cls");
	printf("�� �Է��� �ִ� 15���ڸ� ���� �ʵ��� ���ּ���\n");
	printf("PhoneNumber : ");
	scanf("%s", &NewNode->PhoneNumber);
	printf("Name : ");
	scanf("%s", &NewNode->Name);
	printf("E-Mail : ");
	scanf("%s", &NewNode->E_Mail);
	printf("Group : ");
	scanf("%s", &NewNode->Group);
	printf("Address : ");
	scanf("%s", &NewNode->Address);
	return NewNode;
}

//��带 ����ó ����Ʈ�� �߰� 
int AppendNode(CTIF* CTIF, Node* NewNode) {
	int Top = CTIF->Top;
	if (Top == Max_List)
		return 0;
	CTIF->List[Top] = NewNode;
	CTIF->Top++;
	return 1;
}

//��� ���
void PrintNode(Node* Node, int Index) {
	printf("��ȣ : %d\n", Index);
	printf("�̸� : %s\n", Node->Name);
	printf("��ȭ��ȣ : %s\n", Node->PhoneNumber);
	printf("�̸��� : %s\n", Node->E_Mail);
	printf("�׷� : %s\n", Node->Group);
	printf("�ּ� : %s\n\n", Node->Address);
	printf("---------------------------------\n\n");
}

//��� ��� ���
void PrintAllNode(CTIF* CTIF) {
	int i, Top = CTIF->Top;
	Node** List = CTIF->List;
	for (i = 0; i < Top; i++)
		PrintNode(List[i], i+1);
}

//����ó ����Ʈ ���
void Print_CTIFList() {
	int n;
	printf("���� �����ϴ� ����ó ����Ʈ : ");
	for (n = 0; n < CTIF_List_Num; n++)
		printf("%d. %s | ", n + 1, CTIF_List[n]->Name);
	printf("\n");
}

//��� �˻�
void SearchNode(CTIF* CTIF) {
	int n;
	char s[16] = { 0, };
	while (1) {
		system("cls");
		printf("1. �ڷΰ���, 2. ��� ���, 3. ��ȣ�� �˻�, 4. �̸����� �˻�, 5. �׷����� �˻� , 6. ����ó �߰�\n�Է� : ");
		scanf("%d", &n), getchar();

		system("cls");
		if (n == 1)
			break;
		else if (n == 2)
			PrintAllNode(CTIF);
		else if (n == 3) {
			printf("�˻��� ����ó�� ��ȣ�� �Է��ϼ���\n�Է� : ");
			scanf("%d", &n), getchar();
			if (n > CTIF->Top || n <= 0)
				printf("���� ��ȣ�Դϴ�."), getchar();
			else {
				system("cls");
				PrintNode(CTIF->List[n-1], n);
				getchar();
			}
		}
		else if (n == 4) {
			int Top = CTIF->Top;
			Node** Current = CTIF->List;
			printf("�˻��� ����ó�� �̸��� �Է��ϼ���\n�Է� : ");
			scanf("%s", &s), getchar();

			system("cls");
			for (n = 0; n < Top; n++) {
				if (!strcmp(s, Current[n]->Name))
					PrintNode(Current[n], n+1);
			}
		}
		else if (n == 5) {
			int Top = CTIF->Top;
			Node** Current = CTIF->List;
			printf("�˻��� ����ó�� �׷��� �Է��ϼ���\n�Է� : ");
			scanf("%s", &s), getchar();

			system("cls");
			for (n = 0; n < Top; n++) {
				if (!strcmp(s, Current[n]->Group))
					PrintNode(Current[n], n + 1);
			}
		}
		else if (n == 6) {
			AppendNode(CTIF, CreateNode());
		}
		if (n >= 1 && n <= 5) {
			printf("1. �ڷΰ���, 2. ����ó ����\n�Է� : ");
			scanf("%d", &n), getchar();
			if (n == 2) {
				printf("������ ����ó�� ��ȣ�� ������.\n�Է� : ");
				scanf("%d", &n), getchar();
				if (n <= 0 || n > CTIF->Top) {
					system("cls");
					printf("�������� �ʴ� ����ó ��ȣ�Դϴ�.");
					getchar();
				}
				else
					Revise_Node(CTIF->List[n - 1]);
			}
		}
	}
}

//���� �Է�1
void InputInformation_First() {
	int n;
	while (1) {
		system("cls");
		printf("1. ������, 2. ����ó ����Ʈ ����, 3. ����ó ����Ʈ ����\n�Է� : ");
		scanf("%d", &n), getchar();

		system("cls");
		//������
		if (n == 1)
			break;
		//����ó ����Ʈ ����
		else if (n == 2) {
			//����ó ����Ʈ�� ���� �� ����ó��
			if (CTIF_List_Num == 0) {
				printf("���� ������ ����ó ����Ʈ�� �����ϴ�. ���� ����ó ����Ʈ�� ���弼��");
				getchar();
				continue;
			}
			//������ ����ó ����Ʈ ��ȣ �ޱ�
			//���� ������ ����ó ����Ʈ ���
			Print_CTIFList();
			printf("������ ����ó ����Ʈ�� ��ȣ�� �Է��ϼ���.");
			printf("\n�Է� : "), scanf("%d", &n), getchar();
			system("cls");
			if (n > CTIF_List_Num || n <= 0)
				printf("���� ��ȣ�Դϴ�."), getchar();
			else
				SearchNode(CTIF_List[n-1]);
		}
		else if (n == 3) {
			Revise_CTIF();
		}
	}
}

//����ó ����Ʈ ����
void Revise_CTIF() {
	int n;
	while (1) {
		system("cls");
		Print_CTIFList();
		printf("1. �ڷΰ���, 2. ����ó ����Ʈ �����, 3.  �̸� ����, 4. ����\n�Է� : ");
		scanf("%d", &n), getchar();

		system("cls");
		//1, �ڷΰ���
		if (n == 1)
			break;
		//2.����ó ����Ʈ �����
		else if (n == 2) {
			if (IsCTIFListFull())
				printf("����ó ����Ʈ�� �ִ밳���� �Ѱ�ġ�Դϴ�."), getchar();
			else
				Create_CTIF();
		}
		// 3. �̸� ����
		else if (n == 3) {
			Print_CTIFList();
			printf("������ ����ó ����Ʈ�� ��ȣ�� �Է��ϼ���\n�Է� : ");
			scanf("%d", &n), getchar();
			system("cls");
			if (n > CTIF_List_Num || n <= 0)
				printf("���� ��ȣ�Դϴ�."), getchar();
			else {
				printf("������ �̸��� �Է��ϼ���\n �Է� : ");
				scanf("%s", CTIF_List[n - 1]->Name);
			}
		}
		//4. ����
		else if (n == 4) {
			if (CTIF_List_Num == 0)
				printf("���� ������ ����ó ����Ʈ�� �����ϴ�."), getchar();
			else {
				Print_CTIFList();
				printf("������ ����ó�� ��ȣ�� �Է��ϼ���.\n�Է� : ");
				scanf("%d", &n), getchar();
				if (n > CTIF_List_Num || n <= 0)
					printf("���� ��ȣ�Դϴ�."), getchar();
				else
					DestroyCTIF(n - 1);
			}
		}
	}
}

//����ó ����
void Revise_Node(Node* Node) {
	int n;
	system("cls");
	printf("���� ����ó\n");
	PrintNode(Node, -1);
	printf("�ǳ� �ٷ��� -1�� �Է��Ͻð� ���� �Ϸ��� 1�� �Է��ϼ���.\n");
	printf("PhoneNumber : "), scanf("%d", &n), getchar();
	if (n == 1) {
		printf("�Է� : ");
		scanf("%s", &Node->PhoneNumber);
	}
	printf("Name : "), scanf("%d", &n), getchar();
	if (n == 1) {
		printf("�Է� : ");
		scanf("%s", &Node->Name);
	}
	printf("E-Mail : "), scanf("%d", &n), getchar();
	if (n == 1) {
		printf("�Է� : ");
		scanf("%s", &Node->E_Mail);
	}
	printf("Group : "), scanf("%d", &n), getchar();
	if (n == 1) {
		printf("�Է� : ");
		scanf("%s", &Node->Group);
	}
	printf("Address : "), scanf("%d", &n), getchar();
	if (n == 1) {
		printf("�Է� : ");
		scanf("%s", &Node->Address);
	}
}

void DestroyCTIF(int i) {
	Node** List = CTIF_List[i]->List;
	int Top = CTIF_List[i]->Top;
	free(CTIF_List[i]);
	for (i = 0; i < Top; i++)
		free(List[i]);
	CTIF_List_Num--;
}

void AllClear() {
	for (int i = 0; i < CTIF_List_Num; i++) 
		DestroyCTIF(i);
}