#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    const std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dateToDayOfYear(const std::string& date) {
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));
        
        int dayCount = 0;
        for (int i = 0; i < month - 1; ++i) {
            dayCount += daysInMonth[i];
        }
        return dayCount + day;
    }

public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice, std::string arriveBob, std::string leaveBob) {
        // Convert all date intervals to numerical day boundaries
        int startA = dateToDayOfYear(arriveAlice);
        int endA = dateToDayOfYear(leaveAlice);
        int startB = dateToDayOfYear(arriveBob);
        int endB = dateToDayOfYear(leaveBob);
        
        // The overlap range begins at the maximum of the two arrival days
        // and ends at the minimum of the two departure days
        int overlapStart = std::max(startA, startB);
        int overlapEnd = std::min(endA, endB);
        
        // If they overlap, return the difference + 1 (inclusive count). Otherwise, return 0.
        return std::max(0, overlapEnd - overlapStart + 1);
    }
};
