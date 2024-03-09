#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100




void bubbleSort(int arr[], int n, int *total_swaps, int loop)
{
    int i, j, temp;
    int swap = 0;
    int swaps_per_element[MAX_SIZE] = {0};

    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps_per_element[arr[j]]++;
                swaps_per_element[arr[j+1]]++;
                (*total_swaps)++;
                swap++;
            }
        }
    }
    printf("array%d:\n", loop);
    for (i = 0; i < n; i++) {
        printf("%d: %d of times %d swapped \n", arr[i], swaps_per_element[arr[i]], arr[i]);
    }
}

void selectionSort(int arr[], int n, int *total_swaps, int loop)
{
    int i, j, min_idx, temp;
    int swaps_per_element[MAX_SIZE] = {0}; 

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            (*total_swaps)++;
            swaps_per_element[arr[i]]++;
        }
    }
    printf("array%d:\n", loop);
    for (i = 0; i < n; i++) {
        printf("%d: %d of times %d swapped \n", arr[i], swaps_per_element[arr[i]], arr[i]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int array1[] = {97,  16,  45,  63,  13,  22,  7,  58,  72};
    int array2[] = {90,  80,  70,  60,  50,  40,  30,  20,  10};
    int n = 9;
    int total_swaps = 0;
    int temp = 0;
    int loop = 1;
    bubbleSort(array1, n, &total_swaps, loop);
    loop++;
    printf("\nTotal number of swaps performed: %d\n", total_swaps);
    temp = total_swaps;
    printf("\n");
    bubbleSort(array2, n, &total_swaps, loop);
    temp = total_swaps- temp;
    printf("\nTotal number of swaps performed: %d\n", temp);
    printf("\nTotal number of swaps performed in bubble sort: %d\n\n", total_swaps);
    int array3[] = {97,  16,  45,  63,  13,  22,  7,  58,  72};
    int array4[] = {90,  80,  70,  60,  50,  40,  30,  20,  10};
    total_swaps = 0;
    temp = 0;
    loop = 1;
    selectionSort(array3, n, &total_swaps, loop);
    loop++;
    temp = total_swaps;
    printf("\nTotal number of swaps performed: %d\n", total_swaps);
    selectionSort(array4, n, &total_swaps, loop);
    temp = total_swaps - temp;
    printf("\nTotal number of swaps performed: %d\n", temp);
    printf("\nTotal number of swaps performed in selection sort: %d\n", total_swaps);
    

    return 0;
}
