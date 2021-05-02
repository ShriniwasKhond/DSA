#include<iostream>
using namespace std;
class sll{
    private:
        struct node{
            int data;
            struct node *next;
        }*head;
    public:
        sll();
        void create();
        void display();
        void search(int key);
        void insert_head();
        void insert_after();
        void insert_last();
        void del();
        ~sll();
};
sll::sll(){
    head=NULL;
}
sll::~sll(){
    node *t1, *t2;
    t1=head->next;
    delete head;
    while(t1->next!=NULL){
        t2=t1->next;
        delete t1;
        t1=t2;
    }
}
void sll::create(){
    node *temp, *NEW;
    int flag,val;
    char ans='y';
    flag=1;
    do{
        cout<<"\n enter the data";
        cin>>val;
        //allocates mmeory to the new node
        NEW = new node;
        if(NEW == NULL)
            cout<<"\n Unable to allocate memory"<<endl;
        NEW->data=val;
        NEW->next=NULL;
        if(flag==1){ //Executed only for the first time
            head=NEW;
            temp=head;
            flag=0;
        }else{
            //temp last keeps track of the most recently created node
            temp->next=NEW;
            temp=NEW;    
        }
        cout<<"\n Do you want to enter more elements?(y/n)"<<endl;
        cin>>ans;
    }while(ans=='y'||ans=='y');
}
void sll::display(){
    node *temp;
    temp = head;
    if(temp==NULL){
        cout<<"The List is empty"<<endl;
        return ;
    }
    while(temp!=NULL){
        cout<<temp->data;
        temp = temp->next;
    }
}
void sll::search(int key){
    node *temp;
    int found = 0;
    temp = head;
    if(temp == NULL){
        cout<<"The linked list is empty";
    }
    while(temp != NULL && found == 0){
        if(temp->data != key){
            temp = temp->next;
        }else{
            found = 1;
        }
    }
    if(found == 1){
        cout<<"\n The Element is persent in the list";
    }else{
        cout<<"\n The Element is not present in the list"<<endl;
    }
}
void sll::del(){
    node *temp,*prev;
    int key;
    temp = head;
    cout<<"\n Enter the data of node you want to delete"<<endl;
    cin>>key;
    while(temp!=NULL){
        if(temp->data==key){
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"\n Node not found";
    }else{
        if(temp==head)//first node
            head = temp->next;
        else
            prev->next=temp->next; //intermediate node
    }
    delete temp;
    cout<<"\n Element is deleted";
}
void sll::insert_last(){
    node *New,*temp;
    cout<<New->data;
    if(head==NULL){
        head=New;
        }
    else{
        temp=head;
    }
    while(temp->next!=NULL){
        temp=temp->next;
        New->next=NULL;
    }
}
void sll::insert_after(){
    int key;
    node *temp,*New;
    New = new node;
    cout<<"\n Enter The element after which you want to insert";
    cin>>New->data;
    if(head==NULL){
        head=New;
    }else{
        cout<<"\n Enter the element after which you want to insert the node";
        cin>>key;
        temp=head;
    }
    do{
        if(temp->data==key){
            New->next=temp->next;
            temp->next=New;
            break;
        }else{
            temp=temp->next;
        }
    }while(temp!=NULL);
}
void sll::insert_head(){
    node *New,*temp;
    New = new node;
    cout<<"\n Enter the element which you want to insert";
    cin>>New->data;
    if(head==NULL){
        head=New;
    }else{
        temp=head;
        New->next=temp;
        head=New;
    }
}
int main(){
    sll s;
    int choice, val, ch;
    char ans = 'y';
    do{
        cout<<"\n Program to perform Various Linked list operations on Linked List";
        cout<<"\n 1.create";
        cout<<"\n 2.Display";
        cout<<"\n 3.search";
        cout<<"\n 4.Insert an element in the list";
        cout<<"\n 5.Delete an element from the list";
        cout<<"\n 6.Quit";
        cout<<"\n Enter your choice(1-6)"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                s.create();
                break;
            case 2:
                s.display();
                break;
            case 3:
                cout<<"\n enter the element you want to delete"<<endl;
                cin>>val;
                s.search(val);
                break;
            case 4:
                cout<<"\n The list is:"<<endl;
                s.display();
                cout<<"\n 1.insert at the begining";
                cout<<"\n 2.insert after";
                cout<<"\n 3.insert at last";
                cout<<"\n Enter your choice"<<endl;
                       cin>>ch;
                       switch(ch){
                            case 1:
                                s.insert_head();
                                break;
                            case 2:
                                s.insert_after();
                                break;
                            case 3:
                                s.insert_last();
                                break;
                            default:
                                cout<<"\n Invalid choice";
                       }
                break;
            case 5:
                s.del();
                break;
            default:
                cout<<"\n Invalid choice";
        }
        cout<<"Continue?";
        cin>>ans;
    }while(ans=='y'||ans=='Y');
}