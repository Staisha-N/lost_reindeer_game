#include <iostream>
#include "pick_province&city.hpp"

int province_hiding_spot() {
  
    std::size_t reindeer_province {0};

    while (reindeer_province == 0) { 
        reindeer_province = rand() % 14;  
    }
    
    return reindeer_province;
}

std::string city_hiding_spot(int province) {
  
    std::size_t i {0};
    std::string r {};

    while (i == 0) {
        i = rand() % 4;
    }

    if (province == 1) {
        
        if ( i == 1) {
            r = "Whitehorse";
        } else if (i == 2) {
            r = "Tagish";
        } else {
            r = "Teslin";
        }

    } else if (province == 2) {
        if ( i == 1) {
            r = "Wrigley";
        } else if (i == 2) {
            r = "Yellowknife";
        } else {
            r = "Whati";
        }
    } else if (province == 3) {
        if ( i == 1) {
            r = "Igloolik";
        } else if (i == 2) {
            r = "Iqaluit";
        } else {
            r = "Qikiqtarjuaq";
        }
    } else if (province == 4) {
        if ( i == 1) {
            r = "Vancouver";
        } else if (i == 2) {
            r = "Victoria";
        } else {
            r = "Kamloops";
        }
    } else if (province == 5) {
        if ( i == 1) {
            r = "Edmonton";
        } else if (i == 2) {
            r = "Calgary";
        } else {
            r = "Banff";
        }
    } else if (province == 6) {
        if ( i == 1) {
            r = "Saskatoon";
        } else if (i == 2) {
            r = "Regina";
        } else {
            r = "Moose-Jaw";
        }
    } else if (province == 7) {
        if ( i == 1) {
            r = "Winnipeg";
        } else if (i == 2) {
            r = "Churchill";
        } else {
            r = "Dauphin";
        }
    } else if (province == 8) {
        if ( i == 1) {
            r = "Ottawa";
        } else if (i == 2) {
            r = "Toronto";
        } else {
            r = "Waterloo";
        }
    } else if (province == 9) {
        if ( i == 1) {
            r = "Montreal";
        } else if (i == 2) {
            r = "Quebec City";
        } else {
            r = "Saguenay";
        }
    } else if (province == 10) {
        if ( i == 1) {
            r = "Fredericton";
        } else if (i == 2) {
            r = "Rogersville";
        } else {
            r = "Moncton";
        }
    } else if (province == 11) {
        if ( i == 1) {
            r = "Halifax";
        } else if (i == 2) {
            r = "Digby";
        } else {
            r = "Lower-Sackville";
        }
    } else if (province == 12) {
        if ( i == 1) {
            r = "Charlottetown";
        } else if (i == 2) {
            r = "Wellington";
        } else {
            r = "O'Leary";
        }
    } else if (province == 13) {
        if ( i == 1) {
            r = "St.John's";
        } else if (i == 2) {
            r = "Happy-Valley-Goose-Bay";
        } else {
            r = "Holyrood";
        }
    }

    
    return r;
}

std::string WhereAmI_province(char * board, std::size_t &xdim, std::size_t &ydim) {
    std::size_t location {xdim + ydim*51};
    std::string province {};

    if (board[location] == 1) {
        province = "Yukon";
    } else if (board[location] == 2) {
        province = "Northwest Territories";
    } else if (board[location] == 3) {
        province = "Nunavut";
    } else if (board[location] == 4) {
        province = "British Columbia";
    } else if (board[location] == 5) {
        province = "Alberta";
    } else if (board[location] == 6) {
        province = "Saskatchewan";
    } else if (board[location] == 7) {
        province = "Manitoba";
    } else if (board[location] == 8) {
        province = "Ontario";
    } else if (board[location] == 9) {
        province = "Quebec";
    } else if (board[location] == 10) {
        province = "New Brunswick";
    } else if (board[location] == 11) {
        province = "Nova Scotia";
    } else if (board[location] == 12) {
        province = "Prince Edward Island";
    } else if (board[location] == 13) {
        province = "Newfoundland and Labrador";
    } else if (board[location] == 4) {
        province = "British Columbia";
    } else if (board[location] == 14) {
        province = "a province you have already inspected";
    } else {
       province = "the ocean"; 
    }

    return province;
}