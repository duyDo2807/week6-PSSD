#include <vector>
#include <iostream>

using namespace std;

class DerivativeSequence {
public:
    vector<int> derSeq(vector<int> a, int n) {
        vector<int> current = a;
        
        for (int i = 0; i < n; i++) {
            vector<int> next;
            for (int j = 1; j < current.size(); j++) {
                next.push_back(current[j] - current[j - 1]);
            }
            current = next;
        }
        
        return current;
    }
};