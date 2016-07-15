#include<bits/stdc++.h>
#define first_character '0'
using namespace std;

struct word
{
    bool islastword;
    word *next[15];
    word()
    {
        islastword = false;
        for(int i = 0;i< 12;i++)
            next[i] = NULL;
    }
};

bool is_found ;
class dictionary
{
    word *root;
    public:
        dictionary()
        {
            root = new word();

        }
        void insert_item(string s);
        void delete_dictionary();
        void take_input();
};

void dictionary::insert_item(string s)
{
    word *running = root;

    for(int i = 0 ; i < s.size() ; i++)
    {
        int id = s[i] - first_character;
        if(running->next[id]==NULL)
            running->next[id] = new word();
        if(running->next[id]->islastword)
            is_found = true;
        running = running->next[id];

    }
    running->islastword = true;

}


void dictionary::delete_dictionary()
{
    word *current = root;
    for(int i = 0; i< 12; i++)
    {
        if(current->next[i])
            delete(current->next[i]);
    }
    delete(current);
}

void dictionary::take_input()
{
    string s;
    int t;
    cin>>t;
    vector<string>v;
    for(int i = 0;i < t;i++)
    {
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin() , v.end());
    for(int i = 0 ; i< v.size() ; i++)
        insert_item(v[i]);

    if(is_found)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    v.clear();
}


int main()
{
    int te;
    cin>>te;
    for(int t = 0; t< te; t++)
    {
        word *root = new word();
        is_found  = false;
        dictionary dic ;
        dic.take_input();
        dic.delete_dictionary();
    }

}

