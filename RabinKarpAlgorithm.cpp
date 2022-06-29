#include<bits/stdc++.h>
using namespace std;

//hashCode number is 59
int p=59;
const int mod=1e9,N=1e5;
vector<long long> power(N);


int32_t main(){
    string s ="ma";
    string t ="yashsomani";
    int ns=s.size(),nt=t.size();

power[0]=1;
    for(int i=1;i<N;i++){
        power[i]= (power[i-1]*p)%mod;
    }

    vector<long long> v(nt+1,0);
    for(int i =0;i<nt;i++){
        v[i+1]= (v[i] + (t[i]-'a'+1)*power[i])%mod;
    } 

    long long pat=0;
    for(int i =0;i<ns;i++){
        pat=(pat+ (s[i]-'a'+1)*power[i])%mod;
    }

    for(int i =0;i+ns-1<nt;i++){
        long long curr = (v[i+ns]-v[i]+mod)%mod;

        if(curr== (pat*power[i])%mod){
            cout<<"FOUND at "<<i<<endl;
        }
    }
    return 0;
}