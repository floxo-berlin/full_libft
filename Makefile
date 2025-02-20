# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFTDIR = libft
PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
ADDITIONAL_DIR = additional
OBJDIR = obj

# Source files
LIBFT_SRC = $(wildcard $(LIBFTDIR)/*.c)
PRINTF_SRC = $(wildcard $(PRINTF_DIR)/*.c)
GNL_SRC = $(wildcard $(GNL_DIR)/*.c)
ADDITIONAL_SRC = $(wildcard $(ADDITIONAL_DIR)/*.c)
SRCFILES = $(LIBFT_SRC) $(PRINTF_SRC) $(GNL_SRC) $(ADDITIONAL_SRC)

# Object files
OBJFILES = $(patsubst %.c, $(OBJDIR)/%.o, $(SRCFILES))

# Library name
LIBNAME = libft.a

# Targets
all: $(LIBNAME)

$(LIBNAME): $(OBJFILES)
	ar rcs $@ $^

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(LIBFTDIR) $(OBJDIR)/$(PRINTF_DIR) $(OBJDIR)/$(GNL_DIR) $(OBJDIR)/$(ADDITIONAL_DIR)
	$(CC) $(CFLAGS) -I$(LIBFTDIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -I$(ADDITIONAL_DIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re