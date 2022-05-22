#include <iostream>
#define max 10
using namespace std;
class node{
    public:
    int prn;
    string name;
    node* next;
};
class hashtab{
    public:
    node* hashtable[max];
    void initialize(){
        for(int i=0;i<=max;i++){
            hashtable[i]=NULL;
        }
    }
    int hashfunc(int c){
       return c%max;
    }
    node* newnode(int p,string n){
        node* temp=new node;
        temp->prn=p;
        temp->name=n;
        temp->next=NULL;
        return temp;
    }
    void insertnewelement(int p,string n){
        node* temp=new node;
        node* temp2=new node;
        int hashval=hashfunc(p);
        temp=newnode(p,n);
        temp2=hashtable[hashval];
        if(temp2==NULL){
            hashtable[hashval]=temp;
        }
        else{
            while(temp2->next!=NULL){
                temp2=temp2->next;
            }
            temp2->next=temp;
        }
    }
    void display(){
        for(int i=0;i<=max;i++){
            node* temp=hashtable[i];
            cout<<i<<".)";
            while(temp!=NULL){
                cout<<"prn-"<<temp->prn<<"name-"<<temp->name<<"->";
                temp=temp->next;
            }
            cout<<"\n";
        }
    }
    void search(int v){
        int hashfval=hashfunc(v);
        int flag=0;
        node* temp=hashtable[hashfval];
        while(temp!=NULL){
            if(temp->prn==v){
                flag=1;
                 cout<<"found\n name is "<<temp->name<<"\n";
                 break;
            }
        temp=temp->next;
        }
        if(flag==0){
           cout<<"not found";
        }

    }
    
    
};
int main()
{
    
    hashtab h;
    int choice,p,s;
    string n;
    h.initialize();
    do{
        cout<<"Enter your choice \n1.insert\n2.display\n3.search\n4.exit\n";
        cin>>choice;
        switch(choice){
            case 1:cout<<"Enter prn number ";
                    cin>>p;
                    cout<<"enter name ";
                    cin>>n;
                    h.insertnewelement(p,n);
                    break;
            case 2:h.display();
    
            break;
            case 3:cout<<"enter number to be searched ";
                cin>>s;
                h.search(s);
        }
    }while(choice!=4);

    return 0;
}