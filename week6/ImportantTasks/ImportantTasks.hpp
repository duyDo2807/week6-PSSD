#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ImportantTasks {
public:
    int maximalCost(vector<int> complexity, vector<int> computers) {
        sort(complexity.begin(), complexity.end());
        sort(computers.begin(), computers.end());
        
        int taskCount = 0;
        int i = 0, j = 0;
        
        while (i < complexity.size() && j < computers.size()) {
            if (complexity[i] <= computers[j]) {
                taskCount++;
                i++;
            }
            j++;
        }
        
        return taskCount;
    }
};