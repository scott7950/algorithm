#include <iostream>

using std::cout;
using std::endl;

int fib1(int n) {
    if(n <= 1)
        return 1;
    else
        return (fib1(n-1) + fib1(n-2));
}

int fib2(int* fib2_data, int n) {
    for(int i=2; i<=n; i++) {
        fib2_data[i] = fib2_data[i-1] + fib2_data[i-2];
    }

    return fib2_data[n];
}

int fib3(int n) {
    if(n <= 1)
        return 1;

    int last = 1;
    int last2last = 1;
    int result = 1;

    for(int i=2; i<=n; i++) {
        result = last + last2last;
        last2last = last;
        last = result;
    }

    return result;
}

int main(int argc, char* argv[]) {
    int n = 10;

    int fib1_data = fib1(n);
    cout << fib1_data << endl;

    int *fib2_data = new int[n];
    fib2_data[0] = fib2_data[1] = 1;
    int fib2_data1 = fib2(fib2_data, n);
    cout << fib2_data1 << endl;

    int fib3_data = fib3(n);
    cout << fib3_data << endl;

    return 0;
}

