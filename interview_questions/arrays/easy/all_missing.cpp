#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void display_arr(int* arr, unsigned int arr_size)
{
    for ( unsigned int i = 0; i < arr_size; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Return all missing numbers in an array which should contain all nums from 1 - arr_size
// Time complexity: O(n)
// Aux Space complexity: O(1)
vector<int> missing_nums(int *arr, unsigned int arr_size)
{
    vector<int> missing;
    for ( unsigned int i = 0; i < arr_size; i++ )
    {
        unsigned int index = abs(arr[i]) - 1;
        if ( arr[index] > 0 )
            arr[index] = -arr[index];
    }

    display_arr(arr, arr_size);

    for ( unsigned int i = 0; i < arr_size; i++ )
    {
        if ( arr[i] > 0 )
            missing.push_back(i + 1);
    }

    return missing;
}

int main()
{
    int arr[] = { 6, 6, 1, 2, 2, 3 };

    // 6 -> mark index 5 as neg
    // 1 -> mark index 0 as neg
    // 2 -> mark index 1 as neg
    // 3 -> mark index 2 as neg
    // non-neg indices 3, 4 -> missing nums 4, 5
    vector<int> missing = missing_nums(arr, 6);
    for ( auto const& item : missing )
        cout << item << endl;
}