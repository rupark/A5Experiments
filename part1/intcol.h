/*************************************************************************
 * intColumn::
 * Holds int pointers. The ints are external.  Nullptr is a valid
 * value.
 */
//class Column;
class StringColumn;
class BoolColumn;
class FloatColumn;

#pragma once
#include "column.h"
#include "boolcol.h"
#include "floatcol.h"
#include "stringcol.h"
#include "string.h"
#include "iostream"
using namespace std;

/**
 * Represent a Int of Float SoR Type
 */
class IntColumn : public Column {
public:
    int* vals_;
    size_t size_;
    size_t capacity_;

    IntColumn() {
        size_ = 0;
        capacity_ = 100 * 1000 * 1000;
        vals_ = new int[capacity_];
    }

    ~IntColumn(){
        delete[] vals_;
    }

    IntColumn(int n, ...) {
        va_list args;
        va_start(args, n);
        for(size_t i=0; i<n; i++)
        {
            vals_[i] = va_arg(args, int);
        }
    }

    /**
     * Returns this if it is a StringColumn
     * @return
     */
    StringColumn* as_string() {
        return nullptr;
    }

    /**
     * Returns this if it is a IntColumn
     * @return
     */
    IntColumn* as_int() {
        return this;
    }

    /**
     * Returns this if it is a BoolColumn
     * @return
     */
    BoolColumn* as_bool() {
        return nullptr;
    }

    /**
     * Returns this if it is a FloatColumn
     * @return
     */
    FloatColumn* as_float() {
        return nullptr;
    }

    /** Returns the int at idx; undefined on invalid idx.*/
    int * get(size_t idx) {
        if (idx >= 0 && idx <= this->size()) {
            return &vals_[idx];
        } else {
            exit(1);
        }
    }

    /** Out of bound idx is undefined. */
    void set(size_t idx, int * val) {
        if (idx >= 0 && idx <= this->size()) {
            vals_[idx] = *val;
            size_++;
        } else {
            exit(1);
        }
    }

    /**
     * Returns the size of this IntColumn
     */
    size_t size() {
        return size_;
    }

    /**
     * Adds the given int to this if it is a IntColumn
     */
    virtual void push_back(int val) {
        this->vals_[size_] = val;
        size_++;
    }

    /**
     * Adds the given bool to this if it is a BoolColumn
     */
    virtual void push_back(bool val) {
        exit(1);
    }

    /**
     * Adds the given float to this if it is a FloatColumn
     */
    virtual void push_back(float val) {
        exit(1);
    }

    /**
     * Adds the given String to this if it is a StringColumn
     */
    virtual void push_back(String* val) {
        exit(1);
    }

    /** Return the type of this column as a char: 'S', 'B', 'I' and 'F'. */
    char get_type() {
        return 'I';
    }
};