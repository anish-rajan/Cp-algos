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
#define N 300005
#define mod 1000000007
ll t;
struct cmp
{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b) const
    {
        if (a.fi == b.fi)
            return a.se < b.se;
        else
            return a.fi > b.fi;
    }
};

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
        ll n;
        cin >> n;
        v<ll> a(n + 1);
        set<pair<ll, ll>, cmp> subs;
        subs.insert(mp(n, 1));
        ll i = 1;
        while (!subs.empty())
        {
            auto temp = *(subs.begin());
            subs.erase(temp);
            ll l = temp.se, len = temp.fi, mid;
            if (temp.fi % 2)
                mid = (2 * l + len - 1) / 2;
            else
                mid = (2 * l + len - 2) / 2;
            a[mid] = i++;
            if (mid - l > 0)
                subs.insert(mp(mid - l, l));
            if (l + len - 1 - mid > 0)
                subs.insert(mp(l + len - 1 - mid, mid + 1));
        }
        for (ll i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}