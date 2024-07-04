#include <iostream>
#include <fstream>
#include <string>
#include <regex>

/*bool is_date_valid(const std::string& date) {
    std::regex date_regex(R"((\d{4})-(\d{2})-(\d{2}))");
    return std::regex_match(date, date_regex);
}*/

bool is_fraction(const std::string& str) {
    std::regex fraction_regex(R"((\d+)/(\d+))");
    return std::regex_match(str, fraction_regex);
}

double parse_fraction(const std::string& str) {
    std::regex fraction_regex(R"((\d+)/(\d+))");
    std::smatch match;
    if (std::regex_match(str, match, fraction_regex)) {
        double numerator = std::stod(match[1].str());
        double denominator = std::stod(match[2].str());
        return numerator / denominator;
    }
    return 0.0;
}

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::regex date_regex(R"((\d{4}-\d{2}-\d{2}))");
    std::regex number_regex(R"((\d+/\d+|\d+(?:\.\d+)?(?:[eE][+-]?\d+)?))");

    std::smatch match;
    std::string::const_iterator search_start(content.cbegin());

    if (!std::regex_search(search_start, content.cend(), match, date_regex)) {
        std::cerr << "No date found in the file" << std::endl;
        return 1;
    }

    std::string date = match[0];
    /*if (!is_date_valid(date)) {
        std::cerr << "Invalid date format" << std::endl;
        return 1;
    }*/

    std::string pre_date_content(content.cbegin(), match[0].first);
    if (std::regex_search(pre_date_content, match, number_regex)) {
        std::cerr << "File is incorrect: numbers found before the date" << std::endl;
        return 1;
    }

    search_start = match.suffix().first;

    // Найти числа после даты
    double sum_integers = 0;
    double sum_floats = 0;

    while (std::regex_search(search_start, content.cend(), match, number_regex)) {
        std::string number_str = match[0];
        if (is_fraction(number_str)) {
            sum_floats += parse_fraction(number_str);
        }
        else if (number_str.find('.') != std::string::npos || number_str.find('e') != std::string::npos || number_str.find('E') != std::string::npos) {
            sum_floats += std::stod(number_str);
        }
        else {
            sum_integers += std::stoi(number_str);
        }
        search_start = match.suffix().first;
    }

    std::cout << "Date: " << date << std::endl;
    std::cout << "Sum of integers: " << sum_integers << std::endl;
    std::cout << "Sum of floats: " << sum_floats << std::endl;

    return 0;
}
