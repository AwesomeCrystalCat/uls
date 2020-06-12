NAME = uls

LIB = ./libmx/libmx.a

INC = ./inc/uls.h

HEAD = uls.h

SRCOUT = main.c \
	mx_check_perm.c \
	mx_parse_args.c \
	mx_data_init.c \
	mx_read_data.c \
	mx_set_mode.c \
	mx_setuser.c \
	mx_setgrp.c \
	mx_set_bsize.c \
	mx_set_time.c \
	mx_getstats.c \
	mx_files_count.c \
	mx_find_name_len.c \
	mx_read_dir.c \
	mx_get_win_size.c \
	mx_quick_elem_sort.c \
	mx_dir_parse.c \
	mx_print_err.c \
	mx_prior_all.c \
	mx_switch_flags.c \
	mx_print_files.c \
	mx_print_dirs.c \
	mx_print_colored.c \
	mx_output_l.c \
	mx_output_1.c \
	mx_output_x.c \
	mx_output_c.c \
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
	mx_print_fname.c \
	mx_recursion.c \
	mx_printer.c \
	mx_itoa.c \
	mx_print_spaces.c \
	mx_print_is.c \
	mx_output_file.c \
	mx_output_file_x.c \
	mx_print_total.c \
	mx_print_link.c \
	mx_denied_error.c \
	mx_l_link.c \
	mx_l_uid.c \
	mx_l_gid.c \
	mx_l_size.c \
	mx_p_xattr.c \
	mx_set_prior_1.c \
	mx_big_destroyer.c \
	mx_write_total.c \

SRCS = $(addprefix ./src/, $(SRCOUT))

OBJOUT = $(SRCOUT:%.c=%.o)

CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install clean

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
