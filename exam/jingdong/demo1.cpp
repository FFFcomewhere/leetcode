#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;

    string S;
    cin>>S;

    for(int i=0; i<n; i++){
        if(i<k && 'a' <= S[i] && S[i] <= 'z'){
            S[i] = S[i] - 'a' + 'A';
        } else if(i>=k && 'A' <= S[i] && S[i] <= 'Z'){
            S[i] = S[i] - 'A' + 'a';
        }
    }

    cout<<S;

    return 0;
}