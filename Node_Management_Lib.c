#include "Node_Management_H.h"

//연락처 저장소 개수
int CTIF_List_Num = 0;

//연락처 저장소
CTIF* CTIF_List[Max_CTIF];

//연락처 생성
void Create_CTIF() {
	CTIF* NewCTIF = (CTIF*)malloc(sizeof(CTIF));
	system("cls");
	printf("연락처의 이름을 입력하세요\n입력 : ");
	scanf("%s", &NewCTIF->Name);
	NewCTIF->Top = NULL;
	NewCTIF->List = NULL;
	CTIF_List[CTIF_List_Num++] = NewCTIF;
}

//연락처 저장소가 다 찼는지
int IsCTIFListFull() {
	return (CTIF_List_Num == Max_CTIF);
}

//노드 만들기 & 노드 정보 입력 받기
Node* CreateNode() {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	system("cls");
	printf("각 입력은 최대 15글자를 넘지 않도록 해주세요\n");
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

//노드를 연락처 리스트에 추가 
void AppendNode(CTIF* CTIF, Node* NewNode) {
	if (CTIF->List == NULL)
		CTIF->List = NewNode;
	else {
		CTIF->Top->Next = NewNode;
		NewNode->Prior = CTIF->Top;
	}
	CTIF->Top = NewNode;
}

//노드 제거
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

//노드 삭제
void DestroyNode(Node* Node) {
	free(Node);
}

//인덱스로 노드추소 불러오기 
Node* GNbI(CTIF* CTIF, int Index) {
	Node* Current = CTIF->List;
	while (Index-- && Current->Next != NULL)
		Current = Current->Next;
	return Current;
}

//노드를 주소로 추가 
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

//노드 출력
void PrintNode(Node* Node) {
	printf("이름 : %s\n", Node->Name);
	printf("전화번호 : %s\n", Node->PhoneNumber);
	printf("이메일 : %s\n", Node->E_Mail);
	printf("그룹 : %s\n", Node->Group);
	printf("주소 : %s\n\n", Node->Address);
	printf("---------------------------------\n\n");
}

//노드 모두 출력
void PrintAllNode(CTIF* CTIF) {
	Node* Current = CTIF->List;
	int i = 0;
	while (Current != NULL) {
		printf("번호 : %d", ++i);
		PrintNode(Current);
		Current = Current->Next;
	}
}
//정보 입력1
void InputInformation_First() {
	int n;
	while (1) {
		system("cls");
		printf("1.연락처 리스트 수정, 2.연락처 리스트 접근, 3. 끝내기\n선택지의 번호를 입력 : ");
		scanf("%d", &n);
		getchar();
		system("cls");
		if (n == 1) {
			printf("1.연락처 리스트 만들기, 2. 연락처 리스트 삭제\n 입력 : ");
			scanf("%d", &n);
			getchar();
			system("cls");
			if (n == 1) {
				if (IsCTIFListFull()) {
					printf("연락처 리스트 저장소가 다 찼습니다.");
					getchar();
				}
				else
					Create_CTIF();
			}
			if (n == 2) {
				printf("삭제할 연락처 리스트의 번호를 입력하세요\n번호: ");
				for (int i = 0; i < CTIF_List_Num; i++)
					printf("%d : %s | ", i + 1, CTIF_List[i]->Name);
				printf("\n입력 : ");
				scanf("%d", &n);
				getchar();
				if (n > CTIF_List_Num) {
					system("cls");
					printf("존재하지 않는 연락처 리스트의 번호입니다.");
					getchar();
				}
				else
					DestroyCTIF(n-1);
			}
		}
		else if (n == 2) {
			if (CTIF_List_Num == 0) {
				printf("먼저 연락처 리스트를 만드세요");
				getchar();
			}
			else {
				printf("접근할 연락처 리스트의 번호를 입력하세요\n접근가능한 연락처 리스트의 번호: ");
				for (int i = 0; i < CTIF_List_Num; i++)
					printf("%d : %s | ", i + 1, CTIF_List[i]->Name);
				printf("\n입력 : ");
				scanf("%d", &n);
				getchar();
				if (n > CTIF_List_Num) {
					system("cls");
					printf("접근할 수 없는 값입니다.");
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
		printf("1. 뒤로가기, 2. 연락처 검색, 3. 연락처 수정\n입력 : ");
		scanf("%d", &n);
		getchar();
		if (n == 1)
			break;
		system("cls");
		if (n == 2) {
			if (CTIF_List[CTIF_Num]->List == NULL) {
				printf("먼저 연락처를 생성하세요");
				getchar();
				continue;
			}
			printf("1. 모두다 출력, 2. 번호로 출력\n입력 : ");
			scanf("%d", &n);
			getchar();
			system("cls");
			if (n == 1) 
				PrintAllNode(CTIF_List[CTIF_Num]);
			else if (n == 2) {
				printf("출력할 번호\n입력 : ");
				scanf("%d", &n);
				getchar();
				system("cls");
				PrintNode(GNbI(CTIF_List[CTIF_Num], n - 1));
			}
			getchar();
		}
		else if (n == 3) {
			printf("1. 연락처 추가, 2. 연락처 삭제(번호)\n입력 : ");
			scanf("%d", &n);
			getchar();
			system("cls");
			if (n == 1) {
				printf("추가할 위치(번호 -1을 입력할시 가장 마지막에 추가)입력 : ");
				scanf("%d", &n);
				getchar();
				if (n == -1)
					AppendNode(CTIF_List[CTIF_Num], CreateNode());
				else
					ANbI(CTIF_List[CTIF_Num], CreateNode(), GNbI(CTIF_List[CTIF_Num], n - 1));
			}
			else if (n == 2) {
				if (CTIF_List[CTIF_Num]->List == NULL) {
					printf("삭제할 연락처가 없습니다.");
					getchar();
					continue;
				}
				printf("삭제할 연락처의 번호 입력 : ");
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
