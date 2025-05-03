#include <bits/stdc++.h>
using namespace std;

int  main() {
    // Input For Size Of The Array , Target Element
    int n,target;
    cin>>n>>target;
    vector <int> a(n);
    // Input For Array Elements
    for(int i=0;i<n;i++)
        cin>>a[i];
    // Binary Search Start
    int l=0,h=n-1,f=0;
    while(l<=h)
    {   
        int mid=l+(h-l)/2;
        if(a[mid]==target)
        {
            f=1;
            break;
        }
        else if(a[mid]<target)
        l=mid+1;
        else
        h=mid-1;
    }
    if(f==1)
    cout<<"Target Element found\n";
    else
    cout<<"Target Element not found\n";
}