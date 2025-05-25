#include <bits/stdc++.h>
using namespace std;

int main() {
    // Input For Number
    int n;
    cin>>n;
    if(n<=1){
    cout<<"is not a Prime Number";
    return 0;
    }
    int f=1;
    // Check Prime Start
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            f=0;
            break;
        }
    }
    if(f==1)
    cout<<n<<" is a Prime Number";
    else
    cout<<n<<" is not a Prime Number";
    return 0;
}