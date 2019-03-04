#include <iostream>
#include <algorithm>

using namespace std;

// Return highest sum of any contiguous subarray
// Time complexity: O(n)
// Aux Space complexity: O(n)
unsigned int get_max_subarr(int* arr, unsigned int arr_size)
{
    int max_sum_arr[arr_size];

    for ( unsigned int i = 0; i < arr_size; i++ )
        max_sum_arr[i] = arr[i];

    for ( unsigned int i = 1; i < arr_size; i++ )
        max_sum_arr[i] = max( max_sum_arr[i], max_sum_arr[i - 1] + max_sum_arr[i] );

    int max_sum = max_sum_arr[0];
    for ( unsigned int i = 1; i < arr_size; i++ )
    {
        int cur_sum = max_sum_arr[i];
        if ( cur_sum > max_sum )
            max_sum = cur_sum;
    }
    return max_sum;
}

int main()
{
    int arr_continuous[] = { 1, 2, 0, 5 };
    cout << get_max_subarr(arr_continuous, 4) << endl;

    int arr_broken_end[] = { 1, 2, -4, 5 };
    cout << get_max_subarr(arr_broken_end, 4) << endl;

    int arr_broken_begin[] = { 5, 6, -20, 5 };
    cout << get_max_subarr(arr_broken_begin, 4) << endl;
}