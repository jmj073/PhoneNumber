#ifndef NODE_MANAGEMENT_H
#define NODE_MANAGEMENT_H

#define _CRT_SECURE_NO_WARNINGS

#include <malloc.h>
#include <stdio.h>
#include <Windows.h>

// ����ó ������� �ִ� �뷮
#define Max_CTIF 3

//�� ����� ����
typedef struct tagNode {
	struct tagNode* Prior;
	char PhoneNumber[16];
	char Name[16];
	char E_Mail[16];
	char Group[16];
	char Address[16];
	struct tagNode* Next;
}Node;

//����ó
typedef struct ContactInformation {
	char Name[32];
	Node* Top;
	Node* List;
}CTIF;

//����ó ����
void Create_CTIF();
//����ó ����Ұ� �� á����
int IsCTIFListFull();
//��� �����
Node* CreateNode();
//��带 ����ó ����Ʈ�� �߰�
void AppendNode(CTIF* CTIF, Node* NewNode);
//��� ����
void RemoveNode(CTIF* CTIF, Node* Node);
//��� ����
void DestroyNode(Node* Node);
//�ε����� ����߼� �ҷ����� GetNodebyIndex
Node* GNbI(CTIF* CTIF, int Index);
//��带 �ּҷ� �߰� AppendNodebyAddress 
void ANbI(CTIF* CTIF, Node* NewNode, Node* IndexNode);
//��� ���
void PrintNode(Node* Node);
//��� ��� ���
void PrintAllNode(CTIF* CTIF);
//���� �Է�1
void InputInformation_First();
//�����Է� ����ó ������
void InputInformation_CTIF(int CTIF_Num);
//CTIF����
void DestroyCTIF();
//��� ����
void AllClear();

#endif // NODE_MANAGEMENT_H

