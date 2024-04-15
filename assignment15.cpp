#include <iostream>

class DynamicArray {
private:
    int* array;
    int size;
    int capacity;

public:
    DynamicArray(int initialSize) : size(initialSize), capacity(initialSize) {
        array = new int[size];
    }

    ~DynamicArray() {
        delete[] array;
    }

    void addElement(int element) {
        if (size >= capacity) {
           
            capacity *= 2;
            int* newArray = new int[capacity];
            for (int i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
        array[size++] = element;
    }

    void display() const {
        std::cout << "Dynamic Array: ";
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DynamicArray dynArray(5); 

    
    for (int i = 1; i <= 10; ++i) {
        dynArray.addElement(i * 10);
    }

    dynArray.display();

    return 0;
}
