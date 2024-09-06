#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BlackAndWhiteSolitaire {
public:
    int minimumTurns(string cardFront) {
        int n = cardFront.size();
        int flipNum1 = 0, flipNum2 = 0;

        // B
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && cardFront[i] != 'B') {
                flipNum1++;
                }
            if (i % 2 == 1 && cardFront[i] != 'W') {
                flipNum1++;
                }
        }

        // W
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && cardFront[i] != 'W') {
                flipNum2++;
                }
            if (i % 2 == 1 && cardFront[i] != 'B') {
                flipNum2++;
                }
        }

        return min(flipNum1, flipNum2);
    }
};