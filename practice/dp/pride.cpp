#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll g = arr[0];
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] != 1)
            cnt++;
        g = __gcd(g, arr[i]);
    }
    if (g != 1)
    {
        cout << -1 << "\n";
        return 0;
    }
    else if (cnt != n)
    {
        cout << cnt << "\n";
        return 0;
    }
    else
    {
        ll moves = INT64_MAX;
        for (ll i = 0; i < n; i++)
        {
            ll j = i;
            ll g = arr[i];
            for (; j < n; j++)
            {
                g = __gcd(arr[j], g);
                // cout << i << " " << j << " " << g << "\n";
                if (g == 1)
                    break;
            }
            if (g == 1)
            {
                moves = min(moves, j - i);
                // cout << j - i << " ";
            }
        }
        moves += cnt - 1;
        cout << moves << "\n";
        return 0;
    }
}