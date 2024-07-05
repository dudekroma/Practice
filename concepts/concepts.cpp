#include <concepts>
#include <iostream>
#include <vector>

template <typename T>
concept Integral = std::integral<T>;

template <typename T>
concept FloatingPoint = std::floating_point<T>;

template <typename T>
class MyClass;

template <Integral T>
class MyClass<T> {
public:
    long long max = 0;

    MyClass() = default;
    ~MyClass() {}
    MyClass(T a) {
        max = a;
    }

    template <Integral A1>
    auto maximum(const std::vector<A1>& a) {
        A1 result = a[0];
        for (size_t i = 1; i < a.size(); ++i) {
            if (a[i] > result)
                result = a[i];
        }

        max = result;
        return max;
    }
};

template <FloatingPoint T>
class MyClass<T> {
public:
    double max = 0;

    MyClass() = default;
    ~MyClass() {}
    MyClass(T a) {
        max = a;
    }

    template <FloatingPoint A2>
    auto maximum(const std::vector<A2>& a) {
        A2 result = a[0];
        for (size_t i = 1; i < a.size(); ++i) {
            if (a[i] > result)
                result = a[i];
        }

        max = result;
        return max;
    }
};

int main() {
    MyClass<int> item1(0);
    std::cout << item1.max << '\n';
    std::vector<int> a1({ 1, 2, 3, 7, 4 });
    std::cout << item1.maximum(a1) << '\n';
    std::cout << '\n';

    MyClass<double> item2(0.0);
    std::cout << item2.max << '\n';
    std::vector<double> a2({ 1.2, 5.5, 3.1, 4.9 });
    std::cout << item2.maximum(a2) << '\n';

    return 0;
}
