#include <stdlib.h>

#define MAX 20000

typedef struct {
    int maxHeap[MAX];
    int minHeap[MAX];
    int maxSize;
    int minSize;
} MedianFinder;

/* ---------- MAX HEAP ---------- */

void maxHeapInsert(MedianFinder* obj, int val){
    int i = obj->maxSize++;
    obj->maxHeap[i] = val;

    while(i>0){
        int parent = (i-1)/2;
        if(obj->maxHeap[parent] >= obj->maxHeap[i]) break;

        int temp = obj->maxHeap[parent];
        obj->maxHeap[parent] = obj->maxHeap[i];
        obj->maxHeap[i] = temp;

        i = parent;
    }
}

int maxHeapPop(MedianFinder* obj){
    int top = obj->maxHeap[0];
    obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];

    int i=0;
    while(1){
        int left = 2*i+1, right = 2*i+2, largest=i;

        if(left < obj->maxSize && obj->maxHeap[left] > obj->maxHeap[largest])
            largest = left;
        if(right < obj->maxSize && obj->maxHeap[right] > obj->maxHeap[largest])
            largest = right;

        if(largest == i) break;

        int temp = obj->maxHeap[i];
        obj->maxHeap[i] = obj->maxHeap[largest];
        obj->maxHeap[largest] = temp;

        i = largest;
    }

    return top;
}

/* ---------- MIN HEAP ---------- */

void minHeapInsert(MedianFinder* obj, int val){
    int i = obj->minSize++;
    obj->minHeap[i] = val;

    while(i>0){
        int parent = (i-1)/2;
        if(obj->minHeap[parent] <= obj->minHeap[i]) break;

        int temp = obj->minHeap[parent];
        obj->minHeap[parent] = obj->minHeap[i];
        obj->minHeap[i] = temp;

        i = parent;
    }
}

int minHeapPop(MedianFinder* obj){
    int top = obj->minHeap[0];
    obj->minHeap[0] = obj->minHeap[--obj->minSize];

    int i=0;
    while(1){
        int left=2*i+1, right=2*i+2, smallest=i;

        if(left < obj->minSize && obj->minHeap[left] < obj->minHeap[smallest])
            smallest = left;
        if(right < obj->minSize && obj->minHeap[right] < obj->minHeap[smallest])
            smallest = right;

        if(smallest == i) break;

        int temp = obj->minHeap[i];
        obj->minHeap[i] = obj->minHeap[smallest];
        obj->minHeap[smallest] = temp;

        i = smallest;
    }

    return top;
}

/* ---------- MAIN FUNCTIONS ---------- */

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {

    if(obj->maxSize == 0 || num <= obj->maxHeap[0])
        maxHeapInsert(obj, num);
    else
        minHeapInsert(obj, num);

    /* Balance heaps */
    if(obj->maxSize > obj->minSize + 1)
        minHeapInsert(obj, maxHeapPop(obj));

    if(obj->minSize > obj->maxSize)
        maxHeapInsert(obj, minHeapPop(obj));
}

double medianFinderFindMedian(MedianFinder* obj) {

    if(obj->maxSize > obj->minSize)
        return obj->maxHeap[0];

    return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}
