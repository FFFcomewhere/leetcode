#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 0;
    cin>>n;
    int sum=0;
    vector<string> data(n);
    for(int i=0; i<n; i++){
        cin>>data[i];
    }

    for(auto e : data){
        if(e.size() > 10){
            continue;
        }
        bool flag = true;
        for(int i=0; i<e.size(); i++){
            if(('a' <= e[i]  && e[i] <= 'z') || 'A' <= e[i]  && e[i] <= 'Z'){
                continue;
            } else {
                flag = false;
                break;
            }
        }
        if (flag){
            sum++;
        }
    }
    cout<<sum;

    return 0;       
}
    

