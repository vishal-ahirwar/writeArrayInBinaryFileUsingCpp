
// Auto Genrated C++ file by aura CLI
// Copyright 2023 Vishal Ahirwar //replace it with your copyright notice!
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::fstream file("array.bin", std::ios::out | std::ios::binary);
    std::string arr_str[] = {"hello", "there", "cpp", "string"};
    if (file)
    {
        for (int i = 0; i < sizeof(arr_str) / sizeof(std::string); ++i)
        {
            size_t size = arr_str[i].length();
            file.write(reinterpret_cast<char *>(&size), sizeof size);
            if (file.write((arr_str + i)->c_str(), size))
            {
                std::cout << "success\n";
            }
            else
            {
                std::cout << "failed to write array\n";
            };
        };
        file.close();
    }
    else
    {
        std::cout << "error!\n";
    }
    return 0;
};
