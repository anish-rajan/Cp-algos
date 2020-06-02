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
#define N 200005
#define mod 1000000007
#define INF INT_MAX

ll n, m;
v<pair<pair<ll, ll>, pair<ll, ll>>> a;
v<ll> ans(N);

struct cmp
{
    bool operator()(pair<pair<ll, ll>, pair<ll, ll>> a, pair<pair<ll, ll>, pair<ll, ll>> b) const
    {
        return a.fi.se < b.fi.se;
    }
};

bool cmp1(pair<pair<ll, ll>, pair<ll, ll>> a, pair<pair<ll, ll>, pair<ll, ll>> b)
{
    if (a.fi.fi == b.fi.fi)
        return a.se.fi > b.se.fi;
    return a.fi.fi < b.fi.fi;
}

multiset<pair<pair<ll, ll>, pair<ll, ll>>, cmp> actors;

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

bool cmp(pair<pair<ll, ll>, pair<ll, ll>> a, pair<pair<ll, ll>, pair<ll, ll>> b)
{
    if (a.fi.se - a.fi.fi + 1 == b.fi.se - b.fi.fi + 1)
        return a < b;
    return a.fi.se - a.fi.fi + 1 < b.fi.se - b.fi.fi + 1;
}
bool sat(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.fi <= b.fi && b.se <= a.se)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a.pb(mp(mp(x, y), mp(0, i)));
    }
    cin >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        a.pb(mp(mp(x, y), mp(z, i)));
    }
    sort(a.begin(), a.end(), cmp1);
    ll poss = 1;
    for (auto x : a)
    {
        if (x.se.fi == 0)
        {
            auto itr = actors.lower_bound(x);
            if (itr == actors.end())
            {
                poss = 0;
                break;
            }
            auto temp = *itr;
            if (x.fi.se <= temp.fi.se)
            {
                ans[x.se.se] = temp.se.se;
                temp.se.fi--;
                // cout << temp.se.fi << " " << temp.se.se << "\n";
                actors.erase(itr);
                if (temp.se.fi)
                    actors.insert(temp);
            }
        }
        else
        {
            actors.insert(x);
        }
    }
    if (poss == 0)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}