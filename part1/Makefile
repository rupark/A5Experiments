compile: tests.o bool.h boolcol.h changeIntsRower.h column.h fielder.h float.h floatcol.h helper.h intcol.h integer.h modified_dataframe.h object.h row.h rower.h schema.h string.h stringcol.h sumRower.h thread.h thread_map.h
	clang++ --std=c++11 bool.h boolcol.h changeIntsRower.h column.h fielder.h float.h floatcol.h helper.h intcol.h integer.h modified_dataframe.h object.h row.h rower.h schema.h string.h stringcol.h sumRower.h thread.h thread_map.h tests.o

tests.o:
	clang++ --std=c++11 -c tests.cpp -o tests.o

clean:
	rm *.h.gch *.o a.out *.gch.tmp
