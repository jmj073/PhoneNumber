#ifndef NODE_MANAGEMENT_H
#define NODE_MANAGEMENT_H

#define _CRT_SECURE_NO_WARNINGS

#include <malloc.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>

// 연락처 저장소의 최대 용량
#define Max_CTIF 3

//연락처 리스트의 최대 용량
#define Max_List 25

//한 사람의 정보
typedef struct tagNode {
	char PhoneNumber[16];
	char Name[16];
	char E_Mail[16];
	char Group[16];
	char Address[16];
}Node;

//연락처
typedef struct ContactInformation {
	char Name[32];
	int Top;
	Node** List;
}CTIF;

//연락처 생성
void Create_CTIF();
//연락처 저장소가 다 찼는지
int IsCTIFListFull();
//노드 만들기
Node* CreateNode();
//노드를 연락처 리스트에 추가
int AppendNode(CTIF* CTIF, Node* NewNode);
//노드 출력
void PrintNode(Node* Node, int Index);
//노드 모두 출력
void PrintAllNode(CTIF* CTIF);
//연락처 리스트 출력
void Print_CTIFList();
//노드 검색
void SearchNode(CTIF* CTIF);
//정보 입력1
void InputInformation_First();
//연락처 리스트 수정
void Revise_CTIF();
//연락처 수정
void Revise_Node(Node* Node);
//CTIF삭제
void DestroyCTIF(int i);
//모두 정리
void AllClear();

#endif // NODE_MANAGEMENT_H

