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

// Return merged array of 2 sorted arrays
// Time complexity: O(n)
// Aux Space complexity: O(1)
int* merge(int* a1, int* a2, unsigned int n_a1, unsigned int n_a2)
{
    int* merged_arr = new int[ n_a1 + n_a2 ];
    
    unsigned int n_min = min(n_a1, n_a2);

    unsigned int c_a1 = 0, c_a2 = 0, i = 0;
    while ( c_a1 < n_a1 && c_a2 < n_a2 )
    {
        if ( a1[c_a1] < a2[c_a2] )
            merged_arr[i] = a1[c_a1++];
        else
            merged_arr[i] = a2[c_a2++];

        i++;
    }

    for ( unsigned int j = c_a1; j < n_a1; j++ )
        merged_arr[i++] = a1[j];
    for ( unsigned int j = c_a2; j < n_a2; j++ )
        merged_arr[i++] = a2[j];

    return merged_arr;
}

int main()
{
    // sorted arrays
    int a1[] = { -1, 4, 5, 9 };
    int a2[] = { -3, 0, 6 };

    display_arr(merge(a1, a2, 4, 3), 7);
}