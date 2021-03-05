#include <stdio.h>

void Swap(int arr[], int idx1, int idx2) {
    int temp;
    temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right) {
    // int pivot = arr[left];  // 피벗의 위치는 가장 왼쪽 !
    // int low = left + 1;
    // int high = right;

    int pivot;
    int low = left;
    int high = right;
    int mid = (left+right) / 2;

    if (arr[left] >= arr[mid]) {
        if (arr[mid] >= arr[right])         // right < mid < left
            pivot = arr[mid];
        else if (arr[left] <= arr[right])   // mid < left < right
            pivot = arr[left], low++;
        else                                // mid < right < left
            pivot = arr[right], high--;
    }
    else if (arr[left] >= arr[right])       // right < left < mid
        pivot = arr[left], low++;
    else if (arr[right] <= arr[mid])        // left < right < mid
        pivot = arr[right], high--;
    else                                    // left < mid < right
        pivot = arr[mid];

    while (low <= high) {   // 교차되지 않을 때까지 반복
        // 피벗보다 큰 값을 찾는 과정
        while (pivot >= arr[low] && low <= right)
            low++;
        
        // 피벗보다 작은 값을 찾는 과정
        while (pivot <= arr[high] && high >= (left+1))
            high--;
        
        // 교차되지 않은 상태라면 Swap 실행
        if (low <= high)
            Swap(arr, low, high);
    }

    Swap(arr, left, high);
    return high;
}

void QuickSort(int arr[], int left, int right) {
    if (left <= right) {
        int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot-1);
        QuickSort(arr, pivot+1, right);
    }
}

int main(void) {
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    // int arr[3] = {3, 3, 3};

    int len = sizeof(arr) / sizeof(int);
    int i;

    QuickSort(arr, 0, len - 1);

    for (i=0 ; i < len ; i++)
        printf("%d ", arr[i]);
    printf("\n");
}