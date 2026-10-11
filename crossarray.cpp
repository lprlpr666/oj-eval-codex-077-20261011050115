#include "crossarray.h"
#include <algorithm>

namespace sjtu {

CrossArray::CrossArray(int lines)
    : capacity_(lines), count_(0) {
    if (capacity_ < 0) capacity_ = 0;
    data_ = new int *[capacity_];
    sizes_ = new int[capacity_];
    for (int i = 0; i < capacity_; ++i) {
        data_[i] = nullptr;
        sizes_[i] = 0;
    }
}

CrossArray::CrossArray(const CrossArray &o)
    : capacity_(o.capacity_), count_(o.count_) {
    data_ = new int *[capacity_];
    sizes_ = new int[capacity_];
    for (int i = 0; i < capacity_; ++i) {
        data_[i] = nullptr;
        sizes_[i] = 0;
    }
    for (int i = 0; i < count_; ++i) {
        int sz = o.sizes_[i];
        if (sz > 0 && o.data_[i] != nullptr) {
            int *arr = new int[sz];
            std::copy(o.data_[i], o.data_[i] + sz, arr);
            data_[i] = arr;
            sizes_[i] = sz;
        }
    }
}

CrossArray &CrossArray::WhichGreater(CrossArray &o) {
    int myTotal = totalElements();
    int otherTotal = o.totalElements();
    if (myTotal >= otherTotal) {
        return *this;
    } else {
        return o;
    }
}

bool CrossArray::IsSame(const CrossArray &o) {
    // Returns true if both instances share the same underlying data pointer array
    return data_ == o.data_;
}

bool CrossArray::InsertArrays(const int *Input, int size) {
    if (count_ >= capacity_) {
        return false;
    }
    int *arr = new int[size];
    std::copy(Input, Input + size, arr);
    data_[count_] = arr;
    sizes_[count_] = size;
    ++count_;
    return true;
}

void CrossArray::AppendArrays(const int *Input, int Line, int size) {
    // Assume Line is valid and already inserted
    int oldSize = sizes_[Line];
    int newSize = oldSize + size;
    int *newArr = new int[newSize];
    if (oldSize > 0) {
        std::copy(data_[Line], data_[Line] + oldSize, newArr);
    }
    std::copy(Input, Input + size, newArr + oldSize);
    delete[] data_[Line];
    data_[Line] = newArr;
    sizes_[Line] = newSize;
}

void CrossArray::DoubleCrossLength() {
    int newCap = capacity_ * 2;
    if (newCap == 0) newCap = 1;
    int **newData = new int *[newCap];
    int *newSizes = new int[newCap];
    for (int i = 0; i < capacity_; ++i) {
        newData[i] = data_[i];
        newSizes[i] = sizes_[i];
    }
    for (int i = capacity_; i < newCap; ++i) {
        newData[i] = nullptr;
        newSizes[i] = 0;
    }
    delete[] data_;
    delete[] sizes_;
    data_ = newData;
    sizes_ = newSizes;
    capacity_ = newCap;
}

const int *CrossArray::AtArray(int i) {
    return data_[i];
}

int &CrossArray::At(int i, int j) {
    return data_[i][j];
}

CrossArray::~CrossArray() {
    for (int i = 0; i < capacity_; ++i) {
        delete[] data_[i];
    }
    delete[] data_;
    delete[] sizes_;
}

} // namespace sjtu

