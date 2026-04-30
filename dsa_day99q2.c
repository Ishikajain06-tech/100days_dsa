#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    double time;
} Car;

// Sort in descending order of position
int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;
    return c2->position - c1->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    
    if (positionSize == 0) return 0;

    Car cars[positionSize];

    // Step 1: compute time to reach target
    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Step 2: sort by position (descending)
    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double maxTime = 0;

    // Step 3: count fleets
    for (int i = 0; i < positionSize; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    return fleets;
}
