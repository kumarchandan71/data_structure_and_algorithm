#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
//Insertion sort- just like arranging cards in hand.
void InsertionSort(int A[], int n){
    int j, key;

    for(int i=1; i<n; i++){
        j=i-1;
        key=A[i];
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    } 
   
}




int main(){
    int A[]={11,13,7,12,16,9,24,5,10,3}, n=10;
    InsertionSort(A,n);
    for(int i=0; i<10; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}