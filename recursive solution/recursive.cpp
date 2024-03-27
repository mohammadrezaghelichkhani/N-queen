#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
vector<vector<char>> board;
unordered_map<int, bool> columns, rowPlusColum, rowMinusColumn;
void solve(int row)
{
    if (row == n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (!columns[i])
            {
                if (!rowPlusColum[i + row])
                {
                    if (!rowMinusColumn[row - i])
                    {
                        ans++;
                        board[n - 1][i] = 'Q';
                        for (auto u : board)
                        {
                            for (auto v : u)
                            {
                                cout << v << " ";
                            }
                            cout << "\n";
                        }
                        board[n - 1][i] = '.';
                        cout << "\n";
                    }
                }
            }
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!columns[i])
        {
            if (!rowPlusColum[i + row])
            {
                if (!rowMinusColumn[row - i])
                {
                    columns[i] = true;
                    rowMinusColumn[row - i] = true;
                    rowPlusColum[row + i] = true;
                    board[row][i] = 'Q';
                    solve(row + 1);
                    columns[i] = false;
                    rowMinusColumn[row - i] = false;
                    rowPlusColum[row + i] = false;
                    board[row][i] = '.';
                }
            }
        }
    }
}
int main()
{
    cin >> n;
    board = vector<vector<char>>(n, vector<char>(n, '.'));
    solve(0);
    cout << ans << "\n";
}