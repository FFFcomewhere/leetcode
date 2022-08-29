#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

//AC 82%
// int main(){
//     int n, m;
//     cin>>n>>m;

//     list<int> l;
//     for(int i=1; i<=n; i++){
//         l.push_back(i);
//     }

//     vector<int> op(m);
//     for(int i=0; i<m; i++){
//         cin>>op[i];
//     }

//     for(int i=0; i<m; i++){
//         int data = op[i];
//         auto index = find(l.begin(), l.end(), data);
//         l.erase(index);
//         l.push_front(data);
//     }

//     auto it = l.begin();
//     for(int i=0; i<n; i++){
//         cout<<*it<<" ";
//         it++;
//     }
//     // for (auto e : l){
//     //     cout<<e<<" ";
//     // }

//     return 0;       
// }
    

int main() {
    int n, m;
    cin>>n>>m;

    vector<int> data(m+n);
    vector<int> loc(n+1);
    for(int i=m; i<m+n; i++){
        data[i] = i-m+1;
        loc[i-m+1] = i;
    }
  
    vector<int> op(m);
    for(int i=0; i<m; i++){
        cin>>op[i];
    }

    int index=m-1;
    for(int i=0; i<m; i++){
        data[loc[op[i]]] = -1;
        loc[op[i]] = index;
        data[index] = op[i];
        index--;
    }

    for(int i=0; i<n+m; i++){
        if(data[i] != -1){
            cout<<data[i]<<" ";
        }
    }

}