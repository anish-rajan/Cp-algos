#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
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
#define N 5001
#define mod 1000000007
#define INF INT_MAX

ll n;
v<ll> a(N), b(N), f, ans(N);
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
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll neg = (a[i] < 0);
        ll num = 1;
        a[i] = abs(a[i]);
        if (a[i] != 0)
        {
            for (ll j = 2; j * j <= a[i]; j++)
            {
                ll cnt = 0;
                while (a[i] % j == 0)
                {
                    cnt++;
                    a[i] /= j;
                }
                if (cnt % 2)
                    num *= j;
            }
            if (a[i] > 0)
                num *= a[i];
            if (neg == 1)
                num *= -1;
            a[i] = num;
        }
        f.pb(a[i]);
        b[i] = a[i];
    }
    sort(f.begin(), f.end());
    UN(f);
    // for (ll i = 0; i < n; i++)
    //     cout << f[i] << " ";
    // cout << "\n";
    for (ll i = 1; i <= n; i++)
        a[i] = lower_bound(f.begin(), f.end(), a[i]) - f.begin();
    ans[1] += n;
    for (ll i = 1; i <= n; i++)
    {
        // cout << a[i] << " ";
        v<ll> seen(n + 2, 0);
        ll gps = 0;
        if (b[i])
        {
            seen[a[i]]++;
            gps++;
        }
        for (ll j = i + 1; j <= n; j++)
        {
            if (b[j] && !seen[a[j]])
            {
                seen[a[j]]++;
                gps++;
            }
            ans[max(1, gps)]++;
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}