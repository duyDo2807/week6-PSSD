#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class AlternateColors {
public:
    string getColor(long r, long g, long b, long k) {
        string red = "RED", green = "GREEN", blue = "BLUE";
        k--; // Convert to 0-based index

        long min_balls = min({r, g, b});

        if (k < 3 * min_balls) {
            if (k % 3 == 0) return red;
            if (k % 3 == 1) return green;
            return blue;
        }

        r -= min_balls;
        g -= min_balls;
        b -= min_balls;
        k -= 3 * min_balls;

        if (g > 0 && b > 0) {
            min_balls = min(g, b);
            if (k < 2 * min_balls) {
                return (k % 2 == 0) ? green : blue;
            }
            k -= 2 * min_balls;
            g -= min_balls;
            b -= min_balls;
        } else if (r > 0 && b > 0) {
            min_balls = min(r, b);
            if (k < 2 * min_balls) {
                return (k % 2 == 0) ? red : blue;
            }
            k -= 2 * min_balls;
            r -= min_balls;
            b -= min_balls;
        } else if (r > 0 && g > 0) {
            min_balls = min(r, g);
            if (k < 2 * min_balls) {
                return (k % 2 == 0) ? red : green;
            }
            k -= 2 * min_balls;
            r -= min_balls;
            g -= min_balls;
        }

        if (r > 0) return red;
        if (g > 0) return green;
        return blue;
    }
};