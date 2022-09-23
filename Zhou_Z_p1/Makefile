COURSE = cs373
SEMESTER = fall2022
CP_NUMBER = 1
LASTNAME = Zhou
EXE = zhou_p1

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = $(LASTNAME)_$(firstinitial)_p$(CP_NUMBER).tar

FLAGS = -g -O3
CC = g++
BIN = bin
OBJ = obj

# Store executables in a subdirectory
all: $(EXE)

$(EXE): main.o Help.o State.o NFA.o Transition.o
	$(CC) $(FLAGS) main.o Help.o State.o NFA.o Transition.o -o $@

# OBJECTS BELOW
main.o: main.cpp Help.h Parser.h NFA.h State.h Transition.h
	$(CC) $(FLAGS) -c $< -o $@

Help.o: Help.cpp Help.h Parser.h
	$(CC) $(FLAGS) -c $< -o $@

NFA.o: NFA.cpp NFA.h State.h Transition.h
	$(CC) $(FLAGS) -c $< -o $@

State.o: State.cpp State.h Transition.h
	$(CC) $(FLAGS) -c $< -o $@

Transition.o: Transition.cpp Transition.h State.h
	$(CC) $(FLAGS) -c $< -o $@


# Run make tar to build a .tar.gz file appropriate for uploading to Brightspace
tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f /*.o $(EXE) *.tar.gz
	rm -f *.o 