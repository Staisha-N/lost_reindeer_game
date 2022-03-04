#include <iostream>
#include <cassert>
#include <cstring>
#include <time.h> 

class Node;
class Linked_list;
std::ostream &operator<<( std::ostream &out, Linked_list const &list );

int main();
int province_hiding_spot();
int city_hiding_spot();
void test (int secret_province);

int carrots {3};

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



int main() {
  srand(time(NULL));
  int secret_province {1}; // province_hiding_spot()
  int secret_city {city_hiding_spot()};
  
  std::cout << "Province: " << secret_province << std::endl
  << "City: " << secret_city << std::endl;

  test(secret_province);

    // Linked_list Yukon {};
    // Linked_list Northwest_Territories {};
    // Linked_list Nunavut {};
    // Linked_list BC {};
    // Linked_list Alberta {};
    // Linked_list Saskatchewan {};
    // Linked_list Manitoba {};
    // Linked_list Ontario {};
    // Linked_list Quebec {};
    // Linked_list NB {};
    // Linked_list NS {};
    // Linked_list PEI {};
    // Linked_list NandL {}; 

    // Yukon.push_front( "Whitehorse" );
    // Yukon.push_front( "Tagish" );
    // Yukon.push_front( "Teslin" ); 

    // Northwest_Territories.push_front( "Wrigley" );
    // Northwest_Territories.push_front( "Yellowknife" );
    // Northwest_Territories.push_front( "Whati" ); 

    // Nunavut.push_front( "Igloolik" );
    // Nunavut.push_front( "Iqaluit" );
    // Nunavut.push_front( "Qikiqtarjuaq" ); 

    // BC.push_front( "Vancouver" );
    // BC.push_front( "Victoria" );
    // BC.push_front( "Kamloops" );

    // Alberta.push_front( "Edmonton" );
    // Alberta.push_front( "Calgary" );
    // Alberta.push_front( "Banff" );

    // Saskatchewan.push_front( "Saskatoon" );
    // Saskatchewan.push_front( "Regina" );
    // Saskatchewan.push_front( "Moose Jaw" );

    // Manitoba.push_front( "Winnipeg" );
    // Manitoba.push_front( "Churchill" );
    // Manitoba.push_front( "Dauphin" );

    // Ontario.push_front( "Ottawa" );
    // Ontario.push_front( "Toronto" );
    // Ontario.push_front( "Waterloo" );

    // Quebec.push_front( "Montreal" );
    // Quebec.push_front( "Quebec City" );
    // Quebec.push_front( "Saguenay" );

    // NB.push_front( "Fredericton" );
    // NB.push_front( "Rogersville" );
    // NB.push_front( "Moncton" );

    // NS.push_front( "Halifax" );
    // NS.push_front( "Digby" );
    // NS.push_front( "Lower Sackville" );

    // PEI.push_front( "Charlottetown" );
    // PEI.push_front( "Wellington" );
    // PEI.push_front( "O'Leary" );

    // NandL.push_front( "St. John's" );
    // NandL.push_front( "Happy Valley-Goose Bay" );
    // NandL.push_front( "Holyrood" );

    // int guess_counter {0};

    // switch (secret_province)
    // {
    //     case 1 :  // Yukon
    //     {
    //         std::cout << "Where is the reindeer hiding in Yukon?" << std::endl;
    //         for ( Node *p_node{ Yukon.p_list_head_ }; p_node != nullptr; p_node = p_node->p_next_node() ) {
    //           std::cout << "-->" << p_node->city() << std::endl;
               
    //         }

    //         break;
    //     }
    //     case 2 :  // N-W territories
    //     {
    //         std::cout << "Options for city 2";
    //         break;
    //     }
    //     case 3 :  // Nunavut
    //     {
    //         std::cout << "Options for city 3";
    //         break;
    //     }
    // }

    //   Linked_list Ontario {};
    //   Linked_list Quebec {};
    //   Linked_list Nova_Scotia {};


    //   Ontario.push_front( "Ottawa" );
    //   Ontario.push_front( "Toronto" );
    //   Ontario.push_front( "London" );

    //   std::cout << Ontario << std::endl;

  


  return 0;
} 

Node::Node(std::string const new_city,
            Node  *const p_new_next_node ):
city_{new_city},
p_next_node_{ p_new_next_node } {
  // Empty constructor
}

// Access the member varialbe 'city_'
std::string Node::city() const {
  return city_;
} 

// Access the member varialbe 'p_next_node_'
Node *Node::p_next_node() const {
  return p_next_node_;
}

Linked_list::Linked_list():
p_list_head_{ nullptr },
p_list_tail_{ nullptr } {
  std::clog << ">>> Calling the constructor Linked_list()"
            << std::endl;
}

Linked_list::~Linked_list() {
  std::clog << ">>> Calling the destructor ~Linked_list()"
            << std::endl;

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

// Insert a new node at the front of the linked list
// where that node is storing the value 'new_value'.
// 
// If the linked list was initially empty prior to
// calling this member function, the first node has
// the null pointer initializing its next-node pointer;
//
// otherwise, the address that was initially stored as
// that of the front of the linked list becomes the 
// value of the new node's next-node pointer.
void Linked_list::push_front( std::string new_city ) {
  // Begin critical code:
    p_list_head_ = new Node{ new_city, p_list_head_ };

    //If there is no tail (list is empty), p_list_tail_
    // and p_list_head_ are the same because there is just one node
    if ( p_list_tail_ == nullptr ) {
      p_list_tail_ = p_list_head_;
    }

    
  // End critical code
}

void Linked_list::pop_front() {
  if ( !empty() ) {
    Node *p_old_head{ p_list_head_ };

    // Begin critical code:
      p_list_head_ = p_list_head_->p_next_node();

      if ( p_list_head_ == nullptr ) {
        p_list_tail_ = nullptr;
      }

      
    // End critical code

    delete p_old_head;
    p_old_head = nullptr;
  }
}


void Linked_list::clear() {
  while ( !empty() ) {
    pop_front();
  }
}


//KEEP THIS SO YOU CAN PRINT
// std::ostream &operator<<( std::ostream &out,
//                           Linked_list const &list ) {
//   out << "head -> ";

//   for ( Node *p_node{ list.p_list_head_ };
//               p_node != nullptr; p_node = p_node->p_next_node() ) {
//     out << p_node->city() << " -> ";
//   }

//   out << "nullptr";

//   return out;
// }

int province_hiding_spot() {
  
    std::size_t reindeer_province {0};

    while (reindeer_province == 0) { 
        reindeer_province = rand() % 3;  
    }
    
    return reindeer_province;
}

int city_hiding_spot() {
  
    std::size_t reindeer_city {0};

    while (reindeer_city == 0) {
        reindeer_city = rand() % 3;
    }
    
    return reindeer_city;
}

void test (int secret_province) {
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

    int guess_counter {0};

    switch (secret_province)
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
}