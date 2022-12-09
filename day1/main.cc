#include <string>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
  std::vector<uint64_t> elfs{};
  uint64_t val = 0;

  for (std::string line; std::getline(std::cin, line);)
  {
    if (!line.empty())
    {
      val += std::atoi(line.c_str());
    }
    else
    {
      elfs.emplace_back(val);
      val = 0;
    }
  }

  std::sort(std::begin(elfs), std::end(elfs), std::greater{});
  uint64_t total = std::accumulate(std::begin(elfs), std::begin(elfs)+3, 0);
  std::cout << "Part 1: " << *elfs.begin() << std::endl;
  std::cout << "Part 2: " << total << std::endl;

  return 0;
}
