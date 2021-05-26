#ifndef NODE_MANAGEMENT_H
#define NODE_MANAGEMENT_H

#define _CRT_SECURE_NO_WARNINGS

#include <malloc.h>
#include <stdio.h>
#include <Windows.h>

// 연락처 저장소의 최대 용량
#define Max_CTIF 3

//한 사람의 정보
typedef struct tagNode {
	struct tagNode* Prior;
	char PhoneNumber[16];
	char Name[16];
	char E_Mail[16];
	char Group[16];
	char Address[16];
	struct tagNode* Next;
}Node;

//연락처
typedef struct ContactInformation {
	char Name[32];
	Node* Top;
	Node* List;
}CTIF;

//연락처 생성
void Create_CTIF();
//연락처 저장소가 다 찼는지
int IsCTIFListFull();
//노드 만들기
Node* CreateNode();
//노드를 연락처 리스트에 추가
void AppendNode(CTIF* CTIF, Node* NewNode);
//노드 제거
void RemoveNode(CTIF* CTIF, Node* Node);
//노드 삭제
void DestroyNode(Node* Node);
//인덱스로 노드추소 불러오기 GetNodebyIndex
Node* GNbI(CTIF* CTIF, int Index);
//노드를 주소로 추가 AppendNodebyAddress 
void ANbI(CTIF* CTIF, Node* NewNode, Node* IndexNode);
//노드 출력
void PrintNode(Node* Node);
//노드 모두 출력
void PrintAllNode(CTIF* CTIF);
//정보 입력1
void InputInformation_First();
//정보입력 연락처 선택지
void InputInformation_CTIF(int CTIF_Num);
//CTIF삭제
void DestroyCTIF();
//모두 정리
void AllClear();

#endif // NODE_MANAGEMENT_H

