#include <stdlib.h>
#include <stdio.h>

typedef struct BSTNode {
    int data;
    struct BSTNode *l_child, *r_child;
} BSTNode, *BST;

// 插入节点
int BSTInsert(BST *, int);

void CreateBST(BST *, int[], int);

BSTNode *BSTSearch(BST, int);

BSTNode *BSTRecursiveSearch(BST, int);

void BSTInOrder(BST);


int BSTInsert(BST *bst_pointer, int d) {
    // 出口
    // 找到NULL节点时，创建新节点，加入二叉排序树，并返回1
    if (*bst_pointer == NULL) {
        *bst_pointer = (BSTNode *) malloc(sizeof(BSTNode));
        (*bst_pointer)->data = d;
        (*bst_pointer)->l_child = NULL;
        (*bst_pointer)->r_child = NULL;
        return 1;
    }
        // 公式
        // 所指节点与待插入数相等时 返回0；所指节点小于待插入数时，向右子树插入。反之向左子树插入。
    else if ((*bst_pointer)->data == d) {
        return 0;
    } else if ((*bst_pointer)->data < d) {
        return BSTInsert(&(*bst_pointer)->r_child, d);
    } else {
        return BSTInsert(&(*bst_pointer)->l_child, d);
    }
}

void CreateBST(BST *bst_pointer, int data[], int n) {
    // 向一颗空树中按数组序列循环添加节点。
    *bst_pointer = NULL;
    int i = 0;
    while (i < n) {
        BSTInsert(bst_pointer, data[i]);
        i++;
    }
}

BSTNode *BSTSearch(BST bst, int data) {
    // 循环比对值，比对成功或为NULL时退出
    while (bst != NULL && bst->data != data) {
        if (bst->data < data) {
            bst = bst->r_child;
        } else {
            bst = bst->l_child;
        }

    }
    return bst;
}

BSTNode *BSTRecursiveSearch(BST bst, int data) {
    // 递归查找
    if (bst == NULL) {
        return bst;
    }
    if (bst->data == data) {
        return bst;
    } else if (bst->data < data) {
        return BSTRecursiveSearch(bst->r_child, data);
    } else {
        return BSTRecursiveSearch(bst->l_child, data);
    }
}

void BSTInOrder(BST bst) {
    // 二叉排序树的中序遍历，是从小到大输出的
    if (bst != NULL) {
        BSTInOrder(bst->l_child);
        printf("%d\n", bst->data);
        BSTInOrder(bst->r_child);
    }
}

int IsBST(BST bst, int low, int high) {
    // 判断是否为二叉排序树，对每个节点递归比较大小，设置无限小和无限大两个游标。
    if (bst == NULL) {
        return 1;
    }
    if (bst->data <= low && bst->data >= high) {
        return 0;
    }
    int l = IsBST(bst->l_child, low, bst->data);
    int r = IsBST(bst->r_child, bst->data, high);
    return l && r;
}


int main(int argc, char const *argv[]) {
    int n = 5;
    int data[] = {4, 7, 6, 5, 10};

    // 构造二叉排序树
    BST *bst_root_pointer = (BST *) malloc(sizeof(BST *));
    CreateBST(bst_root_pointer, data, n);

    // 按值搜索二叉排序树
    // BSTNode *found_bst = BSTSearch(*bst_root_pointer, 121);
    BSTNode *found_bst = BSTRecursiveSearch(*bst_root_pointer, 6);
    if (found_bst) {
        printf("%d\n", found_bst->data);

    } else {
        printf("NULL\n");
    }

    // 中序遍历，从小到大输出
    BSTInOrder(*bst_root_pointer);
    // 判断是否为二叉排序树
    printf("%d",IsBST(*bst_root_pointer,INT_MIN,INT_MAX));
    return 0;
}

