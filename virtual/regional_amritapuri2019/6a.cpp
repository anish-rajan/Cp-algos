#include <bits/stdc++.h>
using namespace std;

#define double long double
#define int long long
#define ALL(x) x.begin(), x.end()
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb(x) push_back(x)
#define eb emplace_back
#define SORT(ls) sort(ls.begin(), ls.end())
#define DESC(ls) sort(ls.rbegin(), ls.rend())
#define mp(x, y) make_pair(x, y)
#define INF 1000000000
#define F(i, a, n) for (i = a; i < n; i++)
#define SI(x) cin >> x
#define DI(x, y) cin >> x >> y
#define TI(x, y, z) cin >> x >> y >> z
#define FI(w, x, y, z) cin >> w >> x >> y >> z
#define SO(x) cout << x << "\n"
#define DO(x, y) cout << x << " " << y << "\n"
#define TO(x, y, z) cout << x << " " << y << " " << z << "\n"
#define FO(w, x, y, z) cout << w << " " << x << " " << y << " " << z << "\n"
#define FASTER                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int MOD = 1e9 + 7;

const int MAXN = 4e5 + 10;

int factorial[MAXN];

void fillFactorial()
{
    int i;
    factorial[0] = 1;
    F(i, 1, MAXN)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int inverse(int x)
{
    return binpow(x, MOD - 2, MOD);
}

long long combination(int n, int k)
{
    if (n == 0)
        return 1;
    return (factorial[n] * inverse(factorial[k]) % MOD) % MOD * inverse(factorial[n - k]) % MOD;
}

inline int mul(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

int32_t main(void)
{
    FASTER;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, j;
    int t;
    SI(t);
    fillFactorial();
    while (t--)
    {
        int n;
        SI(n);
        int a[n];
        F(i, 0, n)
        SI(a[i]);
        sort(a, a + n);
        int numWays = 1;
        for (int i = 0; i + 1 < n; i++)
        {
            if (a[i + 1] % a[i])
            {
                numWays = 0;
                break;
            }
            int x = a[i + 1] / a[i];
            if (x & (x - 1))
            {
                numWays = 0;
                break;
            }
        }
        if (numWays == 0)
        {
            SO(0);
            continue;
        }
        map<int, int> type1;
        //value->count, numWays
        map<int, ii> type2;
        int fin = 0;
        F(i, 0, n)
        type1[a[i]]++;
        for (auto y : type1)
        {
            int cnt = y.second;
            numWays = 1;
            if (type2.count(y.first))
            {
                numWays = mul(numWays, combination(cnt + type2[y.first].first, cnt));
                numWays = mul(numWays, binpow(type2[y.first].second, type2[y.first].first, MOD));
            }
            int x = (type2[y.first].first + cnt);
            if (x % 2 && x != 1)
            {
                numWays = 0;
                break;
            }
            fin = x / 2;
            type2[2 * y.first] = {x / 2, numWays};
            //TO(type2[2*y.first].first, type2[2*y.first].second, 2*y.first);
        }
        if (fin & (fin - 1))
            numWays = 0;
        SO(numWays);
    }
#ifdef LOCAL
    cout << endl
         << endl
         << "Time: " << (float)clock() / CLOCKS_PER_SEC << " seconds" << endl;
#endif
    return 0;
}