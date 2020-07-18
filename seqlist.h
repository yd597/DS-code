#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"Common.h"

#define SEQLIST_DEFAULT_SIZE 8

//����˳���Ľṹ
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
		printf("˳���������%d ����ͷ������.\n", x);
		return;
	}
	plist->base[plist->size++] = x;
}

void SeqListPushFront(SeqList *plist, ElemType x)//β��
{
	assert(plist != NULL);
	//����
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))//
	{
		printf("˳���������%d ����β������.\n", x);
		return;
	}
	//ͷ��
	for (size_t i = plist->size; i>0; --i)
		plist->base[i] = plist->base[i - 1];
	plist->base[0] = x;
	plist->size++;
}

void SeqListShow(SeqList *plist)//��ʾ
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

void SeqListPopBack(SeqList *plist)//βɾ
{
	assert(plist != NULL);
	//�п�
	if (IsEmpty(plist))
	{
		printf("˳����ѿ�,����β��ɾ��.\n");
		return;
	}
	plist->size--;
}
void SeqListPopFront(SeqList *plist)//ͷɾ
{
	assert(plist != NULL);
	//�п�
	if (IsEmpty(plist))
	{
		printf("˳����ѿ�,����ͷ��ɾ��.\n");
		return;
	}
	for (size_t i = 0; i < plist->size; ++i)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;

}

void SeqListClear(SeqList *plist)//���
{
	assert(plist != NULL);
	plist->size = 0;
}

bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x)//
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("˳�������,%d ������ %d λ�ò���.\n", x, pos);
		return false;
	}
	if (pos<0 || pos>plist->size)
	{
		printf("Ҫ�����λ��[%d]�ǷǷ�λ��, %d ���ܲ���.\n", pos, x);
		return false;
	}

	for (size_t i = plist->size; i>pos; --i)
		plist->base[i] = plist->base[i - 1];
	plist->base[pos] = x;
	plist->size++;

	return true;
}
bool SeqListEraseByPos(SeqList *plist, int pos)//���޸�
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


void SeqListSort(SeqList *plist)//����
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
void SeqListReverse(SeqList *plist)//����
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
int SeqListFind(SeqList *plist, ElemType x )//����
{
	assert(plist != NULL);
	size_t i = 0;
	if (IsEmpty(plist))
	{
		printf("˳����ѿ�,���ܽ��в���.\n");
		
		
	}
	
	for(;i<plist->size;++i)
	{
		if (plist->base[i] == x)
		{
			printf("���ҳɹ��� ");
			return i;
			
		}
				
	}
	
	printf("���޴���");
	
	return -1;
	
}
int Search(SeqList *plist, ElemType a)
{
	assert(plist != NULL);
	size_t i = 0;
	if (IsEmpty(plist))
	{
		printf("˳����ѿ�,���ܽ��в���.\n");


	}

	for (; i<plist->size - 1; ++i)
	{
		if (plist->base[i] == a)
		{
			//	printf("���ҳɹ��� ");
			return i;

		}

	}

	//printf("���޴���");

	return -1;

}
void SeqListErase_val(SeqList *plist, ElemType x)//��ֵɾ��
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
		printf("�߳��ɹ���");
	}
	else
	{
		printf("��Ҫ�߳�����������");
	}

}
bool SeqListinsert_val(SeqList *plist, ElemType x)//��ֵ����;���޸�
 {
	 assert(plist != NULL);
	
	 if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("˳�������,%d ���ܲ���.\n",  x);
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
	printf("����ɹ���");
 }


#endif /* _SEQLIST_H_ */