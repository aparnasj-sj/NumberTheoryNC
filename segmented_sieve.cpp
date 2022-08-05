#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    
    // write your code here
    int root=sqrt(1000000001);
    int sieve[root+1];
     memset(sieve,0,sizeof(sieve));
    sieve[0]=sieve[1]=1;
    for(int i=2;i*i<=root;i++){
        if(sieve[i]==0){
            for(int j=i*i;j<=root;j+=i){
                sieve[j]=1;
            }
        }
    }
    vector<int>prime;
    for(int i=0;i<=root;i++){
        if(sieve[i]==0){
            prime.pb(i);
            //cout<<i<<" ";
            
        }
    }
    
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int sieve[r-l+1];
        memset(sieve,0,sizeof(sieve));
        int start=0;
        // find first multiple of p in range L to R
        for(auto p:prime){
            if(l%p==0){start=(l/p)*p;}else{
                start=((l/p)*p)+p;
                
            }
            if(start==p){start+=p;}
        
         
            for(int j=start;j<=r;j+=p){
             
                sieve[j-l]=1;  // elm j is mapped to indx j-L
              
            }
            
        }
        // if range starts from 1 , mark 1 not prime 
        if(l==1){sieve[0]=1; }
        for(int i=0;i<(r-l+1);i++){
            //cout<<sieve[i]<<endl;
            if(sieve[i]==0){
                cout<<(i+l)<<" ";
            }
        }
        cout<<endl;
        
        
        
        
    }
    
    return 0;
}
