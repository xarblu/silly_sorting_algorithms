#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>

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

    // find min and max value in array in O(n)
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    for (int i : input) {
        if (i < min) {
            min = i;
        }
        if (i > max) {
            max = i;
        }
    }

    if (input.size() == 0) {
        std::cerr << "Input is empty" << std::endl;
        std::exit(-1);
    }

    // allocate an new vector with "max" counters in it
    // should at worst be O(max)
    std::vector<int> sortmap = std::vector<int>();
    sortmap.insert(sortmap.begin(), max-min+1, 0);

    // increase each values counter by 1 for each occurence
    // O(n)
    for (int i : input) {
        sortmap.at(i-min)++;
    }

    // push all non empty vector values in order to output vector O(n)
    std::vector<int> output = std::vector<int>();
    for (int i = 0; i < sortmap.size(); i++) {
        if (sortmap.at(i) == 0) {
            continue;
        }
        output.insert(output.end(), sortmap.at(i), i+min);
    }

    // print
    for (int i : output) {
        std::cout << i << std::endl;
    }
}
