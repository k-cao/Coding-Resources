#include <iostream>

using namespace std;

// Remove instances of elem from array in-place
// Time complexity: O(n)
// Aux Space complexity: O(1)
unsigned int rm_instances(int* arr, unsigned int arr_size, int elem)
{
    unsigned int slow = 0;
    for ( unsigned int fast = 0; fast < arr_size; fast++ )
    {
        if ( arr[fast] != elem )
            arr[slow++] = arr[fast];
    }
    
    return slow; // length of new array without duplicates
}

int main()
{
    int arr[] = { 1, -3, 2, 4, -3, -3, 1, 2, -3 };
    int arr_size = sizeof( arr ) / sizeof( *arr );

    unsigned int new_arr_size = rm_instances(arr, arr_size, -3);

    for ( unsigned int i = 0; i < new_arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
}