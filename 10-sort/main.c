#include"sort.h"
#define LENGTH 10

int main()
{
    int arr[LENGTH];

    produce_arr(arr,LENGTH);
    printf("the original array is:\n");  
    traversal_arr(arr,LENGTH);
    printf("after the bubblesort is:\n");
    bubble_sort(arr,0,LENGTH-1);
    traversal_arr(arr,LENGTH);
    printf("\n");

    produce_arr(arr,LENGTH);
    printf("the original array is:\n");  
    traversal_arr(arr,LENGTH);
    printf("after the quicksort is:\n");
    quick_sort(arr,0,LENGTH-1);
    traversal_arr(arr,LENGTH);
    printf("\n");

    produce_arr(arr,LENGTH);
    printf("the original array is:\n");
    traversal_arr(arr,LENGTH);
    heapsort(arr,LENGTH);
    printf("after the heapsort is:\n");
    traversal_arr(arr,LENGTH);
    printf("\n");

    produce_arr(arr,LENGTH);
    printf("the original array is:\n");
    traversal_arr(arr,LENGTH);
    insersort(arr,LENGTH);
    printf("after the insertsort is:\n");
    traversal_arr(arr,LENGTH);
    printf("\n");

    produce_arr(arr,LENGTH);
    printf("the original array is:\n");
    traversal_arr(arr,LENGTH);
    shellsort(arr,LENGTH);
    printf("after the shellsort is:\n");
    traversal_arr(arr,LENGTH);
    printf("\n");
    return 0;
}