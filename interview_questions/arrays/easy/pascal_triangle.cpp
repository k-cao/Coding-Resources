#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

// Return pascal's triangle
// Time complexity: O(n)
// Aux Space complexity: O(n)
vector< vector<int> > pascal(int n_rows)
{
    vector< vector<int> > triangle;
    for ( unsigned int n = 0; n < n_rows; n++ )
    {
        vector<int> row;
        row.push_back(1);

        if (n > 0)
        {
            vector<int> prev_row = triangle[n - 1];
            for ( unsigned int i = 0; i < prev_row.size() - 1; i++ )
            {
                row.push_back( prev_row[i] + prev_row[ i + 1 ] );
            }

            row.push_back(1);
        }

        triangle.push_back(row);
    }

    return triangle;
}

void display_pascal(vector< vector<int> > triangle)
{
    unsigned int n_rows = triangle.size();
    vector<int> last_row = triangle[n_rows - 1];

    ostringstream oss;
    copy(last_row.begin(), last_row.end(), ostream_iterator<int>(oss, " "));
    unsigned int n_spaces = oss.str().size();

    for (const auto& row: triangle)
    {
        ostringstream oss;
        copy(row.begin(), row.end(), ostream_iterator<int>(oss, " "));
        unsigned int cur_spaces = oss.str().size();
        unsigned int half_spaces = (n_spaces - cur_spaces) / 2;

        for ( unsigned int i = 0; i < half_spaces; i++ )
            cout << " ";
        for (const auto& num: row)
            cout << num << " ";
        cout << endl;
    }
}

int main()
{
    vector< vector<int> > triangle_basic = pascal(1);
    display_pascal(triangle_basic);

    vector< vector<int> > triangle_two = pascal(2);
    display_pascal(triangle_two);

    vector< vector<int> > triangle_odd = pascal(7);
    display_pascal(triangle_odd);

    vector< vector<int> > triangle_even = pascal(10);
    display_pascal(triangle_even);
}