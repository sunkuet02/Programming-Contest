#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;

char grid[40][90];
int Size[40],temp[40];
char ch;
bool isvisited[40][90];
int k;
int maxx, maxy;

int colorGrid(int x,int y)
{

    if((x<0|| x>=maxx)||(y<0||y>=maxy+1))
        return 0;
    if(grid[x][y]==ch || isvisited[x][y])
        return 0;
    isvisited[x][y] = true;
    if(x!=0)
        if(grid[x-1][y]==ch)
            grid[x][y] = '#';
    if(grid[x+1][y]==ch)
        grid[x][y] = '#';
    if(y!=0)
        if(grid[x][y-1]==ch)
            grid[x][y] = '#';
    if(grid[x][y+1]==ch)
        grid[x][y] = '#';

    colorGrid(x-1,y);
    colorGrid(x+1,y);
    colorGrid(x,y-1);
    colorGrid(x,y+1);
}

int main()
{
    int test;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>test;
    getchar();
    for(int t = 0; t<test; t++)
    {
        string s;
        k = 0;
        memset(Size,0,sizeof(Size));

        for(int i = 0; i<33; i++)
        {
            for(int j = 0; j<81; j++)
            {
                grid[i][j] = ' ';
                isvisited[i][j] = false;
            }
        }

        maxx = maxy = 0;
        while(getline(cin,s))
        {

            if(s[0]=='_')
            {

                for(int i = 0; i<k; i++)
                {
                    for(int j = 0; j<Size[i]; j++)
                    {
                        if(grid[i][j]== '*')
                        {
                            maxx = k;
                            grid[i][j]= ' ';
                            colorGrid(i,j);

                        }
                    }
                }

                memset(Size,0,sizeof(Size));
                for(int i = 0; i<k; i++)
                {
                    for(int j = 0; j<=maxy; j++)
                    {
                        if(grid[i][j]!=' ')
                            Size[i] = j+1;
                    }

                }
                for(int i = 0; i<k; i++)
                {
                    if(Size[i]!=0)
                    for(int j = 0; j<Size[i]; j++)
                    {
                        cout<<grid[i][j];
                    }
                    cout<<endl;
                }
                k = 0;
                cout<<s<<endl;
                break;
            }

            Size[k] = s.size();
            if(maxy<s.size())
                maxy = s.size();
            for(int i = 0; i<s.size(); i++)
            {

                grid[k][i] = s[i];
                if(s[i]!=' ' && s[i]!='*' )
                    ch = s[i];
            }
            k++;
        }

    }
}

