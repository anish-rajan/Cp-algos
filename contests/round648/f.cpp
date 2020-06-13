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
#define N 505
#define mod 1000000007
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);

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

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll C(ll n, ll r)
{
    if (n < r)
        return 0;
    ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
    temp *= powmod(fact[n - r], mod - 2, mod);
    temp %= mod;
    return temp;
}

/////////////////////////////////////START CODE HERE////////////////////////////////////////////

ll t;
ll n, m;
v<ll> a(N), b(N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        for (ll i = 1; i <= n; i++)
            cin >> b[i];
        multiset<pair<ll, ll>> a1, b1;
        for (ll i = 1; i <= n / 2; i++)
        {
            a[i] > a[n - i + 1] ? a1.insert(mp(a[n - i + 1], a[i])) : a1.insert(mp(a[i], a[n - i + 1]));
            b[i] > b[n - i + 1] ? b1.insert(mp(b[n - i + 1], b[i])) : b1.insert(mp(b[i], b[n - i + 1]));
        }
        if (n % 2)
        {
            if (a[n / 2 + 1] != b[n / 2 + 1])
            {
                cout << "No\n";
                continue;
            }
        }
        if (a1 == b1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}