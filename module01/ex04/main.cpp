#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return (1);
    }

    std::ifstream infile(argv[1]);
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ofstream replace("MIAOU.txt");
    if (!replace)
    {
        std::cerr << "Error: Create failed" << std::endl;
        return (1);
    }
    std::string line;
    while (std::getline(infile, line))
    {
        line.replace(line.find(s1), s1.length(), s2);
        replace << line << std::endl;
    }
    infile.close();
    replace.close();

    return (0);
}