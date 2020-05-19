#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
vector<vector<ll>> arr(3, vector<ll>(N));
int main()
{
    ll n, q;
    cin >> n >> q;
    ll points = 0;
    while (q--)
    {
        ll r, c;
        cin >> r >> c;
        ll temp = c;
        arr[r][c] = arr[r][c] == 1 ? 0 : 1;
        if (r == 1)
        {
            if (arr[r + 1][c] == 1)
                points = arr[r][c] == 1 ? points + 1 : points - 1;
            if (arr[r + 1][c + 1] == 1)
                points = arr[r][c] == 1 ? points + 1 : points - 1;
            if (arr[r + 1][c - 1] == 1)
                points = arr[r][c] == 1 ? points + 1 : points - 1;
        }
        if (r == 2)
        {
            if (arr[r - 1][c] == 1)
                points = arr[r][c] == 1 ? points + 1 : points - 1;
            if (arr[r - 1][c + 1] == 1)
                points = arr[r][c] == 1 ? points + 1 : points - 1;
            if (arr[r - 1][c - 1] == 1)
                points = arr[r][c] == 1 ? points + 1 : points - 1;
        }
        if (points == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}