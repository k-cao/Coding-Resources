#include <iostream>

using namespace std;

// Return index of elem if found or where it should be inserted in sorted array
// Time complexity: O(log n)
// Aux Space complexity: O(1)
unsigned int get_index(int* arr, unsigned int arr_size, int elem)
{
    unsigned int low = 0;
    unsigned int high = arr_size - 1;

    while ( low <= high )
    {
        unsigned int mid = (low + high) / 2;

        if ( arr[mid] == elem )
            return mid;
        else if ( arr[mid] < elem )
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    int arr[] = { -6, -6, -6, 0, 1, 1, 2, 5, 6, 6, 8, 9, 9 }; // sorted array
    int arr_size = sizeof( arr ) / sizeof( *arr );

    cout << get_index(arr, arr_size, 3) << endl;

    cout << get_index(arr, arr_size, 7) << endl;

    cout << get_index(arr, arr_size, 10) << endl;

    cout << get_index(arr, arr_size, -7) << endl;
}