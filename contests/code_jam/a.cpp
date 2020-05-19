#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define N 102
ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n, r = 0, c = 0, s = 0;
        cin >> n;
        v<v<ll>> arr(n + 1, v<ll>(n + 1));
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            v<ll> check(n + 1);
            check = {0};
            for (ll j = 1; j <= n; j++)
            {
                check[arr[i][j]]++;
                if (check[arr[i][j]] == 2)
                {
                    r++;
                    break;
                }
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            v<ll> check(n + 1);
            check = {0};
            for (ll j = 1; j <= n; j++)
            {
                check[arr[j][i]]++;
                if (check[arr[j][i]] == 2)
                {
                    c++;
                    break;
                }
            }
        }
        for (ll i = 1; i <= n; i++)
        {

            for (ll j = 1; j <= n; j++)
            {
                if (i == j)
                    s += arr[i][j];
            }
        }
        cout << "Case #" << i + 1 << ": " << s << " " << r << " " << c << endl;
    }
}