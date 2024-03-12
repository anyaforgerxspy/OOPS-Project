#include <iostream>

class computation {
public:
    int compute(int a, int b) {
        return a + b;
    }

    float compute(int a, float b) {
        return a + b;
    }

    double compute(int a, double b) {
        return a + b;
    }

    int compute(char a, char b) {
        return int(a) + int(b);
    }

    int compute(char a, int b) {
        return int(a) + b;
    }

    int compute() {
        return 0;
    }
};

int main() {
    computation obj;
    
    std::cout << "Integer Addition: " << obj.compute(5, 10) << std::endl;
    std::cout << "Integer-Float Addition: " << obj.compute(5, 10.5f) << std::endl;
    std::cout << "Integer-Double Addition: " << obj.compute(5, 10.5) << std::endl;
    std::cout << "Character ASCII Addition: " << obj.compute('a', 'b') << std::endl;
    std::cout << "Character-Integer ASCII Addition: " << obj.compute('a', 10) << std::endl;
    std::cout << "No-value Addition: " << obj.compute() << std::endl;

    return 0;
}