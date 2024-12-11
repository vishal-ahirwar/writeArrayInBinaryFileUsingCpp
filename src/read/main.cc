#include <iostream>
#include <fstream>
#include <vector>
#include<colors.hpp>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr <<RED<<"No Input files to read!\n"<<WHITE;
        return 0;
    };

    for (int i = 1; i < argc; ++i)
    {
        std::ifstream file;
        file.open(argv[i], std::ios::in | std::ios::binary);
        if (!file)
        {
            std::cerr <<RED<< "failed to read file : " << argv[i] << "\n"<<WHITE;
            file.close();
            continue;
        };
        file.seekg(0, std::ios::end);
        auto size{file.tellg()};
        if(size<=0)
        {
            std::cerr<<RED<<argv[i]<<" is empty!\n"<<WHITE;
            file.close();
            continue;
        }
        file.seekg(0,std::ios::beg);
        char *buffer = new char[size];
        if(buffer==nullptr)
        {
            std::cerr<<RED<<"Failed to allocate memory!\n"<<WHITE;
            file.close();
            continue;
        };
        if(!file.read(buffer, size))
        {
            std::cerr<<RED<<"unkown error : failed to read file\n"<<WHITE;
            file.close();
            continue;
        };
        buffer[size] = '\0';
        std::cout <<YELLOW<<"File Read "<< argv[i] << ": \n"<<WHITE;
        std::cout << buffer << "\n";
        file.close();
        delete[] buffer;
    }
}