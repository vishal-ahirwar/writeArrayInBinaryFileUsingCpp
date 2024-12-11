
// Auto Genrated C++ file by aura CLI
// Copyright 2023 Vishal Ahirwar //replace it with your copyright notice!
#include <iostream>
#include <fstream>
#include<colors.hpp>

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
                std::cout <<GREEN<< "success\n"<<WHITE;
            }
            else
            {
                std::cout <<RED<< "failed to write array\n"<<WHITE;
            };
        };
        file.close();
    }
    else
    {
        std::cout <<RED<< "error!\n"<<WHITE;
    }
    return 0;
};
