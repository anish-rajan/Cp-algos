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
#define mod 1000000007
#define INF INT_MAX
ll n, m, dx, dy;
v<pair<ll, ll>> a(N);
v<ll> c(N);
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
    cin >> n >> m >> dx >> dy;
    for (ll i = 1; i <= m; i++)
        cin >> a[i].fi >> a[i].se;
    ll ans = 0, ci = -1;
    for (ll i = 1; i <= m; i++)
    {
        ll x = a[i].fi, y = a[i].se;
        ll cons = (y * dx - x * dy + n * n) % n;
        c[cons]++;
        ci = ans < c[cons] ? cons : ci;
        ans = max(ans, c[cons]);
    }
    for (ll i = 1; i <= n; i++)
    {
        ll x = a[i].fi, y = a[i].se;
        ll cons = (y * dx - x * dy + n * n) % n;
        if (cons == ci)
        {
            cout << x << " " << y << "\n";
            return 0;
        }
    }
}