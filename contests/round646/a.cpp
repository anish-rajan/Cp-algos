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
#define N 5005
#define mod 1000000007
#define INF INT_MAX

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
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        v<ll> a(n + 1);
        ll o = 0, e = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] % 2)
                o++;
            else
                e++;
        }
        ll pos = 0;
        for (ll i = 1; i <= x; i += 2)
        {
            ll to = o, te = e;
            if (to >= i)
                to -= i;
            else
                continue;
            if (te >= x - i)
                pos = 1;
        }
        if (pos == 1)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}