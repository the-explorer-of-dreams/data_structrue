#include <stdlib.h>
int GetRandomInteger(int seedNum) {
	return rand() % seedNum;//�������������0~m-1֮��
}