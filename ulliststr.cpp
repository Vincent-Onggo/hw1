#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) {
    if (head_ == nullptr) { // if list is empty
        head_ = new Item;
        tail_ = head_;
        tail_->val[0] = val;
        tail_->last = 1; // Initialize last index for the new head
    } else if (tail_->last > 9) { // if no space at the tail node
        Item* temp = tail_;
        tail_ = new Item;
        tail_->val[0] = val;
        tail_->prev = temp;
        temp->next = tail_;
        tail_->last = 1; // Initialize last index for the new tail
    } else {
        size_t index = tail_->last;
        tail_->val[index] = val;
        tail_->last++;
    }
    size_++;
}

void ULListStr::push_front(const std::string &val) {
    if (head_ == nullptr) {
        head_ = new Item;
        tail_ = head_;
        head_->val[9] = val;
        head_->first = 9;
        head_->last = 10;
    } else if (head_->first <= 0) {
        Item* temp = head_;
        head_ = new Item;
        head_->val[9] = val;
        head_->next = temp;
        temp->prev = head_;
        head_->first = 9;
        head_->last = 10;
    } else {
        size_t index = head_->first - 1;
        head_->val[index] = val;
        head_->first--;
    }
    size_++;
}

void ULListStr::pop_back() {
    if(tail_ == nullptr){
        return;
    } else {
        if(tail_->last - tail_->first == 1) { // if one item left, delete the item
            if(tail_ == head_) {
                delete tail_;
                head_ = nullptr;
                tail_ = nullptr;
            } else {
                Item* temp = tail_;
                tail_ = tail_->prev;
                tail_->next = nullptr;
                delete temp;
            }
        } else {
            tail_->last--;
        }
        size_--;
    }
}


void ULListStr::pop_front() {
    if(head_ == nullptr){ // deleting from zero nodes
        return;
    }else{
        if(head_->last - head_->first <= 1){
            if(tail_ == head_){
                delete head_;
                tail_ = nullptr;
                head_ = nullptr;
            }else{
                Item* temp = head_;
                head_ = head_->next;
                head_->prev = nullptr;
                delete temp;
            }
        }else{
            head_->first++;
        }
        size_--;
    }

}

std::string const & ULListStr::back() const{
    size_t index = tail_->last - 1;
    return tail_->val[index];
}

std::string const & ULListStr::front() const {
    size_t index = head_->first;
    return head_->val[index];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
    if(head_ == nullptr){
        return nullptr;
    }

    Item* itm = head_;
    size_t index = head_->first;
    for(size_t i=0; i<loc; i++){
        if(index < itm->last - 1){
            index ++;
        }else{
            if(itm == tail_){
                return NULL;
            }
            itm = itm->next; // move to next node
            index = itm->first;
        }
    }
    return &(itm->val[index]);
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
