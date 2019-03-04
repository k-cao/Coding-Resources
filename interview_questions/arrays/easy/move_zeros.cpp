#include <iostream>

using namespace std;

void display_arr(int* arr, unsigned int arr_size)
{
    for ( unsigned int i = 0; i < arr_size; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Move 0s to end of array
// Time complexity: O(n)
// Aux Space complexity: O(1)
void move_zeros(int *arr, unsigned int arr_size)
{
    unsigned int insert_pos = 0;
    for ( unsigned int i = 0; i < arr_size; i++ )
    {
        if ( arr[i] != 0 )
            arr[insert_pos++] = arr[i];
    }
    
    for ( ; insert_pos < arr_size; insert_pos++ )
        arr[insert_pos] = 0;
}

int main()
{
    int arr[] = { 0, 1, 2, 0, 3, 0 };
    move_zeros(arr, 6);
    display_arr(arr, 6);
}