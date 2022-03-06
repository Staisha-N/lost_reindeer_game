#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h> 
#include <limits>
#include <cassert>

#include "linked_list.hpp"
#include "linked_list.cpp"
#include "graphics.hpp"
#include "graphics.cpp"
#include "trivia.hpp"
#include "trivia.cpp"

int main();
bool game();
void print_canada_start();
void print_canada_with_player(char * board, std::size_t &xdim, std::size_t &ydim);
int province_hiding_spot();
std::string city_hiding_spot(int province); 
void startGame(char * & board);
void cleanBoard(char * board);
char getAction();
char getAction_noInspect();
void mark_province (char * board, int index, std::size_t &xdim, std::size_t &ydim); //maybe use & before board?
void reposition (char * board, std::size_t &xdim, std::size_t &ydim, char action, int province_num, std::string city_name);
void actionInspect(char * board, std::size_t &xdim, std::size_t &ydim, int province_num, std::string city_name);
std::string WhereAmI_province(char * board, std::size_t &xdim, std::size_t &ydim);
void GetCarrots (int province_num, int &carrots);


//global variables
int hint_countdown {3};
bool inspect_lock {false};
bool game_won {false};

int main() {
    srand(time(NULL));

    game();
    return 0;
} 

bool game() {
    bool inspect_lock = false;
    Colors colors;
    canada_graphic can;
    
    char * gameBoard {NULL};
    std::size_t xdim {};
    std::size_t ydim {};
    int province_index = province_hiding_spot(); // random province (1-13) 
    std::string city_name = city_hiding_spot(province_index); // random city (1-3)

    std::cout << province_index << std::endl;
    std::cout << city_name << std::endl;

    startGame(gameBoard);

    std::cout << "Oh no! One of Santa's reindeer has escaped." << std::endl
    << "He is hiding somewhere in Canada. Your mission is to find him." << std::endl
    << "Do you accept this mission? Yes [Y] or No [N]" << std::endl;


    std::string accept_mission {};
    bool key {false};
    while (key == false) {
        std::cin >> accept_mission;

        if ((accept_mission == "Y") || (accept_mission == "y")) {
            key = true;
        } else if ((accept_mission == "N") || (accept_mission == "n")) {
            return false;
        } else {
            std::cout << "Please enter a valid response (Y or N)" << std::endl;
        } 
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Here is your map of Canada: " << std::endl;

    print_canada_start();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Choose the coordinates of the location where you would like to begin your search." << std::endl;
    reposition(gameBoard, xdim, ydim, 'Z', province_index, city_name);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "This is the location you chose on the map: " << std::endl;

    print_canada_with_player(gameBoard, xdim, ydim);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    while (inspect_lock == false) {
        char players_action = getAction();

        
        reposition(gameBoard, xdim, ydim, players_action, province_index, city_name);
        if (game_won == true) {
            return false;
        }
        print_canada_with_player(gameBoard, xdim, ydim);
        std::string province = WhereAmI_province(gameBoard, xdim, ydim);
        std::cout << "You are currently in " << province << ". What would you like do do now?" << std::endl << std::endl;
        

    }

    return false;
}


void startGame(char * & board){
  cleanBoard(board);
  board = createBoard();
}

void cleanBoard(char * board) {
    delete[] board;
    board = nullptr;
}



void print_canada_start() {
    Colors colors;
    canada_graphic can;

    for (std::size_t i {0}; i < can.capacity; i++) {
        
        if ((i != 0) && (i%51 == 0)) {
            std::cout << std::endl;
        }

        
        if (can.characters[i] == '#') {
            std::cout << colors.green << can.characters[i]; 
        } else {
            std::cout << colors.blue << can.characters[i];
        }

    }

}

void reposition(char * board, std::size_t &xdim, std::size_t &ydim, char action, int province_num, std::string city_name) {


    if (action == 'Z') {
        //Player picks their initial position

        std::cout << "Enter X-coordinate (0-50): ";
    
        bool valid_x {false};
        while (valid_x == false) {
            std::cin >> xdim; 
            if ((xdim >=0) && (xdim <= 50)){
                valid_x = true;
            } else {
            std::cout << "Please enter a value between 0 and 50: ";
            }
        }

        std::cout << "Enter Y-coordinate (0-20): ";
        bool valid_y {false};
        while (valid_y == false) {
            std::cin >> ydim; 
            if ((ydim >=0) && (ydim <= 50)){
                valid_y = true;
            } else {
            std::cout << "Please enter a value between 0 and 20: ";
            }
        }  
    } else {
        //Player moves to a different position
        
        if ((action == 'I') || (action == 'i'))  // Inspect
        {
            if (board[xdim + ydim*51] == 0) {
                std::cout << "You are in the ocean. Reindeers are not sea creatures, dummy. Move to a province to inspect." << std::endl;
                char new_action = getAction_noInspect();
                reposition(board, xdim, ydim, new_action, province_num, city_name);
            } else if (board[xdim + ydim*51] == 14) {
                std::cout << "You have already checked this province. Move to another one to inspect." << std::endl;
                char new_action = getAction_noInspect();
                reposition(board, xdim, ydim, new_action, province_num, city_name);
            } else {
                actionInspect(board, xdim, ydim, province_num, city_name);
            }
            
        }
        else if ((action == 'N') || (action == 'n'))  // go north
        {
            if (ydim != 0) {
                ydim -= 1;  
            } else {
                char planB {'0'};
                while ((planB == 'N') || (planB == 'n') || (planB == '0')) {
                    std::cout << "You cannot explore beyond the map. Pick a different action (I, E, S, or W): ";
                    std::cin >> planB;
                }
                std::cout << "plan B is " << planB << std::endl;
                reposition(board, xdim, ydim, planB, province_num, city_name);
            }
           
        }
        else if ((action == 'E') || (action == 'e')) // go east
        {
            if (xdim != 50) {
                xdim += 1;  
            } else {
                char planB {'0'};
                while ((planB == 'E') || (planB == 'e') || (planB == '0')) {
                    std::cout << "You cannot explore beyond the map. Pick a different action (I, N, S, or W): ";
                    std::cin >> planB;
                }
                reposition(board, xdim, ydim, planB, province_num, city_name);
            }
        }
        else if ((action == 'S') || (action == 's')) // go south
        {
            if (ydim != 20) {
                ydim += 1;  
            } else {
                char planB {'0'};
                while ((planB == 'S') || (planB == 's') || (planB == '0')) {
                    std::cout << "You cannot explore beyond the map. Pick a different action (I, N, E, or W): ";
                    std::cin >> planB;
                }
                reposition(board, xdim, ydim, planB, province_num, city_name);
                
            }
        }
        else if ((action == 'W') || (action == 'w'))  // go west
        {
            if (xdim != 0) {
                xdim -= 1;  
            } else {
                char planB {'0'};
                while ((planB == 'W') || (planB == 'w') || (planB == '0')) {
                    std::cout << "You cannot explore beyond the map. Pick a different action (I, N, E, or S): ";
                    std::cin >> planB;
                }
                reposition(board, xdim, ydim, planB, province_num, city_name);
            }
            
        }
    

    }
}


void print_canada_with_player(char * board, std::size_t &xdim, std::size_t &ydim) {
    Colors colors;
    canada_graphic can;

    for (std::size_t print_row {0}; print_row < 21; print_row++){
      
        for (std::size_t print_col {0}; print_col < 51; print_col++){
            
            if ((print_row == ydim) && (print_col == xdim)) {
                //player's location
                std::cout << colors.red << "O";

            } else if (board[print_row*51 + print_col] == 14) {
                //marked as no reindeer
                std::cout << colors.yellow << "X";
            } else {
                
                if (can.characters[print_row*51 + print_col] == '#') {
                    std::cout << colors.green << can.characters[print_row*51 + print_col];
                } else {
                    std::cout << colors.blue << can.characters[print_row*51 + print_col];
                } 

            }
        }
      
      std::cout << std::endl;
    }
}

char getAction()
{
  char action {0};

  std::cout << "Please enter the letter corresponding to the action you wish to complete: " << std::endl;
  std::cout << "I - Inspect this province" << std::endl;
  std::cout << "N - Move North" << std::endl;
  std::cout << "E - Move East" << std::endl;
  std::cout << "S - Move South" << std::endl;
  std::cout << "W - Move West" << std::endl;
  std::cin >> action;

  if (islower(action)) {
    action = toupper(action);  
  }
    
  return action;
}

char getAction_noInspect() {
    char action {0};

  std::cout << "Please enter the letter corresponding to the action you wish to complete: " << std::endl;
  std::cout << "N - Move North" << std::endl;
  std::cout << "E - Move East" << std::endl;
  std::cout << "S - Move South" << std::endl;
  std::cout << "W - Move West" << std::endl;
  std::cin >> action;

  if (islower(action)) {
    action = toupper(action);  
  }
    
  return action;
}

void mark_province (char * board, int index, std::size_t &xdim, std::size_t &ydim) { //may need & before board
    
    for (std::size_t i{}; i < 1071; i++) {
        if (board[i] == index) {
            board[i] = 14;
        }
    }
}

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

void actionInspect (char * board, std::size_t &xdim, std::size_t &ydim, int province_num, std::string city_name) {
    
    std::string city_guess {};
    char hint_choice {};
    int carrots {0};

    Linked_list Yukon {};
    Linked_list Northwest_Territories {};
    Linked_list Nunavut {};
    Linked_list BC {};
    Linked_list Alberta {};
    Linked_list Saskatchewan {};
    Linked_list Manitoba {};
    Linked_list Ontario {};
    Linked_list Quebec {};
    Linked_list NB {};
    Linked_list NS {};
    Linked_list PEI {};
    Linked_list NandL {}; 

    Yukon.push_front( "Whitehorse" );
    Yukon.push_front( "Tagish" );
    Yukon.push_front( "Teslin" ); 

    Northwest_Territories.push_front( "Wrigley" );
    Northwest_Territories.push_front( "Yellowknife" );
    Northwest_Territories.push_front( "Whati" ); 

    Nunavut.push_front( "Igloolik" );
    Nunavut.push_front( "Iqaluit" );
    Nunavut.push_front( "Qikiqtarjuaq" ); 

    BC.push_front( "Vancouver" );
    BC.push_front( "Victoria" );
    BC.push_front( "Kamloops" );

    Alberta.push_front( "Edmonton" );
    Alberta.push_front( "Calgary" );
    Alberta.push_front( "Banff" );

    Saskatchewan.push_front( "Saskatoon" );
    Saskatchewan.push_front( "Regina" );
    Saskatchewan.push_front( "Moose-Jaw" );

    Manitoba.push_front( "Winnipeg" );
    Manitoba.push_front( "Churchill" );
    Manitoba.push_front( "Dauphin" );

    Ontario.push_front( "Ottawa" );
    Ontario.push_front( "Toronto" );
    Ontario.push_front( "Waterloo" );

    Quebec.push_front( "Montreal" );
    Quebec.push_front( "Quebec City" );
    Quebec.push_front( "Saguenay" );

    NB.push_front( "Fredericton" );
    NB.push_front( "Rogersville" );
    NB.push_front( "Moncton" );

    NS.push_front( "Halifax" );
    NS.push_front( "Digby" );
    NS.push_front( "Lower-Sackville" );

    PEI.push_front( "Charlottetown" );
    PEI.push_front( "Wellington" );
    PEI.push_front( "O'Leary" );

    NandL.push_front( "St.John's" );
    NandL.push_front( "Happy-Valley-Goose-Bay" );
    NandL.push_front( "Holyrood" );


    if (province_num != board[xdim + ydim*51]) {
        if (hint_countdown != 0) {
            hint_countdown -= 1;
        }
        std::cout << "Nope! Santa's reindeer is not in this province. " << std::endl;
        
        mark_province(board, board[xdim + ydim*51], xdim, ydim);
        if (hint_countdown == 0) {
            print_canada_with_player(board, xdim, ydim);
            std::cout << "Would you like a hint? [Y]es or [N]o: ";
            std::cin >> hint_choice;
                if ((hint_choice == 'Y') || (hint_choice == 'y')) {
                    HelpHint(province_num);

                }
        } else {
            std::cout << "You must inspect " << hint_countdown << " more province(s) before a hint becomes available." << std::endl;
        }
        std::cin.ignore();
        std::cout << "Press Enter if you would like to continue.";
        std::cin.get();
        
    } else {
        inspect_lock = true;
        
        std::cout << "Yes! This is the province where the reindeer is hiding." << std::endl
        << "There are three cities where the reindeer could be hiding." << std::endl
        << "Why is he in a city rather than a forest?" << std::endl
        << "Santa's reindeer know their way around the cities very well :)" << std::endl;

        std::cin.ignore();
        std::cout << "Press Enter to continue";
        std::cin.get();

        std::cout << std::endl << std::endl;

        std::cout << "You will earn a carrot for each trivia question you answer correctly." << std::endl
        << "Each carrot allows you to search one city.";
        
        std::cin.ignore();
        std::cout << "Press Enter to start trivia";
        std::cin.get();

        std::cout << std::endl;
        
        GetCarrots(province_num, carrots);

        std::cout << std::endl;

        std::cout << "You have " << carrots << " carrots, so you can search " 
        << carrots << " cities. If you can't find the reindeer, he'll escape to a different location." 
        << std::endl << std::endl;

        //list city options
            switch (province_num)
        {
            case 1 :  // Yukon
            {
                std::cout << "Where is the reindeer hiding in Yukon?" << std::endl;
                for ( Node *p_node{ Yukon.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }

                break;
            }
            case 2 :  // N-W territories
            {
                std::cout << "Where is the reindeer hiding in Northwest Territories?" << std::endl;
                for ( Node *p_node{ Northwest_Territories.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }
                break;
            }
            case 3 :  // Nunavut
            {
                std::cout << "Where is the reindeer hiding in Nunavut?" << std::endl;
                for ( Node *p_node{ Nunavut.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }
                break;
            }
            case 4 :  // BC
            {
                std::cout << "Where is the reindeer hiding in British Columbia?" << std::endl;
                for ( Node *p_node{ BC.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }
                break;
            }
            case 5 :  // Alberta
            {
                std::cout << "Where is the reindeer hiding in Alberta?" << std::endl;
                for ( Node *p_node{ Alberta.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }
                break;
            }
            case 6 :  // Saskatchewan
            {
                std::cout << "Where is the reindeer hiding in Saskatchewan?" << std::endl;
                for ( Node *p_node{ Saskatchewan.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }
                break;
            }
            case 7 :  // Manitoba
            {
                std::cout << "Where is the reindeer hiding in Manitoba?" << std::endl;
                for ( Node *p_node{ Manitoba.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }
                break;
            }
            case 8 :  // Ontario
            {
                std::cout << "Where is the reindeer hiding in Ontario?" << std::endl;
                for ( Node *p_node{ Ontario.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }
                break;
            }
            case 9 :  // Quebec
            {
                std::cout << "Where is the reindeer hiding in Quebec?" << std::endl;
                for ( Node *p_node{ Quebec.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }
                break;
            }
            case 10 :  // New Brunswick
            {
                std::cout << "Where is the reindeer hiding in New Brunswick?" << std::endl;
                for ( Node *p_node{ NB.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }
                break;
            }
            case 11 :  // Nova Scotia territories
            {
                std::cout << "Where is the reindeer hiding in Nova Scotia?" << std::endl;
                for ( Node *p_node{ NS.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }
                break;
            }
            case 12 :  // PEI
            {
                std::cout << "Where is the reindeer hiding in Prince-Edward-Island?" << std::endl;
                for ( Node *p_node{ Northwest_Territories.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }
                break;
            }
            case 13 :  // Newfoundland and Labrador
            {
                std::cout << "Where is the reindeer hiding in Newfoundland and Labrador?" << std::endl;
                for ( Node *p_node{ NandL.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                    std::cout << "--> " << p_node->city() << std::endl;
                }
                break;
            }
        }

        while (carrots != 0) {
            
            
            std::cout << "Enter the city you want to search:  ";
            //the user enters the name of the city

            std::cin >> city_guess;

            if (city_guess == city_name) {
                game_won = true;
                std::cout << "CORRECT! You have found the reindeer. You are guarenteed a spot on Santa's nice list for the rest of your life.";
                break;
            } else {
                std::cout << "INCORRECT GUESS" << std::endl;
            }

            carrots -= 1;
        }

        if (game_won == false) {
            
            std::cout << std::endl << "You have run out of guesses." << std::endl
            << "The city where the reindeer was hiding was " << city_name << ". " << std::endl
            << "The reindeer has run to a different province." << std::endl;
            
            std::cin.ignore();
            std::cout << "Press Enter to restart the search.";
            std::cin.get();

            int hint_countdown = 3;
            bool inspect_lock = false;

            cleanBoard (board);
            game ();
            Yukon.clear();
            Northwest_Territories.clear();
            Nunavut.clear ();
            BC.clear();
            Alberta.clear();
            Saskatchewan.clear();
            Manitoba.clear();
            Ontario.clear();
            Quebec.clear();
            NB.clear();
            NS.clear();
            PEI.clear();
            NandL.clear();

        }
    } 
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

