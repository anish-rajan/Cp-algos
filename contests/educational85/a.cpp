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
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 505
ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        v<pair<ll, ll>> a(n + 1);
        a[0].fi = 0, a[0].se = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i].fi >> a[i].se;
        }
        ll f = 1;
        for (ll i = 1; i <= n; i++)
        {
            ll temp = a[i].fi - a[i - 1].fi;
            ll temp2 = a[i].se - a[i - 1].se;
            if (temp < 0 || temp2 < 0 || temp2 > temp)
            {
                cout << "NO\n";
                f = 0;
                break;
            }
        }
        if (f == 1)
            cout << "YES\n";
    }
}