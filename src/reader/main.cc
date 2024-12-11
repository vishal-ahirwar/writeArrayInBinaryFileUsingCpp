
// Auto Genrated C++ file by aura CLI
// Copyright 2023 Vishal Ahirwar //replace it with your copyright notice!
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<std::string> data{};
    std::fstream file("array.bin", std::ios::in | std::ios::binary);
    if (file)
    {
        while (true)
        {
            size_t size{};
            char *buffer;
            file.read(reinterpret_cast<char *>(&size), sizeof(size));
            buffer = new char[size];
            file.read(buffer, size);
            buffer[size] = '\0';
            data.push_back(buffer);
            delete[] buffer;
            if (file.eof())
                break;
        };
        file.close();
        std::cout << "data read : \n";
        for (const std::string &str : data)
            std::cout << str << "\n";
    }
    else
    {
        std::cout << "error!\n";
    }
    return 0;
};
