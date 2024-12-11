#include <iostream>
#include <fstream>

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
            std::cout << arr[i] << "\n";
        delete[] arr;
        return 0;
    };
    int arr[] = {34, 2, 32, 4, 34, 65, 67, 56, 34, 23, 4};
    std::fstream file("arr.dat", std::ios::out | std::ios::binary);
    if (file)
    {
        size_t size{sizeof(arr) / sizeof(arr[0])};

        file.write(reinterpret_cast<char *>(&size), sizeof(size));
        if (file.write(reinterpret_cast<char *>(arr), sizeof(arr)))
        {
            std::cout << "success\n";
        };
        file.close();
    }
    else
    {
        std::cout << "error\n";
    };
};
