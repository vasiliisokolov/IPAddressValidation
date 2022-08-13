#include <iostream>
#include <stdlib.h>

bool check_format(const std::string&);
std::string get_address_part(const std::string&, int oktetNumber);
bool check_part(const std::string&);

int main()
{
    loop:
    std::string ip;
    int oktetNumber;
    bool valid = true;
    std::cout << "IP Address Validation!\n";
    std::cout << "Enter your IP:\n";
    std::cin >> ip;

    if (check_format(ip))
    {
        for (oktetNumber = 0; oktetNumber <= 3; oktetNumber++)
        {
            if (!check_part(get_address_part(ip, oktetNumber)))
            {
                valid = false;
                break;
            }
        }
    }
    else
    {
        valid = false;
    }
    std::cout << (valid ? "Valid\n": "Invalid\n");
}

bool check_format(const std::string &ip)
{
    if (ip.find("..") != -1)
    {
        return false;
    }
    else if (ip[0] == '.' || ip[ip.length() - 1] == '.')
    {
        return false;
    }
    else
    {
        for (int i = 0; i < ip.length(); i++)
        {
            if (ip[i] < '.' || ip[i] > '9')
            {
                return false;
            }
            
        }
    }
    return true;
}

std::string get_address_part(const std::string &ip, int oktetNumber)
{
    
    std::string part1, part2, part3, part4, temp;
    std::string result;
    
    int number = 0;
    for (int i = 0; i < ip.length(); i++)
    {
        if (ip[i] != '.')
        {
            switch (number)
            {
            case 0:
                part1 += ip[i];
                break;
            case 1:
                part2 += ip[i];
                break;
            case 2:
                part3 += ip[i];
                break;
            case 3:
                part4 += ip[i];
                break;
            }
        }
        else if (ip[i] == '.')
        {
            number++;
            temp.clear();

        }

    }

    switch (oktetNumber)
    {
    case 0:
        result = part1;
        break;
    case 1:
        result = part2;
        break;
    case 2:
        result = part3;
        break;
    case 3:
        result = part4;
        break;
    }
      
    return std::string(result);
}

bool check_part(const std::string &part)
{
    
    if (part.length() > 3)
    {
        return false;
    }
    else
    {
        int number = atoi(part.c_str());
        if (number >= 0 && number <= 225)
        {
            return true;
        }
        else
        { 
            return false;
        }
    }

}
