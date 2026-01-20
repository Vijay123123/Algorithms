
#include <bits/stdc++.h>
using namespace std;


class Seg {
    
    public:
    int n; 
    vector <int> seg(4*n);
    Seg(int n) {
        
        this->n=n;
        seg.resize(4*n,0);
    }
    
    void build(int ind,int low,int high) {
        
        if(low==high) {
            seg[ind]=a[low];
            return;
        }
        
        int mid=(low+high)/2;
        build(2*ind+1,low,mid);
        build(2*ind+2,mid+1,high);
        
        // perform required operation here
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
};

int main() {
    
    int n; 
    cin>>n;
    
    vector <int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    
    Seg(n);
    build(0,0,n-1);
    
    return 0;
}
