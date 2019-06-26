#include <iostream>
#include <cstring>


using namespace std;




int main()

{

    char str1[101], str2[101];

    cin >> str1;

    cin >> str2;

    int len = strlen(str1), div = 1;

    bool cond = true;

    for (div; div<len; div++)

    {

        if (!(len%div))

        {

            int n = len / div;

            for (int i = 0; i<div; i++)

            {

                for (int j = 0; j<n; j++)

                {

                    if (str1[i + j*div] != str2[i*n + j])

                    {

                        cond = false;

                        break;

                    }

                    else

                        cond = true;

                }

                if (!cond)

                    break;

            }

        }

        if (cond)

            break;

    }

    if (cond)

        cout << div;

    else

        cout << "No Solution";

    return 0;

}
