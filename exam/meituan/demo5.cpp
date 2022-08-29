#include<iostream>
#include<vector>
using namespace std;

//AC 82%
int main(){
    int n, k, T;
    cin>>n>>k>>T;

    vector<int> t(k);
    vector<int> nums(k);

    for(int i=0; i<k; i++){
        cin>>t[i];
    }

    vector<int> thing(n);
    for(int i=0; i<n; i++){
        cin>>thing[i];
    }

    int _min = 0;
    for(int i=0; i<n; i++){
        //遇到猫
        if(thing[i] == 0){
            //检查背包
            int payTime = 0;
            int toolNum = 0;
            for(int j=0; j<k; j++){
                if(payTime<t[j] && nums[j]>0){
                    payTime = t[j];
                    toolNum = j;
                }
            }

            if(payTime > 0){
                nums[toolNum]--;
                _min+=payTime;
            } else {
                _min += T;
            }
        } else {
            //遇到工具
            nums[thing[i]-1]++;
            //cout<<nums[thing[i]-1]<<endl;
        }
    }

    cout<<_min<<endl;

    return 0;       
}
    

