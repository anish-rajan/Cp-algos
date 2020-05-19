#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1003
vector<ll> par(N), child(N);
int main()
{
    ll n, x;
    cin >> n >> x;
    for (ll i = 1; i <= n; i++)
    {
        ll u;
        cin >> u;
        child[u] = i;
        par[i] = u;
    }
    ll offset = 0;
    vector<ll> compo;
    for (ll i = 1; i <= n; i++)
    {
        ll f = 0, ex = 0;
        if (par[i] == 0)
        {
            ll j = i;
            while (j != 0)
            {
                if (j == x)
                {
                    offset = f;
                    ex = 1;
                }
                j = child[j];
                f++;
            }
            if (ex == 0)
            {
                compo.push_back(f);
            }
        }
    }
    set<ll> ans;
    ll n1 = compo.size();
    // cout << offset << "\n";
    // for (ll i = 0; i < n1; i++)
    // {
    //     cout << compo[i];
    // }
    for (ll i = 0; i < n1; i++)
    {
        vector<ll> ans1;
        ans1.push_back(compo[i] + offset + 1);
        for (auto y : ans)
        {
            ans1.push_back(y + compo[i]);
        }
        for (ll j = 0; j < ans1.size(); j++)
        {
            ans.insert(ans1[j]);
        }
    }
    ans.insert(1 + offset);
    for (auto y : ans)
    {
        cout << y << "\n";
    }
}