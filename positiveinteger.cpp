#include <iostream>
using namespace std;

int sum_of_series(int n) {
    int series_sum = 0; 
    int term_sum = 0;
    
    for (int i = 1; i <= n; i++) {
        term_sum += i;
        series_sum += term_sum;
    }
    return series_sum;
}

int main() {
    int n;
    
    cout << "Enter a positive integer: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1; 
    }
    
    int result = sum_of_series(n);
     cout << "Sum of series: " << result << endl;
    
    return 0;
}
