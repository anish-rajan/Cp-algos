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
        string s;
        cin >> s;
        ll n = s.size();
        v<ll> c1(n + 1);
        c1[0] = s[0] == '1' ? 1 : 0;
        for (ll i = 1; i < n; i++)
        {
            if (s[i] == '1')
                c1[i] = c1[i - 1] + 1;
            else
                c1[i] = c1[i - 1];
        }
        ll ans = min(c1[n - 1], n - c1[n - 1]);
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                ans = min(ans, c1[i] + n - i - 1 - (c1[n - 1] - c1[i]));
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                ans = min(ans, i + 1 - c1[i] + c1[n - 1] - c1[i]);
            }
        }
        cout << ans << "\n";
    }
}