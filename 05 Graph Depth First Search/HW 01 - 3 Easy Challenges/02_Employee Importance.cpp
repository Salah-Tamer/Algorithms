#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
    unordered_map<int, Employee*> EmployeeMap;
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(Employee* e : employees){
            EmployeeMap[e->id] = e;
        }

        return dfs(id);
    }

    int dfs( int idx){
        Employee* employee = EmployeeMap[idx];
        int ans = employee->importance;
        for(int subordinateId : employee->subordinates){
            ans += dfs(subordinateId);
        }

        return ans;
    }
};