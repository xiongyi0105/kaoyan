//
// Created by xiongy on 2023/8/24.
//
#include <stdlib.h>
#include <stdio.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BST;

// 插入节点
int BSTInsert(BST *, int);

void CreateBST(BST *, int[], int);

BSTNode *BSTSearch(BST, int);


int BSTInsert(BST *bstP, int d) {
    // 出口
    // 找到NULL节点时，创建新节点，加入二叉排序树，并返回1
    if (*bstP == NULL) {
        *bstP = (BSTNode *) malloc(sizeof(BSTNode));
        (*bstP)->data = d;
        (*bstP)->lchild = NULL;
        (*bstP)->rchild = NULL;
        return 1;
    }
        // 公式
        // 所指节点与待插入数相等时 返回0；所指节点小于待插入数时，向右子树插入。反之向左子树插入。
    else if ((*bstP)->data == d) {
        return 0;
    } else if ((*bstP)->data < d) {
        return BSTInsert(&(*bstP)->rchild, d);
    } else {
        return BSTInsert(&(*bstP)->lchild, d);
    }
}

void CreateBST(BST *bstP, int data[], int n) {
    // 向一颗空树中按数组序列循环添加节点。
    *bstP = NULL;
    int i = 0;
    while (i < n) {
        BSTInsert(bstP, data[i]);
        i++;
    }
}

BSTNode *BSTSearch(BST p, int data) {
    while (p != NULL && p->data != data) {
        if (p->data < data) {
            p = p->rchild;
        } else {
            p = p->lchild;
        }

    }
    return p;
}

int main(int argc, char const *argv[]) {
    int n = 5;
    int data[] = {4, 7, 6, 5, 10};
    BST *BstRootP = (BST *) malloc(sizeof(BST *));
    CreateBST(BstRootP, data, n);
    BSTNode *found = BSTSearch(*BstRootP, 121);
    if (found) {
        printf("%d", found->data);

    } else {
        printf("NULL");
    }
    return 0;
}

