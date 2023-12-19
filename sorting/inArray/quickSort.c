#include <stdio.h>
// T.C => best, avg= O(nlogn) ,worst = O(n^2)
// S.C => O(1)
//use when elements are in random shuffle and not in nearly sorted, already sorted or array having same elements..
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
void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
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
    quickSort(arr, 0, n - 1);
    printf("\nSorted array is : ");
    printArray(arr, n);
}