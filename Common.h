#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#pragma warning (disable:4996)
#include <string.h>
//#include<vld.h>  //ÓÃÓÚÄÚ´æÐ¹Â©µÄ¼ì²â

#define ElemType int
void Swap(ElemType *a, ElemType *b)
{
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}

#endif /* _COMMON_H_ */