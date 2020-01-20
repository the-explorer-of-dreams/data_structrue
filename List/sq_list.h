#include "Common.h"
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct {
	ElemType* elem;
	int length;
	int listSize;
}SqList;

Status InitListSq(SqList *sqList) {
	(*sqList).elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(*sqList).elem) exit(OVERFLOW);
	(*sqList).length = 0;
	(*sqList).listSize = LIST_INIT_SIZE;
	
	return OK;
}

Status AssignListSqWithRandomInteger(SqList* sqList, int size, int seedNum) {
	for (int i = 0; i < size; i++) {
		(*sqList).elem[i] = GetRandomInteger(seedNum);
		++(*sqList).length;
	}

	return OK;

}

Status DisplaySqListValues(SqList* sqList) {

	for (int i = 0; i < (*sqList).length; i++) {
		printf("\nassign the %d element: %d", i, (*sqList).elem[i]);
	}

	return OK;

}


Status ListInsertSq(SqList *sqList, int i, ElemType e) {
	//insert a new element before the element whose index is i;
	//check the input paras 
	if (i < 1 || i >((*sqList).length + 1)) return ERROR;
	//ensure free space
	if ((*sqList).length >= (*sqList).listSize) {
		ElemType* newBase = (ElemType*)realloc((*sqList).elem,
			((*sqList).listSize + LIST_INCREMENT) * sizeof(ElemType));

		if (!newBase) exit(OVERFLOW);

		(*sqList).elem = newBase;
		(*sqList).listSize += LIST_INCREMENT;
	}
	//insert the new element
	//move all the elemnent whose index >= i
	ElemType* q = &(*sqList).elem[i - 1];
	for (ElemType* p = &(*sqList).elem[(*sqList).length - 1]; p >= q; --p) *(p + 1) = *p;

	//assign the new element
	*q = e;
	++(*sqList).length;

	return OK;
}

Status ListDeleteSq(SqList* sqList, int i, ElemType *e) {
	//delete the element whose index is i from the array;
	//check the input paras 
	if (i < 1 || i >((*sqList).length)) return ERROR;
	//get the element
	ElemType* p = &((*sqList).elem[i - 1]);
	*e = *p;
	ElemType* q = (*sqList).elem + (*sqList).length - 1;
	//move backward all the data
	for (++p; p <= q; ++p) *(p - 1) = *p;
	--(*sqList).length;

	return OK;
}


Status compare(ElemType e1, ElemType e2) {
	if (e1 > e2) return 1;
	else if (e1 == e2) return 0;
	else return -1;
}

int LocateElemSq(SqList *sqList, ElemType e, Status (*compare)(ElemType, ElemType)) {
	int index = 1;
	ElemType* p = (*sqList).elem;
	while((index <= (*sqList).length) && ((*compare)(*p++, e))) ++index;
	if (index <= (*sqList).length) return index;
	else return 0;
}

Status SortListMyIdeaSq(SqList* sqList, OrderType orderType) {
	ElemType tempElem,*p,*q;

	for (int index = 0; index < (*sqList).length; index++) {
		p = (*sqList).elem+index;
		for (int innerIndex = (index + 1); innerIndex < (*sqList).length; innerIndex++) {
			q = (*sqList).elem + innerIndex;
			if (orderType == 1) {
				if (*p > * q) {
					tempElem = *q;
					*q = *p;
					*p = tempElem;
				}
			}
			else if (orderType == -1) {
				if (*p < * q) {
					tempElem = *q;
					*q = *p;
					*p = tempElem;
				}
			}
		
		}
	}

	return OK;

}

Status SwitchElements(SqList* sqList, int fisrtIndex, int secondIndex) {
	ElemType tempElement;
	tempElement = (*sqList).elem[secondIndex];
	(*sqList).elem[secondIndex] = (*sqList).elem[fisrtIndex];
	(*sqList).elem[fisrtIndex] = tempElement;

	return OK;

}

//QUICK SORT
Status Partition(SqList* sqList, int low, int high) {
	int pivotKey = (*sqList).elem[low];
	while (low < high) {
		while (low < high && (*sqList).elem[high] >= pivotKey) --high;
		SwitchElements(sqList, low, high);
		while (low < high && (*sqList).elem[low] <= pivotKey) ++low;
		SwitchElements(sqList, low, high);
	}
	return low;

}

Status PartitionFirstImprovement(SqList* sqList, int low, int high) {
	//(*sqList).elem[0] = (*sqList).elem[low];
	int pivotKey = (*sqList).elem[low];
	while (low < high) {
		while (low < high && (*sqList).elem[high] >= pivotKey) --high;
		(*sqList).elem[low] = (*sqList).elem[high];
		while (low < high && (*sqList).elem[low] <= pivotKey) ++low;
		(*sqList).elem[high] = (*sqList).elem[low];
	}

	(*sqList).elem[low] = pivotKey;

	return low;
}


Status QSort(SqList* sqList, int low, int high) {
	if (low < high) {
		int pivotIndex = PartitionFirstImprovement(sqList, low, high);
		QSort(sqList, low, pivotIndex - 1);
		QSort(sqList, pivotIndex + 1, high);
	}

	return OK;
}












void MergeListSq(SqList sqListA, SqList sqListB, SqList *sqListC) {
	//init condition: sqListA and sqListB have to be sorted.
	//merge operation
	ElemType *pa, *paLast, *pb, *pbLast, *pc;
	//init sqListC
	(*sqListC).listSize = (*sqListC).length = sqListA.length + sqListB.length;
	pc = (*sqListC).elem = (ElemType *)malloc((*sqListC).listSize * sizeof(ElemType));
	if (!(*sqListC).elem) exit(OVERFLOW);

	//start to merge
	pa = sqListA.elem;
	pb = sqListB.elem;
	paLast = sqListA.elem + (sqListA.length - 1);
	pbLast = sqListB.elem + (sqListB.length - 1);

	while (pa <= paLast && pb <= pbLast) {
		if (*pa < *pb)  *pc++ = *pa++;
		else *pc++ = *pb++;
	}

	while (pa <= paLast) *pc++ = *pa++;
	while (pb <= pbLast) *pc++ = *pb++;
	
}
