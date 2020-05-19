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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll maxpo = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxpo = max(maxpo, arr[i]);
        }
        ll m;
        cin >> m;
        vector<pair<ll, ll>> hero;
        ll f = 0;
        for (ll i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            if (u >= maxpo)
            {
                f = 1;
            }
            hero.push_back(make_pair(u, v));
        }
        if (f == 0)
        {
            cout << -1 << "\n";
            continue;
        }
        sort(hero.begin(), hero.end());
        vector<ll> maxend(m);
        maxend[m - 1] = hero[m - 1].second;
        for (ll i = m - 2; i >= 0; i--)
        {
            maxend[i] = max(maxend[i + 1], hero[i].second);
        }
        ll days = 1;
        ll maxpower = arr[0];
        pair<ll, ll> a(arr[0], 0);
        ll ind = lower_bound(hero.begin(), hero.end(), a) - hero.begin();
        ll endu = maxend[ind];
        ll start = 0;
        for (ll i = 0; i < n; i++)
        {
            if (maxpower < arr[i])
            {
                maxpower = arr[i];
                pair<ll, ll> a(maxpower, 0);
                ind = lower_bound(hero.begin(), hero.end(), a) - hero.begin();
                endu = maxend[ind];
                if (endu < i - start + 1)
                {
                    start = i;
                    days++;
                }
            }
            else
            {
                if (endu < i - start + 1)
                {
                    maxpower = arr[i];
                    pair<ll, ll> a(maxpower, 0);
                    ind = lower_bound(hero.begin(), hero.end(), a) - hero.begin();
                    endu = maxend[ind];
                    start = i;
                    days++;
                }
            }
        }
        cout << days << "\n";
    }
}