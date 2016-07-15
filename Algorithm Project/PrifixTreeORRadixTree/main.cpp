#include<bits/stdc++.h>
#define first_character 'a'
using namespace std;

struct word
{
    bool islastword;
    word *next[27];
    word()
    {
        islastword = false;
        for(int i = 0;i< 26;i++)
            next[i] = NULL;
    }
};

word *root = new word();

class dictionary
{
    word *top;

    public:
        dictionary()
        {
            top = NULL;
        }
        void insert_item(string s);
        void delete_dictionary();
        bool search_word(string s);
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
        running = running->next[id];
    }
    running->islastword = true;

}

bool dictionary::search_word(string s)
{
    word *current = root;
    for(int i = 0; i < s.size(); i++ )
    {
        int id = s[i] - first_character;
        if(current->next[id]==NULL)
            return false;
        current = current->next[id];
    }
    return current->islastword;
}

void dictionary::delete_dictionary()
{
    word *current = root;
    for(int i = 0; i< 26; i++)
    {
        if(current->next[i])
            delete(current->next[i]);
    }
    delete(current);
}

void dictionary::take_input()
{
    string s;
    for(int i = 0;i < 3;i++)
    {
        cin>>s;
        insert_item(s);
    }
    cin>>s;
    if(search_word(s))
        cout<<"word is found"<<endl;
    else
        cout<<"word is not there"<<endl;
}


int main()
{
    dictionary dic ;
    dic.take_input();
    dic.delete_dictionary();

}
