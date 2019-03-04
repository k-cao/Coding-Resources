#include <iostream>

using namespace std;

// Return the only missing number in an array of format 0, 1, 2, ..., n
// Time complexity: O(n)
// Aux Space complexity: O(1)
int find_missing(int *arr, unsigned int arr_size)
{
    int i = 0;
    int xor_elem = 0;
    for ( ; i < arr_size; i++ )
    {
        xor_elem = xor_elem ^ i ^ arr[i];
        cout << xor_elem << endl;
    }

    cout << xor_elem << " " << i << endl;
    return xor_elem ^ i;
}

int main()
{
    // expected 2 but got 3
    // 010
    // 011
    // 001 -> 1

    // offset 
    // i 3, cur 4
    // 011
    // 100
    // 111 -> 7 = 3 + 4
    // 001
    // 110 -> 6 = 7 - 1

    // offset 
    // i 4, cur 5
    // 100
    // 101
    // 001 -> 1 = 5 - 4
    // 110
    // 111 -> 7 = 1 + 6

    // 5: 101 <- arr len
    // 7: 111 <- offset 3 + 4 - 1 + 5 - 4 = 3 + 5 - 1 <- 3 offsets in an arr of size 5 => elem 2 missing
    //    010 <- 2 = 7 - 5
    int arr1[] = { 0, 1, 3, 4, 5 };
    cout << find_missing(arr1, 5) << endl;

    // 14: 00001110 <- offset
    // 12: 00001100 <- arr len
    //     00000010 <- 2 = 14 - 12
    int arr2[] = { 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    cout << find_missing(arr2, 12) << endl;
}