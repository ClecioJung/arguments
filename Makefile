# ----------------------------------------
# Project options
# ----------------------------------------

NAME := arguments

EXAMPLE := example

# Flags for compiler
CFLAGS := -W -Wall -Wextra -pedantic -Wconversion \
          -Werror -flto -std=c89 -O2

# ----------------------------------------
# Compilation and linking rules
# ----------------------------------------

all: $(NAME).a

$(NAME).a: $(NAME).o
	$(AR) rcs $@ $(filter %.o,$^)

$(NAME).o: $(NAME).c $(NAME).h
	$(CC) -c $(filter %.c %.s %.o %.a,$^) -o $@ $(CFLAGS)

$(EXAMPLE): $(EXAMPLE).c $(NAME).a $(NAME).h
	$(CC) $(filter %.c %.s %.o %.a,$^) -o $@ $(CFLAGS)

# ----------------------------------------
# Script rules
# ----------------------------------------

clean:
	$(RM) $(EXAMPLE) *.a *.o

remade: clean all

.PHONY: all clean remade

# ----------------------------------------
