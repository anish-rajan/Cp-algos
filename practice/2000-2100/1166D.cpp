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
ll t, a, b, m;
v<ll> pow2(52);
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
void comp(ll n)
{
    ll l = 1, r = m;
    cout << n << " ";
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        ll temp = b - pow2[n - 2] * (a + mid);
        if (temp < 0)
            r = mid - 1;
        else if (temp >= pow2[n - 2])
            l = mid + 1;
        else
        {
            // cout << mid << " " << temp;
            v<ll> r(n + 1);
            r[n] = mid;
            for (ll i = n - 1; i >= 2; i--)
            {
                r[i] = temp % 2 + mid;
                temp /= 2;
            }
            r[1] = 0;
            ll term = a;
            cout << a << " " << a + r[2] << " ";
            term = a + r[2];
            for (ll i = 3; i <= n; i++)
            {
                term = 2 * term + r[i] - r[i - 1];
                cout << term << " ";
            }
            cout << "\n";
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pow2[0] = 1;
    for (ll i = 1; i <= 51; i++)
    {
        pow2[i] = 2 * pow2[i - 1];
    }
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> m;
        if (a == b)
        {
            cout << 1 << " " << a << "\n";
            continue;
        }
        ll f = 0;
        for (ll i = 2; i <= 50; i++)
        {
            ll temp = pow2[i - 2] * (a + 1), temp1 = pow2[i - 2] * (a + m);
            if (b >= temp && b <= temp1)
            {
                comp(i);
                f = 1;
                break;
            }
            else if (b < temp)
                break;
        }
        if (f == 0)
            cout << -1 << "\n";
    }
}