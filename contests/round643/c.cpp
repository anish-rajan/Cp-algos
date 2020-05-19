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
#define INF INT64_MAX
ll t;
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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for (ll i = c + 1; i <= d + 1; i++)
    {
        ll minx = max(i - c, a);
        ll miny = max(i - minx, b);
        if (minx > b || miny > c)
            break;
        ll ys = c - miny + 1;
        ll xs = b - minx + 1;
        ll rangey = min(xs, miny - b + 1);
        ll temp = ((ys + rangey - 1) * (ys + rangey)) / 2 - (ys * (ys - 1)) / 2 + max((ll)0, xs - rangey) * (ys + rangey - 1);
        ans += temp;
    }
    cout << ans << "\n";
}