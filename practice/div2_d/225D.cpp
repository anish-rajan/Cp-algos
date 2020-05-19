#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define N 17
const ll dx[] = {-1, 0, 1, 0};
const ll dy[] = {0, 1, 0, -1};
ll n, m, k;
v<string> s(N);
v<pair<ll, ll>> snake(10);
v<ll> dist(15000000);

ll valid(v<pair<ll, ll>> snake, ll x, ll y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#')
        return 0;
    for (ll i = 1; i < k - 1; i++)
    {
        if (snake[i].fi == x && snake[i].se == y)
            return 0;
    }
    return 1;
}

v<pair<ll, ll>> move(v<pair<ll, ll>> snake, ll dir)
{
    v<pair<ll, ll>> snake1;
    if (!valid(snake, snake[0].fi + dx[dir], snake[0].se + dy[dir]))
        return snake1;
    snake1.pb(mp(snake[0].fi + dx[dir], snake[0].se + dy[dir]));
    for (ll i = 0; i < k - 1; i++)
        snake1.pb(snake[i]);
    return snake1;
}

ll dir(pair<ll, ll> seg1, pair<ll, ll> seg2)
{
    if (seg1.fi == seg2.fi)
        return seg1.se > seg2.se ? 3 : 1;
    else
        return seg1.fi > seg2.fi ? 0 : 2;
}

void decode(v<pair<ll, ll>> &snake, ll val)
{
    v<ll> d(10);
    for (ll i = 0; i < k - 1; i++)
    {
        d[k - 1 - i] = val % 4;
        val /= 4;
    }
    snake[0].se = val % 15;
    snake[0].fi = val / 15;
    for (ll i = 1; i < k; i++)
    {
        snake[i].fi = snake[i - 1].fi + dx[d[i]];
        snake[i].se = snake[i - 1].se + dy[d[i]];
    }
}

ll encode(v<pair<ll, ll>> snake)
{
    ll temp = snake[0].fi * 15 + snake[0].se;
    // cout << snake[0].fi << " " << snake[0].se << "\n";
    for (ll i = 1; i < k; i++)
    {
        temp = temp * 4 + dir(snake[i - 1], snake[i]);
    }
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
        for (ll j = 0; j < m; j++)
        {
            if (s[i][j] >= '1' && s[i][j] <= '9')
            {
                snake[s[i][j] - '0' - 1].fi = i;
                snake[s[i][j] - '0' - 1].se = j;
                // cout << snake[s[i][j] - '0' - 1].fi << endl;
                k = max(k, (ll)s[i][j] - '0');
            }
        }
    }
    queue<ll> nodes;
    ll st = encode(snake);
    dist[st] = 1;
    nodes.push(st);
    // cout << st << "\n";
    while (!nodes.empty())
    {
        st = nodes.front();
        nodes.pop();
        decode(snake, st);
        // cout << snake[0].fi << " " << snake[0].se << " " << snake[1].fi << " " << snake[1].se << " " << snake[2].fi << " " << snake[2].se << " " << snake[3].fi << " " << snake[3].se << "\n";
        // cout << st << "\n";
        if (s[snake[0].fi][snake[0].se] == '@')
        {
            cout << dist[st] - 1 << "\n";
            return 0;
        }
        for (ll i = 0; i < 4; i++)
        {
            vector<pair<ll, ll>> snake1;
            snake1 = move(snake, i);
            if (snake1.empty())
                continue;
            ll p = encode(snake1);
            // cout << p << " " << snake1[0].fi << " " << snake1[0].se << " " << snake1[1].fi << " " << snake1[1].se << " " << snake1[2].fi << " " << snake1[2].se << " " << snake1[3].fi << " " << snake1[3].se << "\n";
            // cout << st << " " << p << "\n";
            if (!dist[p])
            {
                dist[p] = dist[st] + 1;
                nodes.push(p);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}