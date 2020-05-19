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
ll n, t;
v<string> q(N);
v<ll> a(10, 10), b(10);
string s;
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
    cin >> s >> t;
    n = s.size();
    ll temp = t;
    while (temp--)
        cin >> q[temp];
    for (ll i = 0; i < 10; i++)
        b[i] = i;
    for (ll i = 0; i < t; i++)
    {
        ll p = 1, cur = 0, no = q[i][0] - '0';
        for (ll j = 3; j < q[i].size(); j++)
        {
            ll c = q[i][j] - '0';
            p = (a[c] * p) % mod;
            cur = ((a[c] * cur) % mod + b[c]) % mod;
        }
        a[no] = p, b[no] = cur;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll c = s[i] - '0';
        ans = ((ans * a[c]) % mod + b[c]) % mod;
    }
    cout << ans << "\n";
}