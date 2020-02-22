//
// Created by Kate Rupar on 2/20/20.
//

//
//

#pragma once
#include "row.h"
#include "rower.h"

/**
 * A Rower which returns the sum of the ints across all the Rows it visits
 */
class sumRower : public Rower {
public:

    size_t sum;

    sumRower() {
        sum = 0;
    }

    ~sumRower() {

    }

    //Adds every int in the Row to sum
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

    //Returns a new sumRower
    Rower* clone() {
        return new sumRower();
    }
};