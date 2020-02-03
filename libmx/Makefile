NAME = libmx.a

SRCS = src/mx_printchar.c \
	src/mx_printstr.c \
	src/mx_strlen.c \
	src/mx_printint.c \
	src/mx_strcmp.c \
	src/mx_strnew.c \
	src/mx_strcpy.c \
	src/mx_strdup.c \
	src/mx_print_strarr.c \
	src/mx_strdel.c \
	src/mx_del_strarr.c \
	src/mx_strndup.c \
	src/mx_strncpy.c \
	src/mx_count_words.c \
	src/mx_strsplit.c \
	src/mx_file_to_str.c \
	

OBJ = mx_printchar.o \
	mx_printstr.o \
	mx_strlen.o \
	mx_printint.o \
	mx_strcmp.o \
	mx_strnew.o \
	mx_strcpy.o \
	mx_strdup.o \
	mx_print_strarr.o \
	mx_strdel.o \
	mx_del_strarr.o \
	mx_strndup.o \
	mx_strncpy.o \
	mx_count_words.o \
	mx_strsplit.o \
	mx_file_to_str.o \
	

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install

install:
	@clang $(CFLAGS) $(SRCS) -c $(SRCS)
	@mkdir -p obj
	@cp $(OBJ) obj/.
	@ar -rc $(NAME) $(OBJ)
	@rm -rf $(OBJ)

uninstall: clean
	@rm -rf $(NAME)

clean:
	@rm -rf obj

reinstall: uninstall install