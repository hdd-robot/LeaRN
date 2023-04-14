CC = g++ -std=c++11
CFLAGS = -Wall  
EXEC_NAME = LearRN
INCLUDES =
LIBS = 
OBJ_FILES = main.o ll
INSTALL_DIR = /usr/bin

all : $(EXEC_NAME)

clean :
	rm -f *~
	rm -f $(EXEC_NAME) $(OBJ_FILES)
	rm -f *.o
	rm -f *.gch


$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o ../build/$(EXEC_NAME)  $(OBJ_FILES) 


%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

run :
	../build/LeaRN
