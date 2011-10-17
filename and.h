#include "systemc.h"

SC_MODULE(and2) {
    sc_in<bool> A,B;
    sc_out<bool> F;

    void do_and() {
        F.write((A.read() & B.read()));
    }

    SC_CTOR(and2) {
        SC_METHOD(do_and);
        sensitive << A << B;
    }
};
