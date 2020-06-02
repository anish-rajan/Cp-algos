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
#define N 6
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

bool check(ll n)
{
    ll temp = (ll)log2(n);
    ll temp1 = (ll)pow(2, temp);
    if (temp1 == n)
        return true;
    return false;
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
        if (check(n))
        {
            cout << -1 << "\n";
            continue;
        }
        ll p = 1;
        ll ans = 0;
        while (p < n)
        {
            ll temp = (n - p) / (2 * p) + 1;
            if (p == 1)
                temp--;
            ans += p * temp;
            p *= 2;
        }
        cout << ans << "\n";
    }
}