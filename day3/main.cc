#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

int calculate_result(const std::vector<std::set<char>>& items)
{
    int result = 0;
    for (const auto item : items)
    {
        for (const auto ch : item)
        {
            int p = 0;
            if (std::isupper(ch))
            {
                p = (ch + 26 - 'A') + 1;
            }
            else
            {
                p = ch - 'a' + 1;
            }
            result += p;
        }
    }
    return result;
}

int calculate_first_part(const std::vector<std::string> &input)
{
    std::vector<std::set<char>> items;
    for (const auto line : input)
    {
        auto middle = line.size() / 2;
        auto left = line.substr(0, middle);
        auto right = line.substr(middle, line.size());

        items.emplace_back(std::set<char>{});
        auto pos = right.find_first_of(left.c_str());
        if (pos != std::string::npos)
        {
            items.back().insert(right[pos]);
        }
    }

    return calculate_result(items);
}

int calculate_second_part(const std::vector<std::string> &input)
{
    std::vector<std::set<char>> items;
    int iter_count = input.size() / 3;
    for (int i = 0; i < input.size(); i += 3)
    {
        auto first = input[i];
        auto second = input[i+1];
        auto third = input[i+2];

        items.emplace_back(std::set<char>{});

        std::for_each(std::begin(first), std::end(first), [&second, &third, &items](char ch)
                      {
                          if (std::find(std::begin(second), std::end(second), ch) != std::end(second) &&
                              std::find(std::begin(third), std::end(third), ch) != std::end(third))
                          {
                              items.back().insert(ch);
                          }
                      });
    }
    return calculate_result(items);
}

int main(int argc, char **argv)
{
    std::vector<std::string> input;
    for (std::string line; std::getline(std::cin, line);)
    {
        input.emplace_back(std::move(line));
    }

    std::cout << "Part 1: " << calculate_first_part(input) << std::endl;
    std::cout << "Part 2: " << calculate_second_part(input) << std::endl;

    return 0;
}