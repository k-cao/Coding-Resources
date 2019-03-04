#include <iostream>

using namespace std;

// Remove duplicates from sorted array in-place
// Time complexity: O(n)
// Aux Space complexity: O(1)
unsigned int rm_duplicates(int* arr, unsigned int arr_size)
{
    unsigned int slow = 0;
    for ( unsigned int fast = 1; fast < arr_size; fast++ )
    {
        if ( arr[slow] != arr[fast] )
            arr[++slow] = arr[fast];
    }
    
    return slow + 1; // length of new array without duplicates
}

int main()
{
    int arr[] = { -6, -6, -6, 0, 1, 1, 2, 5, 6, 6, 8, 9, 9 }; // sorted array
    int arr_size = sizeof( arr ) / sizeof( *arr );

    unsigned int new_arr_size = rm_duplicates(arr, arr_size);

    for ( unsigned int i = 0; i < new_arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
}