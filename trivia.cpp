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

void GetCarrots (int province_num, int &carrots) {

    //create a linked list for trivia questions?
    int num1 {0};
    int num2 {0};
    int num3 {0};

    if (province_num == 1) {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }

    } else if (province_num == 2) {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }
    } else if (province_num == 3) {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }
    } else if (province_num == 4) {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }
    } else if (province_num == 5) {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }
    } else if (province_num == 6) {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }
    } else if (province_num == 7) {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }
    } else if (province_num == 8) {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }
    } else if (province_num == 9) {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }
    } else if (province_num == 10) {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }
    } else if (province_num == 11) {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }
    } else if (province_num == 12) {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }
    } else {
        std::cout << "How many provinces are in Canada?";
        std::cin >> num1;
        if(num1 == 10) {
            carrots += 1;
        }
        std::cout << "How many territories are in Canada?";
        std::cin >> num2;
        if(num2 == 3) {
            carrots += 1;
        }
        std::cout << "How many maple leafs are on the Canadian flag?";
        std::cin >> num3;
        if(num3 == 1) {
            carrots += 1;
        }
    }
}
