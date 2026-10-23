#include <iostream>

void reverse(int a[], int l, int r)
{
    while (l < r)
    {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;
        l++;
        r--;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    return 1;
    int n = 0;
    for (int i = 0; argv[1][i] != '\0'; i++)
        n = n * 10 + argv[1][i] - '0';
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    int k;
    std::cin >> k;
    k %= n;
    if (k < 0)
        k += n;
    reverse(a, 0, n - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);
    for (int i = 0; i < n; i++)
        std::cout << a[i] << '\n';
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            std::cout << ' ';
        std::cout << a[i];
    }
    std::cout << '\n';
    delete[] a;
    return 0;
}
