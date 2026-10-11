#pragma once

namespace sjtu {
    class CrossArray {
    private:
        int **data_;      // pointers to each 1D array
        int *sizes_;      // length of each 1D array
        int capacity_;    // maximum number of arrays (lines)
        int count_;       // number of inserted arrays

        // helper to compute total element count
        int totalElements() const {
            int total = 0;
            for (int i = 0; i < count_; ++i) {
                total += sizes_[i];
            }
            return total;
        }
    public:
        explicit CrossArray(int lines);
        CrossArray(const CrossArray &o);
        CrossArray &WhichGreater(CrossArray &o);
        bool IsSame(const CrossArray &o);
        bool InsertArrays(const int *Input, int size);
        void AppendArrays(const int *Input, int Line, int size);
        void DoubleCrossLength();
        const int *AtArray(int i);
        int &At(int i, int j);
        ~CrossArray();
    };
}

