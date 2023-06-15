#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

std::vector<Interval> mergeIntervals(std::vector<Interval>& intervals) {
    std::vector<Interval> mergedIntervals;
    
    // Sort intervals based on the starting point
    std::sort(intervals.begin(), intervals.end(), compareIntervals);
    
    // Merge overlapping intervals
    for (const Interval& interval : intervals) {
        if (mergedIntervals.empty() || mergedIntervals.back().end < interval.start) {
            mergedIntervals.push_back(interval);
        } else {
            mergedIntervals.back().end = std::max(mergedIntervals.back().end, interval.end);
        }
    }
    
    return mergedIntervals;
}

void printIntervals(const std::vector<Interval>& intervals) {
    for (const Interval& interval : intervals) {
        std::cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));
    
    std
