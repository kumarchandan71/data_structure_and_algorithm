#include <bits/stdc++.h>
using namespace std;
int climbStairs_helper(int n, vector<int>& dp){
    int left=0,right=0;
    if(n==0 || n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    left=climbStairs_helper(n-1,dp);
    right=climbStairs_helper(n-2,dp);
    return dp[n]=left+right;

}

int climbStairs(int n) {
        vector<int>v(n,-1);
        return climbStairs_helper(n,v);
    }
int climb(int n,vector<int>&dp){
    if(n<4)return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=climb(n-1,dp)+climb(n-2,dp);
}


// Nth fibonacci number
int fibonacci(int n){
    int prev2=1;
    int prev1=1;
    for(int i=2;i<=n;i++){
        int cur_i=prev2+prev1;
        prev2=prev1;
        prev1=cur_i;
    }
    return prev1;
}

int fib(int n, vector<int>&dp){
    if(n<2) return n;
    if(n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}

//Geek Jump with Minimum Energy:
int minimumEnergy(vector<int>& height, int n) {
        
        int left=0, right=0;
        if(n==0) return 0;
        if(n==1) return height[0];
        if(n==2 ) return abs(height[1]-height[0]);
        int x= abs(height[n-1]-height[n-2]);
        int y=abs(height[n-1]-height[n-3]);
        cout<< "value of n is "<<n<<endl;
        cout<<"value of x and y is : "<<x<<" and "<< y<<endl;
        if(x<y){
            left+=minimumEnergy(height, n-1);
            cout<<"left "<<left<<endl;
        }
        else{
            right+=minimumEnergy(height, n-2);
            cout<<"right "<<right<<endl;
        }
        return left+right;
        
    }

int MinEn(vector<int>& height, int n) {
    if (n == 1) return 0; 
    vector<int> dp(n, 0); 
    
    dp[0] = 0; // No energy needed to stay at the first step
    dp[1] = abs(height[1] - height[0]); // Energy needed to jump from the first to the second step
    
    for (int i = 2; i < n; i++) {
        // Minimum energy required to reach the ith step
        dp[i] = min(dp[i - 1] + abs(height[i] - height[i - 1]), dp[i - 2] + abs(height[i] - height[i - 2]));
    }
    
    return dp[n - 1]; // The minimum energy needed to reach the last step
}

int minCostClimbingStairs(vector<int>&cost ,int N) {
        int sum=0;
        int i=0;
        while(i<N-2){
            if(cost[i]+cost[i+2]<cost[i+1] ){
                sum+=cost[i];
                i+=1;
                cout<<"i when if condition is true: "<<i<<endl<<" and sum is :"<<sum<<endl;
            }
            else{
                sum+=cost[i+1];
                i+=2;
                cout<<"i when if condition is false: "<<i<<endl<<" and sum is :"<<sum<<endl;
            }
        }
        if(i==N-2){
            sum+=min(cost[N-1],cost[N-2]);
        }
        return sum;
        //Write your code here
    }
int minCostClimbingStairs_1(vector<int>&cost ,int N) {
        int sum=0;
        int i=0;
        int q=0;
        int s=0;
        while(i<N-5){
            if(cost[i+3]>cost[i+4])
            {q=cost[i]+cost[i+2]+cost[i+4]; }
            else{q=cost[i]+cost[i+2]+cost[i+3];}
            if(cost[i+2]>cost[i+3])
            {s=cost[i+1]+cost[i+3]; }
            else{s=cost[i+1]+cost[i+2];}
            if(s<q ){
                sum+=cost[i];
                i+=1;
                cout<<"i when if condition is true: "<<i<<endl<<" and sum is :"<<sum<<endl;
            }
            else{
                sum+=cost[i+1];
                i+=2;
                cout<<"i when if condition is false: "<<i<<endl<<" and sum is :"<<sum<<endl;
            }
        }
        while(i<N-2){
            if(cost[i]+cost[i+2]<cost[i+1] ){
                sum+=cost[i];
                i+=1;
                cout<<"i when if condition is true: "<<i<<endl<<" and sum is :"<<sum<<endl;
            }
            else{
                sum+=cost[i+1];
                i+=2;
                cout<<"i when if condition is false: "<<i<<endl<<" and sum is :"<<sum<<endl;
            }
        }

        if(i==N-2){
            sum+=min(cost[N-1],cost[N-2]);
        }
        return sum;
        //Write your code here
    }
int m_C_C_S(vector<int>&cost, int N){
    int prev1=cost[1];
    int prev2=cost[0];
    for(int i=2;i<N;i++){
        int curr_i=min(prev1, prev2)+cost[i];
        prev2=prev1;
        prev1=curr_i;
    }
    return min(prev1, prev2);
}

// Something about typedef:- we can use another type for the existing type, such as
//typedef int chandan;

void typedef1(){
    enum hero { red=4, green=5, blue=10, chandan } ;
    int  i;
    for(i=red;i<=chandan;i++) cout<<i<<" ";
}

void variable_in_cpp(){
    //wchar_t  a='chandan';
    //char b=a;
    //cout<<a;

}

string  vector_inside_vector(){
     int n=10;
     char ch='R';
    string str(n,ch);
    
    cout<<str;
}
int globalValue=45;
void global_local_variable(){
    int localValue=4;
    time_t time_hai=time(nullptr);
    cout<<globalValue<<endl<<localValue<<endl<<localtime;
    cout<<endl<<"time is "<<time_hai<<endl;
    tm* localtime1=localtime(&time_hai);
    cout<<"local time "<<localtime1<<endl;
    cout<<"human readable time "<<asctime(localtime1);
}

//Literals are constant whose value cannot be alter by the program:
void Constan_Literals(){
    int n=5;
    int deci=3434;
    int octal= 03445;
    bitset<16> binary_number("1010110");
    int hexa=0xf0;
    long int longg=342l;

    cout<<"deci= "<<deci<<endl;
    cout<<"octa= "<<octal<<endl;
    cout<<"binary_number= "<<binary_number.to_ulong()<<endl;
    cout<<"hexa= "<<hexa<<endl;
    cout<<"long int= "<<longg<<endl;
}

//Defining constant:
void using_define(){
    //#define A 10.1199
    //#define B 5.33
    //cout<<A*B;
}

//Bitwise Operation:
void bitwise_operation(string str1, string str2){
    bitset<7> X(str1);
    bitset<7> Y(str2);
     
    cout<<Y.to_ulong()<<endl;
    bitset<7> result=X^Y;
    cout<<result;
}

struct rectangle {
    int lenght;
    int breadth;

};

struct comples_number{
    int real;
    int img;
    
};

struct card{
    int face;
    int shape;
    int color;
    char x;   //padding
};

void pointer_(){
    int A[]={12,43,25,65,3,2};
    int *p;
    p=A;
    //*p=11;
    //a=12;
    cout<<A[3];
    //cout<<*p<<endl<<A;
    //cout<<endl<<p<<endl<<&A;
}

void reference_(){
    struct rectangle r={10,15};
    cout<<r.lenght<<endl<<r.breadth<<endl;

    struct rectangle *p=&r;
    p->breadth=17;
    (*p).breadth=45;
    cout<<r.breadth;
}

void reference_in_heap(){
    struct rectangle *p;
    p=(struct rectangle *)malloc(sizeof(struct rectangle));     //This is in c language
    p= new rectangle;           //This in in c++
    p->breadth=27432;
    p->lenght=90;
    cout<<p->breadth<<endl<<p->lenght<<endl;
}

void shorting_an_array(){
    int brr[]={2,5,4,23,4,65,43,9};
    int n=sizeof(brr)/sizeof(brr[0]);
    sort(brr, brr+n);
    for(int j=0; j<n; j++){
        cout<<brr[j]<<" ";
    }
    cout<<endl<<n<<endl;
}

void swap(int &x, int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}

long long int calculateValue(const string& s) {
        long long int value = 0;
        for (char c : s) {
            value = static_cast<long long>(value) * 26 + (c - 'A' + 1); // A=1, B=2, ..., Z=26
        }
        return value;
    }


void selection_sort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        int mini=arr[i];
        int index=i;
        for(int j=i+1; j<n; j++){
            
            if(mini>arr[j]){
                mini=arr[j];
                index=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
    }
    
}

void bubble_sort(int *arr, int n){
    int i=n;
    while(i>0){
        for(int j=0; j<i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        i--;

    }
}

void insertion_sort(int *arr, int n){
    for(int i=1; i<n; i++){
        int current_element=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>current_element){
            
            arr[j+1]=arr[j];
            
            j--;
        }
        arr[j+1]=current_element;
    }
}

void sortABS(int A[],int N, int k)
    {
       for(int i=1; i<N; i++){
        int current_ele=A[i];
        int current_difference = abs(A[i]-k);
        int j=i-1;
        while(j>=0 && abs(A[j]-k)>current_difference){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=current_ele;
       }
       //Your code here
    }

void inputArray(int *a, int n){
    for (int i=0; i<n; i++){
    cin>>a[i];
   }
}

void printArray(int *a, int n){
    for(int j=0; j<n; j++){
    cout<<a[j]<<" ";
   }
}

int mrg(int *arr, int low, int mid, int high){
    int j=0;
    int brr[high];
    int left= low;
    int right= mid+1;
    while(left<=mid && right<=high){
        int i=0;
        if(arr[left]<=arr[right]) {
            brr[i]=arr[left];
            i++;
            left++;

        }
        else{
            brr[i]=arr[right];
            i++;
            right++;
        }
    }
    while(j<high){
        arr[low];
        low++;

    }
}
void mergeSort(int *arr, int low, int high){
    if(low==high) return;
    int mid= ( low+high )/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    mrg(arr, low, mid, high);
}

int fun2(int a){
    return 3*a;
}
int fun1(int a){
    return a+fun2(a);
}

double distance_measure(int x[], int y[]) {
    int dx = x[0] - y[0];
    int dy = x[1] - y[1];
    long long int result = static_cast<long long int>(dx) * dx + static_cast<long long int>(dy) * dy;
    return sqrt(static_cast<double>(result));
}

double areaOfTriangle(double a, double b, double c) {
    double s = (a + b + c) / 2; 
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
/*
double maxVolume(double perimeter, double area) {
        double l= (perimeter -sqrt(perimeter*perimeter- 24.0 *area))/12.0;
        double volume= l*( area*0.5 - l*(perimeter*0.25 - l) );
        return volume;
        
        
        // code here
}

double maxVolume(double perimeter, double area) {
        double l = (perimeter - std::sqrt(perimeter * perimeter - 24 * area)) / 12;
        double h = (perimeter / 4) - 2 * l;
        double v = l * l * h;
        
        return std::round(v * 100) / 100;  
}
*/
int CountPairs(int N, int k, int *arr) {
        int count=0;
        for(int i=0; i<N; i++){
            for(int j=i+1;j<N; j++){
                if(arr[i]==arr[j]  ){
                    int k=(i+j+2)%k;
                    if(k==0) count++;
                }
                    
            }
        }
        return count%1000000007;
        // code here
    }

// Recursion: Function which call itself
class Recursion{
    public:

    void recursion1(int n){
        if(n>0){
            cout<<n<<" ";
        recursion1(n-1);}
    }

    void recursion2(int n){
        if(n>0){
            recursion2(n-1);
            cout<<n<<" ";
    
        }
    }

    int recursion3(int n){
        if(n>0){
            return recursion3(n-1)+n;
        }
        return 0;
    }

    void fun1(int n){
        if(n>0){
            cout<<n<<" ";
            fun1(n-1);
            fun1(n-1);
        }
    }

    void funA(int n){
        if(n>0){
            cout<<n<<" ";
            funB(n-1);
        }
    }

    void funB(int n){
        if(n>1){
            cout<<n<<" ";
            funA(n/2);
        }
    }
    
    int sum_n(int n){
        if(n==0) return 0;
        if(n>0){
            
        return sum_n(n-1) +n;
        }
        
    }

}; //Recursion end here.


long long sumMatrix(long long n, long long q) {
        long long count=0;
        for(long long i=1; i<=n; i++){
            if(1+i<=q && q<=n+i){
                count++;
            }
        }
        return count;
        // code here
    }
class Solution {
  public:
    int add(int a, int b){
        return a+b;
    }

  double slope1(int x1, int y1, int x2, int y2){
    int y=y2-y1,  x=x2-x1;
      return static_cast<double>(y)/x;
        }
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        double m1= slope1(p1[0], p1[1], q1[0], q1[1]);
        double m2= slope1(p2[0], p2[1], q2[0], q2[1]);
        
        if(m1!=m2) return "true";
        
        double c1= p1[1]-m1*p1[0];
        double c2= p2[1]-m2*p2[0];
        if(c1==c2) return "true";
        else return "fasle";
        // code here
    }
};


int sum(vector<int> vec){
        int sum=0;
        for(auto i:vec){
            sum+=i;
        }
}

 
class Array{
    public:
        void input(int A[], int i){
            int j=0;
            while(j<i){
                cin>>A[j];
                j++;
            }
        }

        void print(int A[], int n){
            for(int i=0; i<n; i++){
            cout<<A[i]<<endl;}
            
        }

        int to_int(int A[], int n){
            // int n=sizeof(A)/sizeof(A[0]);
            // cout<<n<<endl;
            int output=0;
            for(int i=0; i<n; i++){
                output= output*10 +A[i];
                // cout<<output<<" ";
            }
            return output;

        }

        // int int_to_arr(int n){
        //     string str= to_string(n);
        //     int n= sizeof(str)/sizeof(str[0]);
        //     int A[n];
        //     cout<<n<<endl;
        //     for(int i=0; i<n; i++){
        //         A[i]=str[i];
        //     }
        //     return A;
            
        // }



        
};

int main() {
    int A[5];
    int B[4];
    
    Array arr;
    arr.input(A, 5);
    // arr.print(A, 5);
    arr.input(B, 4);
    // arr.print(B, 4);
    // cout<<arr.to_int(A,5) + 19;
    // cout<<9/10<<endl<<9%10;
    // int c[]= arr.int_to_arr(123);


    // int *p;
    // p=(int *)malloc(5*sizeof(int));
    // arr.input(p,5);
    // arr.print(p);
    return 0;


}