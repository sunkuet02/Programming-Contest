#include<iostream>
#include<sstream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cstring>

using namespace std;

char grid[100][100];
bool isvisited[100][100];
int Size[100];
int j = 0;
char ch;

int colorGrid(int x , int y)
{
    if((x<0|| x>=j)|| (y<0 || y>=Size[x]))
        return 0;
    if(grid[x][y]=='X' || isvisited[x][y])
        return 0;
    isvisited[x][y] = true;

    grid[x][y] = ch;
    colorGrid(x+1,y);
    colorGrid(x-1,y);
    colorGrid(x,y+1);
    colorGrid(x,y-1);
    return 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    string str;
    memset(Size,0,sizeof(Size));

    while(getline(cin,str))
    {
        if(str[0]=='_')
        {
            for(int p = 0;p<j;p++)
            {
                for(int q = 0;q<Size[p];q++)
                {
                    if(grid[p][q]!='X' && grid[p][q]!=' ' && !isvisited[p][q])
                    {
                        ch = grid[p][q];
                        colorGrid(p,q);
                    }
                }
            }

            for(int p = 0;p<j;p++)
            {
                for(int q = 0;q<Size[p];q++)
                {
                    cout<<grid[p][q];
                }
                cout<<endl;
            }

            memset(Size,0,sizeof(Size));
            j = 0;
            cout<<str<<endl;
            continue;
        }

        Size[j] = str.size();

        for(int i = 0;i<str.size();i++)
        {
            isvisited[j][i] = false;
            grid[j][i] = str[i];

        }
        j++;
    }
}

