#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int MOD = 1000000007;

int main() {
    int n;
    cin>>n;

    if(n<6){
        cout<<0;
        return 0;
    }


    long long Res = 1, R1 = 1, R2 =1;
    for(int i=2; 3*i<n; i++){
        int k = n-3*i;

        //R1
        for(int j=0; j<k; j++){
            R1 = (R1*26)%MOD;
        }

        //R2
        for(int j=i+1; j<i+1+k; j++){
            R2 = (R2*j)%MOD;
                        cout<<R2<<" ";

        }
    }

    Res = (R1*R2) % MOD;
    cout<<endl<<Res<<" "<<R1<<" "<<R2<<endl;
    return 0;
}