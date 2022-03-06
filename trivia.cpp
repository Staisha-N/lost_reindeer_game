#include <iostream>
#include <cassert>
#include "trivia.hpp"

void HelpHint(int province_num) {
    if (province_num == 1) {
        std::cout << "Yukon hint" << std::endl;
    } else if (province_num == 2) {
        std::cout << "NWT hint" << std::endl;
    } else if (province_num == 3) {
        std::cout << "Nunavut hint" << std::endl;
    } else if (province_num == 4) {
        std::cout << "BC hint" << std::endl;
    } else if (province_num == 5) {
        std::cout << "Alberta hint" << std::endl;
    } else if (province_num == 6) {
        std::cout << "Saskatchewan hint" << std::endl;
    } else if (province_num == 7) {
        std::cout << "Manitoba hint" << std::endl;
    } else if (province_num == 8) {
        std::cout << "Ontario hint" << std::endl;
    } else if (province_num == 9) {
        std::cout << "Quebec hint" << std::endl;
    } else if (province_num == 10) {
        std::cout << "New Brunswick hint" << std::endl;
    } else if (province_num == 11) {
        std::cout << "Nova Scotia hint" << std::endl;
    } else if (province_num == 12) {
        std::cout << "PEI hint" << std::endl;
    } else {
        std::cout << "Newfoundland and Labrador hint" << std::endl;
    }
    
}
