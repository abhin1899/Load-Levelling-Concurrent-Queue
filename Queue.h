
#ifndef CONCURRENT_QUEUE_
#define CONCURRENT_QUEUE_

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

template <typename T>
class Queue
{
 public:

  T pop() 
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    while (queue_.empty())
    {
      cond_.wait(mlock);
    }
    auto val = queue_.front();
    queue_.pop();
    return val;
  }

  int size()
  {
    int lsize;
    std::unique_lock<std::mutex> mlock(mutex_); // mutex scope lock
    lsize = queue_.size();
    mlock.unlock();
    return lsize;
  }

  bool empty()
  {
    bool status = false;
    std::unique_lock<std::mutex> mlock(mutex_); // mutex scope lock
    if(queue_.empty()) {
      status = true;
    }
    mlock.unlock();
    return status;
  }

  void pop(T& item)
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    while (queue_.empty())
    {
      cond_.wait(mlock);
    }
    item = queue_.front();
    queue_.pop();
  }

  void push(const T& item)
  {
    std::unique_lock<std::mutex> mlock(mutex_);
    queue_.push(item);
    mlock.unlock();
    cond_.notify_one();
  }
  Queue()=default;
  Queue(const Queue&) = delete;            // disable copying
  Queue& operator=(const Queue&) = delete; // disable assignment

  // Queue(const Queue& other)
  // {
  // std::lock_guard<std::mutex> guard( other.mutex_ );
  // queue_ = other.queue_;
  // }

  // Queue& operator= (Queue& other)
  // {
  // if(&other == this)
  // return *this;
  // std::unique_lock<std::mutex> lock1( mutex_, std::defer_lock);
  // std::unique_lock<std::mutex> lock2( other.mutex_, std::defer_lock);
  // std::lock( lock1, lock2);
  // queue_ = other.queue_;
  // return *this;
  // }
  
  
 private:
  std::queue<T> queue_;
  std::mutex mutex_;
  std::condition_variable cond_;
};

#endif
