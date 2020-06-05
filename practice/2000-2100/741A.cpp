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
#define N 102
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

ll lcm(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    return (a * b) / __gcd(a, b);
}

/////////////////////////////////////START CODE HERE////////////////////////////////////////////

ll n;
v<ll> a(N), visited(N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 1;
    ll pos = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ll sz = 0, j = i;
            while (!visited[j])
            {
                visited[j] = 1;
                sz++;
                j = a[j];
            }
            if (j == i)
            {
                if (sz % 2 == 0)
                    ans = lcm(ans, sz / 2);
                else
                    ans = lcm(ans, sz);
            }
            else
            {
                pos = 0;
                break;
            }
        }
    }
    if (pos == 0)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}