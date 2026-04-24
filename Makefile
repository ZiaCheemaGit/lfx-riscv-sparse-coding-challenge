C_FLAGS += -Iinclude

C_SRCS += src/sparse.c

all:
	gcc challenge.c $(C_SRCS) $(C_FLAGS) -lm -o run.o

