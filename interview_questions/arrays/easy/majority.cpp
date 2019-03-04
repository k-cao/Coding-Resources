#include <iostream>

using namespace std;

// Return the majority element
// Time complexity: O(n)
// Aux Space complexity: O(1)
int get_majority_elem(int *arr, unsigned int arr_size)
{
    if (arr_size < 1)
        return 0;

    int majority_elem = arr[0], count = 1;
    for ( unsigned int i = 1; i < arr_size; i++ )
    {
        if ( count == 0 )
        {
            majority_elem = arr[i];
            count++;
        }
        else
        {
            if ( majority_elem == arr[i] )
                count++;
            else
                count--;
        }
    }

    return majority_elem;
}

int main()
{
    int arr[] = { -6, -5, -5, -6, -5 };
    cout << get_majority_elem(arr, 5) << endl;
}