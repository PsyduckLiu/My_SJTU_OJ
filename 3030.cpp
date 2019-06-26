#include <iostream>
 
 
 
using namespace std;
 
#define max(a,b) ((a)>(b))?(a):(b)
 
int main()
 
{
 
    int T, M;
 
    cin >> T >> M;
 
    int **dp;
 
    dp = new int*[M+1];
 
    for (int i = 0; i <=M; ++i)
    {
 
        dp[i] = new int[T + 1];
 
    }
 
 
 
    for (int i = 0; i <= M; ++i)
 
        dp[i][0] = 0;
 
    for (int j = 0; j <= T; ++j)
 
        dp[0][j] = 0;
 
    int w, v;
 
    for (int i = 1; i <= M; ++i)
    {
 
        cin >> w >> v;
 
        for (int j = 1; j <= T; ++j)
        {
 
            if (j >= w)
 
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
 
            else
 
                dp[i][j] = dp[i-1][j];
 
        }
 
    }
 
    cout << dp[M][T] << endl;
 
    for (int i = 0; i <= M; ++i)
 
        delete[] dp[i];
 
    delete[] dp;
 
 
 
    return 0;
 
}
