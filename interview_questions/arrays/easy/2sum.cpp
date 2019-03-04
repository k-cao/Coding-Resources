#include <iostream>
#include <utility>
#include <map>
#include <vector>

using namespace std;

// Find indices of 2 numbers which add up to target (assume sets of numbers)
// Time complexity: O(n)
// Aux Space complexity: O(n)
vector< pair<int, int> > two_sum(int* arr, unsigned int arr_size, int target)
{
    map<int, int> num_to_pair;
    vector< pair<int, int> > pairs;

    for ( unsigned int i = 0; i < arr_size; i++ )
    {
        if ( num_to_pair.find( target - arr[i] ) == num_to_pair.end() )
        {
            num_to_pair[ arr[i] ] = i; // val to index, could be useful for elems after
        }
        else
        {
            pairs.push_back( pair<int, int> ( num_to_pair[ target - arr[i] ], i ) );
        }
    }

    return pairs;
}

// Find 2 numbers which add up to target (assume sets of numbers)
// Time complexity: O(nlog n)
// Aux Space complexity: O(1)
void two_sum_sorted(int* arr, unsigned int arr_size, int target)
{
    sort( arr, arr + arr_size );

    int* low = arr;
    int* high = arr + (arr_size - 1);

    while ( low < high )
    {
        int possible_target = *low + *high;
        if ( possible_target == target )
        {
            cout << *low << " " << *high << endl;

            low++;
            high--;
        } 
        else if ( possible_target < target )
            low++;
        else
            high--;
    }
}

int main()
{
    int arr[] = { -3, 4, 7, 3, 2, -6 };
    int arr_size = sizeof( arr ) / sizeof( *arr );

    vector< pair<int, int> > pairs = two_sum(arr, arr_size, 1);

    for ( auto& pair : pairs )
        cout << pair.first << " " << pair.second << endl;

    cout << endl;

    two_sum_sorted(arr, arr_size, 1);
}