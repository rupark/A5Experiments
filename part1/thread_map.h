//
// Created by Kate Rupar on 2/20/20.
//

#ifndef A5_THREAD_MAP_H
#define A5_THREAD_MAP_H

#endif //A5_THREAD_MAP_H

#include "thread.h"
#include "rower.h"
#include "column.h"

/**
 * Represents a Thread which Maps a Rower over a DataFrame
 */
class Thread_Map : public Thread {
public:
    Column** columns;
    Rower rower;
    Schema schema;
    size_t begin; // begin inclusive
    size_t end; // end exclusive

    Thread_Map(Rower &r, Column** c, Schema& s, size_t begin, size_t end) {
        this->columns = c;
        rower = r;
        schema = s;
        this->begin = begin;
        this->end = end;
    }

    ~Thread_Map() {
        delete[] columns;
    }

    /** Creates rows from this Threads columns and passes each Row to the Rower's accept method */
    void run() {
        Row* row = new Row(schema);
        for (size_t i = this->begin; i < this->end; i++) {

            for (size_t j = 0; j < row->width(); j++) {
                switch (schema.col_type(j)) {
                    case 'I':
                        row->set(j, *columns[j]->as_int()->get(i));
                        break;
                    case 'B':
                        row->set(j, *columns[j]->as_bool()->get(i));
                        break;
                    case 'S':
                        row->set(j, columns[j]->as_string()->get(i));
                        break;
                    case 'F':
                        row->set(j, *columns[j]->as_float()->get(i));

                        break;
                }
            }

            rower.accept(*row);
        }
    }

};