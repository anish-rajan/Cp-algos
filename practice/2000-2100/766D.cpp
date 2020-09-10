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

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
v<ll> prime_check(N);
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

// void init_fact()
// {
//     fact[0] = 1;
//     for (ll i = 1; i < N; i++)
//     {
//         fact[i] = (fact[i - 1] * i) % mod;
//     }
// }

// ll C(ll n, ll r)
// {
//     if (n < r)
//         return 0;
//     ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
//     temp *= powmod(fact[n - r], mod - 2, mod);
//     temp %= mod;
//     return temp;
// }

// void Sieve()
// {
//     for (ll i = 2; i < 1e8; i++)
//     {
//         if (prime_check[i])
//             continue;
//         primes.pb(i);
//         for (ll j = 2 * i; j < 1e8; j += i)
//             prime_check[j] = i;
//     }
// }
// ll phi(ll n)
// {
//     ll i, res = n;
//     for (i = 2; i * i <= n; i++)
//         if (n % i == 0)
//         {
//             while (n % i == 0)
//                 n /= i;
//             res -= res / i;
//         }
//     if (n > 1)
//         res -= res / n;
//     return res;
// }

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

ll n, m, q;
map<string, ll> c;
ll cur;


struct DSU
{
    using S = long long int;
    S n;
    vector<S> parent;
    vector<S> size;
    vector<S> hate;
    DSU(S no)
    {
        n = no;
        parent.resize(n + 1);
        size.resize(n + 1);
        hate.resize(n+1);
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

    void union_sets(S a, S b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void check(string s)
{
    if (c.find(s)!=c.end())
        return;
    c[s]=++cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    // Sieve();
    cin>>n>>m>>q;
    DSU dsu(n);
    for (ll i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        check(s);
    }
    for (ll i=1;i<=m;i++)
    {
        ll t;
        string a, b;
        cin>>t>>a>>b;
        if (t==1)
        {
            ll p1 = dsu.find_set(c[a]), p2 = dsu.find_set(c[b]);
            ll p3 = dsu.find_set(dsu.hate[p1]), p4 =dsu.find_set(dsu.hate[p2]);
            if (p1==p4)
            {
                cout<<"NO\n";
                continue;
            }
            if (p3!=0 && p4!=0)
            {
                dsu.union_sets(p3, p4);
            }
            p3 = dsu.find_set(p3), p4 = dsu.find_set(p4);
            p3 = max(p3, p4);
            dsu.union_sets(p1, p2);
            if (p3!=0)
            {
                dsu.hate[p3] = dsu.find_set(p1);
                dsu.hate[dsu.find_set(p1)] = dsu.find_set(p3);
            }
            cout<<"YES\n";
        }
        else
        {
            ll p1 = dsu.find_set(c[a]), p2 = dsu.find_set(c[b]);
            ll p3 = dsu.find_set(dsu.hate[p1]), p4 =dsu.find_set(dsu.hate[p2]);
            if (p1==p2)
            {
                cout<<"NO\n";
                continue;
            }
            if (p4!=0)
                dsu.union_sets(p1, p4);
            if (p3!=0)
                dsu.union_sets(p2, p3);
            dsu.hate[dsu.find_set(p1)] = dsu.find_set(p2);
            dsu.hate[dsu.find_set(p2)] = dsu.find_set(p1);
            cout<<"YES\n";
        }
    }
    for (ll i=1;i<=q;i++)
    {
        string a, b;
        cin>>a>>b;
        ll p1 = dsu.find_set(c[a]), p2 = dsu.find_set(c[b]);
        ll p3 = dsu.find_set(dsu.hate[p1]);
        if (p1==p2)
            cout<<"1\n";
        else if ((p2==p3))
            cout<<"2\n";
        else
            cout<<"3\n";
    }

}
