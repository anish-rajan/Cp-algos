#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
ll n, m;
vector<ll> attack;
vector<ll> def;
vector<ll> ce;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        string s;
        ll val;
        cin >> s >> val;
        if (s == "ATK")
        {
            attack.push_back(val);
        }
        else
            def.push_back(val);
    }
    for (ll i = 0; i < m; i++)
    {
        ll val;
        cin >> val;
        ce.push_back(val);
    }
    sort(attack.begin(), attack.end());
    sort(def.begin(), def.end());
    sort(ce.begin(), ce.end());
    ll ans = 0;
    for (ll i = 1; i <= min(attack.size(), ce.size()); i++)
    {
        ll sum = 0;
        // cout << attack[i - 1] << " " << ce[i - 1] << "\n";
        for (ll j = 0; j < i; j++)
        {
            if (ce[m + j - i] >= attack[j])
                sum += ce[m + j - i] - attack[j];
        }
        ans = max(ans, sum);
    }
    // cout << ans << "\n";
    ll tempans = 0;
    ll sz = m, defsz = def.size(), j = 0, q = 0;
    if (sz >= defsz)
    {
        while (j < sz && q < defsz)
        {
            if (ce[j] > def[q])
            {
                ce[j] = 0;
                q++;
            }
            j++;
        }
    }
    if (q >= defsz)
    {
        ll j = 0;
        for (ll i = 0; i < ce.size() && j < attack.size(); i++)
        {
            if (ce[i] >= attack[j])
            {
                ce[i] -= attack[j];
                j++;
            }
        }
        if (j >= attack.size())
        {
            for (ll i = 0; i < ce.size(); i++)
                tempans += ce[i];
            ans = max(ans, tempans);
        }
    }

    cout << ans << "\n";
}