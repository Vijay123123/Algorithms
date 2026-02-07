
#include <bits/stdc++.h>
using namespace std;


class Seg {
    
    public:
    int n; 
    int req;
    vector <int> seg(4*n);
    Seg(int n) {
        
        this->n=n;
        req=0;
        seg.resize(4*n,0);
    }
    
    int combine(int ind) {
        
        return max([2*ind+1],seg[2*ind+2]);
    }
    void build(int ind,int low,int high) {
        
        if(low==high) {
            seg[ind]=a[low];
            return;
        }
        
        int mid=(low+high)/2;
        build(2*ind+1,low,mid);
        build(2*ind+2,mid+1,high);
        
        combine(ind);
    }
    
    int query(int ind,int low,int high,int l,int r) {
        
        if(high <l || low>r) {
            return req;
        }
        if(low>=l && high<=r) {
            return seg[ind];
        }
        int mid=(low+high)/2;
        int left=query(2*ind+1,low,mid,l,r);
        int right=query(2*ind+2,mid+1,high,l,r);
        
        return combine(left,right);
        
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
