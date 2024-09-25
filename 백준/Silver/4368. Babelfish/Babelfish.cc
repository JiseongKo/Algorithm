#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Optimize I/O operations
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_map<std::string, std::string> dictionary;
    std::string line;

    // Read dictionary entries until a blank line is encountered
    while (std::getline(std::cin, line)) {
        if (line.empty())
            break;

        size_t space_pos = line.find(' ');
        if (space_pos != std::string::npos) {
            std::string english = line.substr(0, space_pos);
            std::string foreign = line.substr(space_pos + 1);
            dictionary[foreign] = english;
        }
    }

    // Read the message words and translate
    while (std::getline(std::cin, line)) {
        if (dictionary.find(line) != dictionary.end()) {
            std::cout << dictionary[line] << '\n';
        } else {
            std::cout << "eh\n";
        }
    }

    return 0;
}
