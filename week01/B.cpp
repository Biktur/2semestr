#include<iostream>
#include<climits>
using std::cin;
using std::cout;
using std::endl;


int main()
{
    int N, M, fc[20][20], a;
    cin >> M >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> fc[i][j];
    cin >> a;

    if (a == 0)
    {
        cout << fc[0][0] << endl;
        return 0;
    }    

    int res = 0, fch[20][20];

    while (a > 0)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
               fch[i][j] = INT_MIN;
        fch[0][0] = fc[0][0];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (i < N - 1) 
                    if (fch[i + 1][j] < fch[i][j] + fc[i + 1][j])
                        fch[i + 1][j] = fch[i][j] + fc[i + 1][j];
                if (j < M - 1)
                    if (fch[i][j + 1] < fch[i][j] + fc[i][j + 1])
                        fch[i][j + 1] = fch[i][j] + fc[i][j + 1];
            }    
        if (a >= N + M - 2)
        {
            res += fch[N - 1][M - 1];
            int icur = N - 1, jcur = M - 1;
            while (icur >= 0 && jcur >= 0)
            {
                fc[icur][jcur] = 0; 
                if (icur == 0) jcur--;
                else if (jcur == 0) icur--;
                else
                {
                    if (fch[icur - 1][jcur] > fch[icur][jcur - 1])
                        icur--;
                    else
                        jcur--;
                }
            }
        }
        else
        {
            int max = INT_MIN;
            for (int i = 0; i < a + 1; i++)
                if (i < N && a - i < M)
                    if (max < fch[i][a - i])
                        max = fch[i][a - i];
            res += max;
        }
        a -= N + M - 2;
    }

    cout << res << endl;
    return 0;
}