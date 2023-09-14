#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *PLNode;

typedef struct
{
    PLNode head;
    PLNode tail;
} LinkList;

void InitList(LinkList &);
bool IsEmpty(LinkList);
void PrintList(LinkList);
void InsertFirstNode(LinkList &, int);
void CreateListByHead(LinkList &);
PLNode GetElem(LinkList, int);
bool DeleteByHead(LinkList &, int &);
bool ListInsert(LinkList &, int, int);
bool InsertNextNode(LinkList &, PLNode, int);
bool ListDelete(LinkList &, int, int &);

int main(int argc, char const *argv[])
{
    LinkList L;
    int val;
    CreateListByHead(L);
    PrintList(L);
    ListInsert(L, 1, 200);
    ListInsert(L, 4, 300);
    PrintList(L);
    DeleteByHead(L, val);
    PrintList(L);
    ListDelete(L, 1, val);
    ListDelete(L, 1, val);
    ListDelete(L, 1, val);
    ListDelete(L, 1, val);
    PrintList(L);
}

void InitList(LinkList &L)
{
    L.head = L.tail = (PLNode)malloc(sizeof(LNode));
    L.head->next = NULL;
}

bool IsEmpty(LinkList L)
{
    return L.head->next == NULL && L.tail == L.tail;
}

void PrintList(LinkList L)
{
    if (IsEmpty(L))
    {
        printf("Empty List");
    }
    PLNode s = L.head->next;
    while (s != NULL)
    {
        printf("%5d", s->data);
        s = s->next;
    }
    printf("\n");
}

void CreateListByHead(LinkList &L)
{
    int x;
    InitList(L);
    scanf("%d", &x);
    while (x != -999)
    {
        InsertFirstNode(L, x);
        scanf("%d", &x);
    }
}

PLNode GetElem(LinkList L, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    PLNode p;
    int j = 0;
    p = L.head;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

bool DeleteByHead(LinkList &L, int &val)
{
    if (IsEmpty(L))
    {
        return false;
    }
    PLNode p = L.head->next;
    val = p->data;
    L.head->next = p->next;
    if (L.head->next == NULL)
    {
        L.tail = L.head;
    }
    free(p);
    return true;
}

bool ListInsert(LinkList &L, int i, int val)
{
    PLNode p = GetElem(L, i - 1);
    return InsertNextNode(L, p, val);
}

bool InsertNextNode(LinkList &L, PLNode p, int val)
{
    if (p == NULL)
    {
        return false;
    }
    PLNode s;
    s = (PLNode)malloc(sizeof(LNode));
    s->data = val;
    s->next = p->next;
    p->next = s;
    if (s->next == NULL)
    {
        L.tail = s;
    }
    return true;
}

bool ListDelete(LinkList &L, int i, int &val)
{
    if (IsEmpty(L))
    {
        return false;
    }
    PLNode p = GetElem(L, i - 1);
    if (p == NULL)
    {
        return false;
    }
    PLNode s = p->next;
    if (s == NULL)
    {
        return false;
    }
    val = s->data;
    p->next = s->next;
    if (p->next == NULL)
    {
        L.tail = p;
    }
    free(s);
    return true;
}

void InsertFirstNode(LinkList &L, int val)
{
    PLNode s;
    s = (PLNode)malloc(sizeof(LNode));
    s->data = val;
    s->next = L.head->next;
    L.head->next = s;
    if (s->next == NULL)
    {
        L.tail = s;
    }
}
