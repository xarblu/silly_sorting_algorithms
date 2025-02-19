#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>

int main(int argc, char** argv) {
    std::vector<int> input = std::vector<int>();

    for (std::string line; getline(std::cin, line);) {
        try {
            input.push_back(std::stoi(line));
        } catch (const std::invalid_argument &ex) {
            std::cerr << "Couldn't parse int from: " << line << std::endl;
            std::exit(-1);
        }
    }

    // find max value in array in O(n)
    int max = -1;
    for (int i : input) {
        if (i > max) {
            max = i;
        }
    }

    if (input.size() == 0) {
        std::cerr << "Input is empty" << std::endl;
        std::exit(-1);
    }

    // allocate an new vector with "max" vectors in it
    // should at worst be O(max)
    std::vector<std::vector<int>> temp = std::vector<std::vector<int>>();
    temp.insert(temp.begin(), max, std::vector<int>());

    // insert each value in its slot O(n)
    for (int i : input) {
        temp.at(i-1).push_back(i);
    }

    // push all non empty vector values in order to output vector O(n)
    std::vector<int> output = std::vector<int>();
    for (std::vector<int> vec : temp) {
        for (int i : vec) {
            output.push_back(i);
        }
    }

    // print
    for (int i : output) {
        std::cout << i << std::endl;
    }
}
