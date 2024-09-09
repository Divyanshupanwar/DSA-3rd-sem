



#include <stdio.h>

int findOddOccurrence(int arr[], int n) {
    int result = 0;  // Initialize result

    for (int i = 0; i < n; i++) {
        result ^= arr[i];  // XOR all elements
    }

    return result;  // The result will be the number with odd occurrences
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the array elements
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the number with odd occurrences
    int oddOccurrence = findOddOccurrence(arr, n);
    
    // Output the result
    printf("The number with odd occurrences is: %d\n", oddOccurrence);

    return 0;
}
