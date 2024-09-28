#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <Windows.h>
using namespace std;
using namespace std::chrono_literals;

void On(int n)
{
    // O(N)
    for (int i = 1; i <= n; i++)
    {
        // Statement
    }
}

void Ologn(int n)
{
    // O(log(N))
    for (int i = 1; i <= n; i *= 2)
    {
        // Statement
    }
}

void On2(int n)
{
    // O(N^2)
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= n; i++)
        {
            // Statement
        }
    }
}

void dothoigian(int n, void (*function)(int))
{
    const auto start{std::chrono::steady_clock::now()};
    function(n);
    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double, std::milli> elapsed_seconds{end - start};
    std:cout << elapsed_seconds.count() ;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8); // Thư viện hỗ trợ in Tiếng Việt

    // Đo thời gian với N = 10;
    cout << "Đo thời gian với N = 10\n";
    cout << "   O(N) : "; dothoigian(10, On); cout << " milieconds\n";
    cout << "   O(log(N)) : "; dothoigian(10, Ologn); cout << " miliseconds\n";
    cout << "   O(N^2) : "; dothoigian(10, On2); cout << " miliseconds\n\n";

    // Đo thời gian với N = 100;
    cout << "Đo thời gian với N = 100\n";
    cout << "   O(N) : "; dothoigian(100, On); cout << " miliseconds\n";
    cout << "   O(log(N)) : "; dothoigian(100, Ologn); cout << " miliseconds\n";
    cout << "   O(N^2) : "; dothoigian(100, On2); cout << " miliseconds\n\n";

    // Đo thời gian với N = 1000;
    cout << "Đo thời gian với N = 1000\n";
    cout << "   O(N) : "; dothoigian(1000, On); cout << " miliseconds\n\n";
    cout << "   O(log(N)) : "; dothoigian(1000, Ologn); cout << " miliseconds\n";
    cout << "   O(N^2) : "; dothoigian(1000, On2); cout << " miliseconds\n";
}
