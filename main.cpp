#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

#include "utils.h"

struct IP {
    explicit IP(const std::vector<std::string>& str) : ip1{static_cast<uint8_t>(std::atoi(str[0].data()))},
                                                       ip2{static_cast<uint8_t>(std::atoi(str[1].data()))},
                                                       ip3{static_cast<uint8_t>(std::atoi(str[2].data()))},
                                                       ip4{static_cast<uint8_t>(std::atoi(str[3].data()))} {

    }
    uint8_t ip1;
    uint8_t ip2;
    uint8_t ip3;
    uint8_t ip4;

    std::string toString() const;
};

std::string IP::toString() const {
    return std::to_string(ip1) + "." + std::to_string(ip2) + "." + std::to_string(ip3) + "." + std::to_string(ip4);
}

bool operator<(const IP& lhs, const IP& rhs) {
    if (lhs.ip1 < rhs.ip1) return true;
    else if (lhs.ip1 == rhs.ip1 && lhs.ip2 < rhs.ip2) return true;
    else if (lhs.ip1 == rhs.ip1 && lhs.ip2 == rhs.ip2 && lhs.ip3 < rhs.ip3) return true;
    else if (lhs.ip1 == rhs.ip1 && lhs.ip2 == rhs.ip2 && lhs.ip3 == rhs.ip3 && lhs.ip4 < rhs.ip4) return true;
    return false;
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
        auto it = std::find_if(ip_set.begin(), ip_set.end(), [](const IP& ip){ return ip.ip1 != 1; });
        std::multiset<IP> filter1;
        for (auto ip = ip_set.begin(); ip != it; ++ip) {
            filter1.insert(*ip);
        }
        for (auto ip = filter1.rbegin(); ip != filter1.rend(); ++ip) {
            std::cout << (*ip).toString() << "\n";
        }


        // filter by first and second bytes and output
        auto first = std::find_if(ip_set.begin(), ip_set.end(), [](const IP& ip){ return ip.ip1 == 46 && ip.ip2 == 70; });
        auto last = std::find_if(ip_set.begin(), ip_set.end(), [](const IP& ip){ return ip.ip1 > 46 || (ip.ip1 == 46 && ip.ip2 > 70) ; });
        std::multiset<IP> filter2;
        for (auto ip = first; ip != last; ++ip) {
            filter2.insert(*ip);
        }
        for (auto ip = filter2.rbegin(); ip != filter2.rend(); ++ip) {
            std::cout << (*ip).toString() << "\n";
        }

        // filter by any byte and output
        std::for_each(ip_set.rbegin(), ip_set.rend(), [](const IP& ip){
            if (ip.ip1 == 46 || ip.ip2 == 46 || ip.ip3 == 46 || ip.ip4 == 46) {
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
