#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <array>

#include "utils.h"

struct IP {
    explicit IP(const std::vector<std::string>& str)  {
        ip_parts[0] = std::atoi(str[0].data());
        ip_parts[1] = std::atoi(str[1].data());
        ip_parts[2] = std::atoi(str[2].data());
        ip_parts[3] = std::atoi(str[3].data());
    }
    std::array<uint8_t, 4> ip_parts;

    std::string toString() const;
};

std::string IP::toString() const {
    return std::to_string(ip_parts[0]) + "." + std::to_string(ip_parts[1]) + "." + std::to_string(ip_parts[2]) + "." + std::to_string(ip_parts[3]);
}

bool operator<(const IP& lhs, const IP& rhs) {
    return lhs.ip_parts < rhs.ip_parts;
}

int main(int argc, char const *argv[])
{
    try
    {
        std::multiset<IP> ip_set;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = Utils::split(line, '\t');
            ip_set.insert(IP(Utils::split(v.at(0), '.')));
        }

        // reverse lexicographically sort
        for (auto ip = ip_set.rbegin(); ip != ip_set.rend(); ++ip) {
            std::cout << (*ip).toString() << "\n";
        }

        // filter by first byte and output
        auto it = std::find_if(ip_set.begin(), ip_set.end(), [](const IP& ip){ return ip.ip_parts[0] != 1; });
        std::multiset<IP> filter1;
        for (auto ip = ip_set.begin(); ip != it; ++ip) {
            filter1.insert(*ip);
        }
        for (auto ip = filter1.rbegin(); ip != filter1.rend(); ++ip) {
            std::cout << (*ip).toString() << "\n";
        }


        // filter by first and second bytes and output
        auto first = std::find_if(ip_set.begin(), ip_set.end(), [](const IP& ip){ return ip.ip_parts[0] == 46 && ip.ip_parts[1] == 70; });
        auto last = std::find_if(ip_set.begin(), ip_set.end(), [](const IP& ip){ return ip.ip_parts[0] > 46 || (ip.ip_parts[0] == 46 && ip.ip_parts[1] > 70) ; });
        std::multiset<IP> filter2;
        for (auto ip = first; ip != last; ++ip) {
            filter2.insert(*ip);
        }
        for (auto ip = filter2.rbegin(); ip != filter2.rend(); ++ip) {
            std::cout << (*ip).toString() << "\n";
        }

        // filter by any byte and output
        std::for_each(ip_set.rbegin(), ip_set.rend(), [](const IP& ip){
            if (ip.ip_parts[0] == 46 || ip.ip_parts[1] == 46 || ip.ip_parts[2] == 46 || ip.ip_parts[3] == 46) {
                std::cout << ip.toString() << "\n";
            }
        });
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
