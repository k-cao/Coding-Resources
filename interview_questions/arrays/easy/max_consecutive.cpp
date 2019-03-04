#include <iostream>
#include <algorithm>

using namespace std;

// Return the number of consecutive 1s in an arr
// Time complexity: O(n)
// Aux Space complexity: O(1)
int longest_consecutive(int *arr, unsigned int arr_size)
{
    unsigned int max_num_consecutive = 0, cur_num_consecutive = 0;
    for ( unsigned int i = 0; i < arr_size; i++ )
    {
        int cur = arr[i];
        if ( cur != 1 )
            cur_num_consecutive = 0;
        else
            cur_num_consecutive += 1;

        max_num_consecutive = max(max_num_consecutive, cur_num_consecutive);
    }

    return max_num_consecutive;
}

int main()
{
    int arr1[] = { 1, 1, 1, 1 };
    cout << longest_consecutive(arr1, 4) << endl;

    int arr2[] = { 1, 1, 0, 1 };
    cout << longest_consecutive(arr2, 4) << endl;

    int arr3[] = { 1, 1, 0, 0, 1, 1, 1, 0, 1, 1 };
    cout << longest_consecutive(arr3, 10) << endl;

    int arr4[] = { 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1 };
    cout << longest_consecutive(arr4, 15) << endl;
}