#include <iostream>
#include <algorithm>

using namespace std;

// Return the max profit if we can only buy and sell once 
// Time complexity: O(n)
// Aux Space complexity: O(1)
int max_profit(int *stock_prices, unsigned int arr_size)
{
    int max_profit = 0, max_cur = 0;
    for (unsigned int i = 1; i < arr_size; i++)
    {
        max_cur = max(0, max_cur += stock_prices[i] - stock_prices[i - 1]);
        max_profit = max(max_profit, max_cur);
    }

    return max_profit;
}

int main()
{
    // buy on day 1, sell on day 2: 9 - -3 = 12
    // 9 - - 3 = 12
    // -1 - 9 = -10 -> 2
    // 3 - -1 = 4 -> 6
    // take the max of these
    int profit_beginning[] = { -3, 9, -1, 3 };

    // buy on day 2, sell on day 4: 9 - - 6 = 15
    // -6 - -3 = -3 -> 0
    // -1 - -6 = 5 -> 5
    // 9 - -1 = 10 -> 15 <-- -1 no effect after the 2 ops
    // 7 - 9 = -2 -> 13
    int profit_mid[] = { -3, -6, -1, 9, 7 };

    // buy on day 3, sell on day 4: 11 - -6 = 17
    // 9 - -3 = 10
    // -6 - 9 = -17 -> 0
    // 11 - -6 = 17
    int profit_end[] = { -3, 9, -6, 11 };

    // buy on day 4, sell on day 5: 3 - -99 = 102
    // -8 - -6 = -2 -> 0
    // 10 - -8 = 18
    // -99 - 10 = -109 -> 0
    // 3 - -99 = 102
    int profit_not_min_max[] = { -6, -8, 10, -99, 3 };

    cout << max_profit(profit_beginning, 4) << endl;
    cout << max_profit(profit_mid, 5) << endl;
    cout << max_profit(profit_end, 4) << endl;
    cout << max_profit(profit_not_min_max, 5) << endl;
}