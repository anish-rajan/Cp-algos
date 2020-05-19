#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 100005
#define mod 1000000007
ll k, n;
ll c;
v<v<ll>> weights(N);
map<string, ll> stoin;
map<ll, string> inv;
v<ll> maxpos(N), pals;
long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}

bool is_pal(string s)
{
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}
string pal(string s)
{
    for (ll i = 0; i < s.size() / 2; i++)
    {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k >> n;
    for (ll i = 1; i <= k; i++)
    {
        string s;
        ll val;
        cin >> s >> val;
        if (stoin.find(s) == stoin.end())
        {
            weights[++c].pb(val);
            stoin[s] = c;
            inv[c] = s;
        }
        else
            weights[stoin[s]].pb(val);
    }
    ll ans = 0;
    ll palsum = 0;
    for (ll i = 1; i <= c; i++)
        sort(weights[i].begin(), weights[i].end(), greater<ll>());
    for (ll i = 1; i <= c; i++)
    {
        if (is_pal(inv[i]))
        {
            for (ll j = 0; j + 1 < weights[i].size(); j += 2)
            {
                ll temp = weights[i][j] + weights[i][j + 1];
                if (temp > 0)
                    maxpos[i] += temp;
                else
                    break;
            }
            palsum += maxpos[i];
            pals.pb(i);
        }
        else
        {
            string s1 = pal(inv[i]);
            if (stoin.find(s1) != stoin.end())
            {
                ll i1 = stoin[s1];
                for (ll j = 0; j < min(weights[i].size(), weights[i1].size()); j++)
                {
                    ll temp = weights[i][j] + weights[i1][j];
                    if (temp > 0)
                        maxpos[i] += temp;
                    else
                        break;
                }
                ans += maxpos[i];
            }
        }
    }
    ans /= 2;
    ll ans1 = palsum;
    for (ll t = 0; t < pals.size(); t++)
    {
        ll j = 0, i = pals[t];
        for (; j + 1 < weights[i].size(); j += 2)
        {
            ll temp = weights[i][j] + weights[i][j + 1];
            if (temp > 0)
                continue;
            else
                break;
        }
        if (j < weights[i].size())
            ans1 = max(ans1, palsum + weights[i][j]);
        if (j - 2 >= 0)
            ans1 = max(ans1, palsum - weights[i][j - 1]);
    }
    ans += ans1;
    cout << ans << "\n";
}