NAME = uls

LIB = ./libmx/libmx.a

INC = ./inc/uls.h

HEAD = uls.h

SRCOUT = main.c \
	mx_parse_args.c \
	mx_data_init.c \
	mx_read_data.c \
	mx_read_flags.c \
	mx_quick_cmp_sort.c \
	mx_set_mode.c \
	mx_setuser.c \
	mx_setgrp.c \
	mx_set_bsize.c \
	mx_set_time.c \
	mx_getstats.c \
	mx_files_count.c \
	mx_set_stats.c \
	mx_find_name_len.c \
	mx_read_dir.c \
	mx_get_win_size.c \
	mx_quick_elem_sort.c \
	mx_dir_parse.c \
	mx_print_err.c \
	mx_prior_all.c \
	mx_switch_flags.c \
	mx_get_real_cols.c \
	mx_print_files.c \
	mx_print_dirs.c \
	mx_print_colored.c \
	mx_output_l.c \
	mx_output_1.c \
	mx_output_x.c \
	mx_print_errors.c \
	mx_errors_array.c \
	mx_output_m.c \
	mx_cols_and_rows.c \
	mx_get_bsize_num.c \
	mx_get_inode_num.c \
	mx_sorting.c \
	mx_quick_rev_elem_sort.c \
	mx_quick_size_sort.c \
	mx_quick_rev_size_sort.c \
	mx_get_path.c \
	mx_quick_time_sort.c \
	mx_quick_rev_time_sort.c \
	mx_printer.c \
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
