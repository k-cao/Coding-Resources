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

// Rotate array by shifting to the right
// Time complexity: O(n)
// Aux Space complexity: O(d)
void rotate_arr_tmp(int *arr, unsigned int arr_size, int right_shift)
{
    right_shift %= arr_size;

    int tmp_arr[arr_size - right_shift + 1];

    unsigned int end_index = arr_size - right_shift;
    for (unsigned int i = 0; i < end_index; i++)
        tmp_arr[i] = arr[i];

    for (unsigned int i = 0; i < right_shift; i++)
        arr[i] = arr[end_index + i];
    
    for (unsigned int i = right_shift; i < arr_size; i++)
        arr[i] = tmp_arr[i - right_shift];
}

void reverse_arr(int *arr, unsigned int beginning, unsigned int after_end)
{
    for ( unsigned int i = beginning; i < after_end; i++ )
    {
        int tmp = arr[i];
        unsigned int paired_index = after_end - 1 - (i - beginning);
        arr[i] = arr[paired_index];
        arr[paired_index] = tmp;
    }
}

// Rotate array by shifting to the right
// Time complexity: O(n)
// Aux Space complexity: O(1)
void rotate_arr_in_place(int *arr, unsigned int arr_size, int right_shift)
{
    right_shift %= arr_size;

    reverse_arr(arr, right_shift, arr_size);
    reverse_arr(arr, 0, right_shift);
    reverse_arr(arr, 0, arr_size);
}

int main()
{
    int arr_seven[] = { 1, 2, 3, 4, 5, 6, 7 };
    rotate_arr_tmp(arr_seven, 7, 3);
    display_arr(arr_seven, 7);

    int arr_seven_mod[] = { 1, 2, 3, 4, 5, 6, 7 };
    rotate_arr_tmp(arr_seven_mod, 7, 3);
    display_arr(arr_seven_mod, 7);
}