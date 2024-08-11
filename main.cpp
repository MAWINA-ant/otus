#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

template<typename ...>
using void_t=void;

/**
 * \brief Metafunction is_container
 *      Needed to determine whether a type is a container
 */
template<typename T, typename U = void>
struct is_container : std::false_type {};

template<>
struct is_container<std::string> : std::false_type {};

template<typename T>
struct is_container<T, void_t<typename T::iterator>> : std::true_type {};

/**
 * \brief Metafunction is_container
 *      Needed to determine whether a type is a tuple
 */
template <typename T>
struct is_tuple : std::false_type {};

template <typename ...Ts>
struct is_tuple<std::tuple<Ts...>> : std::true_type{};

/**
 * \brief Metafunction printTuple
 *      Needed for print tuple
 */
template <size_t I = 0, typename... Ts>
typename std::enable_if_t<I == sizeof...(Ts)>
printTuple(std::tuple<Ts...> tup) {
    return;
}

template <size_t I = 0, typename... Ts>
typename std::enable_if_t<I < sizeof...(Ts)>
printTuple(std::tuple<Ts...> tup) {
    std::cout << std::get<I>(tup);
    if (I != (sizeof... (Ts) - 1)) {
        std::cout << ".";
    }
    return printTuple<I+1>(tup);
}

/**
 * \brief Print ip from integral type
 *
 * \tparam T - some type
 * \param [in] val Object for convert to ip
 * \return void if SFINAE is enable this version
 *
 */
template <typename T>
typename std::enable_if_t<std::is_integral<T>::value>
print_ip(const T& val) {
    auto tmp = val;
    size_t size = sizeof(T);
    std::vector<int> v;
    v.reserve(sizeof(T));
    for (size_t i = 0; i < size; ++i) {
        v.push_back(tmp & 0xFF);
        tmp = tmp >> 8;
    }
    std::cout << v.at(size-1);
    for (int i = size - 2; i >= 0; --i) {
        std::cout << ".";
        std::cout << v.at(i);
    }
    std::cout << "\n";
}

/**
 * \brief Print ip from string
 *
 * \tparam T - some type
 * \param [in] val Object for convert to ip
 * \return void if SFINAE is enable this version
 *
 */
template <typename T>
typename std::enable_if_t<std::is_same<T, std::string>::value>
print_ip(const T& val) {
    std::cout << val << "\n";
}

/**
 * \brief Print ip from container vector or list
 *
 * \tparam T - some type
 * \param [in] val Object for convert to ip
 * \return void if SFINAE is enable this version
 *
 */
template <typename T>
typename std::enable_if_t<is_container<T>::value>
print_ip(const T& val) {
    auto it = val.begin();
    std::cout << *it++;
    for (; it != val.end(); ++it) {
        std::cout << "." << *it;
    }
    std::cout << "\n";
}

/**
 * \brief Print ip from tuple
 * \tparam T - some type
 * \param [in] val Object for convert to ip
 * \return void if SFINAE is enable this version*
 */
template <typename T>
typename std::enable_if_t<is_tuple<T>::value>
print_ip(const T& val) {
    printTuple(val);
    std::cout << "\n";
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
