#Compilateur
CC = g++
#Flags du compilateur
CCFLAGS = -Wall -pedantic -ansi -std=c++11 -DMAP -g

#librairie
LIBS=-lcppunit

#Interfaces
DEPS_H = $(wildcard *.h)
#Fichiers de réalisation
DEPS_CPP = $(wildcard *.cpp)
#Fichiers binaires
OBJS = $(DEPS_CPP:.cpp=.o)
#Nom de l'éxécutable
EXE = TestController

#En fonction de l'OS
ifdef OS
   RM = del /Q
   FixPath = $(subst /,\,$1)
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
      FixPath = $1
   endif
endif


$(EXE) : $(OBJS)
	@echo ">>> Edition des liens de <$@>"
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

%.o : %.cpp $(DEPS_H)
	@echo ">>> Compilation de <$<>"
	$(CC) $(CCFLAGS) -c $< $(LIBS)

clean:
	@echo "Nettoyage des binaires et executables"

	$(RM) $(OBJS)
	$(RM) $(EXE)

cleanbin:
	@echo "Nettoyage des binaires"
	@rm -f $(OBJS)
