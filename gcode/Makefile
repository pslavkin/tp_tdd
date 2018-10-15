CC=g++
LIBS=
SRC_DIR=./src
EXE_DIR=./exe


_OBJ= \
		main.o\
		parser.o\
		uart.o\
		pos.o\

OBJ_DIR=./obj
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

_DEP = \
		 parser.h\
		 uart.h\
		 pos.h\

DEP_DIR=./src
DEP = $(patsubst %,$(DEP_DIR)/%,$(_DEP))


tdd: ${OBJ}
	${CC} -o ${EXE_DIR}/$@ $^ ${LIBS}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${DEP}
	${CC}  -g -c -o $@  $< -I${DEP_DIR} 

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp ${DEP}
	${CC}  -g -c -o $@  $< -I${DEP_DIR} 
clean:
	@rm -f ${EXES} ${OBJ_DIR}/*
