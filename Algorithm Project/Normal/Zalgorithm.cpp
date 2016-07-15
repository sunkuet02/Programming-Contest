int z[mx] ;
string s;
int zAlgorithm(int m)
{
    int n = s.size();
    int cnt = 0 ;
    int L = 0, R = 0;
    z[0] = 0 ;
    for (int i = 1; i <= n-m; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && s[R-L] == s[R])
                R++;
            z[i] = R-L;
            R--;
        }
        else
        {
            int k = i-L;
            if (z[k] < R-i+1)
                z[i] = z[k];
            else
            {
                L = i;
                while (R < n && s[R-L] == s[R])
                    R++;
                z[i] = R-L;
                R--;
            }
        }
        if(z[i]==m)
            cnt ++ ;

    }
    printf("%d\n",cnt);
}