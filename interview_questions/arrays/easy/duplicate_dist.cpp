#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Find duplicates apart by at most k indices
// Time complexity: O(n)
// Aux Space complexity: O(n)
int duplicate_dist(int *arr, unsigned int arr_size, int k)
{
    map<int, vector<unsigned int> > num_index;
    for (unsigned int i = 0; i < arr_size; i++)
    {
        int cur_num = arr[i];
        if ( num_index.find( cur_num ) == num_index.end() )
        {
            vector<unsigned int> init (1, i);
            num_index[cur_num] = init;
        }
        else
        {
            unsigned int dist = i - num_index[cur_num].back() - 1;
            if ( dist <= k )
                return cur_num;

            num_index[cur_num].push_back(i);
        }
    }
    return -1;
}

int main()
{
    int arr[] = { 1, -3, 5, 6, -5, -6, -3, 4, 7, -3 };
    cout << duplicate_dist(arr, 10, 3) << endl;

    int arr_one[] = { 1 };
    cout << duplicate_dist(arr_one, 1, 3) << endl;
}