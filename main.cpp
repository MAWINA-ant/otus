#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

template<typename ...>
using void_t=void;

template<typename T, typename U = void>
struct is_container : std::false_type {
};

template<typename T>
struct is_container<T, void_t<typename T::iterator>> : std::true_type {

};

template <typename T>
struct is_tuple : std::false_type {

};

template <typename ...Ts>
struct is_tuple<std::tuple<Ts...>> : std::true_type{

};

template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type
print_ip(const T& val) {

}

template <typename T>
typename std::enable_if<std::is_polymorphic<T>::value>::type
print_ip(const T& val) {

}

template <typename T>
typename std::enable_if<is_container<T>::value>::type
print_ip(const T& val) {

}


template <typename T>
typename std::enable_if<is_tuple<T>::value>::type
print_ip(const T& val) {

}


int main() {   
    print_ip ( int8_t{-1} ); // 255
    print_ip ( int16_t{0} ); // 0.0
    print_ip ( int32_t{2130706433} ); // 127.0.0.1
    print_ip ( int64_t{8875824491850138409} );// 123.45.67.89.101.112.131.41
    print_ip ( std::string{"Hello, World!"} ); // Hello, World!
    print_ip ( std::vector<int>{100, 200, 300, 400} ); // 100.200.300.400
    print_ip ( std::list<short>{400, 300, 200, 100} ); // 400.300.200.100
    print_ip ( std::make_tuple(123, 456, 789, 0) ); // 123.456.789.0

    return 0;
}
