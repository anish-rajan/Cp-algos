#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define pii pair<ll, ll>
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 200005
#define mod 998244353

ll t;

ll powmod(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

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
        v<ll> a(n + 1), occ(n + 1), inv(n + 1);
        ll pos;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            inv[a[i]] = i;
            if (a[i] == 1)
            {
                occ[i] = 1;
                pos = i;
            }
        }
        ll f = 1;
        for (ll i = 2; i <= n; i++)
        {
            if (pos + 1 == n + 1)
            {
                occ[inv[i]] = 1;
                pos = inv[i];
            }
            else if (occ[pos + 1] == 1)
            {
                occ[inv[i]] = 1;
                pos = inv[i];
            }
            else
            {
                if (pos + 1 != inv[i])
                {
                    f = 0;
                    break;
                }
                else
                {
                    occ[inv[i]] = 1;
                }
            }
        }
        if (f == 0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}