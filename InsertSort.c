//
// Created by xiongy on 2023/8/24.
//
#include <stdio.h>

void InsertSort(int [], int);

void InsertSort(int A[], int n) {
    int i,j,temp;
    for(i=1;i<n;i++){
        if(A[i]<A[i-1]){
            temp = A[i];
            for(j=i-1; j>=0 && A[j]>temp; j--){
                A[j+1] = A[j];
            }
            A[j+1] = temp;
        }
    }
}

void BinaryInsertSort(int A[], int n){
    int i,j,low,high,mid,temp;
    for(i=1;i<n;i++){
        temp = A[i];
        low = 0;
        high = i-1;
        while(low<=high){
            mid = (low+high)/2;
            if(A[mid]>temp){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        for(j=i-1;j>=low;j--){
            A[j+1]= A[j];
        }
        A[low] = temp;

    }



}

int main(){
    int A[] = {49,38,65,97,76,13,27,49};
//    InsertSort(A,8);
    BinaryInsertSort(A, 8);
    for(int i = 0 ; i< sizeof(A)/sizeof(int);i++){
        printf("%d ",A[i]);
    }
}




