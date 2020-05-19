#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, pair<ll, ll>>> res(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> res[i].second.first;
        cin >> res[i].first;
        res[i].second.second = i;
    }
    sort(res.begin(), res.end());
    ll k;
    cin >> k;
    vector<pair<ll, ll>> tables;
    for (ll i = 0; i < k; i++)
    {
        ll u;
        cin >> u;
        tables.push_back(make_pair(u, i));
    }
    sort(tables.begin(), tables.end());
    ll ans = 0;
    ll nos = 0;
    vector<pair<ll, ll>> req;
    ll s = k;
    for (ll i = n - 1; i >= 0; i--)
    {

        ll ind = lower_bound(tables.begin(), tables.end(), pair<ll, ll>(res[i].second.first, 0)) - tables.begin();
        // cout << ind << " " << s << "\n";
        if (ind < s)
        {
            req.push_back(make_pair(tables[ind].second + 1, res[i].second.second + 1));
            ans += res[i].first;
            nos++;
            tables.erase(tables.begin() + ind);
            s--;
        }
    }
    sort(req.begin(), req.end());
    cout << nos << " " << ans << "\n";
    for (ll i = 0; i < req.size(); i++)
    {
        cout << req[i].second << " " << req[i].first << endl;
    }
}