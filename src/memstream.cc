//
// Created by Andrey Ryabov on 3/25/20.
//

#include "memstream.h"
#include <stdexcept>
#include <cstring>

using namespace std;

namespace fasttext {

MemStream::MemStream(void * d, size_t s) : _data((uint8_t*)d), _size(s) {
}

void * MemStream::allocate(size_t size) {
    if (_ptr + size > _size) {
        throw runtime_error("MemStream::allocate out of range");
    }
    auto r = _data + _ptr;
    _ptr += size;
    return r;
}

int MemStream::get() {
    if (_ptr >= _size) {
        throw runtime_error("MemStream::get out of range");
    }
    return _data[_ptr++];
}

string_view MemStream::getStringView() {
    auto s = _data + _ptr;
    size_t size = 0;
    while (_data[_ptr++] != 0) {
        size++;
    }
    return {(char*)s, size};
}

void MemStream::read(void * dest, size_t size) {
    if (_ptr + size > _size) {
        throw runtime_error("MemStream::read out of range");
    }
    memcpy(dest, _data + _ptr, size);
    _ptr += size;
}

}