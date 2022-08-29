#include<iostream>
#include<vector>
using namespace std;
void getAllPermutation(vector<vector<int>>& res, vector<int>& subRes, vector<int>& book, int index, int n){
    if(index == n){
        res.push_back(subRes);
        return;
    }

    for(int i=0; i<n; i++){
        if(book[i] == 0){
            subRes.push_back(i);
            book[i] = 1;
            getAllPermutation(res, subRes, book, index+1, n);
            subRes.pop_back();
            book[i] = 0;
        }
    }
}


//AC 55%
int main(){
    int n, m;
    cin>>n>>m;

    string S;
    cin>>S;

    vector<int> sLen(m);
    for(int i=0; i<m; i++){
        cin>>sLen[i];
    }
    vector<string> s(m);
    for(int i=0; i<m; i++){
        cin>>s[i];
    }

    //获取全排列
    vector<vector<int>> all;
    vector<int> subAll;
    vector<int> book(m,0);
    getAllPermutation(all, subAll, book, 0, m);

    // for(int i=0; i<all.size(); i++){
    //     for(int j=0; j<all[i].size(); j++){
    //         cout<<all[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int res=0;

    //重组字符串
    for(int i=0; i<all.size(); i++){
        int SL=0;
        bool flag = true;
        for(int j=0; j<all[i].size(); j++){
            int L = sLen[all[i][j]];
            if(s[all[i][j]] != S.substr(SL, L)){
                flag = false;
                break;
            }
            SL += L;
        }
        if(flag){
            res++;
        }
    }

    cout<<res;
    return 0;       
}
    
