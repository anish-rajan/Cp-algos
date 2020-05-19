#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        ll h, n;
        cin >> h >> n;
        vector<ll> p(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        if (n == 1)
        {
            cout << 0 << "\n";
        }
        else if (n == 2)
        {
            if (p[1] == 1)
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << 1 << "\n";
            }
        }
        else
        {
            ll ans = 0, i = 0;
            for (; i < n - 2; i++)
            {
                if (p[i] - p[i + 1] >= 2)
                {
                    p[i] = p[i + 1] + 1;
                }
                if (p[i] - p[i + 2] >= 3)
                {
                    ans++;
                    p[i + 1] = p[i + 2] + 1;
                }
                else
                {
                    i++;
                }
            }
            if (i == n - 2)
            {
                if (p[n - 1] != 1)
                {
                    ans++;
                }
            }
            cout << ans << "\n";
        }
    }
}