#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>

struct cmd
{
    cmd(uint32_t c, size_t f, size_t t) : cnt{c}, from{f}, to{t} {}
    uint32_t cnt;
    size_t from;
    size_t to;
};

using cmds_t = std::vector<cmd>;
using data_t = std::vector<std::deque<char>>;

void crate9000(const cmds_t &cmds, data_t &data)
{
    for (auto &cmd : cmds)
    {
        for (uint32_t i = 0; i < cmd.cnt; ++i)
        {
            data[cmd.to].emplace_back(data[cmd.from].back());
            data[cmd.from].pop_back();
        }
    }

    for (const auto &d : data)
    {
        std::cout << d.back();
    }
    std::cout << std::endl;
}

void crate9001(const cmds_t &cmds, data_t &data)
{
    for (const auto &cmd : cmds)
    {
        if (cmd.cnt == 1)
        {
            data[cmd.to].emplace_back(data[cmd.from].back());
            data[cmd.from].pop_back();
        }
        else
        {
            auto begin{std::end(data[cmd.from]) - cmd.cnt};
            auto end{std::end(data[cmd.from])};

            data[cmd.to].insert(std::end(data[cmd.to]), begin, end);
            data[cmd.from].erase(begin, end);
        }
    }

    for (const auto &d : data)
    {
        std::cout << d.back();
    }
    std::cout << std::endl;
}

std::vector<std::string> split_commands(std::string&& line)
{
    std::stringstream ss(line);
    std::vector<std::string> splitted;
    std::string word;
    while (std::getline(ss, word, ' '))
    {
        splitted.emplace_back(word);
    }
    return splitted;
}

int main()
{
    data_t data;
    cmds_t cmds;

    for (std::string line; std::getline(std::cin, line);)
    {
        for (size_t i = 0; i < line.size(); ++i)
        {
            if (std::isupper(line[i]))
            {
                auto target{(i - 1) / 4};
                if (data.size() <= target)
                    data.resize(target + 1);
                data[target].emplace_front(line[i]);
            }
            else if (i == 0 && line[i] == 'm')
            {
                auto splitted = split_commands(std::move(line));
                cmds.emplace_back(std::stoi(splitted[1]), std::stoi(splitted[3]) - 1, std::stoi(splitted[5]) - 1);
                break;
            }
        }
    }

    auto data2{data};
    crate9000(cmds, data);
    crate9001(cmds, data2);

    return 0;
}