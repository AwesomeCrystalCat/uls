NAME = uls

LIB = ./libmx/libmx.a

INC = ./inc/uls.h

HEAD = uls.h
<<<<<<< HEAD

SRCS = ./src/main.c \
=======
>>>>>>> fe2e4b2900d5b50c3aa32d615152f86c8fa2f0a2

SRCOUT = main.c \
	mx_parse_args.c \
	mx_print_error.c \
	mx_read_flags.c \
	mx_uls.c \

SRCS = $(addprefix ./src/, $(SRCOUT))

OBJOUT = $(SRCOUT:%.c=%.o)

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