#include <stdio.h>
#include <stdlib.h>

// Structure to store position and time
typedef struct {
    int position;
    double time;
} Car;

// Comparator for sorting in descending order of position
int compare(const void *a, const void *b) {
    Car *car1 = (Car *)a;
    Car *car2 = (Car *)b;
    return car2->position - car1->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    // Step 1: Calculate time for each car
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Step 2: Sort cars by position (descending)
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double maxTime = 0;

    // Step 3: Traverse and count fleets
    for (int i = 0; i < n; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    return fleets;
}

// Driver code
int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;

    printf("Number of Car Fleets: %d\n", carFleet(target, position, speed, n));
    return 0;
}