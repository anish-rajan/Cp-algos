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
    for (ll i = 1; i <= t; i++)
    {
        ll x, y;
        cin >> x >> y;
        v<ll> fx, fy;
        while (x != 0)
        {
            fx.push_back(x % 2);
            x /= 2;
        }
        while (y != 0)
        {
            fy.push_back(y % 2);
            y /= 2;
        }
        ll s1 = fx.size(), s2 = fy.size();
        for (ll i = fx.size(); i <= 32; i++)
            fx.pb(0);
        for (ll i = fy.size(); i <= 32; i++)
            fy.pb(0);
        ll f = 1;
        // cout << s1 << " " << s2 << "\n";
        for (ll i = 0; i < max(s1, s2); i++)
        {
            if (fx[i] == 0 && fy[i] == 0)
            {
                if (i == 0)
                {
                    f = 0;
                    break;
                }
                else if (fx[i - 1] != 0)
                {
                    fx[i] = fx[i - 1];
                    fx[i - 1] = -fx[i - 1];
                }
                else
                {
                    fy[i] = fy[i - 1];
                    fy[i - 1] = -fy[i - 1];
                }
            }
            else if (abs(fx[i]) == 1 && abs(fy[i]) == 1)
            {
                if (i == 0)
                {
                    f = 0;
                    break;
                }
                else if (fx[i - 1] != 0)
                {
                    fx[i - 1] = -fx[i - 1];
                    fx[i + 1] += fx[i];
                    fx[i] = 0;
                }
                else
                {
                    fy[i - 1] = -fy[i - 1];
                    fy[i + 1] += fy[i];
                    fy[i] = 0;
                }
            }
            else
            {
                if (abs(fx[i]) == 2)
                {
                    fx[i + 1] += fx[i] / 2;
                    fx[i] = 0;
                }
                if (abs(fy[i]) == 2)
                {
                    fy[i + 1] += fy[i] / 2;
                    fy[i] = 0;
                }
                if (fx[i] == 0 && fy[i] == 0)
                {
                    if (i == 0)
                    {
                        f = 0;
                        break;
                    }
                    else if (fx[i - 1] != 0)
                    {
                        fx[i] = fx[i - 1];
                        fx[i - 1] = -fx[i - 1];
                    }
                    else
                    {
                        fy[i] = fy[i - 1];
                        fy[i - 1] = -fy[i - 1];
                    }
                }
            }
        }
        if (f == 0)
        {
            cout << "Case #" << i << ": IMPOSSIBLE\n";
            continue;
        }
        else
        {
            cout << "Case #" << i << ": ";
            v<char> move;
            for (ll i = 0;; i++)
            {
                if (fx[i] == 0 && fy[i] == 0)
                    break;
                if (fx[i] != 0)
                {
                    if (fx[i] == 1)
                        move.pb('E');
                    else
                        move.pb('W');
                }
                else
                {
                    if (fy[i] == 1)
                        move.pb('N');
                    else
                        move.pb('S');
                }
            }
            for (ll i = 0; i < move.size(); i++)
                cout << move[i];
            cout << "\n";
        }
    }
}