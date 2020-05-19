#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 100005
ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n;
        vector<vector<ll>> arr(n);
        vector<ll> check(n + 2);
        fill(check.begin(), check.begin() + n, 0);
        ll f = 0;
        ll ind = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> k;
            f = 0;
            for (ll j = 0; j < k; j++)
            {
                ll val;
                cin >> val;
                arr[i].push_back(val);
                if (f == 0 && check[arr[i][j]] != 1)
                {
                    f = 1;
                    check[arr[i][j]] = 1;
                }
            }
            if (f == 0)
                ind = i;
        }
        for (ll j = 1; j <= n; j++)
        {
            if (!check[j])
            {
                cout << "IMPROVE\n";
                cout << ind + 1 << " " << j << "\n";
                f = 2;
                break;
            }
        }
        if (f != 2)
        {
            cout << "OPTIMAL\n";
        }
    }
}