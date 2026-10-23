#include <iostream>

int toi(char* s) {
    int x = 0;
    int i = 0;
    while (s[i] != '\0') {
        x = x * 10 + (s[i] - '0');
        i++;
    }
    return x;
}

int main(int argc, char* argv[]) {
    if (argc != 2)
        return 1;
    int n = toi(argv[1]);
    double* a = new double[n];
    double* b = new double[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];
    double result = 0;
    for (int i = 0; i < n; i++)
        result += a[i] * b[i];
    std::cout << result << '\n';
    delete[] a;
    delete[] b;
    return 0;
}
