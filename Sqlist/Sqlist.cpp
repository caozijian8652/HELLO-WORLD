#include<stdio.h>
#define LIST_INIT_SIZE 100 //顺序表存储空间的初始分配量
#define LISTINCREMENT 10//顺序表存储空间的分配增量
#define ElemType int
#include<stdlib.h>
#define OK 1
#define overflow -2
#define TURE 1
#define ERRO 0
typedef struct{
                                        ElemType *elem;//存储空间基址
                                        int length ;//当前长度
                                        int listsize;//当前分配的存储容量
                            }SqList;//顺序表定义
int InitList_Sq(SqList &L)//构造一个空的顺序表L
{
            L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));//初试分配100个int 字长
            if(! L.elem)
            exit(overflow);//存储分配失败
            L.length = 0;    //空表长度为零
            L.listsize = LIST_INIT_SIZE;//初始存储量
            return 1;
}//初始化
int DestroyList(SqList &L)
{
        free(L.elem);
        L.elem= NULL;
}
int ClearList(SqList &L)
{
        if (!L.elem)
        {
                L.length = 0;
        }
}
int ListEmpty(Sqlist &L)
{
        if (L.elem)
        {
                if(L.length == 0)
                {
                        return TURE;
                }
                else{
                        return ERRO;
                }
        }
}
int ListLength(SqList &L)
{
        return L.length;
}
void outsed(SqList &L,ElemType e)
{
            printf("%d ",L.elem[e - 1]);
}
int ListAdd_Sq(SqList &L,int i ,ElemType e)//e用来传输赋值，i表示对第几个赋值
{
        L.elem[i - 1] = e;
        L.length ++;
}
int  ListInsert_Sq(SqList &L, int i ,ElemType e)
{
        ElemType   *newbase;
        ElemType   *p;
        //在顺序表L中第i个位置之前插入新元素e
        //i的合法值为1<=i<=ListLength_Sq(L)+1
        if(i < 1||i > L.length + 1)
        {
                return ERRO;
        }//i值不合法
        if (L.length >= L.listsize)//当前储存空间已满，增加分配
        {
               newbase = (ElemType *)realloc(L.elem,(L.listsize + LISTINCREMENT)*sizeof(ElemType));//newbase未声明
                if(!newbase)
                {
                        exit(overflow);//存储分配失败
                }
                L.elem = newbase;
                L.listsize += LISTINCREMENT;
        }
        ElemType *q = &(L.elem[i - 1]);
       for(p = &(L.elem[L.length-1]); p >= q; --p)
        {
                    *(p + 1) = *p;
        }
        *q = e;
        ++L.length;
        return OK;
}//ListInsert_Sq
int ListDelete_Sq(SqList &L,int i,int &e)
{
            if (i < 1 || i > L.length)//删除范围在1～length 之间
            {
                    printf("ListDelete ERRO ");
                    return ERRO;
            }
            for (e = *(L.elem + i - 1); i  <= L.length ; i ++ )
            {
                    *(L.elem + i - 1) = *(L.elem + i );
            }
            L.length -- ;
}
void ListDeleteMin_Sq(SqList &L,ElemType &A)//由A返回
{
        int Sq_min = 0 ;//最小值下标
        int e;

        for (int i = 1 ; i < L.length ;i ++ )//找出最小值的下标
        {
                if (L.elem[i] < L.elem[Sq_min])
                {
                                Sq_min = i;
                }
        }
        Sq_min ++;
        A = L.elem[Sq_min - 1];
        L.elem[Sq_min - 1] = L.elem[L.length - 1];
}
void List_Rerserve(SqList &L)
{
        int a ;
        for (int i = 0 ;i <= L.length/2 ; i++)
        {
                a = L.elem[i];
                L.elem[i] = L.elem[L.length - i -1];
                L.elem[L.length - i - 1] = a;
        }
}
int  main()
{
            SqList a;
            InitList_Sq(a);//顺序表初始化操作
            for (int i = 1 ; i <= 5 ; i++ )
            {
                    ListAdd_Sq(a,i, i);
            }
            int e;
            List_Rerserve(a);
            for (int i = 1 ; i <= 10 ;i ++)
            {
                    outsed(a,i);
            }
}



