#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Common.h"

#define MAX_SIZE 1000

typedef struct {
	ElemType data;
	int nextIndex;
}component, SLinkList[MAX_SIZE];


int LocateElemSL(SLinkList sLinkList, ElemType e) {
	int curIndex;
	curIndex = sLinkList[0].nextIndex;
	while (curIndex && sLinkList[curIndex].data != e) curIndex = sLinkList[curIndex].nextIndex ;

	return curIndex;
}

void InitSpaceSL(SLinkList space) {
	for (int i = 0; i < MAX_SIZE - 1; ++i) {
		space[i].nextIndex = i + 1;
	}

	space[MAX_SIZE - 1].nextIndex = 0;
}

int MallocSL(SLinkList space) {
	int i = space[0].nextIndex;
	if (space[0].nextIndex) space[0].nextIndex = space[i].nextIndex;

	return i;
}

void FreeSL(SLinkList space, int k) {
	space[k].nextIndex = space[0].nextIndex;
	space[0].nextIndex = k;
}

Status InitSLinkListWithRandomValue(SLinkList sLinkList, SLinkList space, int sLinkListSize) {
	int i, r;
	sLinkList[0].nextIndex = MallocSL(space);
	r = sLinkList[0].nextIndex;
	for (int j = 1; j <= sLinkListSize; ++j) {
		i = MallocSL(space);
		space[i].data = GetRandomInteger(1000);
		space[r].nextIndex = i;
		r = i;
	}
	space[r].nextIndex = 0;

	return OK;
}


Status DisplaySLinkList(SLinkList sLinkList) {
	int nextIndex = 0, data = 0, i = 1;
	nextIndex = sLinkList->nextIndex;
	while (nextIndex != 0) {
		printf("the value of the %d element is :%d", i, sLinkList[nextIndex].data);
		nextIndex = sLinkList[nextIndex].nextIndex;
		++i;
	};

	return OK;
}


void difference() {
}






