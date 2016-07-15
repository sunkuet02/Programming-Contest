#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt" , "r" ,stdin);

    stack<int>s;
    queue<int>q;
    priority_queue<int>pq;

    int n ;

    while(scanf("%d",&n)!=EOF)
    {
        while(!s.empty())
            s.pop();
        while(!q.empty())
            q.pop();
        while(!pq.empty())
            pq.pop();

        bool st = true;
        bool qu = true;
        bool pqu = true;
        bool flag = true;

        for(int i = 0 ; i< n ; i++ )
        {
            int a  , b;

            cin>> a >> b;
            if(a==1)
            {
                s.push(b);
                q.push(b);
                pq.push(b);
            }
            else
            {
                if(s.size()==0)
                {
                    flag = false;
                    continue;
                }

                int stak = s.top() ;
                int queu = q.front() ;
                int pqueu  = pq.top();

                if(b != stak)
                {
                    st = false;
                }
                if(b!= queu)
                {
                    qu = false;
                }
                if(b!= pqueu)
                {
                    pqu = false;
                }

                if(b != stak && b!= queu && b!= pqueu)
                {
                    flag =false;
                }

                s.pop();
                q.pop();
                pq.pop();
            }
        }
        if(!flag || (!st && !qu && !pqu))
        {
            cout<<"impossible"<<endl;
            continue;
        }

        int cn = 0 ;
        if(st)
            cn++;
        if(qu)
            cn++;
        if(pqu)
            cn++;
        if(cn>1)
        {
            cout<<"not sure"<<endl;
            continue;
        }
        if(st)
            cout<<"stack"<<endl;
        else if(qu)
            cout<<"queue"<<endl;
        else if(pqu)
            cout<<"priority queue"<<endl;

    }

}

