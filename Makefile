NAME = uls

LIB = ./libmx/libmx.a

INC = ./inc/header.h

HEAD = header.h

SRCS = ./src/main.c \

SRCOUT = main.c \

OBJS = ./obj/main.o \

OBJOUT = main.o \

CFLAG = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install

install:
	@make install -C libmx
	@cp $(SRCS) .
	@cp $(INC) .
	@cp $(LIB) .
	@clang $(CFLAGS) -c $(SRCOUT) -I $(HEAD)
	@clang $(CFLAGS) $(LIB) $(OBJOUT) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJOUT) ./obj

clean:
	@rm -rf $(OBJOUT) $(SRCOUT) $(HEAD) obj
	@make uninstall -C libmx

uninstall: clean
	@make clean -C libmx
	@rm -rf $(NAME)
	@rm -rf libmx.a

reinstall: uninstall install