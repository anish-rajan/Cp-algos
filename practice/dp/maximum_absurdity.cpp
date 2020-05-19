#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> absurd(n + 1);
    vector<ll> cum(n + 1);
    vector<pair<ll, ll>> maxi(n + 1);

    for (ll i = 1; i <= n; i++)
    {
        cin >> absurd[i];
    }
    cum[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        cum[i] = cum[i - 1] + absurd[i];
        // cout << cum[i] << " ";
    }
    for (ll i = n; i > k; i--)
    {
        cum[i] -= cum[i - k];
        // cout << cum[i] << " ";
    }
    maxi[n].first = cum[n];
    maxi[n].second = n;
    for (ll i = n - 1; i >= 1; i--)
    {
        if (maxi[i + 1].first <= cum[i])
        {
            maxi[i].first = cum[i];
            maxi[i].second = i;
        }
        else
        {
            maxi[i].first = maxi[i + 1].first;
            maxi[i].second = maxi[i + 1].second;
        }
        // cout << maxi[i].first << " " << maxi[i].second << "\n";
    }
    ll a, b;
    ll maximum = -1;
    for (ll i = k; i <= n - k; i++)
    {
        if (cum[i] + maxi[i + k].first > maximum)
        {
            a = i - k + 1, b = maxi[i + k].second - k + 1;
            maximum = cum[i] + maxi[i + k].first;
        }
        // cout << a << " " << b << " " << maximum << "\n";
    }
    cout << a << " " << b << "\n";
}