#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <limits>
#include <cassert>



int main();
bool game();
void print_canada_start();
void print_canada_with_player(char * board, std::size_t &xdim, std::size_t &ydim);
int province_hiding_spot();
std::string city_hiding_spot(int province); 
char * createBoard();
void startGame(char * & board);
void cleanBoard(char * board);
char getAction();
char getAction_noInspect();
void mark_province (char * board, int index, std::size_t &xdim, std::size_t &ydim); //maybe use & before board?
void reposition (char * board, std::size_t &xdim, std::size_t &ydim, char action, int province_num, std::string city_name);
void actionInspect(char * board, std::size_t &xdim, std::size_t &ydim, int province_num, std::string city_name);
std::string WhereAmI_province(char * board, std::size_t &xdim, std::size_t &ydim);
void HelpHint(int province_num);
void GetCarrots (int province_num);



//global variables
int hint_countdown {3};
int carrots {0};
bool inspect_lock {false};
bool game_won {false};

class Node;
class Linked_list;
class Colors;
class canada_graphic;

class Node {
  public:
    Node(std::string const new_city,
          Node  *const p_new_next_node );
    

    std::string city() const; // to write
    Node *p_next_node() const;
 
  private:
    std::string city_;
    Node  *p_next_node_;
};

class Linked_list {
  public:
    Linked_list();
   ~Linked_list();
    
    std::string front() const;
    bool empty() const;
    
    void push_front( std::string new_city );
    void pop_front();
    void clear();

    Node *p_list_head_;
    Node *p_list_tail_;
    
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

Node::Node(std::string const new_city,
            Node  *const p_new_next_node ):
city_{new_city},
p_next_node_{ p_new_next_node } {}

std::string Node::city() const {
  return city_;
} 

Node *Node::p_next_node() const {
  return p_next_node_;
}

Linked_list::Linked_list():
p_list_head_{ nullptr },
p_list_tail_{ nullptr } {
  
}

Linked_list::~Linked_list() {
  clear();
}

std::string Linked_list::front() const {
  if ( !empty() ) {
    return p_list_head_->city(); 
  } else {
    assert( empty() );
    throw std::out_of_range{ "The linked list is empty" };
  }
}

bool Linked_list::empty() const {
  return ( p_list_head_ == nullptr );
}

void Linked_list::push_front( std::string new_city ) {
    p_list_head_ = new Node{ new_city, p_list_head_ };

    if ( p_list_tail_ == nullptr ) {
      p_list_tail_ = p_list_head_;
    }
}

void Linked_list::pop_front() {
  if ( !empty() ) {
    Node *p_old_head{ p_list_head_ };

    p_list_head_ = p_list_head_->p_next_node();

    if ( p_list_head_ == nullptr ) {
        p_list_tail_ = nullptr;
    }

    delete p_old_head;
    p_old_head = nullptr;
  }
}


void Linked_list::clear() {
  while ( !empty() ) {
    pop_front();
  }
}


void startGame(char * & board){
  cleanBoard(board);
  board = createBoard();
}

void cleanBoard(char * board) {
    delete[] board;
    board = nullptr;
}

char * createBoard() {
    /*
    Bit mask legend:
        Ocean (~) = 0
        Yukon = 1
        Northwest Territories = 2
        Nunavut = 3
        British Columbia = 4
        Alberta = 5
        Saskatchewan = 6
        Manitoba = 7
        Ontario = 8
        Quebec = 9
        New Brunswick = 10
        Nova Scotia = 11
        Prince Edward Island = 12
        Newfoundland and Labrador = 13
        Marked as no reindeer = 14
    */
    
    
    canada_graphic can;
    char *board{new char[1071]{}};
    
    //Ocean
    for (std::size_t i{}; i < 1071; i++) {
        if (can.characters[i] == '~') {
            board[i] = 0;
        }
    }

    //Yukon
        board[209] = 1;
        board[259] = 1;
        board[260] = 1;
        board[261] = 1;
        board[308] = 1;
        board[309] = 1;
        board[310] = 1;
        board[311] = 1;
        board[312] = 1;
        board[357] = 1;
        board[358] = 1;
        board[359] = 1;
        board[360] = 1;
        board[361] = 1;
        board[362] = 1;
        board[363] = 1;
        board[408] = 1;
        board[409] = 1;
        board[410] = 1;
        board[411] = 1;
        board[412] = 1;
        board[413] = 1;
        board[414] = 1;
        board[464] = 1;
        board[465] = 1;

    //Northwest Territories
        board[119] = 2;

        board[168] = 2;
        board[169] = 2;

        board[216] = 2;
        board[217] = 2;
        board[218] = 2;
        board[219] = 2;

        board[262] = 2;
        board[263] = 2;
        board[264] = 2;
        board[265] = 2;
        board[269] = 2;
        board[270] = 2;
        board[271] = 2;

        board[313] = 2;
        board[314] = 2;
        board[315] = 2;
        board[316] = 2;
        board[317] = 2;
        board[318] = 2;
        
        board[364] = 2;
        board[365] = 2;
        board[366] = 2;
        board[367] = 2;
        board[368] = 2;
        board[369] = 2;
        
        board[415] = 2;
        board[416] = 2;
        board[417] = 2;
        board[418] = 2;
        board[419] = 2;
        board[420] = 2;
        board[421] = 2;
        board[422] = 2;
        
        
        board[466] = 2;
        board[467] = 2;
        board[468] = 2;
        board[469] = 2;
        board[470] = 2;
        board[471] = 2;
        board[472] = 2;
        board[473] = 2;
        board[474] = 2;
        board[475] = 2;
        board[476] = 2;
        board[477] = 2;

        board[519] = 2;
        board[520] = 2;
        board[521] = 2;
        board[522] = 2;
        board[523] = 2;
        board[524] = 2;
        board[525] = 2;
        board[526] = 2;
        board[527] = 2;
        board[528] = 2;
        
        board[576] = 2;
        board[577] = 2;
        board[578] = 2;
        board[579] = 2;
        
        
    //Nunavut
        board[23] = 3;
        board[24] = 3;
        board[25] = 3;

        board[72] = 3;
        board[73] = 3;
        board[74] = 3;
        board[75] = 3;
        board[76] = 3;

        board[121] = 3;
        board[122] = 3;
        board[124] = 3;
        board[125] = 3;
        board[126] = 3;
        board[127] = 3;

        board[171] = 3;
        board[172] = 3;
        board[173] = 3;
        board[174] = 3;
        board[175] = 3;
        board[176] = 3;
        board[177] = 3;
        board[178] = 3;

        board[225] = 3;
        board[226] = 3;
        board[227] = 3;
        board[228] = 3;
        board[229] = 3;

        board[272] = 3;
        board[273] = 3;
        board[275] = 3;
        board[276] = 3;
        board[277] = 3;
        board[279] = 3;
        board[280] = 3;
        board[281] = 3;
        board[282] = 3;
        board[283] = 3;
        board[284] = 3;

        board[319] = 3;
        board[320] = 3; 
        board[321] = 3;
        board[322] = 3;
        board[323] = 3;
        board[324] = 3;
        board[325] = 3;
        board[327] = 3;
        board[328] = 3;
        board[330] = 3;
        board[331] = 3;
        board[332] = 3;
        board[333] = 3;
        board[334] = 3;
        board[335] = 3;
        board[336] = 3;
        board[337] = 3;
        board[338] = 3;

        board[370] = 3;
        board[371] = 3;
        board[372] = 3;
        board[373] = 3;
        board[374] = 3;
        board[375] = 3;
        board[378] = 3;
        board[379] = 3;
        board[380] = 3;
        board[381] = 3;
        board[383] = 3;
        board[386] = 3;
        board[388] = 3;
        board[389] = 3;
        board[390] = 3;
        board[391] = 3;
        board[392] = 3;

        board[423] = 3;
        board[424] = 3;
        board[425] = 3;
        board[426] = 3;
        board[427] = 3;
        board[428] = 3;
        board[429] = 3;
        board[430] = 3;
        board[431] = 3;
        board[432] = 3;
        board[433] = 3;
        board[434] = 3;

        board[438] = 3;
        board[439] = 3;  
        board[440] = 3;
        board[441] = 3;
        board[442] = 3;
        board[443] = 3;

        board[478] = 3;
        board[479] = 3;
        board[480] = 3;
        board[481] = 3;
        board[482] = 3;
        board[483] = 3;
        board[484] = 3;
        board[485] = 3;
        board[486] = 3;
        board[487] = 3;
        
        board[493] = 3;
        board[494] = 3;

        board[529] = 3;
        board[530] = 3;
        board[531] = 3;
        board[532] = 3;
        board[533] = 3;

        board[580] = 3;
        board[581] = 3;
        board[582] = 3;
        board[583] = 3;
        

    //British Columbia
        board[461] = 4;
        board[462] = 4;
        board[463] = 4;
        
        board[512] = 4;
        board[513] = 4;
        board[514] = 4;
        board[515] = 4;
        board[516] = 4;
        board[517] = 4;
        board[518] = 4;
        
        board[562] = 4;
        board[563] = 4;
        board[564] = 4;
        board[565] = 4;
        board[566] = 4;
        board[567] = 4;
        board[568] = 4;
        
        board[613] = 4;
        board[614] = 4;
        board[615] = 4;
        board[616] = 4;
        board[617] = 4;
        board[618] = 4;
        
        board[664] = 4;
        board[665] = 4;
        board[666] = 4;
        board[667] = 4;
        board[668] = 4;
        board[669] = 4;

        board[714] = 4;
        board[715] = 4;
        board[716] = 4;
        board[717] = 4;
        board[718] = 4;
        board[719] = 4;
        board[720] = 4;
        
        board[769] = 4;
        board[770] = 4;
        board[771] = 4;
        board[772] = 4;
        board[773] = 4;
        
        
    //Alberta
        board[569] = 5;
        board[570] = 5;
        board[571] = 5;
        board[572] = 5;
        board[573] = 5;
        board[574] = 5;
        board[575] = 5;
        
        board[619] = 5;
        board[620] = 5;
        board[621] = 5;
        board[622] = 5;
        board[623] = 5;
        board[624] = 5;
        board[625] = 5;
        
        board[670] = 5;
        board[671] = 5;
        board[672] = 5;
        board[673] = 5;
        board[674] = 5;
        board[675] = 5;
        
        board[721] = 5;
        board[722] = 5;
        board[723] = 5;
        board[724] = 5;
        board[725] = 5;
        
        board[773] = 5;
        board[774] = 5;
        board[775] = 5;
        
        board[825] = 5;

    //Saskatchewan
        board[626] = 6;
        board[627] = 6;
        board[628] = 6;
        board[629] = 6;
        
        board[676] = 6;
        board[677] = 6;
        board[678] = 6;
        board[679] = 6;
        board[680] = 6;
        
        board[726] = 6;
        board[727] = 6;
        board[728] = 6;
        board[729] = 6;
        board[730] = 6;
        
        board[776] = 6;
        board[777] = 6;
        board[778] = 6;
        board[779] = 6;
        board[780] = 6;
        board[781] = 6;
        
        board[826] = 6;
        board[827] = 6;
        board[828] = 6;
        board[829] = 6;
        board[830] = 6;
        board[831] = 6;
        

    //Manitoba
        board[630] = 7;
        board[631] = 7;
        board[632] = 7;
        board[633] = 7;
        board[634] = 7;
        
        board[681] = 7;
        board[682] = 7;
        board[683] = 7;
        board[684] = 7;
        board[685] = 7;
        board[686] = 7;
        board[687] = 7;

        board[731] = 7;
        board[732] = 7;
        board[733] = 7;
        board[734] = 7;
        board[735] = 7;
        board[736] = 7;
        
        board[782] = 7;
        board[783] = 7;
        board[784] = 7;
        board[785] = 7;
        
        board[832] = 7;
        board[833] = 7;
        board[834] = 7;
        board[835] = 7;
        board[836] = 7;
        
    //Ontario
        board[688] = 8;
        board[689] = 8;

        board[737] = 8;
        board[738] = 8;
        board[739] = 8;
        board[740] = 8;
        board[741] = 8;
        board[742] = 8;
        board[743] = 8;

        board[786] = 8;
        board[787] = 8;
        board[788] = 8;
        board[789] = 8;
        board[790] = 8;
        board[791] = 8;
        board[792] = 8;
        board[793] = 8;
        board[794] = 8;
        board[795] = 8;
        
        board[837] = 8;
        board[838] = 8;
        board[839] = 8;
        board[840] = 8;
        board[841] = 8;
        board[842] = 8;
        board[843] = 8;
        board[844] = 8;
        board[845] = 8;
        board[846] = 8;
        board[847] = 8;
        board[848] = 8;
        
        board[895] = 8;
        board[896] = 8;
        board[897] = 8;
        board[898] = 8;
        board[899] = 8;

        board[950] = 8;
        board[951] = 8;
        board[952] = 8;
        board[953] = 8;
        
        board[1001] = 8;
        board[1002] = 8;

        board[1051] = 8;

    //Quebec
        board[541] = 9;
        board[542] = 9;
        board[543] = 9;
        board[544] = 9;

        board[547] = 9;
        board[548] = 9;

        board[592] = 9;
        board[593] = 9;
        board[594] = 9;
        board[595] = 9;
        board[596] = 9;
        board[597] = 9;
        board[598] = 9;
        board[599] = 9;
        board[600] = 9;

        board[644] = 9;
        board[645] = 9;
        board[646] = 9;
        board[647] = 9;
        board[648] = 9;
        board[649] = 9;
        board[650] = 9;
        board[651] = 9;
        
        board[694] = 9;
        board[695] = 9;
        board[696] = 9;
        board[697] = 9;
        board[698] = 9;
        board[699] = 9;
        board[700] = 9;
        board[701] = 9;
        board[702] = 9;
        
        board[746] = 9;
        board[747] = 9;
        board[748] = 9;
        board[749] = 9;
        board[750] = 9;
        board[751] = 9;
        board[752] = 9;
        board[753] = 9;
        board[754] = 9;
        board[755] = 9;

        board[757] = 9;
        board[758] = 9;

        board[797] = 9;
        board[798] = 9;
        board[799] = 9;
        board[800] = 9;
        board[801] = 9;
        board[802] = 9;
        board[803] = 9;
        board[804] = 9;
        board[805] = 9;
        board[806] = 9;
        board[807] = 9;

        board[849] = 9;
        board[850] = 9;
        board[851] = 9;
        board[852] = 9;
        board[853] = 9;
        board[854] = 9;
        board[855] = 9;
        board[856] = 9;
        
        board[900] = 9;
        board[901] = 9;
        board[902] = 9;
        board[903] = 9;
        board[904] = 9;
        board[905] = 9;
        

    //New Brunswick
        board[808] = 10;

        board[858] = 10;
        board[859] = 10;
        board[860] = 10;
        board[861] = 10;

        board[910] = 10;
        board[911] = 10;
        
        
    //Nova Scotia
        board[812] = 11;
        board[862] = 11;
        board[912] = 11;
        
    //Prince Edward Island
        board[810] = 12;
        board[811] = 12;

    //Newfoundland and Labrador
        board[601] = 13;
        board[602] = 13;
        board[603] = 13;
        board[604] = 13;
        
        board[652] = 13;
        board[653] = 13;
        board[654] = 13;
        board[655] = 13;
        board[656] = 13;
        board[657] = 13;
        board[658] = 13;

        board[660] = 13;
        board[661] = 13;
        board[662] = 13;
        
        board[703] = 13;
        board[704] = 13;
        board[705] = 13;
        board[706] = 13;
        board[707] = 13;
        
        board[704] = 13;
        board[705] = 13;
        board[706] = 13;
        board[707] = 13;
        
        board[710] = 13;
        board[711] = 13;
        board[712] = 13;
        board[713] = 13;
        
        
        
    return board;
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
            r = "Moose Jaw";
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
            r = "Lower Sackville";
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
            r = "St. John's";
        } else if (i == 2) {
            r = "Happy Valley-Goose Bay";
        } else {
            r = "Holyrood";
        }
    }

    
    return r;
}

//solve city problem
void actionInspect (char * board, std::size_t &xdim, std::size_t &ydim, int province_num, std::string city_name) {
    
    std::string city_guess {};
    char hint_choice {};

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
    Saskatchewan.push_front( "Moose Jaw" );

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
    NS.push_front( "Lower Sackville" );

    PEI.push_front( "Charlottetown" );
    PEI.push_front( "Wellington" );
    PEI.push_front( "O'Leary" );

    NandL.push_front( "St. John's" );
    NandL.push_front( "Happy Valley-Goose Bay" );
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
        << "Santa's reindeer know their way around the cities very well :)" << std::endl << std::endl
        << "You will earn a carrot for each trivia question you answer correctly." << std::endl
        << "Each carrot allows you to search one city." << std::endl;
        

        std::cin.ignore();
        std::cout << "Press enter to continue";
        std::cin.get();
        
        
        
        GetCarrots(province_num);

        

        std::cout << "You have " << carrots << " carrots, so you can search " 
        << carrots << " cities. If you can't find the reindeer, he will run to a different province." 
        << std::endl;

        //list city options
            switch (province_num)
        {
            case 1 :  // Yukon
            {
                std::cout << "Where is the reindeer hiding in Yukon?" << std::endl;
                for ( Node *p_node{ Yukon.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
                std::cout << "-->" << p_node->city() << std::endl;
                
                }

                break;
            }
            case 2 :  // N-W territories
            {
                std::cout << "Options for city 2";
                break;
            }
            case 3 :  // Nunavut
            {
                std::cout << "Options for city 3";
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
            
            std::cout << "You have run out of guesses." << std::endl
            << "The city where the reindeer was hiding was " << city_name
            << "The reindeer has run to a different province. You need to restart the search." << std::endl;
            
            std::cin.ignore();
            std::cout << "Press Enter if you would like to continue.";
            std::cin.get();

            int hint_countdown = 3;
            int carrots = 0;
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

void GetCarrots (int province_num) {

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

