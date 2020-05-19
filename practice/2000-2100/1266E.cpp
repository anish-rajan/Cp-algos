#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 200005
#define mod 998244353
ll n, m, sum;
map<pair<ll, ll>, ll> query;
map<ll, ll> no;
ll powmod(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll val;
        cin >> val;
        sum += val;
        no[i] = val;
    }
    cin >> m;
    while (m--)
    {
        ll s, t, u;
        cin >> s >> t >> u;
        if (query.find(mp(s, t)) != query.end())
        {
            ll temp = query[mp(s, t)];
            query.erase(mp(s, t));
            if (no[temp] >= 0)
                sum++;
            no[temp]++;
            if (u != 0)
            {
                query[mp(s, t)] = u;
                if (no[u] > 0)
                    sum--;
                no[u]--;
            }
        }
        else
        {
            if (u != 0)
            {
                query[mp(s, t)] = u;
                if (no[u] > 0)
                    sum--;
                no[u]--;
            }
        }
        cout << sum << "\n";
    }
}