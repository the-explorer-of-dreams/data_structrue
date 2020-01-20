#include<stdio.h>
#include<stdlib.h>
#include "sq_list.h"

Status InsertDataAtIndex(SqList* sqList, int index, ElemType elem);
Status DeleteDataAtIndex(SqList* sqList, int index, ElemType* elem);
Status SortListData(SqList* sqList, OrderType orderType);
void MergeTwoList(SqList sqListA, SqList sqListB, SqList* pSqListC);


int main(int argc, char *argv[])
{
	printf("SqListMain.main() is running!");
	////define a SqList
	//SqList sqList;
	////init the sqList
	//int result = InitListSq(&sqList);
	//printf("InitListSq result is %d!\n", result);
	////set data
	//int inputNum;
	//printf("please input the number you want to input: ");
	//scanf_s("%d", &inputNum);
	//printf("inputNum is %d.", inputNum);
	////asign data
	//AssignListSqWithRandomInteger(&sqList, inputNum, 1000);

	////insert element
	//InsertDataAtIndex(&sqList, 4, 0);

	////delete element
	//ElemType delElem;
	//DeleteDataAtIndex(&sqList, 5, &delElem);
	//printf("\nThe element %d is deleted.", delElem);


	//printf("1,3-> %d\n", compare(1, 3));
	//printf("3,3-> %d\n", compare(3, 3));
	//printf("5,3-> %d\n", compare(5, 3));

	////locate
	//int index = LocateElemSq(&sqList, 169, compare);
	//printf("locate index is %d.", index);

	////sort data
	//SortListData(&sqList, 1);

	////merge data
	//printf("**********merge data test**********");

	//SqList sqListA;
	//SqList sqListB;
	//SqList sqListC;

	//InitListSq(&sqListA);
	//InitListSq(&sqListB);
	//AssignListSqWithRandomInteger(&sqListA, 6, 1000);
	//AssignListSqWithRandomInteger(&sqListB, 8, 1000);
	//SortListData(&sqListA, 1);
	//SortListData(&sqListB, 1);

	//printf("\n**********sqListA result**********");
	//DisplaySqListValues(&sqListA);
	//printf("\n**********sqListB result**********");
	//DisplaySqListValues(&sqListB);
	//MergeTwoList(sqListA, sqListB, &sqListC);
	//printf("\n**********sqListC result**********");
	//DisplaySqListValues(&sqListC);

	//quick sort method
	printf("\n**********quick sort method**********");
	SqList sqListPartition;
	InitListSq(&sqListPartition);
	AssignListSqWithRandomInteger(&sqListPartition, 8, 500);
	printf("\nbefore Partition:");
	DisplaySqListValues(&sqListPartition);
	int returnIndex = QSort(&sqListPartition, 0, sqListPartition.length - 1);
	printf("\nbefore Partitioned:");
	DisplaySqListValues(&sqListPartition);
	printf("\nthe return index: %d", returnIndex);


	return 0;
}


Status InsertDataAtIndex(SqList* sqList, int index, ElemType elem) {
	//display data
	printf("\nbefore insert:");
	DisplaySqListValues(sqList);
	//insert data
	ListInsertSq(sqList, index, elem);
	//display data
	printf("\nafter inserted:");
	DisplaySqListValues(sqList);

	printf("\n");

	return OK;
}

Status DeleteDataAtIndex(SqList* sqList, int index, ElemType *elem) {
	//display data
	printf("\nbefore delete:");
	DisplaySqListValues(sqList);
	//delete data
	ListDeleteSq(sqList, index, elem);
	//display data
	printf("\nafter deleted:");
	DisplaySqListValues(sqList);
	printf("\n");
	return OK;
}

Status SortListData(SqList* sqList, OrderType orderType) {
	//display data
	printf("\nbefore Sort:");
	DisplaySqListValues(sqList);
	//delete data
	SortListMyIdeaSq(sqList, orderType);
	//display data
	printf("\nafter Sorted:");
	DisplaySqListValues(sqList);
	printf("\n");
	return OK;
}

void MergeTwoList(SqList sqListA, SqList sqListB, SqList* pSqListC) {
	MergeListSq(sqListA, sqListB, pSqListC);
}