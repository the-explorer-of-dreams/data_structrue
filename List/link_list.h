#include "Common.h"
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;


void CreateList(LinkList linkList, int n) {
	//create linklist by reverse order
	linkList = (LinkList)malloc(sizeof(LNode));
	linkList->next = NULL;

	LinkList p;
	for (int i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(LNode));
		if (!p) exit(OVERFLOW);
	
		scanf(&(p->data));
		p->next = linkList->next;
		linkList->next = p;

}


LinkList GetLNodePointer(LinkList linkList, int i) {
	LinkList p = linkList;
	int j = 1;

	while (p && j < i) {
		p = p->next;
		++j;
	}

	if (!p || j > i) return NULL;

	return p;
}

Status GetElementLink(LinkList linkList, int i, ElemType *e) {
	//查找插入节点
	LinkList p = GetLNodePointer(linkList, i);

	if (!p || j > i) return ERROR;

	*e = p->data;

	return OK;
}




Status ListInsertLink(LinkList linkList, int i, ElemType e) {


	//查找插入节点
	LinkList p = GetLNodePointer(linkList, i);

	//判断根据获取到的节点
	if (!p) return ERROR;
	//构建新的链表节点
	LinkList pNewLNode = (LinkList)malloc(sizeof(LNode));
	//判断返回地址是否为空
	if (!pNewLNode) exit(OVERFLOW);
	pNewLNode->data = e;
	//插入节点
	pNewLNode->next = p->next;
	p->next = pNewLNode;
}

Status ListDeleteLink(LinkList linkList, int i, ElemType* e) {
	//查找前一个节点
	LinkList p = GetLNodePointer(linkList, i-1);
	//判断根据获取到的节点
	if (!p) return ERROR;
	//删除节点
	LinkList q = p->next;
	p->next = p->next->next;
	*e = q->data;
	free(q);
	
	return OK;
}

void MergeListLink(LinkList linkListA, LinkList linkListB, LinkList linkListC) {
	LinkList pa, pb, pc;
	pa = linkListA->next; pb = linkListB->next;
	linkListC = pc = linkListA;

	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else {
			pc->next = pb; pc = pb; pb = pb->next;
		}
		
	}

	pc->next = pa ? pa : pb;
	free(linkListB);
}