#include <iostream>
#include <algorithm>

using namespace std;

void display_arr(int* arr, unsigned int arr_size)
{
    for ( unsigned int i = 0; i < arr_size; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Return digits array which has been incremented
// Time complexity: O(n)
// Aux Space complexity: O(1)
int* increment(int* digits, unsigned int arr_size)
{
    for ( int i = arr_size - 1; i > -1; i-- )
    {
        if ( digits[i] < 9 )
        {
            digits[i]++;
            return digits;
        }

        digits[i] = 0; // continue to moveup
    }

    // additional digit at beginning
    int *additional = new int[ arr_size + 1 ];
    additional[0] = 1;
    copy( digits, digits + arr_size, additional + 1 );

    return additional;
}

int main()
{
    int zero[] = { 0 };
    display_arr(increment(zero, 1), 1);

    int digits[] = { 1, 0, 5, 6 };
    display_arr(increment(digits, 4), 4);

    int moveup[] = { 9, 9, 9, 9 };
    display_arr(increment(moveup, 4), 5);
}