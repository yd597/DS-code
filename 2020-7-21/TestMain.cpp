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
		printf("请选择:>");
		scanf("%d", &select);
		if(select == 0)
			break;
		switch(select)
		{
		case 1:
			printf("请输入要插入的数据<以-1结束>:");
			while(scanf("%d", &item), item!=-1)
			{
				SListPushBack(&list, item);
			}
			printf("头部插入数据成功......\n");
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:");
			while(scanf("%d", &item), item!=-1)
			{
				SListPushFront(&list, item);
			}
			printf("尾部插入数据成功......\n");
			break;
		case 3:
			SListShow(&list);
			break;
		case 4:
			SListPopBack(&list);
			printf("尾部删除数据成功......\n");
			break;
		case 5:
			//SListPopFront(&list);
			printf("头部删除数据成功......\n");
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的元素:>");
			scanf("%d", &item);
			//flag = SeqListInsertByPos(&list, pos, item);
			if(flag)
				printf("插入数据成功.......\n");
			else
				printf("插入数据失败.......\n");
			break;
		case 7:
			printf("请输入要插入的元素:>");
			scanf("%d", &item);
			SListSort(&list);
			SListInsertByVal(&list, item);
			printf("插入数据成功.......\n");
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListEraseByPos(&list, pos);
			printf("删除数据成功.......\n");
			break;
		case 9:
			printf("请输入要删除的元素:>");
			scanf("%d", &item);
			SListEraseByVal(&list, item);
			printf("删除数据成功.......\n");
			break;
		case 10:
			printf("请输入要查找的关键值:>");
			scanf("%d", &item);
		  p = SListFind(list, item);
			if(p == NULL)
				printf("数据查找失败.\n");
			else
				printf("数据查找成功.\n");
			break;
		case 11:
			//printf("SList Length = %d\n", SListLength(list));
			break;
		case 12:
			//printf("SeqList Capacity = %d\n", SeqListCapacity(&list));
			break;
		case 13:
			//SListSort(&list);
			printf("顺序表排序成功......\n");
			break;
		case 14:
			SListReverse(&list);
			printf("转置完成.\n");
			break;
		case 15:
			SListClear(&list);
			break;
		case 16:
			//printf("表头元素为: %d\n", SListFront(list));
			break;
		case 17:
			//printf("表尾元素为: %d\n", SListBack(list));
			break;
		case 19:
			printf("请输入要删除的元素:>");
			scanf("%d", &item);
			//SListEraseAll(&list, item);
			break;
		default:
			printf("命令出错,请重新输入......\n");
			break;
		}
		system("pause");
		system("cls");
	}

	//SListDestroy(&list); //SListClear();
	return 0;
}