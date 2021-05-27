#include "Node_Management_H.h"

//연락처 저장소 개수
int CTIF_List_Num = 0;

//연락처 저장소
CTIF* CTIF_List[Max_CTIF];

//연락처리스트 생성
void Create_CTIF() {
	CTIF* NewCTIF = (CTIF*)malloc(sizeof(CTIF));
	system("cls");
	printf("연락처 리스트의 이름을 입력하세요\n입력 : ");
	scanf("%s", &NewCTIF->Name);
	NewCTIF->Top = 0;
	NewCTIF->List = (Node**)malloc(sizeof(Node*) * Max_List);
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
	return NewNode;
}

//노드를 연락처 리스트에 추가 
int AppendNode(CTIF* CTIF, Node* NewNode) {
	int Top = CTIF->Top;
	if (Top == Max_List)
		return 0;
	CTIF->List[Top] = NewNode;
	CTIF->Top++;
	return 1;
}

//노드 출력
void PrintNode(Node* Node, int Index) {
	printf("번호 : %d\n", Index);
	printf("이름 : %s\n", Node->Name);
	printf("전화번호 : %s\n", Node->PhoneNumber);
	printf("이메일 : %s\n", Node->E_Mail);
	printf("그룹 : %s\n", Node->Group);
	printf("주소 : %s\n\n", Node->Address);
	printf("---------------------------------\n\n");
}

//노드 모두 출력
void PrintAllNode(CTIF* CTIF) {
	int i, Top = CTIF->Top;
	Node** List = CTIF->List;
	for (i = 0; i < Top; i++)
		PrintNode(List[i], i+1);
}

//연락처 리스트 출력
void Print_CTIFList() {
	int n;
	printf("현재 존재하는 연락처 리스트 : ");
	for (n = 0; n < CTIF_List_Num; n++)
		printf("%d. %s | ", n + 1, CTIF_List[n]->Name);
	printf("\n");
}

//노드 검색
void SearchNode(CTIF* CTIF) {
	int n;
	char s[16] = { 0, };
	while (1) {
		system("cls");
		printf("1. 뒤로가기, 2. 모두 출력, 3. 번호로 검색, 4. 이름으로 검색, 5. 그룹으로 검색 , 6. 연락처 추가\n입력 : ");
		scanf("%d", &n), getchar();

		system("cls");
		if (n == 1)
			break;
		else if (n == 2)
			PrintAllNode(CTIF);
		else if (n == 3) {
			printf("검색할 연락처의 번호를 입력하세요\n입력 : ");
			scanf("%d", &n), getchar();
			if (n > CTIF->Top || n <= 0)
				printf("없는 번호입니다."), getchar();
			else {
				system("cls");
				PrintNode(CTIF->List[n-1], n);
				getchar();
			}
		}
		else if (n == 4) {
			int Top = CTIF->Top;
			Node** Current = CTIF->List;
			printf("검색할 연락처의 이름을 입력하세요\n입력 : ");
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
			printf("검색할 연락처의 그룹을 입력하세요\n입력 : ");
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
			printf("1. 뒤로가기, 2. 연락처 수정\n입력 : ");
			scanf("%d", &n), getchar();
			if (n == 2) {
				printf("수정할 연락처의 번호를 고르세요.\n입력 : ");
				scanf("%d", &n), getchar();
				if (n <= 0 || n > CTIF->Top) {
					system("cls");
					printf("존재하지 않는 연락처 번호입니다.");
					getchar();
				}
				else
					Revise_Node(CTIF->List[n - 1]);
			}
		}
	}
}

//정보 입력1
void InputInformation_First() {
	int n;
	while (1) {
		system("cls");
		printf("1. 끝내기, 2. 연락처 리스트 접근, 3. 연락처 리스트 수정\n입력 : ");
		scanf("%d", &n), getchar();

		system("cls");
		//끝내기
		if (n == 1)
			break;
		//연락처 리스트 수정
		else if (n == 2) {
			//연락처 리스트가 없을 때 예외처리
			if (CTIF_List_Num == 0) {
				printf("접근 가능한 연락처 리스트가 없습니다. 먼저 연락처 리스트를 만드세요");
				getchar();
				continue;
			}
			//접근할 연락처 리스트 번호 받기
			//접근 가능하 연락처 리스트 출력
			Print_CTIFList();
			printf("접근할 연락처 리스트의 번호를 입력하세요.");
			printf("\n입력 : "), scanf("%d", &n), getchar();
			system("cls");
			if (n > CTIF_List_Num || n <= 0)
				printf("없는 번호입니다."), getchar();
			else
				SearchNode(CTIF_List[n-1]);
		}
		else if (n == 3) {
			Revise_CTIF();
		}
	}
}

//연락처 리스트 수정
void Revise_CTIF() {
	int n;
	while (1) {
		system("cls");
		Print_CTIFList();
		printf("1. 뒤로가기, 2. 연락처 리스트 만들기, 3.  이름 수정, 4. 삭제\n입력 : ");
		scanf("%d", &n), getchar();

		system("cls");
		//1, 뒤로가기
		if (n == 1)
			break;
		//2.연락처 리스트 만들기
		else if (n == 2) {
			if (IsCTIFListFull())
				printf("연락처 리스트의 최대개수가 한계치입니다."), getchar();
			else
				Create_CTIF();
		}
		// 3. 이름 수정
		else if (n == 3) {
			Print_CTIFList();
			printf("수정할 연락처 리스트의 번호를 입력하세요\n입력 : ");
			scanf("%d", &n), getchar();
			system("cls");
			if (n > CTIF_List_Num || n <= 0)
				printf("없는 번호입니다."), getchar();
			else {
				printf("변경할 이름을 입력하세요\n 입력 : ");
				scanf("%s", CTIF_List[n - 1]->Name);
			}
		}
		//4. 삭제
		else if (n == 4) {
			if (CTIF_List_Num == 0)
				printf("삭제 가능한 연락처 리스트가 없습니다."), getchar();
			else {
				Print_CTIFList();
				printf("삭제할 연락처의 번호를 입력하세요.\n입력 : ");
				scanf("%d", &n), getchar();
				if (n > CTIF_List_Num || n <= 0)
					printf("없는 번호입니다."), getchar();
				else
					DestroyCTIF(n - 1);
			}
		}
	}
}

//연락처 수정
void Revise_Node(Node* Node) {
	int n;
	system("cls");
	printf("기존 연락처\n");
	PrintNode(Node, -1);
	printf("건너 뛰려면 -1을 입력하시고 수정 하려면 1을 입력하세요.\n");
	printf("PhoneNumber : "), scanf("%d", &n), getchar();
	if (n == 1) {
		printf("입력 : ");
		scanf("%s", &Node->PhoneNumber);
	}
	printf("Name : "), scanf("%d", &n), getchar();
	if (n == 1) {
		printf("입력 : ");
		scanf("%s", &Node->Name);
	}
	printf("E-Mail : "), scanf("%d", &n), getchar();
	if (n == 1) {
		printf("입력 : ");
		scanf("%s", &Node->E_Mail);
	}
	printf("Group : "), scanf("%d", &n), getchar();
	if (n == 1) {
		printf("입력 : ");
		scanf("%s", &Node->Group);
	}
	printf("Address : "), scanf("%d", &n), getchar();
	if (n == 1) {
		printf("입력 : ");
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