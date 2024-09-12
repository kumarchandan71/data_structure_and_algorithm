#include<bits/stdc++.h>
using namespace std;

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;

}*first=NULL;

//Function to create doubly linked list: 215
void create(int A[], int n)
{
    struct Node *t, *last;
    first=new Node;
    first->data= A[0];
    first->prev=first->next=NULL;
    last=first;

    for(int i=1; i<n; i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        t->prev=last;
        last=t;
    }

}//end create function.

//Function to display doubly linked list: 215
void display(struct Node *p){
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;

}//end of display code.

//Funtion to find length of DLL: 216
int length(struct Node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}//end

//Insert in Doubly linked list: before first node or at any given index.
void before_first(struct Node *head, int x)
{
    Node *p;
    p=new Node;
    p->data=x;
    p->next=first;
    first->prev=p;
    p->prev=NULL;
    first=p;
}//end here.

//Insert function
void insert(struct Node *p, int index, int x)
{
    Node *t;
    t=new Node;
    t->data=x;

    if(index <0 || index> length(p)){
        return;
    }

    if(index==0){
        t->next=p;
        p->prev=t;
        t->prev=NULL;
        first=t;
    }

    else{
        for(int i=1; i<index; i++){
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next){
            p->next->prev=t;

        }
        p->next=t;
    }

}//insert function end here.

/*
Write function to delete the node from the doubly linked list:
                    (i)  Delete first Node
                    (ii) Delete from given index
*/
//Function to delete first node:
void delete_first_node(struct Node *p){
    if(p->next){
        p=p->next;
        p->prev=NULL;

    }
    first=p;
}

//Function to delete from given index: 220
void delete_node(struct Node *p, int index)
{
    if(index<0 || index>length(p)){
        return;
    }
    if(index==1){
        delete_first_node(p);
    }
    
    else{
        Node *q;
        for(int i=0; i<index-2; i++){
            p=p->next;
        }
        
        q=p->next->next;
        if(q==NULL){
            p->next=NULL;
            return ;
        }
        p->next=q;
        q->prev=p;
    }
}// end of delete_node.

//Function to reverse doubly linked list:
void reverse(struct Node *p){
    while(p){
        p=p->next;
    }
    first=p;
    while(p){
        Node *temp;
        temp=p->prev->next;
        p->prev=
        p=p->next;
    }
}



// int main(){
//     int A[]={5, 4,7,2,7,34,6,7,43,5};
//     int n=sizeof(A)/sizeof(A[0]);
//     create(A, n);
//     // insert(first, 4,56);
//     // delete_node(first, 10);
//     reverse(first);
//     display(first);
//     cout<<"length is "<<length(first);


//     return 0;
// }



class Solution {
  public:
    long long cntGood(string S) {
        long long result = 0;
        int n = S.length();
        
        // Iterate through the string
        for (int i = 0; i < n; i++) {
            // Check if S[i] is an odd digit
            if ((S[i] - '0') % 2 == 1) {
                // Count all substrings ending at S[i]
                result += (i + 1); // All substrings from 0 to i are valid
                // Debug print for substrings
                cout << "Odd digit at position " << i << " is " << S[i] << ". Counting substrings: " << (i + 1) << endl;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string S = "31974444222135799753109090";
    cout << "Total count of good substrings: " << sol.cntGood(S) << endl;
    return 0;
}
