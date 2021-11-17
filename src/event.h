/**
 * @author      : Dbeela (paomagbite@gmail.com)
 * @file        : event
 * @created     : Tuesday Nov 09, 2021 13:14:55 HKT
 */

#pragma once
#ifndef SRC_EVENT_H

#define SRC_EVENT_H

#include <vector>
#include <algorithm>

#include "event_types.h"


// Handler Interface
template <class T>
class Handler {
public:
  virtual void update(T *event) = 0;

};


// Event interface
template <class T>
class Event {
public:
    Event() {}
    virtual ~Event() {}
    
    void add(Handler<T> &handler) {
        this->handlers_.push_back(&handler);
    }
    
    void remove(Handler<T> &handler) {
        this->handlers_.erase(std::remove(handlers_.begin(), handlers_.end(),&handler), handlers_.end());
    }
    
    void notify() {
        for(int i = handlers_.begin(); i!= handlers_.end(); i++) {
            this->handlers_->update(static_cast<T *>(this));
        }
    }


private:
    std::vector<Handler<T> *> handlers_;
};
#endif /* end of include guard SRC_EVENT_H */

