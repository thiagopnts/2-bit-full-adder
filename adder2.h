#include "systemc.h"

SC_MODULE(adder2) {
    sc_in<bool> A1, A2, B1, B2, Cin;
    sc_out<bool> Cout, Sum1, Sum2;

    void do_add() {
        Cout = (Cin & (A1 ^ B1) | (A1 & B1) & (A2 ^ B2) | (A2 & B2));

        Sum1 = (Cin ^ (A1 ^ B1));

        Sum2 = (Cin & (A1 ^ B1)) | (A1 & B1) ^ (A2 ^ B2);
    }

    SC_CTOR(adder2) {
        SC_METHOD(do_add);
        sensitive << A1 << A2 << B1 << B2 << Cin;
    }

};
