#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 1001
#define N1 8000001
#define N2 4000000
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll n, m;
v<v<ll>> nos(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    ll ans = 0;
    for (ll i = 1; i <= m; i++)
    {
        for (ll j = i; j <= m; j++)
        {
            if ((i * i + j * j) % m == 0)
            {
                nos[i].pb(j);
            }
        }
    }
    for (ll i = 1; i <= min(n, m); i++)
    {
        ll temp = (n - i) / m + 1;
        for (ll j = 0; j < nos[i].size(); j++)
        {
            if (nos[i][j] <= n)
            {
                ll temp1 = nos[i][j];
                temp1 = (n - temp1) / m + 1;
                ans += temp * temp1;
                if (i != nos[i][j])
                    ans += temp * temp1;
            }
        }
    }
    cout << ans << "\n";
}