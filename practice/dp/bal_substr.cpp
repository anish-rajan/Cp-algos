#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt0 = 0, cnt1 = 0;
    vector<ll> bal(n);
    for (ll i = 0; i < n; i++)
    {
        cnt0 = s[i] == '0' ? cnt0 + 1 : cnt0;
        cnt1 = s[i] == '1' ? cnt1 + 1 : cnt1;
        bal[i] = cnt0 - cnt1;
        // cout << bal[i] << " ";
    }
    vector<ll> pos(N);
    for (ll i = 0; i < N; i++)
    {
        pos[i] = -1;
    }
    vector<ll> neg(N);
    for (ll i = 0; i < N; i++)
    {
        neg[i] = -1;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (bal[i] < 0)
        {
            if (neg[-1 * bal[i]] == -1)
            {
                neg[-1 * bal[i]] = i;
            }
            else
            {
                ans = max(ans, i - neg[-1 * bal[i]]);
            }
            // cout << neg[-1 * bal[i]] << " ";
        }
        else if (bal[i] > 0)
        {
            if (pos[bal[i]] == -1)
            {
                pos[bal[i]] = i;
            }
            else
            {
                ans = max(ans, i - pos[bal[i]]);
            }
            // cout << pos[bal[i]] << " ";
        }
        else
        {
            ans = max(ans, i + 1);
        }
    }
    cout << ans << "\n";
}