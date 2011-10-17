all: SYSTEMC
	@g++ -m32 -I/Library/SystemC/Current/include -L/Library/SystemC/Current/lib-macosx -lsystemc -lm main.cpp -o main
	@./main

SYSTEMC:
	@g++ -c and.h xor.h stim.h mon.h or2.h adder2.h -m32 -I/Library/SystemC/Current/include -L/Library/SystemC/Current/lib-macosx

