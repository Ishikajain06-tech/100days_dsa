#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

// Comparator for sorting by start time
int compare(const void* a, const void* b) {
    struct Interval* i1 = (struct Interval*)a;
    struct Interval* i2 = (struct Interval*)b;
    return i1->start - i2->start;
}

int canAttendMeetings(struct Interval intervals[], int n) {
    if (n <= 1) return 1;

    qsort(intervals, n, sizeof(struct Interval), compare);

    for (int i = 1; i < n; i++) {
        if (intervals[i].start < intervals[i - 1].end)
            return 0; // overlap
    }
    return 1;
}