#include <iostream>
#include <string>

int main()
{
    uint64_t score_part_one = 0;
    uint64_t score_part_two = 0;
    for(std::string line; std::getline(std::cin, line); )
    {
        char op = line[0], me = line[2];
        if (me == 'X')
        {
            score_part_one += 1;
            if (op == 'C') score_part_one += 6;
            else if (op == 'A') score_part_one += 3;

            if (op == 'A') score_part_two += 3;
            else if (op == 'B') score_part_two +=1;
            else if (op == 'C') score_part_two += 2;
        }
        else if (me == 'Y')
        {
            score_part_one += 2;
            if (op == 'A') score_part_one += 6;
            else if (op == 'B') score_part_one += 3;

            score_part_two += 3;
            if (op == 'A') score_part_two += 1;
            else if (op == 'B') score_part_two += 2;
            else if (op == 'C') score_part_two += 3;
        }
        else if (me == 'Z')
        {
            score_part_one += 3;
            if (op == 'B') score_part_one += 6;
            else if (op == 'C') score_part_one += 3;

            score_part_two += 6;
            if (op == 'A') score_part_two += 2;
            else if (op == 'B') score_part_two += 3;
            else if (op == 'C') score_part_two += 1;
        }
    }

    std::cout << "Part 1: " << score_part_one << std::endl;
    std::cout << "Part 2: " << score_part_two << std::endl;
    return 0;
}