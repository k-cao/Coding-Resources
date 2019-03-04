#include <iostream>
#include <algorithm>

using namespace std;

// Return the max profit if we can buy and sell multiple times
// Time complexity: O(n)
// Aux Space complexity: O(1)
int max_profit(int *stock_prices, unsigned int arr_size)
{
    int max_profit = 0;
    for (unsigned int i = 0; i < arr_size - 1; i++)
    {
        if (stock_prices[i + 1] > stock_prices[i])
            max_profit += stock_prices[i + 1] - stock_prices[i];
    }

    return max_profit;
}

int main()
{
    int profit_beginning[] = { -3, 9, -1, 3 };
    int profit_mid[] = { -3, -6, -1, 9, 7 };
    int profit_end[] = { -3, 9, -6, 11 };
    int profit_not_min_max[] = { -6, -8, 10, -99, 3 };

    cout << max_profit(profit_beginning, 4) << endl;
    cout << max_profit(profit_mid, 5) << endl;
    cout << max_profit(profit_end, 4) << endl;
    cout << max_profit(profit_not_min_max, 5) << endl;
}