#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<char>> temp = board;
    vector<vector<int>> permutations = {{0}};
    for (int i = 1; i < n; i++)
    {
        vector<vector<int>> temp;
        for (auto u : permutations)
        {
            vector<int> temp2 = u;
            for (int j = 0; j <= i; j++)
            {
                u.insert(u.begin() + j, i);
                temp.push_back(u);
                u = temp2;
            }
        }
        permutations = temp;
    }
    for (auto u : permutations)
    {
        unordered_map<int, bool> rowPlusColumn, rowMinusColumn;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (rowPlusColumn[i + u[i]] || rowMinusColumn[i - u[i]])
            {
                flag = false;
                break;
            }
            rowPlusColumn[i + u[i]] = true, rowMinusColumn[i - u[i]] = true;
        }
        if (flag)
        {
            for (int i = 0; i < n; i++)
            {
                board[i][u[i]] = 'Q';
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << board[i][j] << " ";
                }
                cout << "\n";
            }
            board = temp;
            cout << "\n";
        }
    }
}