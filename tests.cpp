//
// Created by Kate Rupar on 2/20/20.
//
#include "modified_dataframe.h"
#include <time.h>

void test() {
    /**
     * Making 2 Schema and 2 DataFrames
     */
    Schema s("FISB");
    DataFrame df(s);
    Schema s2("FISB");
    DataFrame df2(s2);

    /**
     * Making a Row
     */
    Row  r(df.get_schema());
    /**
     * Populating the DataFrames
     */
    for(size_t i = 0; i <  50; i++) {
        r.set(0,(float)3.0);
        r.set(1,(int)i);
        r.set(2,new String("what"));
        r.set(3, (bool)true);
        df.add_row(r);
    }

    /**
     * Making a Row
    */
    Row  r2(df2.get_schema());
    for(size_t i = 0; i <  50; i++) {
        r2.set(0,(float)3.0);
        r2.set(1,(int)i);
        r2.set(2,new String("what"));
        r2.set(3, (bool)true);
        df2.add_row(r2);
    }

    sumRower& rower = *new sumRower();

    //Speed of pmapg
    clock_t t = clock();
    df.pmap(rower);
    double thread_time = (clock() - t);
    cout << "here" << endl;
    //Speed of map
    clock_t t2 = clock();
    df2.map(rower);
    double normal_time = (clock() - t2);
    cout << thread_time << endl;
    cout << normal_time << endl;
    cout << rower.sum << endl;

//
//    //Making sure Rower changed the dfs
//    for(size_t i = 0; i <  50; i++) {
//        GT_EQUALS(df.get_int(1, i), 4);
//        GT_EQUALS(df2.get_int(1, i), 4);
//    }

    exit(0);
}

int main() {
    test();
}