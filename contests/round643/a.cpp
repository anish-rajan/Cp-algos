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
pair<ll, ll> comp(ll a)
{
    ll mini = 10, maxi = 0;
    while (a > 0)
    {
        mini = min(a % 10, mini);
        maxi = max(a % 10, maxi);
        a /= 10;
    }
    return mp(mini, maxi);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll a, k;
        cin >> a >> k;
        k--;
        while (k--)
        {
            auto temp = comp(a);
            ll temp1 = temp.fi * temp.se;
            if (temp1 == 0)
                break;
            a += temp1;
        }
        cout << a << "\n";
    }
}