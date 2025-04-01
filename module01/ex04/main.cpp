#include <iostream>
#include <fstream>
#include <string>

int checkErrors(const std::string &filename, const std::string &s1, const std::string &s2)
{
    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return (1);
    }
    if (s2.empty())
    {
        std::cerr << "Error: s2 cannot be empty." << std::endl;
        return (1);
    }
    if (filename.empty())
    {
        std::cerr << "Error: Filename cannot be empty." << std::endl;
        return (1);
    }
    return (0);
}

std::string stringReplace(const std::string &str, const std::string &s1, const std::string &s2)
{    
    std::string result;
    size_t pos = 0, found;
    while ((found = str.find(s1, pos)) != std::string::npos)
    {
        result.append(str, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(str, pos, str.length() - pos);
    return result;
}

void replaceAndWrite(const std::string &filename, const std::string &s1, const std::string &s2)
{
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: Cannot open input file." << std::endl;
        return;
    }

    std::string outputFile = filename + ".replace";
    std::ofstream outfile(outputFile.c_str());
    if (!outfile)
    {
        std::cerr << "Error: Cannot create output file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        outfile << stringReplace(line, s1, s2) << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Error : Need filename, s1 and s2" << std::endl;
        return (1);
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    if (checkErrors(filename, s1, s2))
        return (1);

    replaceAndWrite(filename, s1, s2);
    
    return (0);
}
