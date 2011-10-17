#include "systemc.h"

SC_MODULE(or2) {
    sc_in<bool> A,B;
    sc_out<bool> F;

    void do_or() {
        F.write((A.read() | B.read()));
    }

    SC_CTOR(or2) {
        SC_METHOD(do_or);
        sensitive << A << B;
    }
};
