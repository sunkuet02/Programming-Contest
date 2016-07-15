#include<iostream>
#include<cstdlib>

using namespace std;

int counter;
struct node
{
    int info[3];
    node *next;
    node *prev;
};

class List
{
    node *top;
    node *back;
    node *New;

public:
    List()
    {
        top = back = New = NULL;
        counter =0;
    }
    void TakeChoice();
    void PushBack();
    void ForwardDisplay();
    void BackDisplay();
    void PushFirst();
    void PushSpecificLocation();
    void DeleteCalledAfterLocaion();
    void DeleteCalledBeforeLocation();
    void BubbleSort();
    void DeleteSpecificLocation();
    void DeleteLast();
    void DeleteFirst();

};
void List::PushBack()
{
    int w,x,y;
    cout<<"Enter 2 Numbers the number u want to push in back"<<endl;
    cin>>w>>x;
    New = new node();
    New->info[0] = w;
    New->info[1] = x;
    New->info[2] = x+w;
    New->next = NULL;
    New->prev = NULL;
    if(top == NULL)
    {
        top = New;
    }
    else
    {
        back->next = New ;
        New->prev = back;
    }
    back = New;
    counter++;
}

void List::PushFirst()
{
    int w,x,y;
    cout<<"Enter 2 Numbers the number u want to push"<<endl;
    cin>>w>>x;
    New = new node();
    New->info[0] = w;
    New->info[1] = x;
    New->info[2] = x+w;
    New ->next = NULL;
    New ->prev = NULL;
    if(back == NULL)
        back = New;
    else
    {
        New ->next = top;
        top->prev = New;
    }
    top = New;
    counter++;
}

void List::PushSpecificLocation()
{
    int v,node_number;
    cout<<"Enter the node Number in which u want to insert"<<endl;
    cin>>node_number;
    if (node_number ==1)
    {
        PushFirst();
    }
    else if(node_number == counter)
    {
        PushBack();
    }
    else if(node_number>=1 && node_number<=counter)
    {
        cout<<"Enter 2 Values u want to Insert"<<endl;
        node *q;
        New = new node();
        int w,x;
        cin>>w>>x;
        New->info[0] = w;
        New->info[1] = x;
        New->info[2] = x+w;

        New ->next = NULL;
        New->prev = NULL;
        node *temp = new node();
        temp = top;
        node *before;
        for( int i = 1 ; i < node_number ; i++ )
        {
            before = temp;
            temp = temp->next;				// go to the next node

            if( temp == NULL )
            {
                cout<<node_number<<" node is not exist"<< endl;
                return;
            }
        }
        before->next = New;
        New->prev = before;
        New->next = temp;
        temp ->prev = New;
        counter++;
    }
    else
        cout<<"YOU ARE ENTERED AN INVALID KEY"<<endl;
}

void List::DeleteLast()
{
    if(counter == 0)
    {
        cout<<"There contains no element"<<endl;
        return ;
    }
    else if(counter == 1)
    {
        back = NULL;
        counter--;
        return;
    }
    else
    {
        node *old,*q;
        back = back->prev;
        back->next = NULL;
        counter --;
    }
}

void List::DeleteFirst()
{
    if(counter == 0)
    {
        cout<<"There contains no element"<<endl;
        return ;
    }
    if(counter == 1)
    {
        top = NULL;
        counter --;
        return;
    }
    node *q;
    q=top;
    top = top->next;
    top->prev = NULL;
    counter--;
    free(q);

}

void List:: BubbleSort()
{
    node *temp1 = new node();
    node *temp2 = new node();
    for(temp1= top ; temp1 !=NULL ; temp1 = temp1->next)
        for(temp2 = temp1->next; temp2 !=NULL ; temp2 = temp2->next)
            if(temp1->info[2] > temp2->info[2])
            {
                int tempA = temp1->info[2];
                int tempB = temp1->info[1];
                int tempC = temp1->info[0];
                temp1->info[2] = temp2->info[2];
                temp1->info[1] = temp2->info[1];
                temp1->info[0] = temp2->info[0];
                temp2->info[2] = tempA;
                temp2->info[1] = tempB;
                temp2->info[0] = tempC;
            }

}

void List::DeleteSpecificLocation()
{
    if(counter == 0)
    {
        cout<<"There contains no element"<<endl;
        return ;
    }
    int v,node_number;
    cout<<"Enter the node Number u want to Delete"<<endl;
    cin>>node_number;
    if(node_number==1)
    {
        DeleteFirst();
    }
    else if(node_number == counter)
        DeleteLast();
    else if(node_number>1 && node_number< counter)
    {
        node *temp = new node();
        node *old_temp = new node();
        temp = top;
        for(int i=1; i<node_number; i++)
        {
            old_temp = temp;
            temp = temp->next;
        }
        temp = temp->next;
        old_temp->next = temp;
        temp->prev = old_temp;
        counter--;
    }
    else
        cout<<"YOU ENTERED THE WRONG KEYWORD"<<endl;

}
void List::DeleteCalledBeforeLocation()
{
    if(counter == 0)
    {
        cout<<"There contains no element"<<endl;
        return ;
    }
    int v,node_number;
    cout<<"Enter the node Number Before u want to Delete"<<endl;
    cin>>node_number;
     node_number-=1;
    if(node_number<1)
    {
        cout<<"CANNOT DELETE THE ELEMENT"<<endl;
        return ;
    }

    else if(node_number == 1)
    {
        DeleteFirst();
    }
    else if(node_number==counter)
        DeleteLast();
    else if (node_number>1 && node_number<counter)
    {
        node *temp = new node();
        node *old_temp = new node();
        temp = top;
        for(int i=1; i<node_number; i++)
        {
            old_temp = temp;
            temp = temp->next;
        }
        temp = temp->next;
        old_temp->next = temp;
        temp->prev = old_temp;
    counter--;
    }
    else
        cout<<"YOU ENTERED THE WRONG KEYWORD"<<endl;
}
void List::DeleteCalledAfterLocaion()
{
    if(counter == 0)
    {
        cout<<"There contains no element"<<endl;
        return ;
    }
    int v,node_number;
    cout<<"Enter the node Number After u want to Delete"<<endl;
    cin>>node_number;
    node_number++;
    if(node_number>counter)
    {
        cout<<"CANNOT DELETE THE NODE"<<endl;
        return ;
    }
    else if(node_number == counter)
        DeleteLast();
    else if(node_number==1)
        DeleteFirst();
    else if(node_number>1 && node_number<counter)
    {
        node *temp = new node();
        node *old_temp = new node();
        temp = top;
        for(int i=1; i<node_number; i++)
        {
            old_temp = temp;
            temp = temp->next;
        }
        temp = temp->next;
        old_temp->next = temp;
        temp->prev = old_temp;
    counter--;
    }
    else
        cout<<"YOU ENTERED THE WRONG KEYWORD"<<endl;
}
void List::ForwardDisplay()
{
    if(counter == 0)
    {
        cout<<"There is nothing to print"<<endl;
        return ;
    }
    node *q;
    cout<<"The contents are :  "<<endl;
    for(q=top; q->next!=NULL; q=q->next)
        cout<< q->info[0]<<" "<<q->info[1]<<" "<<q->info[2]<<endl;
    cout<< q->info[0]<<" "<<q->info[1]<<" "<<q->info[2]<<endl;
    cout<<endl;
}

void List::BackDisplay()
{
    if(counter == 0)
    {
        cout<<"There is nothing to print"<<endl;
        return ;
    }
    cout<<"The contents are :  "<<endl;
    node *q = new node();
    for(q = back; q!=NULL; q=q->prev)
        cout<< q->info[0]<<" "<<q->info[1]<<" "<<q->info[2]<<endl;

}

void List::TakeChoice()
{
    int n;
    while (1)
    {
        cout<<"which operation do u want to do"<<endl;
        cout<<"\t1-PushFirst \n\t2-PushLast\n\t3-Push Specific Location\n\t4-Delete First\n\t5-Delete Last\n\t6-Delete Specific Location\n\t7-Sort Elements\n\t8-Delete Called After Locaion\n\t9-Delete Called Before Location\n\t10-Forward Display\n\t11-Back Dispaly\n\t0-Go Out"<<endl;
        cout<<endl<<endl;
        cin>>n;
        if(n==1)
            PushFirst();
        else if(n==2)
            PushBack();
        else if(n==3)
            PushSpecificLocation();
        else if(n==4)
            DeleteFirst();
        else if(n==5)
            DeleteLast();
        else if(n==6)
            DeleteSpecificLocation();
        else if(n==7)
            BubbleSort();
        else if(n==8)
            DeleteCalledAfterLocaion();
        else if(n==9)
            DeleteCalledBeforeLocation();
        else if(n==10)
            ForwardDisplay();
        else if(n==11)
            BackDisplay();
        else if(n==0)
            break;
        else cout<<"You entered the wrong choice number please correct"<<endl;
    }
    cout<<endl<<endl<<"THANKS FOR OPERATION"<<endl;
}

int main()
{
    List m;
    m.TakeChoice();
    return 0;
}
