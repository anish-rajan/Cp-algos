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
#define N 1003
#define mod 1000000007
#define INF INT64_MAX
ll n, m;
v<v<ll>> a(N, v<ll>(N));
map<pair<ll, ll>, ll> pairs;
v<v<ll>> cs(N);
set<pair<ll, pair<ll, ll>>, greater<pair<ll, pair<ll, ll>>>> nos;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
        {
            ll val;
            cin >> val;
            a[i][j] = val;
            nos.insert(mp(val, mp(i, j)));
        }
    ll ans = -1;
    for (auto itr = nos.begin(); itr != nos.end(); itr++)
    {
        auto temp = *itr;
        ll val = temp.fi, r = temp.se.fi, c = temp.se.se;
        for (ll i = 0; i < cs[r].size(); i++)
        {
            ll c2 = cs[r][i];
            if (pairs.find(mp(c2, c)) != pairs.end())
            {
                ll r2 = pairs[mp(c2, c)];
                ans = min(a[r2][c2], min(a[r2][c], min(a[r][c2], a[r][c])));
            }
            else if (pairs.find(mp(c, c2)) != pairs.end())
            {
                ll r2 = pairs[mp(c, c2)];
                ans = min(a[r2][c2], min(a[r2][c], min(a[r][c2], a[r][c])));
            }
            pairs[mp(c2, c)] = r;
            if (ans != -1)
                break;
        }
        cs[r].pb(c);
        if (ans != -1)
            break;
    }
    cout << ans << "\n";
}