#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> times(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> times[i].first >> times[i].second;
    }
    sort(times.begin(), times.end());
    ll counter = 1;
    ll l = times[0].first, r = times[0].second;
    for (ll i = 1; i < n; i++)
    {
        ll l1 = times[i].first, r1 = times[i].second;
        if (l1 > r)
        {
            counter++;
            l = l1, r = r1;
        }
        else if (r1 < r)
        {
            l = l1, r = r1;
        }
    }
    cout << counter << "\n";
}