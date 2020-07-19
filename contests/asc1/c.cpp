#include <bits/stdc++.h>
using namespace std;

#define double long double
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
#define MOD 998244353
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

const int N = 5e5 + 5;
int dp[N][2];
int ne[N];
vi adj[N];

void dfs(int x, int p = -1)
{
    bool leaf = true;
    for (auto v : adj[x])
    {
        if (v == p)
            continue;
        leaf = false;
        dfs(v, x);
    }
    if (leaf)
        return;
    int &dTake = dp[x][0];
    int &take = dp[x][1];
    for (auto v : adj[x])
    {
        if (v == p)
            continue;
        dTake += max(dp[v][0], dp[v][1]);
    }
    take = 0;
    for (auto v : adj[x])
    {
        if (v == p)
            continue;
        int exp = dTake - max(dp[v][1], dp[v][0]) + dp[v][0] + 1;
        if (exp >= take)
        {
            take = exp;
            ne[x] = v;
        }
    }
}

vi ans;

void reconstruct(int x, int state, int p = -1)
{
    if (state == 1)
    {
        for (auto i : adj[x])
        {
            if (i == p)
                continue;
            if (i == ne[x])
            {
                reconstruct(i, 0, x);
                ans.pb(i + 1);
            }
            else
            {
                if (dp[i][0] >= dp[i][1])
                    reconstruct(i, 0, x);
                else
                    reconstruct(i, 1, x);
            }
        }
    }
    else
    {
        for (auto v : adj[x])
        {
            if (v == p)
                continue;
            if (dp[v][0] >= dp[v][1])
                reconstruct(v, 0, x);
            else
                reconstruct(v, 1, x);
        }
    }
}

int32_t main(void)
{
    FASTER;
    freopen("grant.in", "r", stdin);
    freopen("grant.out", "w", stdout);
    int i, j;
    int n;
    SI(n);
    memset(ne, -1, sizeof(ne));
    F(i, 1, n)
    {
        int x;
        SI(x);
        --x;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    dfs(0);
    int muow = max(dp[0][0], dp[0][1]) * 1000;
    SO(muow);
    if (dp[0][0] > dp[0][1])
        reconstruct(0, 0);
    else
        reconstruct(0, 1);
    sort(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
#ifdef LOCAL
    cout << endl
         << endl
         << "Time: " << (float)clock() / CLOCKS_PER_SEC << " seconds" << endl;
#endif
    return 0;
}