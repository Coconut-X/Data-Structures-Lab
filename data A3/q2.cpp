#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap; 
    bool isMinHeap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0) {
            int p = parent(i);
            if (isMinHeap) {
                if (heap[i] < heap[p]) {
                    swap(heap[i], heap[p]);
                } else {
                    break;
                }
            } else {
                if (heap[i] > heap[p]) {
                    swap(heap[i], heap[p]);
                } else {
                    break;
                }
            }
            i = p;
        }
    }

    void heapifyDown(int i) {
        int size = heap.size();
        while (true) {
            int left = leftChild(i);
            int right = rightChild(i);
            int target = i;

            if (isMinHeap) {
                if (left < size && heap[left] < heap[target]) target = left;
                if (right < size && heap[right] < heap[target]) target = right;
            } else {
                if (left < size && heap[left] > heap[target]) target = left;
                if (right < size && heap[right] > heap[target]) target = right;
            }

            if (target != i) {
                swap(heap[i], heap[target]);
                i = target;
            } else {
                break;
            }
        }
    }

public:
    Heap(bool isMin = true) : isMinHeap(isMin) {}

    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int extractRoot() {
        if (heap.empty()) return isMinHeap ? INT_MAX : INT_MIN;

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    int getRoot() {
        if (heap.empty()) return isMinHeap ? INT_MAX : INT_MIN;
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }

    void clear() {
        heap.clear();
    }

    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

class IntervalHeap {
private:
    Heap minHeap;
    Heap maxHeap;
    int count;   

public:
    IntervalHeap() : minHeap(true), maxHeap(false), count(0) {}

    void insert(int x) {
        if (count % 2 == 0) {
            minHeap.insert(x);
        } else {
            maxHeap.insert(x);
        }
        count++;

        if (!minHeap.empty() && !maxHeap.empty() && minHeap.getRoot() > maxHeap.getRoot()) {
            int left = minHeap.extractRoot();
            int right = maxHeap.extractRoot();
            minHeap.insert(right);
            maxHeap.insert(left);
        }
    }

    void deleteRoot() {
        if (count == 0) {
            cout << "Heap is empty" << endl;
            return;
        }

        if (!minHeap.empty()) minHeap.extractRoot();
        if (!maxHeap.empty()) maxHeap.extractRoot();
        count -= 2;
        if (count < 0) count = 0; 
    }

    void display() {
        cout << "Heap size: " << count << endl;

        vector<int> left, right;

        while (!minHeap.empty()) left.push_back(minHeap.extractRoot());
        while (!maxHeap.empty()) right.push_back(maxHeap.extractRoot());

        for (size_t i = 0; i < left.size(); i++) {
            int l = left[i];
            int r = (i < right.size() ? right[i] : INT_MIN);
            cout << "[" << l << ", " << r << "] ";
        }
        cout << endl;

        for (int val : left) minHeap.insert(val);
        for (int val : right) maxHeap.insert(val);
    }

    void update(int oldValue, int newValue) {
        bool found = false;

        vector<int> tempMin, tempMax;

        
        while (!minHeap.empty()) {
            int top = minHeap.extractRoot();
            if (top == oldValue && !found) {
                tempMin.push_back(newValue); 
                found = true;
            } else {
                tempMin.push_back(top);
            }
        }

        for (int val : tempMin) {
            minHeap.insert(val);
        }

        while (!maxHeap.empty()) {
            int top = maxHeap.extractRoot();
            if (top == oldValue && !found) {
                tempMax.push_back(newValue); 
                found = true;
            } else {
                tempMax.push_back(top);
            }
        }

        for (int val : tempMax) {
            maxHeap.insert(val);
        }

        if (!found) {
            cout << "Value " << oldValue << " not found!" << endl;
        }

        if (!minHeap.empty() && !maxHeap.empty() && minHeap.getRoot() > maxHeap.getRoot()) {
            int left = minHeap.extractRoot();
            int right = maxHeap.extractRoot();
            minHeap.insert(right);
            maxHeap.insert(left);
        }
    }

};

int main() {
    IntervalHeap ih;

    ih.insert(47);
    ih.insert(36);
    ih.insert(15);
    ih.insert(30);
    ih.insert(6);
    ih.insert(40);

    cout << "After insertions:" << endl;
    ih.display();

    ih.deleteRoot();
    cout << "\nAfter deleting root:" << endl;
    ih.display();

    ih.update(15, 20);
    cout << "\nAfter updating 15 to 20:" << endl;
    ih.display();

    return 0;
}
