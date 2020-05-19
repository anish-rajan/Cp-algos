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
ll t, w, h;
string s;
#define mod 1000000000
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
void fix(ll &val)
{
    if (val <= 0)
    {
        val = mod + val;
    }
    else if (val > mod)
    {
        val = val - mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        w = 1, h = 1;
        cin >> s;
        ll c = 1;
        v<ll> a(s.size());
        a = {0};
        v<ll> divs;
        divs.pb(1);
        for (ll i = 0; i < s.size(); i++)
        {
            a[i] = divs.back();
            if (s[i] >= '2' && s[i] <= '9')
            {
                ll temp = (divs.back() * (s[i] - '0')) % mod;
                divs.pb(temp);
            }
            else if (s[i] == ')')
            {
                divs.pop_back();
            }
            // cout << a[i] << " ";
        }
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == 'N')
            {
                h = (h - a[i] + a[i] * mod) % mod;
            }
            else if (s[i] == 'S')
            {
                h = (h + a[i]) % mod;
            }
            else if (s[i] == 'E')
            {
                w = (w + a[i]) % mod;
            }
            else if (s[i] == 'W')
            {
                w = (w - a[i] + a[i] * mod) % mod;
            }
        }
        if (h == 0)
            h = mod;
        if (w == 0)
            w = mod;
        cout << "Case #" << i << ": " << w << " " << h << "\n";
    }
}