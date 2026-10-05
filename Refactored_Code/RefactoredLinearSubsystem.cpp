#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        int* temp = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 5)
        : data(new int[initialCapacity]), size(0), capacity(initialCapacity) {
    }

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

    bool addItem(int value) {
        if (size >= capacity) {
            resize();
        }
        data[size] = value;
        size++;
        cout << "Added item: " << value << endl;
        return true;
    }

    bool removeItemAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return false;
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        cout << "Item removed from index " << index << endl;
        return true;
    }

    int findItem(int target) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == target) {
                return i;
            }
        }
        return -1;
    }

    void printAll() const {
        if (size == 0) {
            cout << "Current List Contents: Empty" << endl;
            return;
        }
        cout << "Current List Contents: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    bool getItem(int index, int& value) const {
        if (index < 0 || index >= size) {
            return false;
        }
        value = data[index];
        return true;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }
};

void processMatrix() {
    const int rows = 3;
    const int columns = 3;
    int matrix[rows][columns] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int transpose[columns][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            cout << setw(4) << transpose[i][j];
        }
        cout << endl;
    }
}

int main() {
    cout << "--- STARTING REFACTORED SUBSYSTEM ---" << endl;
    DynamicArray records;
    records.addItem(10);
    records.addItem(20);
    records.addItem(30);
    records.addItem(40);
    records.addItem(50);
    records.addItem(60);
    records.printAll();

    cout << "Found 30 at index: " << records.findItem(30) << endl;
    cout << "Searching for 999: " << records.findItem(999) << endl;

    records.removeItemAt(2);
    records.printAll();

    records.removeItemAt(-1);
    records.removeItemAt(99);
    records.printAll();

    cout << "Current size: " << records.getSize() << endl;
    cout << "Current capacity: " << records.getCapacity() << endl;

    int value;
    if (records.getItem(0, value)) {
        cout << "Item at index 0: " << value << endl;
    }
    if (!records.getItem(99, value)) {
        cout << "Index 99 is invalid." << endl;
    }

    processMatrix();
    cout << "--- SUBSYSTEM COMPLETE ---" << endl;
    return 0;
}
