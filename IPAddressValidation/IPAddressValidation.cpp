#include <iostream>

bool check_format(std::string ip);
std::string get_address_part(std::string ip, int oktetNumber);

int main()
{
    std::string ip;
    bool valid = true;
    std::cout << "IP Address Validation!\n";
    std::cout << "Enter your IP:\n";
    std::cin >> ip;

    valid = check_format(ip);
    std::cout << (valid ? "Valid\n": "Invalid\n");
}

bool check_format(std::string ip)
{
    for (int i = 0; i > ip.length(); i++)
    {
        if (ip[i] == '.' || ip[i] > '0' && ip[i] < '9')
        {
            return true;
        }
    }
    return false;
}

std::string get_address_part(std::string ip, int oktetNumber)
{
    return std::string();
}
