CC		= c++
#FLAGS	= -Wall -Wextra -Werror -std=c++98
FLAGS	= -g -Wall -Wextra -std=c++98

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

#!--DEBUG

clean	:
	${RM} $O

fclean	: clean
	${RM} ${NAME_EXT}

re		: fclean all

.PHONY : all clean fclean re norm run debug
