#include <stdlib.h>
int GetRandomInteger(int seedNum) {
	return rand() % seedNum;//將随机数控制在0~m-1之间
}