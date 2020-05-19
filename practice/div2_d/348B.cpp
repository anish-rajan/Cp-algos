#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 100005
// #define mp make_pair
// #define v vector
// #define pb push_back
// #define fi first
// #define se second
// #define ALL(v) v.begin(), v.end()
ll n;
vector<ll> a(N);
vector<ll> dp(N), decv(N);
vector<vector<ll>> graph(N);
vector<ll> visited(N);

ll lcm(ll val1, ll val2)
{
    if (__gcd(val1, val2) != 0)
        return (val1 * val2) / (__gcd(val1, val2));
    else
        return val1 * val2;
}

// long long int gcd(long long int a, long long int b, long long int &x, long long int &y)
// {
//     if (a == 0)
//     {
//         x = 0;
//         y = 1;
//         return b;
//     }
//     long long int x1, y1;
//     long long int d = gcd(b % a, a, x1, y1);
//     x = y1 - (b / a) * x1;
//     y = x1;
//     return d;
// }
// // to find any solution
// bool find_any_solution(long long int a, long long int b, long long int c, long long int &x0, long long int &y0, long long int &g)
// {
//     g = gcd(abs(a), abs(b), x0, y0);
//     if (c % g)
//     {
//         return false;
//     }

//     x0 *= c / g;
//     y0 *= c / g;
//     if (a < 0)
//         x0 = -x0;
//     if (b < 0)
//         y0 = -y0;
//     return true;
// }

// // to find solutions in a given range
// void shift_solution(long long int &x, long long int &y, long long int a, long long int b, long long int cnt)
// {
//     x += cnt * b;
//     y -= cnt * a;
// }

// long long int find_min_moves(long long int a, long long int b, long long int c, ll &x, ll &y)
// {
//     long long int g;
//     if (!find_any_solution(a, b, c, x, y, g))
//         return -1;
//     a /= g;
//     b /= g;

//     long long int sign_a = a > 0 ? +1 : -1;
//     long long int sign_b = b > 0 ? +1 : -1;

//     shift_solution(x, y, a, b, (0 - x) / b);
//     if (x < 0)
//         shift_solution(x, y, a, b, sign_b);
//     long long int lx1 = x;
//     ll ly1 = y;

//     shift_solution(x, y, a, b, -(0 - y) / a);
//     if (y < 0)
//         shift_solution(x, y, a, b, -sign_a);
//     ll lx2 = x, ly2 = y;

//     if (lx1 < 0 || ly1 < 0)
//     {
//         lx1 = lx2, ly1 = ly2;
//     }
//     if (lx2 < 0 || ly2 < 0)
//     {
//         lx2 = lx1, ly2 = ly1;
//     }
//     if (lx1 < 0 || ly1 < 0)
//         return -1;
//     if (abs(a) * lx1 + abs(b) * ly1 < abs(a) * lx2 + abs(b) * ly2)
//         x = lx1, y = ly1;
//     else
//         x = lx2, y = ly2;
//     return min(abs(a) * lx1 + abs(b) * ly1, abs(a) * lx2 + abs(b) * ly2);
// }

void dfs(ll u, ll par, ll &moves)
{
    visited[u] = 1;
    decv[u] = 1;
    dp[u] = a[u];
    ll temp = INT64_MAX, child = 0, temp1 = 0, mov = 0, red_value = dp[child], k = max((ll)1, (ll)graph[u].size() - 1);
    for (ll i = 0; i < graph[u].size(); i++)
    {
        if (!visited[graph[u][i]])
        {
            dfs(graph[u][i], u, moves);
            if (temp > dp[graph[u][i]])
            {
                temp = dp[graph[u][i]];
                child = graph[u][i];
            }
            dp[u] += dp[graph[u][i]];
            decv[u] = lcm(decv[u], decv[graph[u][i]]);
        }
    }
    if (u == 1)
        k++;
    if (graph[u].size() > 1)
    {
        decv[u] *= k;
        ll t = decv[u] / k;
        ll x = temp / t;
        x *= t;
        moves += dp[u] - k * x;
        dp[u] = k * x;
    }
    // cout << u << " " << dp[u] << " " << decv[u] << " " << moves << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (long long int i = 0; i < n - 1; i++)
    {
        long long int u, s;
        cin >> u >> s;
        graph[u].push_back(s);
        graph[s].push_back(u);
    }
    ll moves = 0;
    dfs(1, 0, moves);
    cout << moves << '\n';
}