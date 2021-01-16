#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> fibo(10000);

int fibonacci (int ptr, int n){
    for(int i=1;i<=n-ptr;i++)
        fibo[ptr+i]=fibo[ptr+i-1]+fibo[ptr+i-2];
    return n;
}

int main(){
fill(fibo.begin(),fibo.end(),0);
fibo[2]=1;
int ptr=2,x;
while(true){
cout<<"Enter n: ";
cin>>x;
if(x>ptr){
ptr=fibonacci(ptr,x);
cout<<fibo[x]<<endl;
cout<<"ptr"<<ptr<<endl;
}
else
cout<<fibo[x]<<endl;
if(x==-1)
break;
}
return 0;
}