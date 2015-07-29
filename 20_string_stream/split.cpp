#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) 
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) 
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main()
{
    char buffer[30]="h1,h15,40000000,5000,500";    
    std::string demand(buffer);
    std::vector<std::string> str_elemens;

    str_elemens = split(demand, ',');

    std::vector<std::string>::iterator it;

    for (it = str_elemens.begin(); it != str_elemens.end(); it++) 
    {
        std::cout << *it << std::endl;
    }

    std::cout << str_elemens[0][1] << "size: " << str_elemens.size() << endl;
         
    return 0;
}
