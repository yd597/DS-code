//#include"seqlist.h"
#include"slist.h"
//#include"sclist.h"

int main()
{
	//SeqList list;
	//SeqListInit(&list);

	SList list;
	SListInit(&list);
	SListNode *p = NULL;

	/*SCList list;
	SCListInit(&list);
	SCListNode *p = NULL;*/

	ElemType item;
	int pos;
	bool flag;
	int select = 1;
	while(select)
	{
		printf("*********************************************\n");
		printf("*  [1] push_back           [2] push_front   *\n");
		printf("*  [3] show_list           [0] quit_system  *\n");
		printf("*  [4] pop_back            [5] pop_front    *\n");
		printf("*  [6] insert_pos          [7] insert_val   *\n");
		printf("*  [8] erase_pos           [9] erase_val    *\n");
		printf("*  [10] find               [11] length      *\n");
		printf("*  [12] capacity           [13] sort        *\n");
		printf("*  [14] reverse            [15] clear       *\n");
		printf("*  [16] front              [17] back        *\n");
		printf("*  [18] binary_find        [19] erase_all   *\n");
		printf("*********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if(select == 0)
			break;
		switch(select)
		{
		case 1:
			printf("������Ҫ���������<��-1����>:");
			while(scanf("%d", &item), item!=-1)
			{
				SListPushBack(&list, item);
			}
			printf("ͷ���������ݳɹ�......\n");
			break;
		case 2:
			printf("������Ҫ���������<��-1����>:");
			while(scanf("%d", &item), item!=-1)
			{
				SListPushFront(&list, item);
			}
			printf("β���������ݳɹ�......\n");
			break;
		case 3:
			SListShow(&list);
			break;
		case 4:
			SListPopBack(&list);
			printf("β��ɾ�����ݳɹ�......\n");
			break;
		case 5:
			//SListPopFront(&list);
			printf("ͷ��ɾ�����ݳɹ�......\n");
			break;
		case 6:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ�����Ԫ��:>");
			scanf("%d", &item);
			//flag = SeqListInsertByPos(&list, pos, item);
			if(flag)
				printf("�������ݳɹ�.......\n");
			else
				printf("��������ʧ��.......\n");
			break;
		case 7:
			printf("������Ҫ�����Ԫ��:>");
			scanf("%d", &item);
			SListSort(&list);
			SListInsertByVal(&list, item);
			printf("�������ݳɹ�.......\n");
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			//SeqListEraseByPos(&list, pos);
			printf("ɾ�����ݳɹ�.......\n");
			break;
		case 9:
			printf("������Ҫɾ����Ԫ��:>");
			scanf("%d", &item);
			SListEraseByVal(&list, item);
			printf("ɾ�����ݳɹ�.......\n");
			break;
		case 10:
			printf("������Ҫ���ҵĹؼ�ֵ:>");
			scanf("%d", &item);
		  p = SListFind(list, item);
			if(p == NULL)
				printf("���ݲ���ʧ��.\n");
			else
				printf("���ݲ��ҳɹ�.\n");
			break;
		case 11:
			//printf("SList Length = %d\n", SListLength(list));
			break;
		case 12:
			//printf("SeqList Capacity = %d\n", SeqListCapacity(&list));
			break;
		case 13:
			//SListSort(&list);
			printf("˳�������ɹ�......\n");
			break;
		case 14:
			SListReverse(&list);
			printf("ת�����.\n");
			break;
		case 15:
			SListClear(&list);
			break;
		case 16:
			//printf("��ͷԪ��Ϊ: %d\n", SListFront(list));
			break;
		case 17:
			//printf("��βԪ��Ϊ: %d\n", SListBack(list));
			break;
		case 19:
			printf("������Ҫɾ����Ԫ��:>");
			scanf("%d", &item);
			//SListEraseAll(&list, item);
			break;
		default:
			printf("�������,����������......\n");
			break;
		}
		system("pause");
		system("cls");
	}

	//SListDestroy(&list); //SListClear();
	return 0;
}