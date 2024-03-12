#include<iostream>
using namespace std;

class sample {
public:
    int Compute(int (sample::*func)(int), int n) {
        return (this->*func)(n);
    }

    int findFactorial(int n) {
        int fact=1;
        for(int i=1; i<=n; i++) {
            fact = fact * i;
        }
        return fact;
    }

    int findSquare(int n) {
        return n*n;
    }

    int findCube(int n) {
        return n*n*n;
    }
};

int main(int argc, char *argv[]) {
    if(argc < 2) {
        cout << "Usage: ./program_name <number>" << endl;
        return 1;
    }

    int n = atoi(argv[1]);

    sample obj;

    cout << "Factorial of " << n << ": " << obj.Compute(&sample::findFactorial, n) << endl;

    cout << "Square of " << n << ": " << obj.Compute(&sample::findSquare, n) << endl;

    cout << "Cube of " << n << ": " << obj.Compute(&sample::findCube, n) << endl;

    return 0;
}