cmake_minimum_required(VERSION 3.6.2)
#set(CMAKE_C_COMPILER /cygdrive/s/program_files/cygwin/bin/gcc.exe CACHE PATH "" FORCE)
#set(CMAKE_CXX_COMPILER /cygdrive/s/program_files/cygwin/bin/g++.exe CACHE PATH "" FORCE)
project(libft_run C)
set(CMAKE_C_STANDARD 90)
include_directories(.)
include_directories(headers)

#--------------LIB LINK EXAMPLE---------------------
#add_executable(<exe_name> sorce1 source2)
#find_library(FT ft libft)
#target_link_libraries(<exe_name> LINK_PUBLIC ${FT})
#---------------------------------------------------

#add_library(libft.a
include_directories(libft/includes)
add_executable(push_relabel
        src/main.c
		src/array.c
        src/matrix.c
        src/lem_in_read.c
        src/select_paths.c
        src/push_relabel.c
		src/find_paths.c
		src/expand_junctions.c
		src/ft_trnsfr_paths.c
		src/suurballe.c
		src/bellman_ford.c
        ft_read_map.c
        ft_crt_map.c
		src/lem_in_output.c

        libft/ft_memset.c
        libft/ft_bzero.c
        libft/ft_memcpy.c
        libft/ft_memccpy.c
        libft/ft_memcmp.c
        libft/ft_memmove.c
        libft/ft_memchr.c
        libft/ft_strlen.c
        libft/ft_strcpy.c
        libft/ft_strdup.c
        libft/ft_strncpy.c
        libft/ft_strcat.c
        libft/ft_strncat.c
        libft/ft_strlcat.c
        libft/ft_strchr.c
        libft/ft_strrchr.c
        libft/ft_strstr.c
        libft/ft_strnstr.c
        libft/ft_strcmp.c
        libft/ft_strncmp.c
        libft/ft_atoi.c
        libft/ft_isalpha.c
        libft/ft_isdigit.c
        libft/ft_isalnum.c
        libft/ft_isascii.c
        libft/ft_isprint.c
        libft/ft_toupper.c
        libft/ft_tolower.c
        libft/ft_memalloc.c
        libft/ft_memdel.c
        libft/ft_strnew.c
        libft/ft_strdel.c
        libft/ft_strclr.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strequ.c
        libft/ft_strnequ.c
        libft/ft_strsub.c
        libft/ft_strjoin.c
        libft/ft_strtrim.c
        libft/ft_putchar.c
        libft/ft_putstr.c
        libft/ft_putendl.c
        libft/ft_putnbr.c
        libft/ft_putchar_fd.c
        libft/ft_putstr_fd.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr_fd.c
        libft/ft_strcmp.c
        libft/ft_strncmp.c
        libft/ft_itoa.c
        libft/ft_strsplit.c
        libft/ft_lstnew.c
        libft/ft_lstdelone.c
        libft/ft_lstdel.c
        libft/ft_lstadd.c
        libft/ft_lstiter.c
        libft/ft_lstmap.c
        libft/ft_get_next_line.c
        libft/ft_strjoin_free.c
		libft/ft_realloc.c
        )

#        libft.ksticks/src/string/ft_atoi.c
#        libft.ksticks/src/string/ft_bzero.c
#        libft.ksticks/src/string/ft_isalnum.c
#        libft.ksticks/src/string/ft_isalpha.c
#        libft.ksticks/src/string/ft_isascii.c
#        libft.ksticks/src/string/ft_isdigit.c
#        libft.ksticks/src/string/ft_isprint.c
#        libft.ksticks/src/string/ft_memalloc.c
#        libft.ksticks/src/string/ft_memccpy.c
#        libft.ksticks/src/string/ft_memchr.c
#        libft.ksticks/src/string/ft_memcmp.c
#        libft.ksticks/src/string/ft_memcpy.c
#        libft.ksticks/src/string/ft_memdel.c
#        libft.ksticks/src/string/ft_memmove.c
#        libft.ksticks/src/string/ft_memset.c
#        libft.ksticks/src/string/ft_putchar.c
#        libft.ksticks/src/string/ft_putchar_fd.c
#        libft.ksticks/src/string/ft_putendl.c
#        libft.ksticks/src/string/ft_putendl_fd.c
#        libft.ksticks/src/string/ft_putnbr.c
#        libft.ksticks/src/string/ft_putnbr_fd.c
#        libft.ksticks/src/string/ft_putstr.c
#        libft.ksticks/src/string/ft_putstr_fd.c
#        libft.ksticks/src/string/ft_strcat.c
#        libft.ksticks/src/string/ft_strchr.c
#        libft.ksticks/src/string/ft_strclr.c
#        libft.ksticks/src/string/ft_strcmp.c
#        libft.ksticks/src/string/ft_strcpy.c
#        libft.ksticks/src/string/ft_strdel.c
#        libft.ksticks/src/string/ft_strdup.c
#        libft.ksticks/src/string/ft_strequ.c
#        libft.ksticks/src/string/ft_striter.c
#        libft.ksticks/src/string/ft_striteri.c
#        libft.ksticks/src/string/ft_strjoin.c
#        libft.ksticks/src/string/ft_strlcat.c
#        libft.ksticks/src/string/ft_strlcpy.c
#        libft.ksticks/src/string/ft_strlen.c
#        libft.ksticks/src/string/ft_strmap.c
#        libft.ksticks/src/string/ft_strmapi.c
#        libft.ksticks/src/string/ft_strncat.c
#        libft.ksticks/src/string/ft_strncmp.c
#        libft.ksticks/src/string/ft_strncpy.c
#        libft.ksticks/src/string/ft_strnequ.c
#        libft.ksticks/src/string/ft_strnew.c
#        libft.ksticks/src/string/ft_strnstr.c
#        libft.ksticks/src/string/ft_strrchr.c
#        libft.ksticks/src/string/ft_strsplit.c
#        libft.ksticks/src/string/ft_strstr.c
#        libft.ksticks/src/string/ft_strsub.c
#        libft.ksticks/src/string/ft_strtrim.c
#        libft.ksticks/src/string/ft_tolower.c
#        libft.ksticks/src/string/ft_toupper.c
#        libft.ksticks/src/string/ft_strrev.c
#        libft.ksticks/src/string/ft_startswith.c
#
#        libft.ksticks/src/format/ft_itoa.c
#        libft.ksticks/src/format/ft_ultoa.c
#        libft.ksticks/src/format/ft_ftoa.c
#        libft.ksticks/src/format/ft_ftobin.c
#
#        libft.ksticks/src/list/ft_lstadd.c
#        libft.ksticks/src/list/ft_lstaddend.c
#        libft.ksticks/src/list/ft_lstdel.c
#        libft.ksticks/src/list/ft_lstdelone.c
#        libft.ksticks/src/list/ft_lstiter.c
#        libft.ksticks/src/list/ft_lstmap.c
#        libft.ksticks/src/list/ft_lstnew.c
#
#        libft.ksticks/src/math/ft_sqrt.c
#        libft.ksticks/src/math/ft_pow.c
#        libft.ksticks/src/math/ft_abs.c
#        libft.ksticks/src/math/ft_trig.c
#        libft.ksticks/src/math/ft_log.c
#
#        libft.ksticks/src/linalg/matrix.c
#        libft.ksticks/src/linalg/matrix_invert.c
#        libft.ksticks/src/linalg/vector.c
#
#        libft.ksticks/src/hash_table/hash_table.c
#        libft.ksticks/src/hash_table/hash.c
#
#        libft.ksticks/src/ft_alloc.c
#        libft.ksticks/src/ft_swap.c
#        libft.ksticks/src/get_next_line.c
#        libft.ksticks/src/t_buff.c
#        libft.ksticks/src/endian.c
#        libft.ksticks/src/ft_error_exit.c
#
#        libft.ksticks/src/printf/ft_printf.c
#        libft.ksticks/src/printf/spec_parse.c
#        libft.ksticks/src/printf/conversion.c
#        libft.ksticks/src/printf/convert.c
#        libft.ksticks/src/printf/apply_fw.c
#        )
#target_link_libraries(libft_tests m)
