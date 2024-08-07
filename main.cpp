#include <iostream>
#include <vector>
#include <map>

template <typename T, size_t size>
struct my_allocator {
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;

    my_allocator () noexcept : memory{std::malloc(sizeof(T) * size)}, pos{0} {}
    ~my_allocator() { std::free(memory); }

    template <class U> my_allocator  (const my_allocator <U, size>&) noexcept {}

    T* allocate (std::size_t n) {
        if (pos + n > size)
            throw std::bad_alloc();
        int cur = pos;
        pos += n;
        return static_cast<T*>(memory) + cur;
    }

    void deallocate (T* p, std::size_t n) {}

    template <class Up, class... Args>
    void construct(Up* p, Args&&... args) {
        ::new ((void*)p) Up(std::forward<Args>(args)...);
    }

    void destroy(pointer p) {
        p->~T();
    }

    template<typename U>
    struct rebind
    {
        typedef my_allocator<U,size> other;
    };

private:
    void* memory;
    size_t pos;
};

template <typename T, typename Allocator = std::allocator<T>>
struct my_container {
    my_container() = default;
    ~my_container() = default;
    void push_back(const T& x) {
        if (size == capacity) {
            capacity = capacity * 2 + 1;
            T* newData = alloc.allocate(capacity);
            if (data != nullptr)
                std::copy(data, data + size, newData);
            std::swap(newData, data);
            alloc.deallocate(newData, size);
        }
        alloc.construct(&data[size], x);
        ++size;
    }

    T* begin() {
        return data;
    }

    T* end() {
        return &data[size];
    }

private:
    std::size_t size = 0;
    std::size_t capacity = 0;
    T* data = nullptr;
    Allocator alloc;
};

int factorial(int n, int* ar) {
    if (n >= 1) {
        ar[n] = ar[n-1] * n;
    }
    return ar[n];
}

int main(int argc, char const *argv[])
{
    int fac[10]{1};

    // std::map std::allocator
    std::map<int, int> m1;
    for (int i = 0; i < 10; ++i) {
        m1[i] = factorial(i, fac);
    }

    // std::map my_allocator
    auto m2 = std::map<
        int,
        int,
        std::less<int>,
        my_allocator<
            std::pair<
                const int, int>, 10>>{};

    for (int i = 0; i < 10; ++i) {
        m2[i] = factorial(i, fac);
    }

    for (auto &p : m2) {
        std::cout << p.first << " " << p.second << "\n";
    }

    // my_container std::allocator
    my_container<int> c1;
    for (int i = 0; i < 10; ++i) {
        c1.push_back(i);
    }


    // my_container my_allocator
    my_container<int, my_allocator<int, 30>> c2;
    for (int i = 0; i < 10; ++i) {
        c2.push_back(i);
    }

    for (auto &e : c2) {
        std::cout << e << "\n";
    }
    return 0;
}
