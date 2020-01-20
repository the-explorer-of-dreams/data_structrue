#include <stdio.h>
#include "static_link_list.h"

int main(int argc, char *argv[]) {
	printf("sq_link_list example is running!");
	SLinkList sLinkList, space;
	InitSpaceSL(space);
	InitSLinkListWithRandomValue(sLinkList, space, 10);
	DisplaySLinkList(sLinkList);
	return 0;
}