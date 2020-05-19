#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1000006
vector<ll> arr(N);
int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] %= m;
    }
    if (n > m)
    {
        cout << "YES\n";
    }
    else
    {
        sort(arr.begin(), arr.begin() + n);
        vector<vector<ll>> pos_rem(n, vector<ll>(m));
        pos_rem[0][arr[0]] = 1;
        for (ll i = 1; i < n; i++)
        {
            pos_rem[i][arr[i]] = 1;
            for (ll j = 0; j < m; j++)
            {
                if (pos_rem[i - 1][j])
                {
                    pos_rem[i][j] = 1;
                    pos_rem[i][(j + arr[i]) % m] = 1;
                }
            }
        }
        if (pos_rem[n - 1][0])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}