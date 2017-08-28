CC=g++
CPPFLAGS = -std=c++11 -I. -g
DEPS = family.h hashtable.h linkedlist.h
OBJ = family.o linkedlist.o hashtable.o housinghelper.o familymgr.o
EXE = housinghelper
ARGS = familydata.txt

%.o: %c $(DEPS)
	$(CC) $(CPPFLAGS) -c -o $@ 

housinghelper: $(OBJ)
	$(CC) $(CPPFLAGS) -o $(EXE) $^

e: $(OBJ)
	$(CC) $(CPPFLAGS) -o $(EXE) $^
	clear
	clear
	rm -f *.o
	rm -f testfamily
	rm -f testlinkedlist
	rm -f testhashtable
	valgrind --leak-check=yes ./$(EXE) $(ARGS)
	diff assigned.txt expected.txt > diffout.txt	

testfamily: family.o testfamily.o
	$(CC) $(CPPFLAGS) -o $@ $^
	valgrind --leak-check=yes ./$@

testlinkedlist: family.o linkedlist.o testlinkedlist.o
	$(CC) $(CPPFLAGS) -o $@ $^
	valgrind --leak-check=yes ./$@

testhashtable: family.o hashtable.o linkedlist.o testhashtable.o
	$(CC) $(CPPFLAGS) -o $@ $^
	valgrind --leak-check=yes ./$@

generate: generate.o family.o
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	clear
	clear
	rm -f *.o
	rm -f $(EXE)
	rm -f testfamily
	rm -f testlinkedlist
	rm -f testhashtable
