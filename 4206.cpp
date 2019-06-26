#include <iostream>
#include <cmath>
using namespace std;
char ch;
int photo[2000][2000] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int k, currentnum = 2 * n * m, cnt = 0;
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> ch;
            photo[i][j] = ch - '0';
        }
 
    int max;
    if (n > m)
        max = n;
    else
        max = m;
    if(max>800) max=sqrt(max);
 
    for (k = 2; k<= max; k++)
    {
        bool flag = true;
        for (int l = 2; l * l <= k; l++)
        {
            if (k % l == 0)
            {
                flag = false;
                break;
            }
            else
                continue;
        }
        if (flag == true)
        {
            cnt = 0;
            for (int i = 0; i < n + k; i = i + k)
            {
                for (int j = 0; j < m + k; j = j + k)
                {
                    int num = 0;
                    for (int x = i; x < i + k; x++)
                    {
                        for (int y = j; y < j + k; y++)
                        {
                            if (photo[x][y] == 0)
                                num++;
                        }
                    }
                    if (num > k * k - num)
                        num = k * k - num;
 
                    cnt += num;
                    if (cnt > currentnum)
                        break;
                }
                if (cnt > currentnum)
                    break;
            }
            if (currentnum > cnt)
                currentnum = cnt;
        }
    }
    cout << currentnum << endl;
    return 0;
}
