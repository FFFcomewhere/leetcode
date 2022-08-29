#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

void getSlice(vector<string> &table){
    string stence, word;
    cin>>stence;

    istringstream iss(stence);
    for(;iss >> word;){
        table.push_back(word);
    }
}

void getTable(vector<string> &table, int num){
    for(int i=0; i<num; i++){
        cin>>table[i];
    }
}

int main(){
    //输入数据
    int n1, n2, n3, m;
    cin>>n1>>n2>>n3;

    vector<string> data1(n1);
    getTable(data1, n1);


    vector<string> data2(n2);
    getTable(data2, n2);


    vector<string> data3(n3);
    getTable(data3, n3);


    cin>>m;
    vector<string> stence(m);
    for (int i = 0; i < m; i++){
        cin>>stence[i];
    }


    vector<string> res(m);
    //判断是否合规
    for(int i=0; i<m; i++){
        vector<string> stenceSlice;
        getSlice(stenceSlice);
        
        //找主语
        bool haveZhu = false;
        for(int j=0; j<n1; j++){
            if(stenceSlice[0] == data1[j]){
                haveZhu = true;
                break;
            }
        }

        if(!haveZhu){
            res[i] = "NO";
            continue;
        }

        //找谓语
        bool haveWei = false;
        for(int j=0; j<n2; j++){
            for(int k=0; k<stenceSlice.size(); k++){
                if(stenceSlice[k] == data2[j]){
                    haveWei = true;
                    break;
                }
            }
            if(haveWei){
                break;
            }
        }
        if(!haveWei){
            res[i] = "NO";
            continue;
        }


        //对比三者顺序
        // bool isShun = false;
        // vector<int> index(stenceSlice.size());
        // for(int j=0; j<stenceSlice.size(); j++){
        //     for(int k=0; k<n1; k++){
        //         if(stenceSlice[j] == data3[k]){
        //             index[j] = k;
        //             break;
        //         }
        //     }
        // }

        res[i] = "YES";
    }

    for(int j=0; j < res.size(); j++){
        cout<<res[j]<<endl;
    }

    return 0;       
}





