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
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

v<ll> fact(N);
v<ll> prime_check(1e7 + 2);
v<ll> primes;

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

void Sieve()
{
    for (ll i = 2; i <= 1e7 + 1; i++)
    {
        if (prime_check[i])
            continue;
        primes.pb(i);
        for (ll j = 2 * i; j <= 1e7 + 1; j += i)
            prime_check[j] = i;
    }
}
ll phi(ll n)
{
    ll i, res = n;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    if (n > 1)
        res -= res / n;
    return res;
}

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

ll t;

struct DSU
{
    using S = long long int;
    S n;
    vector<S> parent;
    v<S> a, b;
    vector<S> size;

    DSU(S no)
    {
        n = no;
        parent.resize(n + 1);
        size.resize(n + 1);
        a.resize(n + 1), b.resize(n + 1);
        for (S i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    S find_set(S v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(S x, S y)
    {
        x = find_set(x);
        y = find_set(y);
        if (x != y)
        {
            ld a1 = a[x], b1 = b[x], a2 = a[y], b2 = b[y];
            ld temp = (a1 + a2) / (b1 + b2), temp1 = (a1 / b1), temp2 = (a2 / b2);
            if (temp >= max(temp1, temp2))
            {
                if (size[x] < size[y])
                    swap(x, y);
                parent[y] = x;
                size[x] += size[y];
                a[x] += a[y], b[x] += b[y];
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        DSU dsu(n);
        for (ll i = 1; i <= n; i++)
            cin >> dsu.a[i];
        for (ll i = 1; i <= n; i++)
            cin >> dsu.b[i];
        for (ll i = 1; i <= m; i++)
        {
            ll a, b;
            cin >> a >> b;
            dsu.union_sets(a, b);
        }
        ld maxans = -1, vert = 0, sz = 0;
        for (ll i = 1; i <= n; i++)
        {
            ld temp = (1.0 * dsu.a[i]) / dsu.b[i];
            if (maxans < temp && dsu.find_set(i) == i)
            {
                vert = i, maxans = temp, sz = dsu.size[i];
            }
            else if (maxans == temp && dsu.size[i] > sz && dsu.find_set(i) == i)
                vert = i, sz = dsu.size[i];
        }
        cout << dsu.size[vert] << "\n";
        for (ll i = 1; i <= n; i++)
        {
            if (dsu.find_set(i) == vert)
                cout << i << " ";
        }
        cout << "\n";
    }
}