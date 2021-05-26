#include "Node_Management_H.h"

//����ó ����� ����
int CTIF_List_Num = 0;

//����ó �����
CTIF* CTIF_List[Max_CTIF];

//����ó ����
void Create_CTIF() {
	CTIF* NewCTIF = (CTIF*)malloc(sizeof(CTIF));
	system("cls");
	printf("����ó�� �̸��� �Է��ϼ���\n�Է� : ");
	scanf("%s", &NewCTIF->Name);
	NewCTIF->Top = NULL;
	NewCTIF->List = NULL;
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

	NewNode->Prior = NULL;
	NewNode->Next = NULL;

	return NewNode;
}

//��带 ����ó ����Ʈ�� �߰� 
void AppendNode(CTIF* CTIF, Node* NewNode) {
	if (CTIF->List == NULL)
		CTIF->List = NewNode;
	else {
		CTIF->Top->Next = NewNode;
		NewNode->Prior = CTIF->Top;
	}
	CTIF->Top = NewNode;
}

//��� ����
void RemoveNode(CTIF* CTIF, Node* Node) {
	if (Node->Prior == NULL) {
		Node->Next->Prior = NULL;
		CTIF->List = Node->Next;
	}
	else if (Node->Next != NULL) {
			Node->Next->Prior = Node->Prior;
			Node->Prior->Next = Node->Next;
	}
	else 
		Node->Prior->Next = NULL;
}

//��� ����
void DestroyNode(Node* Node) {
	free(Node);
}

//�ε����� ����߼� �ҷ����� 
Node* GNbI(CTIF* CTIF, int Index) {
	Node* Current = CTIF->List;
	while (Index-- && Current->Next != NULL)
		Current = Current->Next;
	return Current;
}

//��带 �ּҷ� �߰� 
void ANbI(CTIF* CTIF, Node* NewNode, Node* IndexNode) {
	if (CTIF->List == NULL) {
		CTIF->List = NewNode;
		CTIF->Top = NewNode;
	}
	else {
		NewNode->Next = IndexNode;
		NewNode->Prior = IndexNode->Prior;
		if (NewNode->Prior == NULL)
			CTIF->List = NewNode;
		else
			IndexNode->Prior->Next = NewNode;
		IndexNode->Prior = NewNode;
	}
}

//��� ���
void PrintNode(Node* Node) {
	printf("�̸� : %s\n", Node->Name);
	printf("��ȭ��ȣ : %s\n", Node->PhoneNumber);
	printf("�̸��� : %s\n", Node->E_Mail);
	printf("�׷� : %s\n", Node->Group);
	printf("�ּ� : %s\n\n", Node->Address);
	printf("---------------------------------\n\n");
}

//��� ��� ���
void PrintAllNode(CTIF* CTIF) {
	Node* Current = CTIF->List;
	int i = 0;
	while (Current != NULL) {
		printf("��ȣ : %d", ++i);
		PrintNode(Current);
		Current = Current->Next;
	}
}
//���� �Է�1
void InputInformation_First() {
	int n;
	while (1) {
		system("cls");
		printf("1.����ó ����Ʈ ����, 2.����ó ����Ʈ ����, 3. ������\n�������� ��ȣ�� �Է� : ");
		scanf("%d", &n);
		getchar();
		system("cls");
		if (n == 1) {
			printf("1.����ó ����Ʈ �����, 2. ����ó ����Ʈ ����\n �Է� : ");
			scanf("%d", &n);
			getchar();
			system("cls");
			if (n == 1) {
				if (IsCTIFListFull()) {
					printf("����ó ����Ʈ ����Ұ� �� á���ϴ�.");
					getchar();
				}
				else
					Create_CTIF();
			}
			if (n == 2) {
				printf("������ ����ó ����Ʈ�� ��ȣ�� �Է��ϼ���\n��ȣ: ");
				for (int i = 0; i < CTIF_List_Num; i++)
					printf("%d : %s | ", i + 1, CTIF_List[i]->Name);
				printf("\n�Է� : ");
				scanf("%d", &n);
				getchar();
				if (n > CTIF_List_Num) {
					system("cls");
					printf("�������� �ʴ� ����ó ����Ʈ�� ��ȣ�Դϴ�.");
					getchar();
				}
				else
					DestroyCTIF(n-1);
			}
		}
		else if (n == 2) {
			if (CTIF_List_Num == 0) {
				printf("���� ����ó ����Ʈ�� ���弼��");
				getchar();
			}
			else {
				printf("������ ����ó ����Ʈ�� ��ȣ�� �Է��ϼ���\n���ٰ����� ����ó ����Ʈ�� ��ȣ: ");
				for (int i = 0; i < CTIF_List_Num; i++)
					printf("%d : %s | ", i + 1, CTIF_List[i]->Name);
				printf("\n�Է� : ");
				scanf("%d", &n);
				getchar();
				if (n > CTIF_List_Num) {
					system("cls");
					printf("������ �� ���� ���Դϴ�.");
					getchar();
				}
				else
					InputInformation_CTIF(n-1);
			}
		}
		else if (n == 3)
			break;
	}
}

void InputInformation_CTIF(int CTIF_Num) {
	int n;
	while (1) {
		system("cls");
		printf("1. �ڷΰ���, 2. ����ó �˻�, 3. ����ó ����\n�Է� : ");
		scanf("%d", &n);
		getchar();
		if (n == 1)
			break;
		system("cls");
		if (n == 2) {
			if (CTIF_List[CTIF_Num]->List == NULL) {
				printf("���� ����ó�� �����ϼ���");
				getchar();
				continue;
			}
			printf("1. ��δ� ���, 2. ��ȣ�� ���\n�Է� : ");
			scanf("%d", &n);
			getchar();
			system("cls");
			if (n == 1) 
				PrintAllNode(CTIF_List[CTIF_Num]);
			else if (n == 2) {
				printf("����� ��ȣ\n�Է� : ");
				scanf("%d", &n);
				getchar();
				system("cls");
				PrintNode(GNbI(CTIF_List[CTIF_Num], n - 1));
			}
			getchar();
		}
		else if (n == 3) {
			printf("1. ����ó �߰�, 2. ����ó ����(��ȣ)\n�Է� : ");
			scanf("%d", &n);
			getchar();
			system("cls");
			if (n == 1) {
				printf("�߰��� ��ġ(��ȣ -1�� �Է��ҽ� ���� �������� �߰�)�Է� : ");
				scanf("%d", &n);
				getchar();
				if (n == -1)
					AppendNode(CTIF_List[CTIF_Num], CreateNode());
				else
					ANbI(CTIF_List[CTIF_Num], CreateNode(), GNbI(CTIF_List[CTIF_Num], n - 1));
			}
			else if (n == 2) {
				if (CTIF_List[CTIF_Num]->List == NULL) {
					printf("������ ����ó�� �����ϴ�.");
					getchar();
					continue;
				}
				printf("������ ����ó�� ��ȣ �Է� : ");
				scanf("%d", &n);
				getchar();
				Node* Abandon = GNbI(CTIF_List[CTIF_Num], n - 1);
				RemoveNode(CTIF_List[CTIF_Num], Abandon);
				DestroyNode(Abandon);
			}
		}
	}
}
void DestroyCTIF(int i) {
	Node* List = CTIF_List[i]->List;
	Node* Current = List;
	while (List != NULL) {
		List = List->Next;
		free(Current);
		Current = List;
	}
	free(CTIF_List[i]);
}

void AllClear() {
	for (int i = 0; i < CTIF_List_Num; i++) 
		DestroyCTIF(i);
}
