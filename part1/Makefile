build: tests.o bool.h boolcol.h printStringRower.h column.h fielder.h float.h floatcol.h helper.h intcol.h integer.h modified_dataframe.h object.h row.h rower.h schema.h string.h stringcol.h sumRower.h thread.h thread_map.h
	clang++ --std=c++11 bool.h boolcol.h printStringRower.h column.h fielder.h float.h floatcol.h helper.h intcol.h integer.h modified_dataframe.h object.h row.h rower.h schema.h string.h stringcol.h sumRower.h thread.h thread_map.h tests.o

tests.o:
	clang++ --std=c++11 -c bench.cpp -o tests.o

clean:
	rm -rf file
	rm -rf data.txt
	rm -rf __MACOSX
	rm *.h.gch *.o a.out

run:
	git clone https://github.com/rupark/file.git
	unzip file/data.txt.zip
	./a.out
	rm -rf file
	rm -rf __MACOSX
	rm -rf data.txt
	rm *.h.gch *.o a.out
