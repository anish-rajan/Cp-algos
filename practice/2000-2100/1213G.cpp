#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 200005
#define mod 998244353

//declaration of variables
ll n, m, currans;                // n stores no of vertices,m- no of queries, currans-stores the answer of current query
v<pair<ll, pair<ll, ll>>> gr(N); // it stores the edges of the graph. first=weight,second.first=first vertex, second.second=second vertex
v<pair<ll, ll>> queries(N);      //stores queries,first=query weight,second=index of query
v<ll> ans(N);                    // stores the final answer of all queries

// this is the disjoint set union data structure
struct DSU
{
    using S = long long int;
    S n;
    vector<S> parent; // checks if two vertices are in same cycle
    vector<S> size;   //maintains size of the set that vertex belongs to

    DSU(S no)
    {
        n = no;
        parent.resize(n + 1);
        size.resize(n + 1);
        for (S i = 1; i <= n; i++)
        {
            parent[i] = i; //initially all have same parent
            size[i] = 1;
        }
    }

    // finds the parent of the vertex v. works in O(1).
    S find_set(S v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    // performs union of 2 sets.
    void union_sets(S a, S b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            // first we subtract the no of paths between vertices in different sets.
            currans -= (size[b] * (size[b] - 1)) / 2;
            currans -= (size[a] * (size[a] - 1)) / 2;
            size[a] += size[b];
            // no we add the new no of paths after we have performed the union.
            currans += (size[a] * (size[a] - 1)) / 2;
        }
    }
};

// taking input of edges of graph
void input_graph(long long int n)
{
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> gr[i].second.first >> gr[i].second.second >> gr[i].first;
    }
}

// taking input of queries of graph
void input_queries(long long int n)
{
    for (ll i = 0; i < n; i++)
    {
        cin >> queries[i].first;
        queries[i].second = i;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;                              // input vertex and no of queries
    input_graph(n);                             //input graph
    input_queries(m);                           // input queries
    sort(gr.begin(), gr.begin() + n - 1);       // sorting the graph acc to first element that is weight of edge
    sort(queries.begin(), queries.begin() + m); //sorting queries acc to weights.
    DSU dsu(n);                                 // initializing the data structure.
    ll idx = 0;                                 // points to the current edge in graph.

    for (ll i = 0; i < m; i++) //loop querying through edges
    {
        for (; idx < n - 1; idx++) // loop querying through graph edges
        {
            if (gr[idx].first > queries[i].first) // if edge weight is greater than current query weight breaks the loop
                break;
            dsu.union_sets(gr[idx].second.first, gr[idx].second.second); // otherwise joins that edge in graph and recalculates currans.
        }
        ans[queries[i].second] = currans; //assigns currans to that query index.
    }

    //output answers
    for (ll i = 0; i < m; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}