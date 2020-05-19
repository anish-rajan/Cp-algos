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
#define N 200005
#define mod 998244353
ll n, t;
v<v<ll>> cods(201, v<ll>(201));
v<v<ll>> temp(201, v<ll>(201));
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
ll gx(ll x)
{
    return x + 100;
}
ll gy(ll y)
{
    return y + 100;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> t;
    ll maxc = n;
    cods[gx(0)][gy(0)] = n;
    while (maxc >= 4)
    {
        maxc = 0;
        for (ll i = -100; i <= 100; i++)
        {
            for (ll j = -100; j <= 100; j++)
            {
                if (cods[gx(i)][gy(j)] >= 4)
                {
                    temp[gx(i - 1)][gy(j)] += cods[gx(i)][gy(j)] / 4;
                    temp[gx(i + 1)][gy(j)] += cods[gx(i)][gy(j)] / 4;
                    temp[gx(i)][gy(j - 1)] += cods[gx(i)][gy(j)] / 4;
                    temp[gx(i)][gy(j + 1)] += cods[gx(i)][gy(j)] / 4;
                    cods[gx(i)][gy(j)] = cods[gx(i)][gy(j)] % 4;
                }
                temp[gx(i)][gy(j)] += cods[gx(i)][gy(j)];
            }
        }
        for (ll i = -100; i <= 100; i++)
        {
            for (ll j = -100; j <= 100; j++)
            {
                cods[gx(i)][gy(j)] = temp[gx(i)][gy(j)];
                temp[gx(i)][gy(j)] = 0;
                maxc = max(cods[gx(i)][gy(j)], maxc);
            }
        }
    }
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        x = gx(x), y = gy(y);
        if (x < 0 || x >= 201 || y < 0 || y >= 201)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << cods[x][y] << "\n";
        }
    }
}