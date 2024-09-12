#include<bits/stdc++.h>
using namespace std;

void set(int A[], int i, int j, int x){
    if(i==j){
        A[i-1]=x;
    }
}

int get(int A[], int i, int j){
    if(i==j){
        return A[i-1];
    }
    return 0;
}