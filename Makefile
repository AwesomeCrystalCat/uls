NAME = uls

LIB = ./libmx/libmx.a

INC = ./inc/uls.h

HEAD = uls.h

SRCOUT = main.c \
	mx_parse_args.c \
	mx_print_error.c \
	mx_read_flags.c \
	mx_uls.c \
	mx_quick_cmp_sort.c \
	mx_set_mode.c \
	mx_setuser.c \
	mx_setgrp.c \
	mx_set_bsize.c \
	mx_set_time.c \
	mx_getstats.c \
	mx_files_count.c \
	mx_strnew.c \
	mx_strcmp.c \
	mx_strcpy.c \
	mx_strdup.c \
	mx_strjoin.c \
	mx_strlen.c \
	mx_strncpy.c \
	mx_strndup.c \
	itoa.c \

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
