#include <iostream>
#include <string>

using namespace std;

class GoodHours {
public:
    int howMany(string beforeTime, string afterTime) {
        int beforeMinutes = convertToMinutes(beforeTime);
        int afterMinutes = convertToMinutes(afterTime);
        
        int goodTimesCount = 0;
        for (int time = beforeMinutes; time <= afterMinutes; ++time) {
            string currentTime = convertToTimeString(time);
            if (isGoodTime(currentTime)) {
                goodTimesCount++;
            }
        }
        
        return goodTimesCount;
    }

private:
    int convertToMinutes(string time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }
    
    string convertToTimeString(int minutes) {
        int hours = minutes / 60;
        int mins = minutes % 60;
        return (hours < 10 ? "0" : "") + to_string(hours) + ":" + 
               (mins < 10 ? "0" : "") + to_string(mins);
    }
    
    bool isGoodTime(string time) {
        int h1 = time[0] - '0';
        int h2 = time[1] - '0';
        int m1 = time[3] - '0';
        int m2 = time[4] - '0';
        
        if (h1 * h2 == m1 * m2) return true;
        if (h1 == h2 * m1 * m2) return true;
        if (h1 * h2 * m1 == m2) return true;
        
        return false;
    }
};