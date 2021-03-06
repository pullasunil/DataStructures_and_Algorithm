#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#define fl(i,n) for(i=0;i<n;i++)
#define gi(x) fastscan(x)
#define pi(x) printf("%d",x)
#define pn printf("\n")
#define ps printf(' ')
using namespace std;
void fastscan(int &x)
{
    bool neg=false;
    register int c;
    x =0;
    c=getchar();
    if(c=='-')
    {
        neg = true;
        c=getchar();
    }
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1) + (x<<3) +c -48;
    if(neg)
        x *=-1;
}
int bs(int *a,int n, int x ,int left,bool asc)
{
    int right,mid;
    right = n;
    while(left<=right)
        {
            mid = (right+left)>>1;
            if(a[mid]==x)
                return mid;
            else if((a[mid] > x)==asc)
                right = mid-1;
            else if((a[mid]< x)==asc)
                left=mid+1;
        }
        return -1;
}
int binarysearch(int *a,int n,int x)
{
    if(a[0]>a[n-1])
        return bs(a,n-1, x ,0,false); // "False" For Decreasingly Sorted Array/List/Vector
    else
        return bs(a,n-1, x ,0,true);  //  "True" For Increasingly Sorted Array/List/Vector
}
//Works for both Ascending and Descending Order Array
int main()
{
    int a[100],i,n,x,t;
    cout<<"Enter N : ";
    gi(n);
    cout<<"Enter Number : ";
    fl(i,n)
    gi(a[i]);
    cout<<"Enter number of searches : ";
    gi(t);
    fl(i,t)
        {
            cout<<"Enter Search Element ";
            gi(x);
            pi(binarysearch(a,n,x));
            pn;
        }
    return 0;
}
