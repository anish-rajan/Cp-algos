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

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);

long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
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

ll n;
v<ll> a(N);
v<set<ll>> divs(N);
v<ll> prime_check(1e7 + 2);
v<ll> primes;
v<ll> ans1(N), ans2(N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    for (ll i = 2; i <= 1e7 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e7 + 1; j += i)
            prime_check[j] = i;
    }
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
    {
        ll temp = a[i];
        while (prime_check[temp])
        {
            divs[i].insert(prime_check[temp]);
            temp /= prime_check[temp];
        }
        if (temp > 1)
            divs[i].insert(temp);
    }
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (auto x : divs[i])
    //         cout << x << " ";
    //     cout << "\n";
    // }
    for (ll i = 1; i <= n; i++)
    {
        if (divs[i].size() >= 2)
        {
            ll a1 = 1, a2 = *(divs[i].begin());
            for (auto x : divs[i])
                a1 *= x;
            a1 /= a2;
            ans1[i] = a1, ans2[i] = a2;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (ans1[i])
            cout << ans1[i] << " ";
        else
            cout << -1 << " ";
    }
    cout << "\n";
    for (ll i = 1; i <= n; i++)
    {
        if (ans2[i])
            cout << ans2[i] << " ";
        else
            cout << -1 << " ";
    }
    cout << "\n";
}