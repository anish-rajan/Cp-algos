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
#define N 1000006
ll mod = 1000000007;
#define INF INT_MAX

ll n, t, k, al, bl, cl, dl, aw, bw, cw, dw, ah, bh, ch, dh, p;

ll mul(ll a, ll b, ll m)
{
    return (a * b) % m;
}
v<ll> start, height, width;
set<pair<ll, pair<ll, ll>>> a;

void insert(ll st, ll h, ll w)
{
    auto itr = a.lower_bound(mp(st, mp(-INF, -INF)));
    if (itr != a.begin())
    {
        itr--;
        if (itr->se.fi < st)
            itr++;
    }
    if (a.size() == 0 || itr == a.end() || itr->fi > st + w)
    {
        a.insert(mp(st, mp(st + w, h)));
        p = (p + 2 * (w + h)) % mod;
        return;
    }
    pair<ll, pair<ll, ll>> sti = *itr, eni = sti;
    ll maxc = sti.fi;
    ll prevh = sti.se.se;
    p = (p + 2 * max(0LL, sti.fi - st)) % mod;
    p = (p + h - sti.se.se) % mod;
    auto itr1 = itr;
    while (itr1 != a.end() && itr1->fi <= st + w)
    {
        auto itr2 = itr1;
        eni = *itr1;
        p = (p + 2 * (eni.fi - maxc)) % mod;
        if (maxc == eni.fi)
            p = (p - abs(prevh - eni.se.se) + mod) % mod;
        else
            p = (p - prevh - eni.se.se + 2 * mod) % mod;
        // cout << eni.fi << " " << eni.se.fi << " " << maxc << " " << p << "\n";
        maxc = itr1->se.fi;
        prevh = eni.se.se;
        itr1++;
        if (itr1 == a.end())
        {
            a.erase(itr2);
            break;
        }
        a.erase(itr2);
    }
    p = (p + 2 * max(0LL, st + w - eni.se.fi)) % mod;
    p = (p + h - eni.se.se) % mod;
    if (sti.fi < st)
    {
        a.insert({sti.fi, {st, sti.se.se}});
        a.insert({st, {st + w, h}});
        if (st + w < eni.se.fi)
        {
            a.insert({st + w, {eni.se.fi, eni.se.se}});
        }
    }
    else
    {
        a.insert({st, {st + w, h}});
        if (st + w < eni.se.fi)
        {
            a.insert({st + w, {eni.se.fi, eni.se.se}});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    freopen("test.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cin >> n >> k;
        ll ans = 1;
        for (ll i = 1; i <= k; i++)
        {
            ll val;
            cin >> val;
            start.pb(val);
        }
        cin >> al >> bl >> cl >> dl;
        for (ll i = 1; i <= k; i++)
        {
            ll val;
            cin >> val;
            width.pb(val);
        }
        cin >> aw >> bw >> cw >> dw;
        for (ll i = 1; i <= k; i++)
        {
            ll val;
            cin >> val;
            height.pb(val);
        }
        cin >> ah >> bh >> ch >> dh;
        for (ll i = 0; i < k; i++)
        {
            insert(start[i], height[i], width[i]);
            // cout << start[i] << " " << height[i] << " " << width[i] << " " << p << "\n";
            ans = mul(ans, p, mod);
        }
        for (ll i = k; i < n; i++)
        {
            ll st = (mul(al, start[i - 2], dl) + mul(bl, start[i - 1], dl) + cl) % dl + 1;
            ll w = (mul(aw, width[i - 2], dw) + mul(bw, width[i - 1], dw) + cw) % dw + 1;
            ll h = (mul(ah, height[i - 2], dh) + mul(bh, height[i - 1], dh) + ch) % dh + 1;
            insert(st, h, w);
            // cout << st << " " << h << " " << w << " " << p << "\n";
            start.pb(st), height.pb(h), width.pb(w);
            ans = mul(ans, p, mod);
        }
        cout << "Case #" << i << ": " << ans << "\n";
        a.clear(), start.clear(), height.clear(), width.clear(), p = 0;
    }
}
