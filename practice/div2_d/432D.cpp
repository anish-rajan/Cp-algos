#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 100005
string s;
ll n;
vector<ll> cnt(N), sum(N);
vector<vector<ll>> graph(N);
vector<ll> visited(N);
ll dfs(ll u)
{
    visited[u] = 1;
    ll sum1 = cnt[u];
    for (ll i = 0; i < graph[u].size(); i++)
    {
        // cout << visited[graph[u][i]] << " " << graph[u][i] << "\n";
        if (!visited[graph[u][i]])
        {
            sum1 += dfs(graph[u][i]);
        }
    }
    sum[u] = sum1;
    // cout << sum1 << " " << u << "\n";
    return sum1;
}
void createGraph(vector<ll> pi)
{
    for (ll i = 0; i < n; i++)
    {
        graph[pi[i]].push_back(i + 1);
    }
}
vector<long long int> prefix_function(string s)
{
    long long int n = (long long int)s.length();
    vector<long long int> pi(n);
    for (long long int i = 1; i < n; i++)
    {
        long long int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    n = s.size();
    vector<ll> pi = prefix_function(s);
    for (ll i = 0; i < n; i++)
    {
        cnt[pi[i]]++;
    }

    createGraph(pi);
    dfs(0);
    vector<pair<ll, ll>> ans;
    ll i = n - 1;
    ans.push_back(make_pair(i + 1, 1));
    i = pi[i] - 1;
    while (i + 1 > 0)
    {
        ans.push_back(make_pair(i + 1, sum[i + 1] + 1));
        i = pi[i] - 1;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}