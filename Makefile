NAME		=	codingame.cpp
BIN			=	codingame
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -MMD
SRC			=	main.cpp SeaBedSecurity.cpp
INC_FILE	=	header.hpp SeaBedSecurity.hpp
INC			=	-I ${INC_PATH}
INC_PATH	=	./inc/
SRC_PATH	=	./src/
OBJ_PATH	=	./obj/
OBJ			=	${addprefix ${OBJ_PATH}, ${SRC:.cpp=.o}}
DEP			=	${OBJ:.o=.d}

${NAME}:${addprefix ${INC_PATH}, ${INC_FILE}} ${addprefix ${SRC_PATH}, ${SRC}}
	@cat $^ | grep -v '#\s*include\s*"' > ${NAME}
	make ${BIN}
	@echo "Created merged file"

${BIN}:${OBJ}
	${CPP} ${CPPFLAGS} $^ -o ${BIN} ${INC}

${OBJ_PATH}:
	mkdir -p ${OBJ_PATH}

${OBJ_PATH}%.o:${SRC_PATH}%.cpp
	@mkdir -p ${dir $@}
	${CPP} ${CPPFLAGS} -c $< -o $@ ${INC}

all:${NAME}

clean:
	rm -rf ${OBJ_PATH} ${BIN} .vscode

fclean:clean
	rm -rf ${NAME}

re:fclean
	make all

.PHONY: all clean fclean re

-include ${DEP}
