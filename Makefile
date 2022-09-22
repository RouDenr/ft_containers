CC		= c++
#FLAGS	= -Wall -Wextra -Werror -std=c++98
#FLAGS	= -g -Wall -Wextra
FLAGS	= -g

EXT		= .out
RM		= rm -rf

NAME		= 	containers
NAME_EXT	= 	${NAME}${EXT}

S		=	src
O		=	obj

SRCS		=	main_ft.cpp
SRCS_std	=	main_orig.cpp

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

ARGS	= 0

run		:	${NAME_EXT}
	@echo
	@./$^  ${ARGS}

debug	:	${NAME_EXT}
	@lldb -- ./$^ ${ARGS}

leaks	:	${NAME_EXT}
	@leaks --atExit -- ./$^  ${ARGS}

norm	:
	cpplint ${SRCS}

NAME_TEST	= main_ft
#TEST_F		= -g -D COUNT=100
TEST_F		= -g
TEST_ARG	= 1

all_tests : ${NAME_TEST}

${NAME_TEST} : ${OBJS}
	${CC} ${TEST_F} src/main_orig.cpp -o test_orig
	${CC} ${TEST_F} src/main_ft.cpp -o test_ft

tests	: ${NAME_TEST}
	time ./test_orig ${TEST_ARG} > test_orig.log || echo err
	time ./test_ft ${TEST_ARG} > test_ft.log  || echo err
	diff test_ft.log test_orig.log

#!--DEBUG

clean	:
	${RM} $O

fclean	: clean
	${RM} ${NAME_EXT}

re		: fclean all

.PHONY : all clean fclean re norm run debug
