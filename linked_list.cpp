#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next; 
    /* data */
}*first=NULL;

void create_LL(int A[],int n )
{
    int i;
    
    struct Node *t, *last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1; i<n; i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next= NULL;
        last->next=t;
        last=t;
    }
    
}

void display_LL(struct Node *p)  // displaying element in linked list: 176
{
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}

void display_r1(struct Node *p) //using recursion  177
{
    if(p!=NULL)
    {
        cout<<p->data<<endl;  //first printing then calling
        display_r1(p->next);
    }
}

void display_r2(struct Node *p) //using recursion 
{
    if(p!=NULL)
    {
        display_r2(p->next); //first calling then printing
        cout<<p->data<<endl;
        
    }
}

//Count the number of nodes in linked list: 178
int count(struct Node *p){
    int count=0;
    while(p!=0){
        count++;
        p=p->next;
    }
    return count;
}
//Now counting nodes using recursion: 178
int Rcount(struct Node *p)
{
    if(p==0) return 0;
    else return count(p->next)+1;
    
}

//Function to find sum of all elements in linked list: 179
int sumof(struct Node *p){
    int result=0;
    while(p){
        result+=p->data;
        p= p->next;
    }
    return result;
}
//sum using recursion 179
int add(struct Node *p){
    if(!p) return 0;
    else return p->data + add(p->next);
}

//Function to find maximum valued element in linked list: 181
int maxElement(struct Node *p){
    int temp=0;
    while(p){
        if(p->data >temp){
            temp=p->data;
        }
        p=p->next;
    }
    return temp;
}
//Write recursive function to find max element: 181
int Rmax(struct Node *p)
{
    if(!p) return 0;       //complete the code

    else{
        int x= Rmax( p->next);
        return x>p->data? x:p->data;
    }
}


//Write function to search an element is present in linked list or not: 183
struct Node * search(struct Node *p, int value){
    while(p){
        if(p->data==value) return (p);
         p=p->next;
    }
    return NULL;
   
              //complete this code
}
//Searching function using recursion: 183
struct Node * Rsearch(struct Node *p, int value){
    if(!p) return NULL;
    if(p->data==value) return (p);
    return Rsearch(p->next, value);
}
// Implementing move to front/head operation in searching technique: 184
struct Node*search1(struct Node *p, int value)
{
    struct Node *q=NULL;
    while(p){
        if(p->data==value){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }

    q=p;
    p=p->next;
    }
    
    return NULL;

}

//Inserting in a Linked-List: (i) Inserting before first (ii) Inserting after given position:-
void Insert_before_first(struct Node *p, int x){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));       // (i) Inserting before first
    t->data=x;
    t->next=first;
    first=t;
}

void Inserting_at_pos(struct Node *p, int pos, int x){    //(ii) Inserting after given position:-

    int n=count(p);
    if(pos>n || pos<0) return;
    Node *t=new Node;
    t->data=x;

    if(pos==0){
        t->next=first;
        first=t;
    }

    else{
        for(int i=1; i<pos; i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }

}

//Inserting in a sorted linked list: 190
void Insert_Sorted_LL(struct Node *p, int x){
    Node *t, *q;
    t=new Node;
    t->data=x;
    t->next=NULL;
    q=NULL;
    if(p==NULL){
        p=t;
    }
    while( p && p->data<x){
        q=p;
        p=p->next;
    }
    if(p==first){
        t->next=first;
        first=t;
    }
    else{
        t->next=p;
        q->next=t;
    }
    
}

/*
    Write code for deleting an element from the Linked list: 192
            i) Delete first Node
            ii) Delete a node at given position
*/

//Function to check whether given linked list is sorted or not: 194
bool check_LL_sorted1( struct Node *p){
    Node *q;

    while(p->next){
        q=p;
        p=p->next;
        if(q->data>p->data) return 0;
    }
    return 1;

}

//Function to remove the duplicates element from the sorted linked list:
void duplicates(struct Node *p){
    Node *q=p;
    while(p->next){
        p=p->next;

        if(p->data==q->data){
            q->next=p->next;
        }
        else{
            q=p;
        }

    }
}

/* Function to reverse an Linked List: 
                            (i) Reversing elements- Done using array
                            (ii)Reversing Links

*/
//Reversing Elemnets:
void reverse_ele(struct Node *p){
    Node *q=p;
    int n=count(p);
    int A[n];
    for(int i=0; i<n; i++){
        A[i]=p->data;
        p=p->next;
    }
    p=q;
    for(int j=0; j<n; j++){
        p->data=A[n-j-1];
        p=p->next;
    }

}

//Reversing Links: This is done using three pointer - Sliding pointer.
void reversing_link(struct Node *p){
    Node * r, *q;
    r=NULL;
    q=NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

//Reversing Linked List using recursion.
void reverse_recursion(struct Node *q, struct Node *p){
    if(p){
        reverse_recursion(p, p->next );
        p->next=q;

    }
    else{
        first=q;
    }
}

//Function to Delete nodes having greater value on right:
Node *compute(Node *head)
    {
        // your code goes here
        Node *p, *q;
        
        q=head;
        p=head->next;
        while(p){
            if(q->data < p->data){
                q->data=p->data;
                q->next=p->next; 
                p=p->next;
            }
            else{
                
                q=p;
                p=p->next;
            }
            
        }
    }

/*    
class Circular_Linked_List
{   
    Node* first;

    public:

        //Function to create circular linked list from an array:
        void create(int A[], int n){
                Node *t, *last, *first;
                first= new Node;
                first->data=A[0];
                first->next=NULL;
                last=first;

                for(int i=1; i<n; i++){
                    t=new Node;
                    t->data=A[i];
                    t->next=NULL;
                    last->next=t;
                    last=t;
                }
                last->next=first;
        }

        void display(struct Node *head){
            Node *p=head;
            do{
                cout<<p->data<<endl;
                p=p->next;
            } while(p!=head);

        }

        //Display function using recursion:
        void Rdisplay(struct Node *head){
            Node *p=head;
            static int flag=0;
            if(p!=head || flag==0){
                cout<<p->data<<endl;
                Rdisplay(p->next);
            }
            flag=0;
        }
};

int main()
{   Circular_Linked_List CLL;
    int A[] = {2, 4, 6, 9, 9, 12, 20,68, 29, 56};
    int num = sizeof(A) / sizeof(A[0]);
    CLL.create(A,num);
    
    CLL.display(first);
    // cout<<INT32_MIN<<endl<<INT32_MAX;
    return 0;
}

*/

class Circular_Linked_List {
    Node* first; // Head of the circular linked list

public:
    // Constructor to initialize the head as NULL
    Circular_Linked_List() {
        first = nullptr;
    }

    // Function to create circular linked list from an array
    void create(int A[], int n) {
        Node *t, *last;
        first = new Node;
        first->data = A[0];
        first->next = first; // Circular link
        last = first;

        for (int i = 1; i < n; i++) {
            t = new Node;
            t->data = A[i];
            t->next = last->next; // last->next is pointing to first initially
            last->next = t;
            last = t;
        }
        last->next = first; // Make the list circular by linking the last node to first
    }

    // Function to display the circular linked list
    void display() {
        Node* p = first;
        if (first == nullptr) return;

        do {
            cout << p->data << " -> ";
            p = p->next;
        } while (p != first);
        cout << "(back to head)" << endl;
    }

    // Function to display the circular linked list using recursion
    void Rdisplay(Node* p) {
        static int flag = 0;
        if (p != first || flag == 0) {
            flag = 1;
            cout << p->data << " -> ";
            Rdisplay(p->next);
        } else if (p == first && flag == 1) {
            cout << "(back to head)" << endl;
        }
        flag = 0; // Reset the flag for subsequent calls
    }

    // Wrapper function to start recursive display
    void Rdisplay() {
        if (first != nullptr) {
            Rdisplay(first);
        }
    }
};

int main() {
    Circular_Linked_List CLL;
    int A[] = {2, 4, 6, 9, 12, 20, 68, 29, 56};
    int num = sizeof(A) / sizeof(A[0]);

    CLL.create(A, num);
    
    // Display using iterative method
    cout << "Iterative Display:" << endl;
    CLL.display();

    // Display using recursive method
    cout << "Recursive Display:" << endl;
    CLL.Rdisplay();

    return 0;
}
