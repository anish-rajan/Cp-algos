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
#define N 200005
#define mod 998244353
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
ll m;
v<ll> a(N), b(N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll j = 1; j <= m; j++)
        cin >> b[j];
    b[m + 1] = INF;
    b[0] = b[1];
    ll j = 1;
    ll ans = 1;
    ll currbeg = 1, cur = 1, length = 0;
    for (ll i = 1; i <= m + 1; i++)
    {
        while (a[j] != b[i])
        {
            if (a[j] > b[i])
                length++;
            else
                length = 0;
            if (a[j] == b[i - 1])
                cur = j;
            else if (a[j] < b[i - 1])
            {
                ans = 0;
                break;
            }
            j++;
            if (j == n + 1)
            {
                if (i < m + 1)
                    ans = 0;
                break;
            }
        }
        if (i > 2)
            ans = (ans * (((cur - currbeg + 1) * (length + 1)) % mod)) % mod;
        else if (i > 1)
            ans = (ans * (length + 1)) % mod;
        currbeg = cur = j;
        // cout << ans << " ";
    }
    if (j < n)
        ans = 0;
    cout << ans << "\n";
}