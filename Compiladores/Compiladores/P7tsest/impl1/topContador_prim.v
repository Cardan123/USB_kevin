// Verilog netlist produced by program LSE :  version Diamond (64-bit) 3.9.0.99.2
// Netlist written on Fri May 17 21:52:53 2019
//
// Verilog Description of module topContador
//

module topContador (indiv0, oscraw0, oscdiv0, clk0, c0, e0, s0);   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(9[8:19])
    input [3:0]indiv0;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(11[3:9])
    output oscraw0 /* synthesis .original_dir=IN_OUT */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(12[5:12])
    output oscdiv0 /* synthesis .original_dir=IN_OUT */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(13[8:15])
    input clk0;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(14[3:7])
    input [2:0]c0;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(15[3:5])
    input [3:0]e0;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(16[3:5])
    output [3:0]s0;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(17[3:5])
    
    wire oscraw0_c /* synthesis is_clock=1 */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(12[5:12])
    wire oscdiv0_c /* synthesis is_clock=1, SET_AS_NETWORK=oscdiv0_c */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(13[8:15])
    
    wire indiv0_c_3, indiv0_c_2, indiv0_c_1, indiv0_c_0, c0_c_2, c0_c_1, 
        c0_c_0, e0_c_3, e0_c_2, e0_c_1, e0_c_0, s0_c_3, s0_c_2, 
        s0_c_1, s0_c_0, VCC_net, GND_net;
    
    VHI i5 (.Z(VCC_net));
    contador REG00 (.s0_c_2(s0_c_2), .oscdiv0_c(oscdiv0_c), .e0_c_2(e0_c_2), 
            .c0_c_1(c0_c_1), .s0_c_1(s0_c_1), .s0_c_0(s0_c_0), .c0_c_0(c0_c_0), 
            .c0_c_2(c0_c_2), .s0_c_3(s0_c_3), .e0_c_3(e0_c_3), .e0_c_1(e0_c_1), 
            .e0_c_0(e0_c_0));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(28[9:17])
    OB oscraw0_pad (.I(oscraw0_c), .O(oscraw0));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(12[5:12])
    OB oscdiv0_pad (.I(oscdiv0_c), .O(oscdiv0));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(13[8:15])
    PUR PUR_INST (.PUR(VCC_net));
    defparam PUR_INST.RST_PULSE = 1;
    topdiv00 OS00 (.oscdiv0_c(oscdiv0_c), .GND_net(GND_net), .indiv0_c_2(indiv0_c_2), 
            .indiv0_c_3(indiv0_c_3), .indiv0_c_0(indiv0_c_0), .indiv0_c_1(indiv0_c_1), 
            .oscraw0_c(oscraw0_c));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(23[10:18])
    VLO i1 (.Z(GND_net));
    TSALL TSALL_INST (.TSALL(GND_net));
    GSR GSR_INST (.GSR(VCC_net));
    OB s0_pad_3 (.I(s0_c_3), .O(s0[3]));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(17[3:5])
    OB s0_pad_2 (.I(s0_c_2), .O(s0[2]));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(17[3:5])
    OB s0_pad_1 (.I(s0_c_1), .O(s0[1]));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(17[3:5])
    OB s0_pad_0 (.I(s0_c_0), .O(s0[0]));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(17[3:5])
    IB indiv0_pad_3 (.I(indiv0[3]), .O(indiv0_c_3));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(11[3:9])
    IB indiv0_pad_2 (.I(indiv0[2]), .O(indiv0_c_2));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(11[3:9])
    IB indiv0_pad_1 (.I(indiv0[1]), .O(indiv0_c_1));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(11[3:9])
    IB indiv0_pad_0 (.I(indiv0[0]), .O(indiv0_c_0));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(11[3:9])
    IB c0_pad_2 (.I(c0[2]), .O(c0_c_2));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(15[3:5])
    IB c0_pad_1 (.I(c0[1]), .O(c0_c_1));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(15[3:5])
    IB c0_pad_0 (.I(c0[0]), .O(c0_c_0));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(15[3:5])
    IB e0_pad_3 (.I(e0[3]), .O(e0_c_3));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(16[3:5])
    IB e0_pad_2 (.I(e0[2]), .O(e0_c_2));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(16[3:5])
    IB e0_pad_1 (.I(e0[1]), .O(e0_c_1));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(16[3:5])
    IB e0_pad_0 (.I(e0[0]), .O(e0_c_0));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(16[3:5])
    
endmodule
//
// Verilog Description of module contador
//

module contador (s0_c_2, oscdiv0_c, e0_c_2, c0_c_1, s0_c_1, s0_c_0, 
            c0_c_0, c0_c_2, s0_c_3, e0_c_3, e0_c_1, e0_c_0);
    output s0_c_2;
    input oscdiv0_c;
    input e0_c_2;
    input c0_c_1;
    output s0_c_1;
    output s0_c_0;
    input c0_c_0;
    input c0_c_2;
    output s0_c_3;
    input e0_c_3;
    input e0_c_1;
    input e0_c_0;
    
    wire oscdiv0_c /* synthesis is_clock=1, SET_AS_NETWORK=oscdiv0_c */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(13[8:15])
    
    wire oscdiv0_c_enable_4;
    wire [3:0]s_3__N_200;
    
    wire n1036, n1037, n477, n1034, n1033, n1035, n1021, n1018, 
        n1059, n975, n1044, n1022, n1019, n1020, n1011, n1043, 
        n4, n1046, n1045, n976, n1032;
    
    FD1P3AX s_i3 (.D(s_3__N_200[2]), .SP(oscdiv0_c_enable_4), .CK(oscdiv0_c), 
            .Q(s0_c_2)) /* synthesis LSE_LINE_FILE_ID=25, LSE_LCOL=9, LSE_RCOL=17, LSE_LLINE=28, LSE_RLINE=28 */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/cont.vhd(55[2] 146[11])
    defparam s_i3.GSR = "ENABLED";
    LUT4 n1036_bdd_3_lut (.A(n1036), .B(e0_c_2), .C(c0_c_1), .Z(n1037)) /* synthesis lut_function=(A (B+!(C))+!A (B (C))) */ ;
    defparam n1036_bdd_3_lut.init = 16'hcaca;
    LUT4 c_2__I_0_Mux_3_i1_4_lut_4_lut_4_lut (.A(s0_c_2), .B(s0_c_1), .C(s0_c_0), 
         .D(c0_c_0), .Z(n477)) /* synthesis lut_function=(A (B (C (D)))+!A !(B+(C+(D)))) */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/cont.vhd(79[4] 96[13])
    defparam c_2__I_0_Mux_3_i1_4_lut_4_lut_4_lut.init = 16'h8001;
    FD1P3AX s_i2 (.D(s_3__N_200[1]), .SP(oscdiv0_c_enable_4), .CK(oscdiv0_c), 
            .Q(s0_c_1)) /* synthesis LSE_LINE_FILE_ID=25, LSE_LCOL=9, LSE_RCOL=17, LSE_LLINE=28, LSE_RLINE=28 */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/cont.vhd(55[2] 146[11])
    defparam s_i2.GSR = "ENABLED";
    FD1P3AX s_i1 (.D(s_3__N_200[0]), .SP(oscdiv0_c_enable_4), .CK(oscdiv0_c), 
            .Q(s0_c_0)) /* synthesis LSE_LINE_FILE_ID=25, LSE_LCOL=9, LSE_RCOL=17, LSE_LLINE=28, LSE_RLINE=28 */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/cont.vhd(55[2] 146[11])
    defparam s_i1.GSR = "ENABLED";
    PFUMX i937 (.BLUT(n1034), .ALUT(n1033), .C0(c0_c_1), .Z(n1035));
    LUT4 n1037_bdd_3_lut (.A(n1037), .B(n1035), .C(c0_c_2), .Z(s_3__N_200[2])) /* synthesis lut_function=(A (B+!(C))+!A (B (C))) */ ;
    defparam n1037_bdd_3_lut.init = 16'hcaca;
    LUT4 s0_c_0_bdd_3_lut_936 (.A(s0_c_0), .B(c0_c_0), .C(s0_c_1), .Z(n1021)) /* synthesis lut_function=(!(A (B (C)+!B !(C))+!A !(B (C)+!B !(C)))) */ ;
    defparam s0_c_0_bdd_3_lut_936.init = 16'h6969;
    LUT4 s0_c_0_bdd_4_lut_932 (.A(c0_c_1), .B(c0_c_0), .C(s0_c_1), .D(s0_c_2), 
         .Z(n1018)) /* synthesis lut_function=(A (C)+!A (B+(D))) */ ;
    defparam s0_c_0_bdd_4_lut_932.init = 16'hf5e4;
    LUT4 i1_2_lut_rep_8 (.A(s0_c_1), .B(s0_c_0), .Z(n1059)) /* synthesis lut_function=(A (B)) */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/cont.vhd(126[6] 143[15])
    defparam i1_2_lut_rep_8.init = 16'h8888;
    LUT4 i885_4_lut (.A(s0_c_3), .B(e0_c_3), .C(c0_c_1), .D(n477), .Z(n975)) /* synthesis lut_function=(A (B (C+!(D))+!B !(C+(D)))+!A (B (C+(D))+!B !(C+!(D)))) */ ;
    defparam i885_4_lut.init = 16'hc5ca;
    LUT4 s0_c_3_bdd_3_lut_958 (.A(s0_c_3), .B(s0_c_1), .C(c0_c_0), .Z(n1044)) /* synthesis lut_function=(A (B+(C))+!A !((C)+!B)) */ ;
    defparam s0_c_3_bdd_3_lut_958.init = 16'hacac;
    LUT4 n1021_bdd_3_lut (.A(n1021), .B(e0_c_1), .C(c0_c_1), .Z(n1022)) /* synthesis lut_function=(A (B+!(C))+!A (B (C))) */ ;
    defparam n1021_bdd_3_lut.init = 16'hcaca;
    PFUMX i933 (.BLUT(n1019), .ALUT(n1018), .C0(s0_c_0), .Z(n1020));
    LUT4 c0_c_0_bdd_4_lut_947 (.A(c0_c_0), .B(s0_c_3), .C(s0_c_2), .D(n1059), 
         .Z(n1011)) /* synthesis lut_function=(!(A (B (C (D))+!B (C+!(D)))+!A !(B (C+!(D))+!B (C (D))))) */ ;
    defparam c0_c_0_bdd_4_lut_947.init = 16'h5acc;
    LUT4 s0_c_3_bdd_4_lut_957 (.A(s0_c_3), .B(s0_c_1), .C(s0_c_2), .D(c0_c_0), 
         .Z(n1043)) /* synthesis lut_function=(A (B (C (D)+!C !(D))+!B !(C (D)+!C !(D)))+!A !(B (C (D)+!C !(D))+!B !(C (D)+!C !(D)))) */ ;
    defparam s0_c_3_bdd_4_lut_957.init = 16'h9669;
    LUT4 n1022_bdd_3_lut (.A(n1022), .B(n1020), .C(c0_c_2), .Z(s_3__N_200[1])) /* synthesis lut_function=(A (B+!(C))+!A (B (C))) */ ;
    defparam n1022_bdd_3_lut.init = 16'hcaca;
    LUT4 s0_c_0_bdd_4_lut_946 (.A(s0_c_0), .B(s0_c_2), .C(c0_c_0), .D(s0_c_1), 
         .Z(n1036)) /* synthesis lut_function=(!(A (B (C (D))+!B !(C (D)))+!A !(B (C+(D))+!B !(C+(D))))) */ ;
    defparam s0_c_0_bdd_4_lut_946.init = 16'h6cc9;
    LUT4 s0_c_0_bdd_4_lut_935 (.A(c0_c_1), .B(c0_c_0), .C(s0_c_3), .D(s0_c_2), 
         .Z(n1019)) /* synthesis lut_function=(A (B (C (D)+!C !(D))+!B !(C (D)+!C !(D)))+!A !(B+!(D))) */ ;
    defparam s0_c_0_bdd_4_lut_935.init = 16'h9328;
    LUT4 c_2__I_0_Mux_3_i4_3_lut (.A(s0_c_0), .B(s0_c_2), .C(c0_c_0), 
         .Z(n4)) /* synthesis lut_function=(A (B+!(C))+!A (B (C))) */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/cont.vhd(56[2] 145[15])
    defparam c_2__I_0_Mux_3_i4_3_lut.init = 16'hcaca;
    LUT4 s0_c_0_bdd_3_lut_983 (.A(s0_c_0), .B(c0_c_1), .C(e0_c_0), .Z(n1046)) /* synthesis lut_function=(A (B (C))+!A ((C)+!B)) */ ;
    defparam s0_c_0_bdd_3_lut_983.init = 16'hd1d1;
    LUT4 i1_3_lut (.A(c0_c_2), .B(c0_c_0), .C(c0_c_1), .Z(oscdiv0_c_enable_4)) /* synthesis lut_function=(A+!(B (C))) */ ;
    defparam i1_3_lut.init = 16'hbfbf;
    PFUMX i943 (.BLUT(n1044), .ALUT(n1043), .C0(c0_c_1), .Z(n1045));
    LUT4 s0_c_0_bdd_3_lut_945 (.A(s0_c_3), .B(c0_c_0), .C(s0_c_1), .Z(n1034)) /* synthesis lut_function=(A ((C)+!B)+!A (B (C))) */ ;
    defparam s0_c_0_bdd_3_lut_945.init = 16'he2e2;
    LUT4 n1046_bdd_3_lut (.A(n1046), .B(n1045), .C(c0_c_2), .Z(s_3__N_200[0])) /* synthesis lut_function=(A (B+!(C))+!A (B (C))) */ ;
    defparam n1046_bdd_3_lut.init = 16'hcaca;
    PFUMX i887 (.BLUT(n975), .ALUT(n976), .C0(c0_c_2), .Z(s_3__N_200[3]));
    FD1P3AX s_i4 (.D(s_3__N_200[3]), .SP(oscdiv0_c_enable_4), .CK(oscdiv0_c), 
            .Q(s0_c_3)) /* synthesis LSE_LINE_FILE_ID=25, LSE_LCOL=9, LSE_RCOL=17, LSE_LLINE=28, LSE_RLINE=28 */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/cont.vhd(55[2] 146[11])
    defparam s_i4.GSR = "ENABLED";
    LUT4 i913_3_lut (.A(n4), .B(n1011), .C(c0_c_1), .Z(n976)) /* synthesis lut_function=(A (B+!(C))+!A (B (C))) */ ;
    defparam i913_3_lut.init = 16'hcaca;
    LUT4 s0_c_2_bdd_3_lut_948 (.A(s0_c_2), .B(n1032), .C(s0_c_0), .Z(n1033)) /* synthesis lut_function=(A (B+!(C))+!A (B (C))) */ ;
    defparam s0_c_2_bdd_3_lut_948.init = 16'hcaca;
    LUT4 s0_c_0_bdd_4_lut_939 (.A(s0_c_3), .B(s0_c_2), .C(c0_c_0), .D(s0_c_1), 
         .Z(n1032)) /* synthesis lut_function=(A (B (C+(D))+!B !((D)+!C))+!A (B ((D)+!C)+!B !(C+(D)))) */ ;
    defparam s0_c_0_bdd_4_lut_939.init = 16'hcca5;
    
endmodule
//
// Verilog Description of module PUR
// module not written out since it is a black-box. 
//

//
// Verilog Description of module topdiv00
//

module topdiv00 (oscdiv0_c, GND_net, indiv0_c_2, indiv0_c_3, indiv0_c_0, 
            indiv0_c_1, oscraw0_c);
    output oscdiv0_c;
    input GND_net;
    input indiv0_c_2;
    input indiv0_c_3;
    input indiv0_c_0;
    input indiv0_c_1;
    output oscraw0_c;
    
    wire clkdiv_N_23 /* synthesis is_inv_clock=1 */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/div00.vhd(18[8:12])
    wire oscdiv0_c /* synthesis is_clock=1, SET_AS_NETWORK=oscdiv0_c */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(13[8:15])
    wire oscraw0_c /* synthesis is_clock=1 */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(12[5:12])
    
    div00 OS01 (.clkdiv_N_23(clkdiv_N_23), .oscdiv0_c(oscdiv0_c), .GND_net(GND_net), 
          .indiv0_c_2(indiv0_c_2), .indiv0_c_3(indiv0_c_3), .indiv0_c_0(indiv0_c_0), 
          .indiv0_c_1(indiv0_c_1));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topdiv00.vhd(22[9:14])
    osc00 OS00 (.clkdiv_N_23(clkdiv_N_23), .oscraw0_c(oscraw0_c), .GND_net(GND_net));   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topdiv00.vhd(20[9:14])
    
endmodule
//
// Verilog Description of module div00
//

module div00 (clkdiv_N_23, oscdiv0_c, GND_net, indiv0_c_2, indiv0_c_3, 
            indiv0_c_0, indiv0_c_1);
    input clkdiv_N_23;
    output oscdiv0_c;
    input GND_net;
    input indiv0_c_2;
    input indiv0_c_3;
    input indiv0_c_0;
    input indiv0_c_1;
    
    wire clkdiv_N_23 /* synthesis is_inv_clock=1 */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/div00.vhd(18[8:12])
    wire oscdiv0_c /* synthesis is_clock=1, SET_AS_NETWORK=oscdiv0_c */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(13[8:15])
    wire [20:0]sdiv;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/div00.vhd(18[8:12])
    
    wire clkdiv_N_23_enable_22, n508;
    wire [20:0]n89;
    
    wire clkdiv_N_23_enable_4, outdiv_N_171, n826, n827, n937, n830, 
        n831, n843, n1050, n4, n368, n853, n689, n12, n829, 
        n825, n12_adj_220, n1057, n1058, n948, n828, n958, n4_adj_221, 
        n9, n969, n53, n30, n34, n833, n832, n1049, n824;
    
    FD1P3IX sdiv_117__i16 (.D(n89[16]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[16])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i16.GSR = "ENABLED";
    FD1P3IX sdiv_117__i17 (.D(n89[17]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[17])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i17.GSR = "ENABLED";
    FD1P3IX sdiv_117__i18 (.D(n89[18]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[18])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i18.GSR = "ENABLED";
    FD1P3AX outdiv_58 (.D(outdiv_N_171), .SP(clkdiv_N_23_enable_4), .CK(clkdiv_N_23), 
            .Q(oscdiv0_c)) /* synthesis LSE_LINE_FILE_ID=26, LSE_LCOL=9, LSE_RCOL=14, LSE_LLINE=22, LSE_RLINE=22 */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/div00.vhd(22[3] 75[11])
    defparam outdiv_58.GSR = "ENABLED";
    CCU2D sdiv_117_add_4_7 (.A0(sdiv[5]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(sdiv[6]), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n826), .COUT(n827), .S0(n89[5]), .S1(n89[6]));   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117_add_4_7.INIT0 = 16'hfaaa;
    defparam sdiv_117_add_4_7.INIT1 = 16'hfaaa;
    defparam sdiv_117_add_4_7.INJECT1_0 = "NO";
    defparam sdiv_117_add_4_7.INJECT1_1 = "NO";
    LUT4 i882_3_lut_4_lut (.A(sdiv[15]), .B(sdiv[14]), .C(sdiv[13]), .D(sdiv[12]), 
         .Z(n937)) /* synthesis lut_function=(!(A+(B+(C+(D))))) */ ;
    defparam i882_3_lut_4_lut.init = 16'h0001;
    CCU2D sdiv_117_add_4_15 (.A0(sdiv[13]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(sdiv[14]), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n830), .COUT(n831), .S0(n89[13]), .S1(n89[14]));   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117_add_4_15.INIT0 = 16'hfaaa;
    defparam sdiv_117_add_4_15.INIT1 = 16'hfaaa;
    defparam sdiv_117_add_4_15.INJECT1_0 = "NO";
    defparam sdiv_117_add_4_15.INJECT1_1 = "NO";
    LUT4 i27_4_lut (.A(indiv0_c_2), .B(indiv0_c_3), .C(indiv0_c_0), .D(indiv0_c_1), 
         .Z(clkdiv_N_23_enable_4)) /* synthesis lut_function=(A (B ((D)+!C)+!B (C (D)))+!A !(B+!(C+!(D)))) */ ;
    defparam i27_4_lut.init = 16'hb819;
    LUT4 i1_4_lut (.A(n843), .B(indiv0_c_3), .C(n1050), .D(indiv0_c_2), 
         .Z(n4)) /* synthesis lut_function=(!(A (B+((D)+!C)))) */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam i1_4_lut.init = 16'h5575;
    FD1P3IX sdiv_117__i1 (.D(n89[1]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[1])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i1.GSR = "ENABLED";
    FD1P3IX sdiv_117__i12 (.D(n89[12]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[12])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i12.GSR = "ENABLED";
    FD1P3IX sdiv_117__i5 (.D(n89[5]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[5])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i5.GSR = "ENABLED";
    FD1P3IX sdiv_117__i2 (.D(n89[2]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[2])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i2.GSR = "ENABLED";
    FD1P3IX sdiv_117__i19 (.D(n89[19]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[19])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i19.GSR = "ENABLED";
    LUT4 i1_4_lut_adj_8 (.A(indiv0_c_0), .B(n368), .C(n853), .D(n689), 
         .Z(n12)) /* synthesis lut_function=(A (B (C)+!B (C+(D)))+!A !(B+!(D))) */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam i1_4_lut_adj_8.init = 16'hb3a0;
    CCU2D sdiv_117_add_4_13 (.A0(sdiv[11]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(sdiv[12]), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n829), .COUT(n830), .S0(n89[11]), .S1(n89[12]));   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117_add_4_13.INIT0 = 16'hfaaa;
    defparam sdiv_117_add_4_13.INIT1 = 16'hfaaa;
    defparam sdiv_117_add_4_13.INJECT1_0 = "NO";
    defparam sdiv_117_add_4_13.INJECT1_1 = "NO";
    CCU2D sdiv_117_add_4_5 (.A0(sdiv[3]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(sdiv[4]), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n825), .COUT(n826), .S0(n89[3]), .S1(n89[4]));   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117_add_4_5.INIT0 = 16'hfaaa;
    defparam sdiv_117_add_4_5.INIT1 = 16'hfaaa;
    defparam sdiv_117_add_4_5.INJECT1_0 = "NO";
    defparam sdiv_117_add_4_5.INJECT1_1 = "NO";
    FD1P3IX sdiv_117__i10 (.D(n89[10]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[10])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i10.GSR = "ENABLED";
    FD1P3IX sdiv_117__i6 (.D(n89[6]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[6])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i6.GSR = "ENABLED";
    LUT4 i6_3_lut_4_lut (.A(sdiv[20]), .B(sdiv[19]), .C(n12_adj_220), 
         .D(sdiv[15]), .Z(n689)) /* synthesis lut_function=(A+(B+(C+(D)))) */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/div00.vhd(39[11:79])
    defparam i6_3_lut_4_lut.init = 16'hfffe;
    LUT4 i1_2_lut_rep_6_3_lut (.A(sdiv[20]), .B(sdiv[19]), .C(sdiv[18]), 
         .Z(n1057)) /* synthesis lut_function=(A+(B+(C))) */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/div00.vhd(39[11:79])
    defparam i1_2_lut_rep_6_3_lut.init = 16'hfefe;
    FD1P3IX sdiv_117__i11 (.D(n89[11]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[11])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i11.GSR = "ENABLED";
    FD1P3IX sdiv_117__i13 (.D(n89[13]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[13])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i13.GSR = "ENABLED";
    LUT4 i1_2_lut_rep_7 (.A(sdiv[20]), .B(sdiv[19]), .Z(n1058)) /* synthesis lut_function=(A+(B)) */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/div00.vhd(39[11:79])
    defparam i1_2_lut_rep_7.init = 16'heeee;
    LUT4 i2_4_lut (.A(n689), .B(n368), .C(n948), .D(indiv0_c_1), .Z(n843)) /* synthesis lut_function=(A (B+(D))+!A (B+((D)+!C))) */ ;
    defparam i2_4_lut.init = 16'hffcd;
    CCU2D sdiv_117_add_4_11 (.A0(sdiv[9]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(sdiv[10]), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n828), .COUT(n829), .S0(n89[9]), .S1(n89[10]));   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117_add_4_11.INIT0 = 16'hfaaa;
    defparam sdiv_117_add_4_11.INIT1 = 16'hfaaa;
    defparam sdiv_117_add_4_11.INJECT1_0 = "NO";
    defparam sdiv_117_add_4_11.INJECT1_1 = "NO";
    FD1P3IX sdiv_117__i14 (.D(n89[14]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[14])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i14.GSR = "ENABLED";
    LUT4 i1_2_lut (.A(sdiv[12]), .B(sdiv[13]), .Z(n948)) /* synthesis lut_function=(A+(B)) */ ;
    defparam i1_2_lut.init = 16'heeee;
    LUT4 i1_3_lut_3_lut_4_lut (.A(sdiv[20]), .B(sdiv[19]), .C(sdiv[17]), 
         .D(sdiv[18]), .Z(n958)) /* synthesis lut_function=(!(A+(B+(C+(D))))) */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/div00.vhd(39[11:79])
    defparam i1_3_lut_3_lut_4_lut.init = 16'h0001;
    FD1P3IX sdiv_117__i15 (.D(n89[15]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[15])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i15.GSR = "ENABLED";
    LUT4 i1_4_lut_adj_9 (.A(n1057), .B(indiv0_c_2), .C(indiv0_c_3), .D(n4_adj_221), 
         .Z(n853)) /* synthesis lut_function=(A (B+!(C))+!A (B (D))) */ ;
    defparam i1_4_lut_adj_9.init = 16'hce8a;
    PFUMX i51 (.BLUT(n937), .ALUT(n9), .C0(indiv0_c_1), .Z(n969));
    LUT4 i1_4_lut_adj_10 (.A(clkdiv_N_23_enable_22), .B(indiv0_c_1), .C(n4), 
         .D(n12), .Z(n508)) /* synthesis lut_function=(A (B (C+(D))+!B (C))) */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam i1_4_lut_adj_10.init = 16'ha8a0;
    CCU2D sdiv_117_add_4_9 (.A0(sdiv[7]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(sdiv[8]), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n827), .COUT(n828), .S0(n89[7]), .S1(n89[8]));   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117_add_4_9.INIT0 = 16'hfaaa;
    defparam sdiv_117_add_4_9.INIT1 = 16'hfaaa;
    defparam sdiv_117_add_4_9.INJECT1_0 = "NO";
    defparam sdiv_117_add_4_9.INJECT1_1 = "NO";
    PFUMX i52 (.BLUT(n53), .ALUT(n958), .C0(indiv0_c_2), .Z(n30));
    LUT4 i416_4_lut (.A(oscdiv0_c), .B(n30), .C(n34), .D(indiv0_c_3), 
         .Z(outdiv_N_171)) /* synthesis lut_function=(A (B (C+!(D))+!B (C (D)))+!A !(B (C+!(D))+!B (C (D)))) */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/div00.vhd(23[5] 74[14])
    defparam i416_4_lut.init = 16'ha599;
    CCU2D sdiv_117_add_4_21 (.A0(sdiv[19]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(sdiv[20]), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n833), .S0(n89[19]), .S1(n89[20]));   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117_add_4_21.INIT0 = 16'hfaaa;
    defparam sdiv_117_add_4_21.INIT1 = 16'hfaaa;
    defparam sdiv_117_add_4_21.INJECT1_0 = "NO";
    defparam sdiv_117_add_4_21.INJECT1_1 = "NO";
    CCU2D sdiv_117_add_4_19 (.A0(sdiv[17]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(sdiv[18]), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n832), .COUT(n833), .S0(n89[17]), .S1(n89[18]));   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117_add_4_19.INIT0 = 16'hfaaa;
    defparam sdiv_117_add_4_19.INIT1 = 16'hfaaa;
    defparam sdiv_117_add_4_19.INJECT1_0 = "NO";
    defparam sdiv_117_add_4_19.INJECT1_1 = "NO";
    CCU2D sdiv_117_add_4_17 (.A0(sdiv[15]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(sdiv[16]), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n831), .COUT(n832), .S0(n89[15]), .S1(n89[16]));   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117_add_4_17.INIT0 = 16'hfaaa;
    defparam sdiv_117_add_4_17.INIT1 = 16'hfaaa;
    defparam sdiv_117_add_4_17.INJECT1_0 = "NO";
    defparam sdiv_117_add_4_17.INJECT1_1 = "NO";
    LUT4 i1_3_lut (.A(sdiv[16]), .B(sdiv[17]), .C(indiv0_c_3), .Z(n4_adj_221)) /* synthesis lut_function=(A (B+(C))+!A (B)) */ ;
    defparam i1_3_lut.init = 16'hecec;
    LUT4 i2_3_lut (.A(indiv0_c_3), .B(indiv0_c_2), .C(indiv0_c_0), .Z(n368)) /* synthesis lut_function=(((C)+!B)+!A) */ ;
    defparam i2_3_lut.init = 16'hf7f7;
    LUT4 i1_4_lut_adj_11 (.A(sdiv[17]), .B(sdiv[16]), .C(n1057), .D(n969), 
         .Z(n34)) /* synthesis lut_function=(!(A+(B+(C+!(D))))) */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/div00.vhd(23[5] 74[14])
    defparam i1_4_lut_adj_11.init = 16'h0100;
    LUT4 i59_4_lut (.A(n1049), .B(n1058), .C(indiv0_c_1), .D(sdiv[18]), 
         .Z(n53)) /* synthesis lut_function=(!(A (B+((D)+!C))+!A (B (C)+!B (C (D))))) */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/div00.vhd(23[5] 74[14])
    defparam i59_4_lut.init = 16'h0535;
    LUT4 i5_4_lut (.A(sdiv[18]), .B(sdiv[16]), .C(sdiv[17]), .D(sdiv[14]), 
         .Z(n12_adj_220)) /* synthesis lut_function=(A+(B+(C+(D)))) */ ;
    defparam i5_4_lut.init = 16'hfffe;
    FD1P3IX sdiv_117__i20 (.D(n89[20]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[20])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i20.GSR = "ENABLED";
    FD1P3IX sdiv_117__i0 (.D(n89[0]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[0])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i0.GSR = "ENABLED";
    LUT4 i1_2_lut_3_lut (.A(sdiv[15]), .B(sdiv[14]), .C(indiv0_c_0), .Z(n9)) /* synthesis lut_function=(A (C)+!A ((C)+!B)) */ ;
    defparam i1_2_lut_3_lut.init = 16'hf1f1;
    LUT4 indiv0_c_3_bdd_4_lut (.A(indiv0_c_3), .B(indiv0_c_2), .C(indiv0_c_0), 
         .D(indiv0_c_1), .Z(clkdiv_N_23_enable_22)) /* synthesis lut_function=(A (B ((D)+!C))+!A (B (C (D))+!B (C+!(D)))) */ ;
    defparam indiv0_c_3_bdd_4_lut.init = 16'hd819;
    LUT4 sdiv_20__bdd_4_lut (.A(sdiv[20]), .B(indiv0_c_1), .C(indiv0_c_0), 
         .D(sdiv[19]), .Z(n1050)) /* synthesis lut_function=(!(A (B)+!A (B+!(C (D))))) */ ;
    defparam sdiv_20__bdd_4_lut.init = 16'h3222;
    FD1P3IX sdiv_117__i7 (.D(n89[7]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[7])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i7.GSR = "ENABLED";
    FD1P3IX sdiv_117__i8 (.D(n89[8]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[8])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i8.GSR = "ENABLED";
    FD1P3IX sdiv_117__i3 (.D(n89[3]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[3])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i3.GSR = "ENABLED";
    LUT4 n6_bdd_3_lut (.A(indiv0_c_0), .B(sdiv[19]), .C(sdiv[20]), .Z(n1049)) /* synthesis lut_function=(A (B+(C))+!A (C)) */ ;
    defparam n6_bdd_3_lut.init = 16'hf8f8;
    CCU2D sdiv_117_add_4_3 (.A0(sdiv[1]), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(sdiv[2]), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .CIN(n824), .COUT(n825), .S0(n89[1]), .S1(n89[2]));   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117_add_4_3.INIT0 = 16'hfaaa;
    defparam sdiv_117_add_4_3.INIT1 = 16'hfaaa;
    defparam sdiv_117_add_4_3.INJECT1_0 = "NO";
    defparam sdiv_117_add_4_3.INJECT1_1 = "NO";
    FD1P3IX sdiv_117__i9 (.D(n89[9]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[9])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i9.GSR = "ENABLED";
    FD1P3IX sdiv_117__i4 (.D(n89[4]), .SP(clkdiv_N_23_enable_22), .CD(n508), 
            .CK(clkdiv_N_23), .Q(sdiv[4])) /* synthesis syn_use_carry_chain=1 */ ;   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117__i4.GSR = "ENABLED";
    CCU2D sdiv_117_add_4_1 (.A0(GND_net), .B0(GND_net), .C0(GND_net), 
          .D0(GND_net), .A1(sdiv[0]), .B1(GND_net), .C1(GND_net), .D1(GND_net), 
          .COUT(n824), .S1(n89[0]));   // C:/lscc/diamond/3.9_x64/ispfpga/vhdl_packages/syn_arit.vhd(928[41:65])
    defparam sdiv_117_add_4_1.INIT0 = 16'hF000;
    defparam sdiv_117_add_4_1.INIT1 = 16'h0555;
    defparam sdiv_117_add_4_1.INJECT1_0 = "NO";
    defparam sdiv_117_add_4_1.INJECT1_1 = "NO";
    
endmodule
//
// Verilog Description of module osc00
//

module osc00 (clkdiv_N_23, oscraw0_c, GND_net);
    output clkdiv_N_23;
    output oscraw0_c;
    input GND_net;
    
    wire clkdiv_N_23 /* synthesis is_inv_clock=1 */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/div00.vhd(18[8:12])
    wire oscraw0_c /* synthesis is_clock=1 */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/topcont0.vhd(12[5:12])
    
    INV i987 (.A(oscraw0_c), .Z(clkdiv_N_23));
    OSCH OSCInst0 (.STDBY(GND_net), .OSC(oscraw0_c)) /* synthesis NOM_FREQ="2.08", syn_instantiated=1, LSE_LINE_FILE_ID=26, LSE_LCOL=9, LSE_RCOL=14, LSE_LLINE=20, LSE_RLINE=20 */ ;   // c:/users/osk4r_000/documents/escom/jasz/arqui de computadoras/diamond/lcd00/p7tsest/impl1/source/osc00.vhd(21[11:15])
    defparam OSCInst0.NOM_FREQ = "2.08";
    
endmodule
//
// Verilog Description of module \OSCH("2.08")(1,4) 
// module not written out since it is a black-box. 
//

//
// Verilog Description of module TSALL
// module not written out since it is a black-box. 
//

