#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=sandwiches.size();
        bool same = true;
        stack<int> s;
        for(int i=sandwiches.size()-1; i>=0; i--){
            s.push(sandwiches[i]);
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            q.push(students[i]);
        }

        for(; !q.empty();){
            int size = q.size();
            same = true;
            for(int i=0; i<size; i++){
                if(q.front() == s.top()){
                    same = false;
                    q.pop();
                    s.pop();
                } else {
                    int temp = q.front();
                    q.pop();
                    q.push(temp);
                }
            }

            if(same == true){
                return size;
            }
        }
        return 0;
    }
};

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=sandwiches.size();
        int s1 = accumulate(students.begin(), students.end(), 0);
        int s0 = n - s1;

        for(auto e:sandwiches){
            if(e == 0 && s0>0){
                s0--;
            } else if(e == 1 && s1>0){
                s1--;
            } else {
                break;
            }
        }

        return s0+s1;
    }
};
/*
分析:

方法:

总结:

*/