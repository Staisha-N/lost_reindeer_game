#pragma once
#include <iostream>

class canada_graphic {
  public:
    std::size_t capacity {1071};
    char characters[1071]{'~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','#','#','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~',
                    '~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','#','#','#','#','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~',
                    '~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','#','~','#','#','~','#','#','#','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~',
                    '~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','#','#','~','#','#','#','#','#','#','#','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~',
                    '~','~','~','~','~','#','~','~','~','~','~','~','#','#','#','#','~','~','~','~','~','#','#','#','#','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~',
                    '~','~','~','~','#','#','#','#','#','#','#','~','~','~','#','#','#','#','#','~','#','#','#','~','#','#','#','#','#','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~',
                    '~','~','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','#','#','~','#','#','#','#','#','#','#','#','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~',
                    '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','~','#','#','#','#','~','#','~','~','#','~','#','#','#','#','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~',
                    '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','~','~','#','#','#','#','#','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~',
                    '~','~','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','~','~','~','~','#','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~',
                    '~','~','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','~','~','~','~','~','~','#','#','#','#','~','~','#','#','~','~','~','~','~','~','~','~','~','~','~','~',
                    '~','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','~','~','~','~','~','~','~','#','#','#','#','#','#','#','#','#','#','#','#','#','~','~','~','~','~','~','~',
                    '~','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','~','~','~','~','~','~','~','~','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','#','#','#',
                    '~','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','~','~','~','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','~','#','#','#','#',
                    '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','~','#','#','#','#','#','#','#','#','#','#','~','#','#','~','~','~','~','~','~',
                    '~','~','~','~','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','#','#','#','#','#','#','#','#','#','#','#','#','~','#','#','#','~','~','~',
                    '~','~','~','~','~','~','~','~','~','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','~','#','#','#','#','#','~','~','~','~',
                    '~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','#','#','#','#','#','#','#','#','#','#','#','~','~','~','~','#','#','#','~','~','~','~','~',
                    '~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','#','#','#','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~',
                    '~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','#','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~',
                    '~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','#','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~','~'};
};

class Colors {
  public:
    const std::string reset = "\033[0m";
    const std::string black = "\033[30m";
    const std::string red = "\033[31m";
    const std::string green = "\033[32m";
    const std::string yellow = "\033[33m";
    const std::string blue = "\033[34m";
    const std::string magenta = "\033[35m";
    const std::string cyan = "\033[36m";
    const std::string white = "\033[37m";
};