//
// Created by Andrey Ryabov on 3/25/20.
//

#pragma once

#include <cstdlib>
#include <cstdint>
#include <stdexcept>
#include <iostream>

namespace fasttext {


template<typename T_>
class MemVector {
  public:
    T_ * begin() {
        return _data;
    }

    T_ * end() {
        return _data + _size;
    }

    T_ & operator[] (int i) {
        return _data[i];
    }

    T_ * data() {
        return _data;
    }

    const T_ * begin() const {
        return _data;
    }

    const T_ * end() const {
        return _data + _size;
    }

    const T_ & operator[] (int i) const {
        return _data[i];
    }

    const T_ * data() const {
        return _data;
    }

    size_t size() const {
        return _size;
    }

    MemVector(size_t s) {
        if (s) {
            throw std::runtime_error("MemVector(size_t) - not implemented");
        }
    }
    MemVector(T_*, T_*) {
        throw std::runtime_error("MemVector(T_*, T_*) - not implemented");
    }
    MemVector(T_ * d, size_t s) : _data(d), _size(s) {
    }

    MemVector& operator = (const MemVector&) = default;
    MemVector(MemVector&) = default;
    MemVector(MemVector&&) = default;
    MemVector(const MemVector&) = default;

  private:
    T_ *   _data{nullptr};
    size_t _size{0};
};

class MemStream {
  public:
    int  get();
    void read(void *, size_t);

    template<typename T_>
    MemVector<T_> getVect(size_t numbrer) {
        return {(T_*)allocate(numbrer * sizeof(T_)), numbrer};
    }

    MemStream(void *, size_t);
  private:
    void * allocate(size_t);

    uint8_t * _data;
    size_t _size;
    size_t _ptr{0};
};

}
