#Compilateur
CC = g++
#Falgs du compilateur
CCFLAGS = -Wall -pedantic -ansi -std=c++11 -DMAP -g

#Interfaces
DEPS_H = $(wildcard *.h)
#Fichiers de réalisation
DEPS_CPP = $(wildcard *.cpp)
#Fichiers binaires
OBJS = $(DEPS_CPP:.cpp=.o)
#Nom de l'éxécutable
EXE = main

$(EXE) : $(OBJS)
	@echo ">>> Edition des liens de <$@>"
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o : %.cpp $(DEPS_H)
	@echo ">>> Compilation de <$<>"
	$(CC) $(CCFLAGS) -c $<

clean:
	@echo "Netoyage des binaires et executables"
	@rm -f $(OBJS)
	@rm -f $(EXE)
