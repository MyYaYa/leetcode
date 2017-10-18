class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int result = 0;
        vector<int> subs;
        for (int i = 0; i < employees.size(); i++) {
            if (employees[i]->id == id) {
                subs = employees[i]->subordinates;
                result += employees[i]->importance;
                break;
            }
        }
        for (auto &i : subs) {
            result += getImportance(employees, i);
        }
        return result;

    }
};