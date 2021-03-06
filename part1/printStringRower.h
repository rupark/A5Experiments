//
// Created by Kate Rupar on 2/14/20.
//

#pragma once
#include "row.h"
#include "rower.h"

/**
 * A Rower with a purpose of printing every String with a length greater than 8
 */
class printStringRower : public Rower {
public:

    printStringRower() {
    }

    ~printStringRower() {
    }

    //If the row contains a String with a length greater than 7, prints that String
    bool accept(Row& r) {
        bool intFlag = false;
        for (int i = 0; i < r.width(); i++) {
            if (r.col_type(i) == 'S') {
                if (r.get_string(i)->size() > 8) {
                    cout << r.get_string(i)->c_str() << endl;
                }
            }
        }
        return intFlag;
    }

    /** Once traversal of the data frame is complete the rowers that were
        split off will be joined.  There will be one join per split. The
        original object will be the last to be called join on. The join method
        is reponsible for cleaning up memory. */
    void join_delete(Rower* other) {
        delete other;
    }

    //Returns a new printStringRower
    Rower* clone() {
        return new printStringRower();
    }
};
