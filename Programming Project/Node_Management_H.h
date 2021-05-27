#ifndef NODE_MANAGEMENT_H
#define NODE_MANAGEMENT_H

#define _CRT_SECURE_NO_WARNINGS

#include <malloc.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>

// ����ó ������� �ִ� �뷮
#define Max_CTIF 3

//����ó ����Ʈ�� �ִ� �뷮
#define Max_List 25

//�� ����� ����
typedef struct tagNode {
	char PhoneNumber[16];
	char Name[16];
	char E_Mail[16];
	char Group[16];
	char Address[16];
}Node;

//����ó
typedef struct ContactInformation {
	char Name[32];
	int Top;
	Node** List;
}CTIF;

//����ó ����
void Create_CTIF();
//����ó ����Ұ� �� á����
int IsCTIFListFull();
//��� �����
Node* CreateNode();
//��带 ����ó ����Ʈ�� �߰�
int AppendNode(CTIF* CTIF, Node* NewNode);
//��� ���
void PrintNode(Node* Node, int Index);
//��� ��� ���
void PrintAllNode(CTIF* CTIF);
//����ó ����Ʈ ���
void Print_CTIFList();
//��� �˻�
void SearchNode(CTIF* CTIF);
//���� �Է�1
void InputInformation_First();
//����ó ����Ʈ ����
void Revise_CTIF();
//����ó ����
void Revise_Node(Node* Node);
//CTIF����
void DestroyCTIF(int i);
//��� ����
void AllClear();

#endif // NODE_MANAGEMENT_H

