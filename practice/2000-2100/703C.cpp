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
#define N 10004
#define mod 1000000007
ll n;
ld w, u, ve;
v<pair<ld, ld>> cords(N);
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
    cin >> n >> w >> ve >> u;
    ld miny = INT_MAX;
    ll minind = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> cords[i].fi >> cords[i].se;
        minind = miny > cords[i].se ? i : minind;
        miny = min(miny, cords[i].se);
    }
    // cout << miny << " " << minind << "\n";
    ll f = 1;
    ld cury = 0;
    ld t = 0;
    for (ll i = minind;; i = (i - 1 + n) % n)
    {
        ld t1 = cords[i].fi / ve;
        t1 -= t;
        ld t2 = (cords[i].se - cury) / u;
        if (t1 < t2 || t1 < 0)
        {
            f = 0;
            break;
        }
        t += t2;
        cury = cords[i].se;
        if (cords[(i - 1 + n) % n].se < cords[i].se)
            break;
    }
    if (f == 1)
    {
        printf("%0.8Lf\n", w / u);
        return 0;
    }
    t = 0, cury = 0;
    for (ll i = minind;; i = (i + 1) % n)
    {
        ld t1 = cords[i].fi / ve, u1;
        t1 -= t;
        if (t1 != 0)
            u1 = (cords[i].se - cury) / t1;
        else
            u1 = INT_MAX;
        if (u1 >= u || t1 < 0)
            t += (cords[i].se - cury) / u;
        else
            t += t1;
        cury = cords[i].se;
        // cout << u1 << " " << t1 << " " << t << " " << cury << "\n";
        if (cords[(i + 1 + n) % n].fi < cords[i].fi)
            break;
    }
    t += (w - cury) / u;
    printf("%0.8Lf\n", t);
}