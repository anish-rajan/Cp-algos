#pragma region predefinition
#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).size())
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define rep(i, n) FOR(i, 1, (n))
#define rept(i, n) FOR(i, 0, (n)-1)
#define C(a) memset((a), 0, sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int, int>
#define pdd pair<double, double>
#define sqr(a) (a) * (a)
#define D(a, b) sqrt(((a).x - (b).x) * ((a).x - (b).x) + ((a).y - (b).y) * ((a).y - (b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define rnd() ((rand() << 16) ^ rand())
#pragma endregion
#define x first.first
#define y first.second

struct edge
{
    int a, b, w, id;
    edge() {}
};

inline bool c1(const edge &a, const edge &b)
{
    if (a.w != b.w)
        return a.w < b.w;
    return a.id < b.id;
}

int p[111111];

int who(int qx)
{
    if (p[qx] == -1)
        return qx;
    return p[qx] = who(p[qx]);
}

void un(int qx, int qy)
{
    int sx = who(qx),
        sy = who(qy);
    if (rand() & 1)
    {
        p[sx] = sy;
    }
    else
    {
        p[sy] = sx;
    }
}

vector<int> res;
vector<vector<int>> g, id;
vector<bool> used;
int timer;
vector<int> tin, fup;

void dfs(int v, int p = -1)
{
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        cout << v << " " << p << " " << g[v][i] << " " << id[v][i] << endl;
        if (id[v][i] == p)
            continue;
        if (used[to])
            fup[v] = min(fup[v], tin[to]);
        else
        {
            dfs(to, id[v][i]);
            fup[v] = min(fup[v], fup[to]);
            // cout << to << " " << fup[to] << " " << tin[v] << " " << v << endl;
            if (fup[to] > tin[v])
                res[id[v][i]] = 1;
        }
    }
}

void find_bridges()
{
    timer = 0;
    tin.assign(L(g), false);
    fup.assign(L(g), false);
    for (int i = 0; i < L(g); ++i)
        used[i] = false;
    for (int i = 0; i < L(g); ++i)
        if (!used[i])
            dfs(i);
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
#endif
    memset(p, -1, sizeof(p));
    int n, m;
    scanf("%d%d", &n, &m);
    vector<edge> e(m);
    rept(i, m)
    {
        scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w);
        e[i].id = i;
    }

    res.assign(m, 0);
    sort(all(e), c1);
    rept(i, m)
    {
        if (i && e[i].w == e[i - 1].w)
            continue;
        vector<pair<pii, int>> ed;
        vector<int> ver;

        for (int j = i; j < m && e[i].w == e[j].w; j++)
        {
            if (who(e[j].a) != who(e[j].b))
            {
                ed.pb(mp(mp(who(e[j].a), who(e[j].b)), e[j].id));
                ver.pb(who(e[j].a));
                ver.pb(who(e[j].b));
                res[e[j].id] = 2;
            }
        }

        UN(ver);
        map<int, int> mver;
        rept(j, L(ver)) mver[ver[j]] = j;

        g.assign(L(ver), vector<int>());
        id.assign(L(ver), vector<int>());
        used.assign(L(ver), false);

        rept(j, L(ed))
        {
            cout << i << " " << ed[j].x << " " << ed[j].y << endl;
            ed[j].x = mver[ed[j].x];
            ed[j].y = mver[ed[j].y];
            g[ed[j].x].pb(ed[j].y);
            g[ed[j].y].pb(ed[j].x);
            id[ed[j].x].pb(ed[j].second);
            id[ed[j].y].pb(ed[j].second);
        }

        find_bridges();

        for (int j = i; j < m && e[i].w == e[j].w; j++)
        {
            if (who(e[j].a) != who(e[j].b))
            {
                un(e[j].a, e[j].b);
            }
        }
    }

    rept(i, m)
    {
        if (res[i] == 0)
        {
            puts("none");
        }
        else
        {
            if (res[i] == 1)
                puts("any");
            else
            {
                puts("at least one");
            }
        }
    }

    return 0;
}