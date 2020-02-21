//
// Created by Kate Rupar on 2/20/20.
//
#include "modified_dataframe.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

void test() {
    /**
     * Making 2 Schema and 2 DataFrames
     */
    Schema s("SSSSIISFFI");
    DataFrame df(s);
    Schema s2("SSSSIISFFI");
    DataFrame df2(s2);

    /**
     * Making a Row
     */
    Row  r(df.get_schema());

    long lineNumber = 1000000;

    static const char filename[] = "data.txt";
    FILE *file = fopen(filename, "r");

    int count = 0;
    if ( file != NULL )
    {
        char line[256]; /* or other suitable maximum line size */
        while (fgets(line, sizeof line, file) != NULL) /* read a line */
        {
            if (count >= lineNumber)
            {
                break;
            }
            else
            {
                int i = 0;
                char *p = strtok (line, ",");
                char *array[10];

                while (p != NULL)
                {
                    array[i++] = p;
                    p = strtok (NULL, ",");
                }

                r.set(0, new String(array[0]));
                r.set(1, new String(array[1]));
                r.set(2, new String(array[2]));
                r.set(3, new String(array[3]));
                r.set(4, (int)atoi(array[4]));
                r.set(5, (int)atoi(array[5]));
                r.set(6, new String(array[6]));
                r.set(7, (float)atof(array[7]));
                r.set(8, (float)atof(array[8]));
                r.set(9, (int)atoi(array[9]));

                df.add_row(r);
                df2.add_row(r);

                count++;
            }
        }
        fclose(file);
    }
    else
    {
        //file doesn't exist
    }

    sumRower& rower = *new sumRower();

    cout << "=============sum============" << endl;
    //Speed of pmapg
    clock_t t = clock();
    df.pmap(rower);
    double thread_time = (clock() - t);
    //Speed of map
    clock_t t2 = clock();
    df2.map(rower);
    double normal_time = (clock() - t2);
    cout << thread_time << endl;
    cout << normal_time << endl;
    cout << rower.sum << endl;


    cout << "=============to 4============" << endl;
    changeIntsRower& rower2 = *new changeIntsRower();
    clock_t t3 = clock();
    df.pmap(rower2);
    double thread_time2 = (clock() - t3);
    //Speed of map
    clock_t t4 = clock();
    df2.map(rower2);
    double normal_time2 = (clock() - t4);
    cout<< "Thread:" << endl;
    cout << thread_time2 << endl;
    cout<< "Normal:" << endl;
    cout << normal_time2 << endl;
    cout << df2.get_int(4, 1);

    exit(0);
}

int main() {
    test();
}