#include <iostream>
#include <string>
#include <set>

static constexpr uint8_t marker_window = 4;
static constexpr uint8_t message_window = 14;

uint64_t get_resulting_position(std::string_view str, uint8_t window)
{
    uint64_t position = 0;
    auto left{std::begin(str)};
    auto right{left + window};

    for (; right != std::end(str); right++)
    {
        std::set<char> chars{left, right};
        if (chars.size() == window)
        {
            position = std::distance(std::begin(str), right);
            break;
        }
        ++left;
    }
    return position;
}

int main()
{
    for (std::string line; std::getline(std::cin, line);)
    {
        std::cout << "Part 1: " << get_resulting_position(line, marker_window) << std::endl;
        std::cout << "Part 2: " << get_resulting_position(line, message_window) << std::endl;
    }
    return 0;
}