#include <stdio.h>
#include <stdlib.h>
#include "Common.h"

int main(int argc, char* argv) {
	printf("please input the data:");
	int data = 0;
	scanf_s("%d", &data);
	printf("the inputed data is:%d", data);

	return OK;
}

