#include <iostream>

using namespace std;

// Return 3rd largest elem in array
// Time complexity: O(n)
// Aux Space complexity: O(1)
int third_largest(int *arr, unsigned int arr_size)
{
    if ( arr_size < 1 )
        return -1;

    int *max = NULL, *max_2 = NULL, *max_3 = NULL;

    for ( unsigned int i = 0; i < arr_size; i++ )
    {
        int cur = arr[i];

        if ( max == NULL || cur > *max )
        {
            if ( max != NULL )
            {
                if ( max_2 != NULL )
                    max_3 = max_2;
                max_2 = max;
            }
            max = &arr[i];
        }
        else if ( cur < *max )
        {
            if ( max_2 == NULL || cur > *max_2 )
            {
                if ( max_2 != NULL )
                    max_3 = max_2;
                max_2 = &arr[i];
            } else if ( cur < *max_2 && (max_3 == NULL || cur > *max_3) )
                max_3 = &arr[i];
        }
    }

    if ( max_3 == NULL )
    {
        if ( max_2 == NULL )
            return *max;
        else
            return *max_2;
    }

    cout << "max: " << *max << " max_2: " << *max_2 << endl;
    return *max_3;
}

int main()
{
    int arr1[] = { 5, 6, 1, 6, 5, 4, 9 };
    cout << third_largest(arr1, 7) << endl;

    int arr2[] = { 2, 2, 1 };
    cout << third_largest(arr2, 3) << endl;

    int arr3[] = { 2 };
    cout << third_largest(arr3, 1) << endl;
}