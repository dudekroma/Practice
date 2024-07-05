#include <iostream>
#include <format>
#include <vector>

int main() {
    std::string name = "Alice";
    int age = 30;
    std::string formatted_string = std::format("Name: {}, Age: {}", name, age);
    std::cout << formatted_string << std::endl;
    std::cout << std::endl;

    bool condition = true;
    std::cout << std::format("It is {}", condition ? "good" : "bad") << std::endl;
    std::cout << std::endl;

    std::cout << std::format("{:<9}|{:<10}|","Left:", "text") << std::endl;
    std::cout << std::format("{:<9}|{:>10}|","Right:", "text") << std::endl;
    std::cout << std::format("{:<9}|{:^10}|","Center:", "text") << std::endl;
    std::cout << std::format("{:<9}|{:*^10}|","*:", "text") << std::endl;
    std::cout << std::endl;

    int number = 245;
    std::cout << std::format("_16_: {:x}", number) << std::endl;
    std::cout << std::endl;

    std::vector<int> values = { 1, 2, 3, 4, 5 };
    std::cout << std::format("Values: [{}]", std::format("{}, {}, {}, {}, {}", values[0], values[1], values[2], values[3], values[4])) << std::endl;

    return 0;
}
