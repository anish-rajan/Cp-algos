#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double ld;
#define N 1002
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
int diameter[10001];

ll n;
v<v<ll>> gr(N);
ll dfs(ll u, v<ll> &visited, ll v1)
{
    // cout << u << "\n";
    visited[u] = 1;
    if (u == v1)
        return 1;
    ll p = 0;
    for (ll i = 0; i < gr[u].size(); i++)
    {
        if (!visited[gr[u][i]])
        {
            p = dfs(gr[u][i], visited, v1);
            if (p == 1)
                return p;
        }
    }
    return p;
}

// The Function to do bfs traversal.
// It uses iterative approach to do bfs
// bfsUtil()
int bfs(int init, vector<v<int>> arr, int n)
{
    // Initializing queue
    queue<int> q;
    q.push(init);

    int visited[n + 1];
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
        diameter[i] = 0;
    }

    // Pushing each node in queue
    q.push(init);

    // Mark the traversed node visited
    visited[init] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < arr[u].size(); i++)
        {
            if (visited[arr[u][i]] == 0)
            {
                visited[arr[u][i]] = 1;

                // Considering weight of edges equal to 1
                diameter[arr[u][i]] += diameter[u] + 1;
                q.push(arr[u][i]);
            }
        }
    }

    // return index of max value in diameter
    return int(max_element(diameter + 1,
                           diameter + n + 1) -
               diameter);
}

pair<int, int> findDiameter(ll given, vector<v<int>> arr, int n)
{
    int init = bfs(given, arr, n);
    int val = bfs(init, arr, n);
    return mp(init, val);
}
void input_graph(long long int n)
{
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << 1 << "\n";
    cin >> n;
    input_graph(n);
    ll given = 1;

    while (1)
    {
        pair<ll, ll> temp = findDiameter(given, gr, n);
        cout << "? " << temp.fi << " " << temp.se << endl;
        cout.flush();
        ll temp1;
        cin >> temp1;
        if (temp1 == temp.fi || temp1 == temp.se)
        {
            cout << "! " << temp1 << "\n";
            return 0;
        }
        else
        {
            given = temp1;
            v<ll> visited(N);
            for (ll i = 1; i < N; i++)
                visited[i] = 0;
            ll pos;
            visited[temp1] = 1;
            for (ll i = 0; i < gr[temp1].size(); i++)
            {
                ll p = dfs(gr[temp1][i], visited, temp.fi);
                if (p == 1)
                {
                    pos = i;
                    // cout << gr[temp1][i] << " " << temp.fi << endl;
                    cout.flush();
                    break;
                }
            }
            for (ll i = 1; i < N; i++)
                visited[i] = 0;
            gr[temp1].erase(gr[temp1].begin() + pos);
            visited[temp1] = 1;
            for (ll i = 0; i < gr[temp1].size(); i++)
            {
                ll p = dfs(gr[temp1][i], visited, temp.se);
                if (p == 1)
                {
                    pos = i;
                    break;
                }
            }
            gr[temp1].erase(gr[temp1].begin() + pos);
            if (gr[temp1].size() == 0)
            {
                cout << "! " << temp1 << "\n";
                return 0;
            }
        }
    }
}