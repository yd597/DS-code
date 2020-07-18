#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"Common.h"

#define SEQLIST_DEFAULT_SIZE 8

//定义顺序表的结构
typedef struct SeqList
{
	ElemType *base;
	size_t    capacity;
	size_t    size;
}SeqList;

void SeqListInit(SeqList *plist);
void SeqListDestroy(SeqList *plist);
void SeqListPushBack(SeqList *plist, ElemType x);
void SeqListPushFront(SeqList *plist, ElemType x);
void SeqListShow(SeqList *plist);

void SeqListPopBack(SeqList *plist);
void SeqListClear(SeqList *plist);
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x);
void SeqListSort(SeqList *plist);
void SeqListPopFront(SeqList *plist);

size_t SeqListLength(SeqList *plist);
void SeqListReverse(SeqList *plist);
int SeqListFind(SeqList *plist, ElemType x);
bool SeqListEraseByPos(SeqList *plist, int pos);
void SeqListErase_val(SeqList *plist, ElemType x);

/////////////////////////////////////////////////////////////////////////////////
void SeqListPopFront(SeqList *plist);
bool SeqListInsertByVal(SeqList *plist, ElemType x);
//////////////////////////////////////////////////////////////////////////////////
bool _Inc(SeqList *plist, size_t new_capacity)
{
	assert(plist != NULL &&  new_capacity > plist->capacity);
	ElemType *new_base = (ElemType *)realloc(plist->base, sizeof(ElemType)*new_capacity);
	if (new_base == NULL)
	{
		return false;
	}
	plist->base = new_base;
	plist->capacity = new_capacity;
	return true;
}
int SeqListCapacity(SeqList *plist)
{
	return plist->capacity;
}

bool IsFull(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size >= plist->capacity;
}
bool IsEmpty(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size == 0;
}

void SeqListInit(SeqList *plist)
{
	assert(plist != NULL);
	plist->capacity = SEQLIST_DEFAULT_SIZE;
	plist->base = (ElemType*)malloc(sizeof(ElemType) * plist->capacity);
	plist->size = 0;
}

void SeqListDestroy(SeqList *plist)
{
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = plist->size = 0;
}

void SeqListPushBack(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist,plist->capacity *2))//
	{
		printf("顺序表已满，%d 不能头部插入.\n", x);
		return;
	}
	plist->base[plist->size++] = x;
}

void SeqListPushFront(SeqList *plist, ElemType x)//尾插
{
	assert(plist != NULL);
	//判满
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))//
	{
		printf("顺序表已满，%d 不能尾部插入.\n", x);
		return;
	}
	//头插
	for (size_t i = plist->size; i>0; --i)
		plist->base[i] = plist->base[i - 1];
	plist->base[0] = x;
	plist->size++;
}

void SeqListShow(SeqList *plist)//显示
{
	assert(plist != NULL);
	for (size_t i = 0; i<plist->size; ++i)
		printf("%d ", plist->base[i]);
	printf("\n");
}

size_t SeqListLength(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size;
}

void SeqListPopBack(SeqList *plist)//尾删
{
	assert(plist != NULL);
	//判空
	if (IsEmpty(plist))
	{
		printf("顺序表已空,不能尾部删除.\n");
		return;
	}
	plist->size--;
}
void SeqListPopFront(SeqList *plist)//头删
{
	assert(plist != NULL);
	//判空
	if (IsEmpty(plist))
	{
		printf("顺序表已空,不能头部删除.\n");
		return;
	}
	for (size_t i = 0; i < plist->size; ++i)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;

}

void SeqListClear(SeqList *plist)//清空
{
	assert(plist != NULL);
	plist->size = 0;
}

bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x)//
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("顺序表已满,%d 不能在 %d 位置插入.\n", x, pos);
		return false;
	}
	if (pos<0 || pos>plist->size)
	{
		printf("要插入的位置[%d]是非法位置, %d 不能插入.\n", pos, x);
		return false;
	}

	for (size_t i = plist->size; i>pos; --i)
		plist->base[i] = plist->base[i - 1];
	plist->base[pos] = x;
	plist->size++;

	return true;
}
bool SeqListEraseByPos(SeqList *plist, int pos)//已修改
{
	assert(plist != NULL);
	
	while (pos < plist->size)
	{
		plist->base[pos] = plist->base[pos+1];
		pos++;
	}
	plist->size--;

	return true;
}


void SeqListSort(SeqList *plist)//排序
{
	assert(plist != NULL);
	for (size_t i = 0; i<plist->size - 1; ++i)
	{
		for (size_t j = 0; j<plist->size - i - 1; ++j)
		{
			if (plist->base[j] > plist->base[j + 1])
				Swap(&plist->base[j], &plist->base[j + 1]);
		}
	}
}
void SeqListReverse(SeqList *plist)//倒置
{
	assert(plist != NULL);
	size_t i = 0;
	size_t j = plist->size - 1;
	while (i<j )
	{
		Swap(&plist->base[i], &plist->base[j]);
		++i; 
		--j;
	}

}
int SeqListFind(SeqList *plist, ElemType x )//查找
{
	assert(plist != NULL);
	size_t i = 0;
	if (IsEmpty(plist))
	{
		printf("顺序表已空,不能进行查找.\n");
		
		
	}
	
	for(;i<plist->size;++i)
	{
		if (plist->base[i] == x)
		{
			printf("查找成功！ ");
			return i;
			
		}
				
	}
	
	printf("查无此数");
	
	return -1;
	
}
int Search(SeqList *plist, ElemType a)
{
	assert(plist != NULL);
	size_t i = 0;
	if (IsEmpty(plist))
	{
		printf("顺序表已空,不能进行查找.\n");


	}

	for (; i<plist->size - 1; ++i)
	{
		if (plist->base[i] == a)
		{
			//	printf("查找成功！ ");
			return i;

		}

	}

	//printf("查无此数");

	return -1;

}
void SeqListErase_val(SeqList *plist, ElemType x)//按值删除
{
	assert(plist != NULL);
	SeqListSort(plist);
	int i = Search(plist, x);
	if (i >= 0)
	{
		while(i< plist->size)
		{
			plist->base[i] = plist->base[i+ 1];
			i++;
		}
		
		plist->size--;
		printf("檫除成功！");
	}
	else
	{
		printf("你要檫除的数不存在");
	}

}
bool SeqListinsert_val(SeqList *plist, ElemType x)//按值插入;已修改
 {
	 assert(plist != NULL);
	
	 if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("顺序表已满,%d 不能插入.\n",  x);
		return false;
	}
	SeqListSort(plist);
	size_t i = plist->size-1;
	while (i>0 && (x<plist->base[i]))
	{
		plist->base[i+1] = plist->base[i];
		--i;
	}
	plist->base[i+1] = x;
	plist -> size++;
	printf("插入成功！");
 }


#endif /* _SEQLIST_H_ */