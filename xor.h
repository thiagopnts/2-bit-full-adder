#include "systemc.h"

SC_MODULE(xor2) {
    sc_in<bool> A, B;
    sc_out<bool> F;

    void do_xor() {
        F.write((A.read() ^ B.read()));
    }

    SC_CTOR(xor2) {
        SC_METHOD(do_xor);
        sensitive << A << B;
    }
};
