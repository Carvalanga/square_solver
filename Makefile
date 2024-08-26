.PHONY: all

CFLAGS := -c -I headers -I headers -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
OBJECTS := square_solver_main_program.o square_solver.o solver.o input_output.o unit_test.o command_line_unit.o
DIROBJECTS := $(addprefix obj/, $(OBJECTS))

all: square.exe

square.exe : $(DIROBJECTS)
	g++ $(DIROBJECTS) -o square.exe

obj/%.o : src/%.cpp
	g++ $<  $(CFLAGS) -o $@

run:
	square.exe
