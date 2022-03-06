#pragma once
#include <iostream>

class Node;
class Linked_list;

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