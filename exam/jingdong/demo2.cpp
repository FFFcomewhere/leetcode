#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// int main() {
//     int n;
//     cin>>n;
//     unordered_map<int, int> h;
//     int _max1=0, _max2=0;
//     int _max1Num=0, _max2Num=0;

//     vector<int> nums(n);
//     for(int i=0; i<n; i++){
//         cin>>nums[i];

//         h[nums[i]]++;
//     }

//     for(auto it=h.begin(); it!=h.end(); it++){
//         if(_max1 < it->second){
//             _max1Num = it->first;
//             _max1 = it->second;
//         }
//     }

//     for(auto it=h.begin(); it!=h.end(); it++){
//         if(_max2 < it->second && it->first != _max1Num){
//             _max2Num = it->first;
//             _max2 = it->second;
//         }
//     }

//     int a1=0, a2=0, b1=0, b2=0;
//     for(int i=0; i<n; i++){
//         if(nums[i]==_max1Num){
//             if(i%2==1){
//                 a1++;
//             } else {
//                 a2++;
//             }
//         } 

//         if(nums[i]==_max2Num){
//             if(i%2==1){
//                 b1++;
//             } else {
//                 b2++;
//             }
//         }
//     }

//     // cout<<a1<<" "<<a2<<endl;
//     // cout<<b1<<" "<<b2<<endl;


//     // cout<<_max1Num<<" "<<_max2Num<<endl;

//     int _maxStay = max(a1+b2, a2+b1);
//     int res = n-_maxStay;

//     cout<<res<<endl;

//     return 0;
// }

int main() {
    int n;
    cin>>n;

    vector<<vector<int>> dp(n, vector<int>(n, 0));

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    for(int i=0; i<n; i++){
        //如果改变
        if(i+2<n && nums[i] != nums[i+2]){
            nums[i+2] = nums[i];
            dp[i][1] = min(dp[i][1]+1, dp[i][0]);
        } else {
            dp[i][0] = min(dp[i][0]+1, dp[i][1]);
        }
    }







    cout<<res<<endl;

    return 0;
}