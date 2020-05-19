#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> edges;
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
    }
    vector<ll> color(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> color[i];
    }
    vector<pair<ll, ll>> notin;
    for (ll i = 0; i < edges.size(); i++)
    {
        ll u = edges[i].first, v = edges[i].second;
        if (color[u] != color[v])
        {
            notin.push_back(edges[i]);
        }
    }
    ll c;
    if (notin.size() == 0)
    {
        cout << "YES\n";
        cout << 1 << "\n";
    }
    else if (notin.size() == 1)
    {
        cout << "YES\n";
        cout << notin[0].first << "\n";
    }
    else
    {
        ll u = notin[0].first, v = notin[0].second, u1 = notin[1].first, v1 = notin[1].second;
        if (u == u1 || u == v1)
            c = u;
        else if (v == u1 || v == v1)
            c = v;
        else
        {
            cout << "NO\n";
            return 0;
        }
        for (ll i = 2; i < notin.size(); i++)
        {
            ll u2 = notin[i].first, v2 = notin[i].second;
            if (c != u2 && c != v2)
            {
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
        cout << c << "\n";
    }
}