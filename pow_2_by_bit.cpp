#include<iostream>

using namespace std;

int main(){
    
    int n;

    cout<<"Enter the value"<<endl;
    cin>>n;

    if((n^(n-1)) == (n+n-1)) cout<<"Yess!!!"<<endl;
    else cout<<"Nope..."<<endl;

    cout<<"Program ending... BYE!!!"<<endl;

    return 0;
}