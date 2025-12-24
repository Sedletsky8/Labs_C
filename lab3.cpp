#include "subvector.h" 

Subvector::Subvector() : top_(0), capacity_(0), mas_(nullptr) {}

Subvector::~Subvector() {
  delete[] mas_;
}

Subvector::Subvector(const Subvector& array) : top_(array.top_), capacity_(array.top_) {
  if (capacity_ > 0) {
    mas_ = new int32_t[capacity_];
    for (uint32_t i = 0; i < top_; ++i) {
      mas_[i] = array.mas_[i];
    }
  } else {
    mas_ = nullptr;
  }
}

Subvector& Subvector::operator=(const Subvector& array) {
  if (this != &array) {
    int32_t* new_mas = nullptr;

    if (array.top_ > 0) {
      new_mas = new(std::nothrow) int32_t[array.top_];
      if (new_mas == nullptr) {
        return *this;
      }
      for (uint32_t i = 0; i < array.top_; ++i) {
        new_mas[i] = array.mas_[i];
      }
    }
    delete[] mas_;
    mas_ = new_mas;
    capacity_ = array.top_;
    top_ = array.top_;
  }
  return *this;
}

Subvector::Subvector(Subvector&& array) noexcept:
      mas_(array.mas_), top_(array.top_), capacity_(array.capacity_)  {
  array.mas_ = nullptr;
  array.top_ = 0;
  array.capacity_ = 0;
}

Subvector& Subvector::operator=(Subvector&& array) noexcept {
  if (this != &array) {
    delete[] mas_;
    mas_ = array.mas_;
    top_ = array.top_;
    capacity_ = array.capacity_;
    array.mas_ = nullptr;
    array.top_ = 0;
    array.capacity_ = 0;
  }
  return *this;
}

bool Subvector::PushBack(int32_t value) {
  if (top_ == capacity_) {
    uint32_t new_capacity = !capacity_ ? 1 : capacity_ * 2;
    if(!Resize(new_capacity)) {
      return false;
    }
  }
  mas_[top_++] = value;
  return true;
}

int32_t Subvector::PopBack() {
  if (top_ == 0) {
    throw std::runtime_error("Vector is empty");
  }
  return mas_[--top_];
}

void Subvector::Clear() {
  delete[] mas_;
  mas_ = nullptr;
  top_ = 0;
  capacity_ = 0;
}

void Subvector::ShrinkToFit() {
  if (top_ < capacity_) {
    Resize(top_);
  }
}

bool Subvector::Resize(uint32_t new_capacity) {
  if (new_capacity == capacity_) {
    return true;
  }
  
  if (new_capacity == 0) {
    Clear();
    return true;
  }

  int32_t* new_mas = nullptr;
  new_mas = new(std::nothrow) int[new_capacity];
  if (new_mas == nullptr) {
    return false;
  }
  uint32_t counter = (top_ < new_capacity) ? top_ : new_capacity;
  for (uint32_t i = 0; i < counter; ++i) {
    new_mas[i] = mas_[i];
  }

  delete[] mas_;
  mas_ = new_mas;
  capacity_ = new_capacity;
  if (top_ > capacity_) {
    top_ = capacity_;
  }
  return true;
}
