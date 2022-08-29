#include<iostream>
#include<vector>
using namespace std;

//AC 82%
int main(){
    int n, m;
    cin>>n>>m;

    string S, s;
    cin>>S>>s;

    int res=0;

    for(int i=0; i<n; i++){
        if(n-i < m){
            break;
        }

        if(S[i] == s[0] || s[0] == '*'){
            int j=0;
            for(; j<m; j++){
                if(s[j] == '*'){
                    continue;
                }
                if(S[i+j] != s[j]){
                    break;
                }
            }
            if(j == m){
                res++;
            }
        }
    }
    cout<<res;

    return 0;       
}
    

