//
// Created by Kate Rupar on 2/20/20.
//

//
//

#pragma once
#include "row.h"
#include "rower.h"

/**
 * A Rower with a purpose of converting every int to 4
 */
class sumRower : public Rower {
public:

    size_t sum;

    sumRower() {
        sum = 0;
    }

    ~sumRower() {

    }

    //If the col_type is int, sets the value to 4
    //Returns true if the row contains an IntColumn
    bool accept(Row& r) {
        bool intFlag = false;
        for (int i = 0; i < r.width(); i++) {
            if (r.col_type(i) == 'I') {
                sum+=r.get_int(i);
                intFlag = true;
            }
        }
        return intFlag;
    }

    /** Once traversal of the data frame is complete the rowers that were
        split off will be joined.  There will be one join per split. The
        original object will be the last to be called join on. The join method
        is reponsible for cleaning up memory. */
    void join_delete(Rower* other) {
        sumRower* sr;
        sr = dynamic_cast<sumRower*> (other);
        if (sr == nullptr) {
            exit(1);
        }
        sum+=sr->sum;
        delete other;
    }

    Rower* clone() {
        return new sumRower();
    }
};