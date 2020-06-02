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
#define N 400005
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
        ll n, k;
        cin >> n >> k;
        v<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        set<ll> pows;
        ll pos = 1;
        for (ll i = 1; i <= n; i++)
        {
            ll c = 0;
            while (a[i] > 0)
            {
                ll temp = a[i] % k;
                if (!(temp == 1 || temp == 0))
                {
                    pos = 0;
                }
                else if (temp == 1)
                {
                    if (pows.find(c) != pows.end())
                        pos = 0;
                    else
                        pows.insert(c);
                }
                a[i] /= k;
                c++;
            }
        }
        if (pos == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}