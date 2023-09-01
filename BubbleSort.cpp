#include <stdlib.h>
#include <stdio.h>

void swap(int &a, int &b);
void BubbleSort(int[], int);

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int A[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (j = n - 1; j > 0; j--)
        {
            if (A[j - 1] > A[j])
            {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        }
        if (!flag)
        {
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    int A[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    BubbleSort(A, 8);
    int i;
    for (i = 0; i < 8; i++)
    {
        printf("%5d", A[i]);
    }
    return 0;
}
