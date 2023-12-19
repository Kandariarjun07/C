#include <stdio.h>
// T.C => best = O(n), Avg and worst = O(n^2)
// S.C => O(1)
// used for less elements as complexity is high
void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag)
            break;
    }
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
    bubbleSort(arr, n);
    printf("\nSorted array is : ");
    printArray(arr, n);
}