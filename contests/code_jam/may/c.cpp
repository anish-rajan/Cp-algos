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
#define N 3003
#define mod 998244353
ll t;
v<ll> inv(300);
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
ll decode(string s)
{
    ll p = 1, no = 0;
    for (ll i = s.size() - 1; i >= 0; i--)
    {
        no += p * inv[s[i]];
        p *= 10;
    }
    return no;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll n, d;
        cin >> n >> d;
        v<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.begin() + n + 1);
        ll maxs = 1, pos = 0;
        for (ll i = 1; i < n; i++)
        {
            if (a[i] == a[i + 1])
                maxs = 2;
        }
        for (ll i = 1; i < n - 1; i++)
        {
            if (a[i] == a[i + 1] && a[i + 1] == a[i + 2])
            {
                maxs = 3, pos = i;
                break;
            }
        }
        ll ans = 4;
        if (d == 2)
        {
            if (maxs >= 2)
                ans = 0;
            else
                ans = 1;
        }
        else if (d == 3)
        {
            if (maxs >= 3)
                ans = 0;
            else if (maxs == 2 && pos < n - 2)
            {
                ans = 1;
            }
            else
            {
                set<ld> nos;
                for (ll i = 1; i <= n; i++)
                {
                    if (nos.find(a[i] / 2.0) != nos.end())
                        ans = 1;
                    nos.insert(a[i]);
                }
                // for (ll i =)
                if (ans == 4)
                    ans = 2;
            }
        }
        cout << "Case #" << i << ": " << ans << "\n";
    }
}