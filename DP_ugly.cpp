#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unsigned getugly(unsigned n){
    unsigned a[n];
    unsigned i2=0, i3=0, i5=0;
    unsigned ni2=2, ni3=3, ni5=5;
    unsigned nun=1;
    a[0]=nun;
    for(int i=1;i<n;i++){
        nun= min(ni2, min(ni3,ni5));
        a[i]=nun;
        if(nun==ni2)
            ni2=a[++i2]*2;
        if(nun==ni3)
            ni3=a[++i3]*3;
        if(nun==ni5)
            ni5=a[++i5]*5;
    }
    return nun;
}
int main(){
    unsigned x;
    cout<<"Enter value of n: ";
    cin>>x;
    cout<<getugly(x);
    return 0;
}