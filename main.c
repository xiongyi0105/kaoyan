//
// Created by xiongy on 2023/8/24.
//
#include <stdio.h>

void ShellSort(int [], int);

void ShellSort(int A[], int n) {
    int i, j, d, temp;
    // d为步长（增量）针对不同的步长依次对子列排序，直到步长为1时排序完成
    for (d = n / 2; d >= 1; d = d / 2)
        // 找到按步长分布的第二个元素开始直插排序
        for (i = d; i <= n; i++) {
            if (A[i] < A[i - d]) {
                temp = A[i];
                // 符合条件时，将大于待插入数的元素依次后移
                for (j = i - d; j >= 0 && A[j] > temp; j -= d) {
                    A[j + d] = A[j];
                }
                A[j + d] = temp;
            }
        }

}


int main() {
    int A[] = {49, 38, 65, 97, 76, 13, 27, 49};
    ShellSort(A, 8);
    for (int i = 0; i < sizeof(A) / sizeof(int); i++) {
        printf("%d ", A[i]);
    }
}