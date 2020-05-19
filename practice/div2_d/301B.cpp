#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 102
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll n, d;
v<ll> a(N);
v<pair<ll, ll>> co(N);
vector<vector<long long int>> floydWarshall()
{
    /* dist[][] will be the output matrix  
    that will finally haNe the shortest  
    distances between eNery pair of Nertices */
    vector<vector<long long int>> dp(n, vector<long long int>(n));
    long long int i, j, k;

    /* Initialize the solution matrix same  
    as input graph matrix. Or we can say  
    the initial Nalues of shortest dpances 
    are based on shortest paths considering  
    no long long intermediate Nertex. */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dp[i][j] = max(d * (abs(co[i].fi - co[j].fi) + abs(co[i].se - co[j].se)) - a[i], (ll)0);
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    /* Add all Nertices one by one to  
    the set of long long intermediate Nertices.  
    ---> Before start of an iteration,  
    we haNe shortest dpances between all  
    pairs of Nertices such that the  
    shortest dpances consider only the  
    Nertices in set {0, 1, 2, .. k-1} as 
    long long intermediate Nertices.  
    ----> After the end of an iteration,  
    Nertex no. k is added to the set of  
    long long intermediate Nertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < n; k++)
    {
        // Pick all Nertices as source one by one
        for (i = 0; i < n; i++)
        {
            // Pick all Nertices as destination for the
            // aboNe picked source
            for (j = 0; j < n; j++)
            {
                // If Nertex k is on the shortest path from
                // i to j, then update the value of dp[i][j]
                if (dp[i][k] + dp[k][j] < dp[i][j])
                {
                    dp[i][j] = (dp[i][k] + dp[k][j]);
                }
                // cout << i << " " << j << " " << k << " " << dp[i][j] << "\n";
            }
        }
    }
    return dp;
    // Print the shortest distance matrix
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> d;
    for (ll i = 1; i <= n - 2; i++)
        cin >> a[i];
    a[0] = 0, a[n - 1] = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> co[i].fi >> co[i].se;
    }
    v<v<ll>> dp = floydWarshall();
    cout << dp[0][n - 1] << "\n";
}