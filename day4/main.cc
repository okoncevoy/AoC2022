#include <iostream>
#include <string>
#include <utility>

std::pair<std::string, std::string> split(const std::string& str, const std::string& delimeter)
{
    auto pos = str.find(delimeter);
    std::pair<std::string, std::string> result{};
    if (pos != std::string::npos)
    {
        result.first = str.substr(0, pos);
        result.second = str.substr(pos+1, str.length());
    }
    return result;
}

int main()
{
    int part_one_count = 0;
    int part_two_count = 0;

    for (std::string line; std::getline(std::cin, line); )
    {
        auto sets = split(line, ",");
        auto left = split(sets.first, "-");
        auto right = split(sets.second, "-");

        int first_begin = std::atoi(left.first.c_str());
        int first_end = std::atoi(left.second.c_str());
        int second_begin = std::atoi(right.first.c_str());
        int second_end = std::atoi(right.second.c_str());

        if (first_begin >= second_begin && first_end <= second_end) part_one_count++;
        else if (second_begin >= first_begin && second_end <= first_end) part_one_count++;

        if (first_end >= second_begin && first_begin <= second_end) part_two_count++;
        else if (first_end <= second_begin && first_begin >= second_begin) part_two_count++;
    }

    std::cout << "Part 1: " << part_one_count << std::endl;
    std::cout << "Part 2: " << part_two_count << std::endl;
    return 0;
}