#include <iostream>
#include <cassert>
#include "linked_list.hpp"

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