#include <bits/stdc++.h>


using namespace std;

int main()
{
    int m,n;
    //freopen("output.txt","r",stdin);
    cin>>m;
    string s,st;
    getchar();
    getchar();
    for(int t = 0;t<m;t++)
    {
        printf("Case #%d:\n",t+1);

        while(1)
        {
            int j = 1;
            getline(cin,s);
            if(s=="")
                break;


            for(int i = 0;i<s.size();i++)
            {
                if(s[i]==' ')
                {

                    if(st.size()>=j)
                    {
                        cout<<st[j-1];
                        j++ ;
                    }

                    st.clear();
                }
                else
                    st.push_back(s[i]);
            }
            if(st.size()>=j)
                        cout<<st[j-1];
                    j++ ;
                    st.clear();
            cout<<endl;
        }
        if(t+1!=m)
            cout<<endl;

    }
}

