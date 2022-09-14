CC		= g++
#FLAGS	= -Wall -Wextra -Werror -std=c++98
FLAGS	= -g -Wall -Wextra

EXT		= .out
RM		= rm -rf

NAME		= 	containers
NAME_EXT	= 	${NAME}${EXT}

S		=	src
O		=	obj

SRCS	=	main.cpp

SRCS	:=	$(foreach file,$(SRCS),$S/$(file))

OBJS	= ${SRCS:$S/%.cpp=$O/%.o}
DEP		= ${OBJS:$O/%.o=$O/%.d}

all		: ${NAME_EXT}

${NAME_EXT}	:	${OBJS}
	${CC} ${FLAGS} $^ -o $@

$O		:
	@mkdir $@

$O/%.o		:	$S/%.cpp | $O
	${CC} ${FLAGS} -MMD -c $< -o $@

-include ${DEP}

#!--DEBUG

ARGS	= test 5 7

run		:	${NAME_EXT}
	@echo
	@./$^ ${ARGS}

debug	:	${NAME_EXT}
	@lldb -- ./$^$ ${ARGS}

leaks	:	${NAME_EXT}
	@leaks --atExit -- ./$^  ${ARGS}

norm	:
	cpplint ${SRCS}

#TEST_F	= -g -D COUNT=100
TEST_F	= -g

tests	: ${OBJS}
	${CC} ${TEST_F} src/test_orig.cpp -o test_orig
	time ./test_orig 0 > test_orig.log || echo err
	${CC} ${TEST_F} src/test_ft.cpp -o test_ft
	time ./test_ft 0 > test_ft.log  || echo err
	diff test_ft.log test_orig.log

#!--DEBUG

clean	:
	${RM} $O

fclean	: clean
	${RM} ${NAME_EXT}

re		: fclean all

.PHONY : all clean fclean re norm run debug
