#include <stdio.h>
// T.C => best, avg= O(nlogn) ,worst = O(n^2)
// S.C => O(1)
// use when elements are in random shuffle and not in nearly sorted, already sorted or array having same elements..
int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < pivot)
        {
            cnt++;
        }
    }
    int pIdx = s + cnt;
    int temp = arr[s];
    arr[s] = arr[pIdx];
    arr[pIdx] = temp;
    int i = s, j = e;
    while (i < pIdx && j > pIdx)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pIdx && j > pIdx)
        {
            int a = arr[i];
            arr[i] = arr[j];
            arr[j] = a;
        }
    }
    return pIdx;
}
void merge(int arr[], int s, int mid, int e)
{
    int lSize = mid - s + 1;
    int rSize = e - mid;
    int L[lSize], R[rSize];
    for (int i = 0; i < lSize; i++)
    {
        L[i] = arr[s + i];
    }
    for (int j = 0; j < rSize; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0;
    int k = s;
    while (i < lSize && j < rSize)
    {
        if (L[i] < R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i < lSize)
    {
        arr[k++] = L[i++];
    }
    while (j < rSize)
    {
        arr[k++] = R[j++];
    }
}
void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Given array is : ");
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("\nSorted array is : ");
    printArray(arr, n);
}