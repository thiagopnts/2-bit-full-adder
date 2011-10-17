#include "systemc.h"
#include "or2.h"
#include "and.h"
#include "xor.h"

SC_MODULE(adder2) {
    sc_in<bool> A1, A2, B1, B2, Cin;
    sc_out<bool> Cout, Sum1, Sum2;
    sc_signal<bool> S1, S2, S3, S4, S5, S6, S7;
    and2 n1,n2,n3,n4;
    xor2 x1,x2,x3,x4;
    or2 o1, o2;
    // Cout = (((Cin & (A0 ^ B0)) | (A0 & B0)) & (A1 ^ B1)) | (A1 & B1)
    // S0 = Cin ^ (A0 ^ B0)
    // S1 = ((Cin & (A0 ^ B0)) | (A0 & B0)) ^ (A1 ^ B1)
    SC_CTOR(adder2): n1("N1"), n2("N2"), n3("N3"), n4("N4"), x1("X1"), x2("X2"), x3("X3"), x4("X4"), o1("O1"), o2("O2") {

        x1.A(A2); x1.B(B2); x1.F(S1);
        x2.A(A1); x2.B(B1); x2.F(S3);
        x3.A(S7); x3.B(S1); x3.F(Sum2);
        x4.A(Cin); x4.B(S3); x4.F(Sum1);

        n1.A(A2); n1.B(B2); n1.F(S2);
        n2.A(A1); n2.B(B1); n2.F(S4);
        n3.A(S7); n3.B(S1); n3.F(S5);
        n4.A(Cin); n4.B(S3); n4.F(S6);

        o1.A(S5); o1.B(S2); o1.F(Cout);
        o2.A(S6); o2.B(S4); o2.F(S7);


/*        x1.A(A2); x1.B(B2); x1.F(S1);
        n1.A(A2); n1.B(B2); n1.F(S2);
        x2.A(A1); x2.B(B1); x2.F(S3);
        n2.A(A1); n2.B(B1); n2.F(S4);

        n3.A(Cin); n3.B(S3); n3.F(S5);
        n4.A(S6); n4.B(S1); n4.F(S7);

        x4.A(S6); x4.B(S1); x4.F(Sum2);
        o2.A(S7); o2.B(S2); o2.F(Cout);
        x3.A(Cin); x3.B(S3); x3.F(Sum1);
        o1.A(S5); o1.B(S4); o1.F(S6);*/

    }

};
