//linklist using structures

#include<iostream>
using namespace std;
struct Node
{
    int data;  //this will take data

    Node *link;

};
Node * head = NULL; //this is global and it is not pointing to any thing right now so it is null
//Todo Insert at Beginning 
void insertBeg(int d)
{
    Node *pointer = new Node();
    //here I am assuming that we have a linnklist already creadted
    //* EX - |1|100|->|2|300|->|3|NULL|
    //and we are inserting at the start of this linklist
    pointer->data = d;
    //TODO: EX - |1|100|->|2|300|->|3|NULL|
    pointer->link = head;
    head = pointer; 
};
//Todo Insert at END
void insertEnd(int d)
{
    //! for inserting at end we will use a temp variable for traversing
    //! move temp till we get temp->link = NUll there we can insert new value
    Node *pointer = new Node();
    pointer->data = d;
    pointer->link = NULL;
    if(head == NULL)
    {
        head = pointer;
    }
    else{
        Node *temp = head;
        cout<<head<<" "<<endl;
        while(temp->link != NULL)
        {
            temp=temp->link;
        }
        temp->link = pointer;
    }
};

void deleteBeg(){
    if(head == NULL)
        cout<<"Cant dele from beginning as list empty";
    else
    {
        Node *pointer = head;
        head = head->link;
        free(pointer);
    }
};

//todo delete node fromm end
void deleteEnd(){
    Node *pointer, *prev;
    if(head == NULL)            //empty list
    cout<<"cant delete because list empty";
    else
    if(head->link == NULL){     //only one node
        pointer = head;
        head = NULL;
        free(pointer);
    }
    else{ 
        pointer = head;
        while(pointer->link != NULL)
        {
            prev = pointer;
            pointer = pointer->link;
        }
        prev->link = NULL;
        free(pointer);
    }

}

//! searching the middle element of the list

void showMid(){
    Node *slow= head;
    Node *fast = head;
    if(head == NULL)
        cout<<"no mid element because list is empty";
    else
    {
        //till fast is not equal to null of the pointer of fast is not equal to null
        //https://youtu.be/M497FJW9mPk?list=PLZgR0futJAU3fCGJn2UvRWbkLqmEje_cd&t=126
        while(fast != NULL&& fast->link != NULL)
        {
            slow =slow->link;
            fast = fast->link->link; 
        }
        cout<<"middle element is "<<slow->data<<endl;
    }
}


//! reverse linklist
//?https://youtu.be/PQIHq0vfADI?list=PLZgR0futJAU3fCGJn2UvRWbkLqmEje_cd
void reverseLists(){
    Node *p,*c,*n;
    
    p = NULL;
    c = head;
    while (c!= NULL)
    {
        n=c->link;
        c->link =p;
        p=c;
        c=n;

    }
    head=p;

}
//! finding loop in linnklist
int findLoop(Node *head)
{
    Node *slow,*fast;
    slow=fast;
    fast=head;
    while(fast!=NULL && fast->link != NULL)
    {
        fast=fast->link->link;
        slow = slow->link;
        if(slow == fast)
        {
            return 1;
        }
    }
    return 0;

}
//Funcion to display
void displayList()
{
 Node *pointer=head;
 while(pointer!=NULL)
 {
  cout<<pointer->data<<" ";
  pointer=pointer->link;
 }
 cout<<"\n";
}

//todo Main function
int main()
{
    Node *pointer =new Node();
    //int d;
    //this will dynamically allocate node and give to point ptr
    // https://youtu.be/Zgzoe8jjidk?list=PLZgR0futJAU3fCGJn2UvRWbkLqmEje_cd&t=220
    //?pointer->data = 2;
    //?pointer->link = NULL;
    //this is not pointing to anything right now
    //?head = pointer; //now the head will point to this node
    insertBeg(100);
    insertBeg(200);
    insertEnd(300);
    insertEnd(400);
    displayList();
    showMid();
    reverseLists();
    displayList();
    
    return 0;
}


