#include <iostream>
#include <fstream>
#include<colors.hpp>

int main()
{
    std::fstream file_r("arr.dat", std::ios::in | std::ios::binary);
    if (file_r)
    {
        size_t size{};
        file_r.read(reinterpret_cast<char *>(&size), sizeof(size));
        int *arr = new int[size];
        file_r.read(reinterpret_cast<char *>(arr), size * sizeof(int));
        for (int i = 0; i < size; ++i)
            std::cout << arr[i] << " ";
        std::cout<<"\n";
        delete[] arr;
        return 0;
    };
    int arr[] = {45,46,47,48,50,55,90,120,150};
    std::fstream file("arr.dat", std::ios::out | std::ios::binary);
    if (file)
    {
        size_t size{sizeof(arr) / sizeof(arr[0])};

        file.write(reinterpret_cast<char *>(&size), sizeof(size));
        if (file.write(reinterpret_cast<char *>(arr), sizeof(arr)))
        {
            std::cout <<GREEN<< "success\n"<<WHITE;
        };
        file.close();
    }
    else
    {
        std::cout <<RED<< "error\n"<<WHITE;
    };
};
