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
#define N 500005
#define mod 1000000007
#define INF INT_MAX

ll n, x;
v<ll> a(N), p, m;

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
    ll n;
    cin >> n;
    ll s1 = 0;
    for (ll i = 1; i <= (n + 1) / 2; i++)
        cin >> a[i], s1 += a[i];
    cin >> x;
    p.pb(s1);
    for (ll i = (n + 1) / 2 + 1; i <= n; i++)
        p.pb(x - a[i - (n + 1) / 2]);
    m.pb(0);
    ll s2 = 0;
    for (ll i = 1; i < p.size(); i++)
    {
        s2 += p[i], m.pb(min(m[i - 1], s2));
        // cout << p[i] << " " << s2 << "\n";
    }
    ll k = -1;
    ll ans = (n + 1) / 2;
    for (ll i = m.size() - 1; i >= 0; i--)
    {
        // cout << p[0] << " " << m[i] << "\n";
        if (p[0] + m[i] > 0)
        {
            k = ans;
            break;
        }
        ans++;
        p[0] += x;
    }
    cout << k << "\n";
}