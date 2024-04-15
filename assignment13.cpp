#include <iostream>

class ArrayComparison {
private:
    int array1[5]; 
    int array2[5]; 

public:
   
    ArrayComparison(int arr1[], int arr2[]) {
        for (int i = 0; i < 5; ++i) {
            array1[i] = arr1[i];
            array2[i] = arr2[i];
        }
    }

    
    int compare() {
        int sum1 = 0, sum2 = 0;

        
        for (int i = 0; i < 5; ++i) {
            sum1 += array1[i];
        }

       
        for (int i = 0; i < 5; ++i) {
            sum2 += array2[i];
        }

       
        if (sum1 > sum2) {
            return 1; 
        } else if (sum1 < sum2) {
            return 2; 
        } else {
            return 0; 
        }
    }
};

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 3, 2, 1};


    ArrayComparison obj(arr1, arr2);


    int result = obj.compare();
    if (result == 1) {
        std::cout << "Array 1 has a higher sum." << std::endl;
    } else if (result == 2) {
        std::cout << "Array 2 has a higher sum." << std::endl;
    } else {
        std::cout << "Both arrays have the same sum." << std::endl;
    }

    return 0;
}