#include <stdio.h>
#include <stdlib.h>

#define InitSize 10

typedef struct
{
    int *data;
    int MaxSize;
    int length;
} SeqList;

void InitSeqList(SeqList &);
void DestroySeqList(SeqList &);
void IncreaseSeqList(SeqList &, int);
bool IsEmpty(SeqList);
bool IsFull(SeqList);
void PrintSeqList(SeqList);
void Append(SeqList &, int);
bool ListInsert(SeqList &, int, int);
bool ListDelete(SeqList &, int, int &);
int GetElement(SeqList, int);
int Location(SeqList, int);

void InitSeqList(SeqList &L)
{
    L.data = (int *)malloc(sizeof(int) * InitSize);
    L.MaxSize = InitSize;
    L.length = 0;
}

void DestroySeqList(SeqList &L)
{
    free(L.data);
    L.length = 0;
    L.MaxSize = 0;
}

void IncreaseSeqList(SeqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc(sizeof(int) * (L.MaxSize + len));
    L.MaxSize += len;
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    free(p);
}

bool IsEmpty(SeqList L)
{
    return L.length == 0;
}

bool IsFull(SeqList L)
{
    return L.length == L.MaxSize;
}

void PrintSeqList(SeqList L)
{
    if (IsEmpty)
    {
        printf("Empty List!\n");
    }

    for (int i = 0; i < L.length; i++)
    {
        printf("%5d", L.data[i]);
    }
    printf("\n");
}

void Append(SeqList &L, int i)
{
    if (IsFull)
    {
        IncreaseSeqList(L, 5);
    }
    L.data[L.length] = i;
    L.length++;
}

bool ListInsert(SeqList &L, int i, int e)
{
    int j;
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    if (IsFull(L))
    {
        IncreaseSeqList(L, 5);
    }
    for (j = L.length - 1; j >= i - 1; j--)
    {
        L.data[j + 1] = L.data[j];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SeqList &L, int i, int &e)
{
    int j;
    if (i < 1 || i > L.length)
    {
        return false;
    }
    e = L.data[i - 1];
    for (j = i - 1; j < L.length; j++)
    {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}

int GetElement(SeqList L, int i)
{
    if (i < 1 || i > L.length)
    {
        return -999;
    }
    return L.data[i - 1];
}

int Location(SeqList L, int val)
{
    int i = 0;
    for (i; i < L.length; i++)
    {
        if (L.data[i] == val)
        {
            return i + 1;
        }
    }
    return -999;
}

int main(int argc, char const *argv[])
{
    SeqList L;
    int e;
    InitSeqList(L);
    PrintSeqList(L);
    Append(L, 5);
    Append(L, 4);
    Append(L, 3);
    PrintSeqList(L);
    ListInsert(L, 1, 6);
    ListInsert(L, 3, 100);
    PrintSeqList(L);
    if (ListDelete(L, 3, e))
    {
        PrintSeqList(L);
        printf("delete elem is %d\n", e);
    }
    else
    {
        printf("delete fail!\n");
    }
    if (GetElement(L, 3) != -999)
        printf("i=3,value=%d\n", GetElement(L, 3));
    else
        printf("get fail!,i is wrong!\n");
    if (Location(L, 5) != -999)
        printf("5 is in %d\n", Location(L, 5));
    else
        printf("location fail!\n");

    return 0;
}
