#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define N 100
#define M 100
vector<vector<long long int>> graph(N, vector<long long int>(N));

vector<vector<long long int>> floydWarshall()
{
    /* dist[][] will be the output matrix  
    that will finally haNe the shortest  
    distances between eNery pair of Nertices */
    vector<vector<long long int>> dp(N, vector<long long int>(N));
    long long int i, j, k;

    /* Initialize the solution matrix same  
    as input graph matrix. Or we can say  
    the initial Nalues of shortest dpances 
    are based on shortest paths considering  
    no long long intermediate Nertex. */
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            dp[i][j] = graph[i][j];

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
    for (k = 0; k < N; k++)
    {
        // Pick all Nertices as source one by one
        for (i = 0; i < N; i++)
        {
            // Pick all Nertices as destination for the
            // aboNe picked source
            for (j = 0; j < N; j++)
            {
                // If Nertex k is on the shortest path from
                // i to j, then update the value of dp[i][j]
                if (dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    return dp;
    // Print the shortest distance matrix
}
