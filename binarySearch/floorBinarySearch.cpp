#include <bits/stdc++.h>
using namespace std;

int main() {
    // Input For Size Of The Array , Target Element
    int n,target;
    cin>>n>>target;
    vector <int> a(n);
    // Input For Array Elements
    for(int i=0;i<n;i++)
        cin>>a[i];
    // Floor Binary Search Start
    // Sort The Array
    sort(a.begin(),a.end());
    int l=0,h=n-1,index=-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(a[mid]<=target)
        {
            index=mid;
            l=mid+1;
        }
        else
        h=mid-1;
    }
    if(index==-1)
        cout<<"Floor does not exist"<<endl;
    else
        cout<<a[index]<<endl;

    return 0;
}