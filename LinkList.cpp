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

int main(int argc, char const *argv[])
{
    return 0;
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
    if (IsEmpty)
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
    if (i < 1)
    {
        return NULL;
    }
    PLNode p;
    int j = 1;
    p = L.head->next;
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
