let data = "\
12\n\
#Here is the number of lines required: 31\n\
##start\n\
Day9 0 0\n\
##end\n\
Gq_6 3 3\n\
M_h7 8 8\n\
Uaa5 11 11\n\
Ykl8 12 12\n\
Ewn2 14 14\n\
Jde7 18 18\n\
Rqn1 23 23\n\
W_s5 28 28\n\
Zui9 32 32\n\
Fdv4 33 33\n\
Ydg6 35 35\n\
Z_r6 37 37\n\
Bkn7 38 38\n\
Aos0 41 41\n\
Gbi3 45 45\n\
Jto2 48 48\n\
Isa6 51 51\n\
Wpa1 54 54\n\
Vez2 57 57\n\
Gjn7 59 59\n\
Ozc0 62 62\n\
Ktz4 65 65\n\
Ras0 69 69\n\
Dtd8 72 72\n\
Kvy0 76 76\n\
Dme1 79 79\n\
Wcx4 81 81\n\
A_z2 82 82\n\
Sv_3 86 86\n\
Cku7 90 90\n\
Msv4 94 94\n\
Ub_2 96 96\n\
Bdt8 101 101\n\
Gmt9 106 106\n\
Kjc8 108 108\n\
Rp_9 111 111\n\
Nof7 116 116\n\
Uyf8 120 120\n\
Yrl4 123 123\n\
Cnt7 125 125\n\
The4 127 127\n\
Okp7 129 129\n\
Yf_9 131 131\n\
Avq4 134 134\n\
Rpt8 135 135\n\
Zpz4 140 140\n\
Gzz3 144 144\n\
Qb_2 147 147\n\
Pej7 149 149\n\
Nem6 152 152\n\
H_a2 157 157\n\
Mof0 159 159\n\
Owg3 160 160\n\
Mje7 165 165\n\
H__5 168 168\n\
Ilt0 172 172\n\
Wfw7 173 173\n\
Xbv3 176 176\n\
Vu_6 180 180\n\
Gps8 183 183\n\
Zqq0 186 186\n\
Eyh9 190 190\n\
Xca6 193 193\n\
Dfp6 197 197\n\
Euo9 200 200\n\
Rpb7 204 204\n\
Hgo0 207 207\n\
Za_7 210 210\n\
Rkq2 214 214\n\
Zkc3 216 216\n\
Fjd7 218 218\n\
Cem8 220 220\n\
Vni7 223 223\n\
Mwm1 227 227\n\
Pjm2 229 229\n\
Vpf8 234 234\n\
Ztx3 237 237\n\
Nrw8 240 240\n\
Ep_5 244 244\n\
Pkd2 247 247\n\
Clh4 249 249\n\
Tqj2 253 253\n\
Z_x5 254 254\n\
Tsh3 256 256\n\
Ud_9 258 258\n\
Gbx2 260 260\n\
V_z3 265 265\n\
Gme6 268 268\n\
Ir_8 272 272\n\
Ntn3 277 277\n\
Asc0 280 280\n\
Vcx2 283 283\n\
Cfv9 284 284\n\
Wir8 288 288\n\
Dtn8 292 292\n\
Akm2 296 296\n\
Gkn9 301 301\n\
Jp_2 302 302\n\
Ifh7 303 303\n\
Glg7 305 305\n\
Mr_9 308 308\n\
Nih7 311 311\n\
Hls2 316 316\n\
Psf5 317 317\n\
Xfx5 321 321\n\
I__3 322 322\n\
Qao6 324 324\n\
G_d9 329 329\n\
Nbn6 333 333\n\
Ags9 338 338\n\
Ckx9 342 342\n\
Fvx1 346 346\n\
Hmh6 348 348\n\
Fjy9 352 352\n\
W__3 357 357\n\
Bqg3 359 359\n\
N_b7 363 363\n\
Wvw3 367 367\n\
Gze3 369 369\n\
Kty8 372 372\n\
Qnh8 377 377\n\
Cts0 381 381\n\
Ece5 385 385\n\
Obj8 388 388\n\
Stu5 391 391\n\
Tvd4 394 394\n\
Xkp8 396 396\n\
Ukn6 400 400\n\
Bbr8 403 403\n\
Elr6 407 407\n\
Tzn6 409 409\n\
Jkk0 412 412\n\
Xok1 415 415\n\
Ipk9 418 418\n\
Dec6 422 422\n\
Jvy8 427 427\n\
Grn9 429 429\n\
Els8 433 433\n\
Cnr7 436 436\n\
Boq2 438 438\n\
Kin5 440 440\n\
Nzq9 443 443\n\
Ebv0 445 445\n\
Ecl5 449 449\n\
A__6 451 451\n\
Twq1 454 454\n\
Dxr6 456 456\n\
Oze8 459 459\n\
Tun9 462 462\n\
Mqp4 463 463\n\
Bub0 464 464\n\
Ikg7 467 467\n\
Vqu3 472 472\n\
Gab2 474 474\n\
Ykz6 478 478\n\
Skz0 481 481\n\
Utm2 483 483\n\
Hzi7 486 486\n\
Qmy7 490 490\n\
Azt3 494 494\n\
Tdy4 497 497\n\
Edq9 501 501\n\
Xbh1 506 506\n\
Ejm3 511 511\n\
Pic0 515 515\n\
Olr2 520 520\n\
Khe6 522 522\n\
Fut0 525 525\n\
Gtr4 528 528\n\
N_w8 530 530\n\
Tvm9 531 531\n\
Jjf0 535 535\n\
Ay_1 537 537\n\
Elu9 539 539\n\
Oci1 542 542\n\
Wow4 545 545\n\
Arc1 548 548\n\
Iqb7 552 552\n\
Qru4 555 555\n\
Qwy0 560 560\n\
Ekm4 561 561\n\
X_e4 563 563\n\
Hre0 567 567\n\
Deu0 569 569\n\
Oth1 572 572\n\
Rcj3 576 576\n\
Qod0 581 581\n\
Ndw3 584 584\n\
Yb_2 587 587\n\
Mxm8 590 590\n\
Nkk7 592 592\n\
Ieb5 595 595\n\
Wbh0 599 599\n\
Gb_4 601 601\n\
Eu_8 603 603\n\
Emr0 606 606\n\
Yij5 608 608\n\
Dya1 612 612\n\
Pb_7 616 616\n\
Odg9 620 620\n\
Flp9 625 625\n\
Xw_0 630 630\n\
Vhg7 632 632\n\
E_s1 636 636\n\
Yyl7 640 640\n\
Aue9 641 641\n\
Zry9 645 645\n\
Z_a1 647 647\n\
Hhy8 649 649\n\
Xxz3 650 650\n\
R__9 654 654\n\
Jfw6 658 658\n\
Yyx1 663 663\n\
Rgq8 665 665\n\
Znn2 668 668\n\
Wvs4 671 671\n\
N_j5 674 674\n\
Gyc8 676 676\n\
Gfn3 680 680\n\
Pke1 684 684\n\
Mko1 686 686\n\
Nhu1 690 690\n\
Pqh2 694 694\n\
Hr_2 698 698\n\
Efo1 701 701\n\
Cid2 703 703\n\
Bup8 707 707\n\
Obe2 711 711\n\
Cbs9 713 713\n\
Imy1 715 715\n\
Bym2 720 720\n\
Wiq8 724 724\n\
Cbh8 727 727\n\
Ngi3 729 729\n\
Oru3 730 730\n\
Mvs5 731 731\n\
Nly2 736 736\n\
Dqs5 739 739\n\
Pzj1 744 744\n\
Ujq3 748 748\n\
Vlt8 751 751\n\
Ksr6 754 754\n\
Gcw5 757 757\n\
Bus9 761 761\n\
Yza5 765 765\n\
Opn2 770 770\n\
X_f2 772 772\n\
Gju5 775 775\n\
Iyn6 780 780\n\
D_e2 783 783\n\
Zmn4 787 787\n\
Gty4 790 790\n\
Ven4 792 792\n\
Mce7 793 793\n\
Grs1 797 797\n\
Ydl0 800 800\n\
Kpc8 803 803\n\
Xso3 805 805\n\
Ylo7 809 809\n\
Dsh0 811 811\n\
Dnx1 815 815\n\
Pat5 818 818\n\
Uxs1 820 820\n\
Qvk7 823 823\n\
Bqj5 827 827\n\
Zmd8 829 829\n\
Vln5 832 832\n\
Gpp3 836 836\n\
Hdd9 837 837\n\
Xcn1 841 841\n\
Kwb8 844 844\n\
Iis0 847 847\n\
Jcj5 849 849\n\
Qlp8 851 851\n\
Ain4 854 854\n\
Nit1 857 857\n\
Gnq2 859 859\n\
Ihb5 863 863\n\
Ftl2 866 866\n\
Bg_1 867 867\n\
Yrd6 870 870\n\
Yor8 874 874\n\
Mrn4 876 876\n\
Fog9 880 880\n\
Jme3 881 881\n\
Hzo3 885 885\n\
K_c1 887 887\n\
Erh8 890 890\n\
Xl_2 893 893\n\
Uce3 897 897\n\
Tnn6 899 899\n\
Sqj4 902 902\n\
Pxk1 904 904\n\
Nin4 906 906\n\
Ytp1 908 908\n\
Mjk3 909 909\n\
Udf9 912 912\n\
Wgr2 916 916\n\
Zos5 918 918\n\
Zvn5 923 923\n\
J_m8 927 927\n\
Drc0 931 931\n\
Nnc5 936 936\n\
Xlf7 940 940\n\
Dqz6 943 943\n\
B_z7 948 948\n\
Bab1 950 950\n\
Tqs7 951 951\n\
Key4 952 952\n\
Zmt5 954 954\n\
Qww6 959 959\n\
Obg0 962 962\n\
Ili4 966 966\n\
Fel8 967 967\n\
Vro7 971 971\n\
Mgd9 974 974\n\
Slm5 977 977\n\
Uux4 978 978\n\
K_p0 981 981\n\
Hgg9 985 985\n\
Kgn1 988 988\n\
Mkp5 992 992\n\
Ryd6 996 996\n\
Fst2 998 998\n\
Clv1 1003 1003\n\
M_b5 1008 1008\n\
Dku9 1011 1011\n\
Vy_6 1014 1014\n\
Xcz7 1018 1018\n\
Xqc8 1021 1021\n\
Evr4 1024 1024\n\
Oul0 1025 1025\n\
Sjd1 1027 1027\n\
Ruq4 1028 1028\n\
W_n8 1031 1031\n\
Dhu8 1034 1034\n\
Nbw1 1039 1039\n\
Xxx5 1041 1041\n\
Asv5 1044 1044\n\
Ytd8 1046 1046\n\
Yqv8 1048 1048\n\
Jih4 1050 1050\n\
Blv0 1054 1054\n\
Qra7 1057 1057\n\
Qin5 1061 1061\n\
Mk_1 1065 1065\n\
Ufe2 1070 1070\n\
Btf3 1073 1073\n\
Who8 1076 1076\n\
Qmm4 1078 1078\n\
Ppc3 1079 1079\n\
Irb7 1082 1082\n\
Nzp7 1084 1084\n\
Xh_9 1089 1089\n\
Edd3 1094 1094\n\
Wkx5 1096 1096\n\
Hbf4 1100 1100\n\
Syk7 1103 1103\n\
Oeo0 1104 1104\n\
Iol8 1107 1107\n\
Crn1 1110 1110\n\
Sfo3 1113 1113\n\
X_g6 1117 1117\n\
Ifu4 1121 1121\n\
Ifr0 1126 1126\n\
Uob6 1128 1128\n\
X_t8 1131 1131\n\
U_p0 1134 1134\n\
P_q9 1137 1137\n\
Hif5 1138 1138\n\
Zdb2 1139 1139\n\
Tzx4 1142 1142\n\
Mo_2 1146 1146\n\
Ezz5 1149 1149\n\
Ccd6 1152 1152\n\
Rkq2-Ccd6\n\
Yza5-Ykl8\n\
Sqj4-Tzx4\n\
Eyh9-Zdb2\n\
Mkp5-Hif5\n\
Nbw1-P_q9\n\
Wfw7-U_p0\n\
Bus9-Rqn1\n\
Tzn6-Sfo3\n\
Eu_8-Ydg6\n\
Kwb8-Iol8\n\
Sqj4-Bkn7\n\
Dya1-Gbi3\n\
Jme3-Isa6\n\
Cnr7-Wpa1\n\
Wbh0-Vez2\n\
Arc1-Wkx5\n\
Eyh9-Gjn7\n\
Ub_2-Edd3\n\
Hre0-Nzp7\n\
Ytd8-Irb7\n\
Qww6-Ppc3\n\
Ub_2-Ras0\n\
Obg0-Btf3\n\
Elu9-Kvy0\n\
Ukn6-Mk_1\n\
Ay_1-Qra7\n\
Ukn6-Msv4\n\
Xxx5-Ub_2\n\
Nbw1-Xxx5\n\
W_n8-Dhu8\n\
Ruq4-W_n8\n\
Sjd1-Ruq4\n\
Oul0-Gmt9\n\
Kjc8-Oul0\n\
Rp_9-Kjc8\n\
Xqc8-Evr4\n\
Xcz7-Xqc8\n\
Vy_6-Xcz7\n\
M_b5-Okp7\n\
Clv1-M_b5\n\
Fst2-Clv1\n\
Yf_9-Fst2\n\
Ryd6-Yf_9\n\
Zpz4-Rpt8\n\
Kgn1-Zpz4\n\
Qb_2-Gzz3\n\
Uux4-K_p0\n\
Nem6-Pej7\n\
Xbv3-Wfw7\n\
Mgd9-Slm5\n\
Vu_6-Vro7\n\
Zqq0-Gps8\n\
Eyh9-Fel8\n\
Xca6-Eyh9\n\
Ili4-Dfp6\n\
Euo9-Qww6\n\
Zmt5-Euo9\n\
Rpb7-Zmt5\n\
Tqs7-Fjd7\n\
Cem8-Tqs7\n\
B_z7-Vni7\n\
Nnc5-Xlf7\n\
Drc0-Nnc5\n\
Pjm2-Drc0\n\
J_m8-Pjm2\n\
Vpf8-Zos5\n\
Ztx3-Vpf8\n\
Nrw8-Ztx3\n\
Udf9-Pkd2\n\
Day9-Tqj2\n\
Tsh3-Z_x5\n\
Ud_9-Tsh3\n\
Gbx2-Mjk3\n\
Ytp1-Gbx2\n\
Ir_8-Gme6\n\
Sqj4-Pxk1\n\
Ntn3-Sqj4\n\
Uce3-Tnn6\n\
Asc0-Uce3\n\
Vcx2-Xl_2\n\
Wir8-Erh8\n\
Jme3-Hzo3\n\
Mrn4-Fog9\n\
Day9-Yor8\n\
Xw_0-Gq_6\n\
Gkn9-Akm2\n\
Bg_1-Gkn9\n\
Ifh7-Jp_2\n\
Ftl2-Glg7\n\
Mr_9-Ftl2\n\
Nih7-Mr_9\n\
Ihb5-Nih7\n\
Gnq2-Ihb5\n\
Hls2-Gnq2\n\
Nit1-Hls2\n\
Psf5-Qlp8\n\
Qao6-I__3\n\
G_d9-Qao6\n\
Nbn6-G_d9\n\
Day9-Ags9\n\
Kwb8-Ckx9\n\
Xcn1-Fvx1\n\
Hmh6-Xcn1\n\
Hdd9-Hmh6\n\
W__3-Fjy9\n\
Wvw3-N_b7\n\
Kty8-Gze3\n\
Zmd8-Vln5\n\
Cts0-Qnh8\n\
Bqj5-Cts0\n\
Ece5-Bqj5\n\
Obj8-Pat5\n\
Stu5-Obj8\n\
Dnx1-Stu5\n\
Dsh0-Tvd4\n\
Xkp8-Dsh0\n\
Ylo7-Ukn6\n\
Bbr8-Ylo7\n\
Elr6-Bbr8\n\
Ydl0-Kpc8\n\
Grs1-Ydl0\n\
Mce7-Grs1\n\
Ven4-Mce7\n\
Gty4-Ven4\n\
D_e2-Ipk9\n\
Dec6-Iyn6\n\
Els8-Grn9\n\
Cnr7-Els8\n\
Boq2-Cnr7\n\
X_f2-Ebv0\n\
Ecl5-Opn2\n\
Yza5-Gq_6\n\
Twq1-Yza5\n\
Dxr6-Twq1\n\
Oze8-Dxr6\n\
Tun9-Oze8\n\
Bus9-Mqp4\n\
Bub0-Bus9\n\
Vqu3-Ikg7\n\
Gcw5-Vqu3\n\
Ksr6-Gab2\n\
Skz0-Ykz6\n\
Vlt8-Skz0\n\
Ujq3-Vlt8\n\
Pzj1-Utm2\n\
Hzi7-Pzj1\n\
Qmy7-Hzi7\n\
Dqs5-Edq9\n\
Nly2-Dqs5\n\
Xbh1-Nly2\n\
Mvs5-Xbh1\n\
Pic0-Gq_6\n\
Olr2-Pic0\n\
Ngi3-Olr2\n\
Wiq8-Gtr4\n\
N_w8-Bym2\n\
Ay_1-Jjf0\n\
Wow4-Oci1\n\
Cid2-Bup8\n\
Arc1-Cid2\n\
Iqb7-Pqh2\n\
Qru4-Nhu1\n\
Qwy0-Qru4\n\
Ekm4-Qwy0\n\
Hre0-Mko1\n\
Gfn3-Pke1\n\
Day9-Gfn3\n\
Rcj3-Gyc8\n\
Qod0-Rcj3\n\
N_j5-Qod0\n\
Ndw3-N_j5\n\
Wvs4-Ndw3\n\
Znn2-Wvs4\n\
Yb_2-Rgq8\n\
Wbh0-Ieb5\n\
Gb_4-Wbh0\n\
Hhy8-Gb_4\n\
Dya1-Zry9\n\
Yyl7-Aue9\n\
E_s1-Pb_7\n\
Vhg7-E_s1\n\
Odg9-Vhg7\n\
Flp9-Odg9\n\
Day9-Flp9\n\
Pb_7-Yyl7\n\
Aue9-Dya1\n\
Zry9-Z_a1\n\
Z_a1-Yij5\n\
Yij5-Emr0\n\
Emr0-Eu_8\n\
Eu_8-Hhy8\n\
Ieb5-Nkk7\n\
Nkk7-Xxz3\n\
Xxz3-Mxm8\n\
Mxm8-R__9\n\
R__9-Jfw6\n\
Jfw6-Yyx1\n\
Yyx1-Yb_2\n\
Rgq8-Znn2\n\
Gyc8-Oth1\n\
Oth1-Deu0\n\
Deu0-Gq_6\n\
Pke1-Hre0\n\
Mko1-X_e4\n\
X_e4-Ekm4\n\
Nhu1-Iqb7\n\
Pqh2-Hr_2\n\
Hr_2-Efo1\n\
Efo1-Arc1\n\
Bup8-Obe2\n\
Obe2-Cbs9\n\
Cbs9-Wow4\n\
Oci1-Elu9\n\
Elu9-Ay_1\n\
Jjf0-Imy1\n\
Imy1-Tvm9\n\
Tvm9-N_w8\n\
Bym2-Wiq8\n\
Gtr4-Fut0\n\
Fut0-Khe6\n\
Khe6-Cbh8\n\
Cbh8-Ngi3\n\
Day9-Oru3\n\
Oru3-Ejm3\n\
Ejm3-Mvs5\n\
Edq9-Tdy4\n\
Tdy4-Azt3\n\
Azt3-Qmy7\n\
Utm2-Ujq3\n\
Ykz6-Ksr6\n\
Gab2-Gcw5\n\
Ikg7-Bub0\n\
Mqp4-Tun9\n\
Day9-A__6\n\
A__6-Ecl5\n\
Opn2-X_f2\n\
Ebv0-Nzq9\n\
Nzq9-Gju5\n\
Gju5-Kin5\n\
Kin5-Boq2\n\
Grn9-Jvy8\n\
Jvy8-Dec6\n\
Iyn6-D_e2\n\
Ipk9-Xok1\n\
Xok1-Zmn4\n\
Zmn4-Gty4\n\
Kpc8-Jkk0\n\
Jkk0-Tzn6\n\
Tzn6-Gq_6\n\
Day9-Xso3\n\
Xso3-Elr6\n\
Ukn6-Xkp8\n\
Tvd4-Dnx1\n\
Pat5-Uxs1\n\
Uxs1-Qvk7\n\
Qvk7-Ece5\n\
Qnh8-Zmd8\n\
Vln5-Gpp3\n\
Gpp3-Kty8\n\
Gze3-Wvw3\n\
N_b7-Bqg3\n\
Bqg3-W__3\n\
Fjy9-Hdd9\n\
Fvx1-Kwb8\n\
Ckx9-Gq_6\n\
Ags9-Nbn6\n\
I__3-Iis0\n\
Iis0-Xfx5\n\
Xfx5-Jcj5\n\
Jcj5-Psf5\n\
Qlp8-Ain4\n\
Ain4-Nit1\n\
Glg7-Ifh7\n\
Jp_2-Bg_1\n\
Akm2-Yrd6\n\
Yrd6-Xw_0\n\
Yor8-Mrn4\n\
Fog9-Jme3\n\
Hzo3-Dtn8\n\
Dtn8-K_c1\n\
K_c1-Wir8\n\
Erh8-Cfv9\n\
Cfv9-Vcx2\n\
Xl_2-Asc0\n\
Tnn6-Ntn3\n\
Pxk1-Nin4\n\
Nin4-Ir_8\n\
Gme6-V_z3\n\
V_z3-Ytp1\n\
Mjk3-Ud_9\n\
Z_x5-Gq_6\n\
Tqj2-Clh4\n\
Clh4-Udf9\n\
Pkd2-Ep_5\n\
Ep_5-Wgr2\n\
Wgr2-Nrw8\n\
Zos5-Zvn5\n\
Zvn5-J_m8\n\
Xlf7-Mwm1\n\
Mwm1-Dqz6\n\
Dqz6-B_z7\n\
Vni7-Bab1\n\
Bab1-Cem8\n\
Fjd7-Key4\n\
Key4-Zkc3\n\
Zkc3-Rkq2\n\
Rkq2-Za_7\n\
Za_7-Hgo0\n\
Hgo0-Rpb7\n\
Qww6-Obg0\n\
Obg0-Ili4\n\
Dfp6-Xca6\n\
Fel8-Zqq0\n\
Gps8-Vu_6\n\
Vro7-Mgd9\n\
Slm5-Xbv3\n\
Wfw7-Ilt0\n\
Ilt0-H__5\n\
H__5-Mje7\n\
Mje7-Owg3\n\
Owg3-Mof0\n\
Mof0-H_a2\n\
H_a2-Nem6\n\
Pej7-Uux4\n\
K_p0-Qb_2\n\
Gzz3-Hgg9\n\
Hgg9-Kgn1\n\
Rpt8-Avq4\n\
Avq4-Mkp5\n\
Mkp5-Ryd6\n\
Okp7-The4\n\
The4-Cnt7\n\
Cnt7-Yrl4\n\
Yrl4-Uyf8\n\
Uyf8-Dku9\n\
Dku9-Vy_6\n\
Evr4-Nof7\n\
Nof7-Rp_9\n\
Gmt9-Sjd1\n\
Dhu8-Bdt8\n\
Bdt8-Nbw1\n\
Ub_2-Gq_6\n\
Nit1-Asv5\n\
Uxs1-Ytd8\n\
Qnh8-Cku7\n\
Xxx5-Sv_3\n\
Jvy8-Yqv8\n\
Ay_1-Jih4\n\
Aue9-Blv0\n\
Asc0-Qin5\n\
Fjd7-A_z2\n\
Oth1-Wcx4\n\
Yf_9-Dme1\n\
Qmy7-Ufe2\n\
Yza5-Dtd8\n\
Ylo7-Who8\n\
Efo1-Ktz4\n\
Pic0-Qmm4\n\
Dme1-Xh_9\n\
Asc0-Ozc0\n\
Nzq9-Hbf4\n\
Mvs5-Jto2\n\
Nem6-Syk7\n\
Qmy7-Oeo0\n\
Vez2-Aos0\n\
Cbh8-Z_r6\n\
The4-Crn1\n\
Wfw7-Fdv4\n\
Fjy9-X_g6\n\
Dme1-Ifu4\n\
Xso3-Ifr0\n\
Gps8-Zui9\n\
Tsh3-Uob6\n\
Xqc8-X_t8\n\
Ktz4-W_s5\n\
Nih7-Jde7\n\
Uxs1-Mo_2\n\
Kin5-Ezz5\n\
Qod0-Ewn2\n\
Bkn7-Uaa5\n\
Clv1-M_h7\n\
#Here is the number of lines required: 31\n\
\n\
L1-Ags9 L2-A__6 L3-Oru3 L4-Yor8 \n\
L5-Ags9 L1-Nbn6 L6-A__6 L2-Ecl5 L3-Ejm3 L7-Yor8 L4-Mrn4 \n\
L8-Ags9 L5-Nbn6 L1-G_d9 L9-A__6 L6-Ecl5 L2-Opn2 L3-Mvs5 L7-Mrn4 L4-Fog9 \n\
L10-Ags9 L8-Nbn6 L5-G_d9 L1-Qao6 L11-A__6 L9-Ecl5 L6-Opn2 L2-X_f2 L3-Xbh1 L7-Fog9 L4-Jme3 \n\
L12-Ags9 L10-Nbn6 L8-G_d9 L5-Qao6 L1-I__3 L11-Ecl5 L9-Opn2 L6-X_f2 L2-Ebv0 L3-Nly2 L7-Jme3 L4-Hzo3 \n\
L12-Nbn6 L10-G_d9 L8-Qao6 L5-I__3 L1-Iis0 L11-Opn2 L9-X_f2 L6-Ebv0 L2-Nzq9 L3-Dqs5 L7-Hzo3 L4-Dtn8 \n\
L12-G_d9 L10-Qao6 L8-I__3 L5-Iis0 L1-Xfx5 L11-X_f2 L9-Ebv0 L6-Nzq9 L2-Gju5 L3-Edq9 L7-Dtn8 L4-K_c1 \n\
L12-Qao6 L10-I__3 L8-Iis0 L5-Xfx5 L1-Jcj5 L11-Ebv0 L9-Nzq9 L6-Gju5 L2-Kin5 L3-Tdy4 L7-K_c1 L4-Wir8 \n\
L12-I__3 L10-Iis0 L8-Xfx5 L5-Jcj5 L1-Psf5 L11-Nzq9 L9-Gju5 L6-Kin5 L2-Boq2 L3-Azt3 L7-Wir8 L4-Erh8 \n\
L12-Iis0 L10-Xfx5 L8-Jcj5 L5-Psf5 L1-Qlp8 L11-Gju5 L9-Kin5 L6-Boq2 L2-Cnr7 L3-Qmy7 L7-Erh8 L4-Cfv9 \n\
L12-Xfx5 L10-Jcj5 L8-Psf5 L5-Qlp8 L1-Ain4 L11-Kin5 L9-Boq2 L6-Cnr7 L2-Els8 L3-Hzi7 L7-Cfv9 L4-Vcx2 \n\
L12-Jcj5 L10-Psf5 L8-Qlp8 L5-Ain4 L1-Nit1 L11-Boq2 L9-Cnr7 L6-Els8 L2-Grn9 L3-Pzj1 L7-Vcx2 L4-Xl_2 \n\
L12-Psf5 L10-Qlp8 L8-Ain4 L5-Nit1 L1-Hls2 L11-Cnr7 L9-Els8 L6-Grn9 L2-Jvy8 L3-Utm2 L7-Xl_2 L4-Asc0 \n\
L12-Qlp8 L10-Ain4 L8-Nit1 L5-Hls2 L1-Gnq2 L11-Els8 L9-Grn9 L6-Jvy8 L2-Dec6 L3-Ujq3 L7-Asc0 L4-Uce3 \n\
L12-Ain4 L10-Nit1 L8-Hls2 L5-Gnq2 L1-Ihb5 L11-Grn9 L9-Jvy8 L6-Dec6 L2-Iyn6 L3-Vlt8 L7-Uce3 L4-Tnn6 \n\
L12-Nit1 L10-Hls2 L8-Gnq2 L5-Ihb5 L1-Nih7 L11-Jvy8 L9-Dec6 L6-Iyn6 L2-D_e2 L3-Skz0 L7-Tnn6 L4-Ntn3 \n\
L12-Hls2 L10-Gnq2 L8-Ihb5 L5-Nih7 L1-Mr_9 L11-Dec6 L9-Iyn6 L6-D_e2 L2-Ipk9 L3-Ykz6 L7-Ntn3 L4-Sqj4 \n\
L12-Gnq2 L10-Ihb5 L8-Nih7 L5-Mr_9 L1-Ftl2 L11-Iyn6 L9-D_e2 L6-Ipk9 L2-Xok1 L3-Ksr6 L7-Sqj4 L4-Pxk1 \n\
L12-Ihb5 L10-Nih7 L8-Mr_9 L5-Ftl2 L1-Glg7 L11-D_e2 L9-Ipk9 L6-Xok1 L2-Zmn4 L3-Gab2 L7-Pxk1 L4-Nin4 \n\
L12-Nih7 L10-Mr_9 L8-Ftl2 L5-Glg7 L1-Ifh7 L11-Ipk9 L9-Xok1 L6-Zmn4 L2-Gty4 L3-Gcw5 L7-Nin4 L4-Ir_8 \n\
L12-Mr_9 L10-Ftl2 L8-Glg7 L5-Ifh7 L1-Jp_2 L11-Xok1 L9-Zmn4 L6-Gty4 L2-Ven4 L3-Vqu3 L7-Ir_8 L4-Gme6 \n\
L12-Ftl2 L10-Glg7 L8-Ifh7 L5-Jp_2 L1-Bg_1 L11-Zmn4 L9-Gty4 L6-Ven4 L2-Mce7 L3-Ikg7 L7-Gme6 L4-V_z3 \n\
L12-Glg7 L10-Ifh7 L8-Jp_2 L5-Bg_1 L1-Gkn9 L11-Gty4 L9-Ven4 L6-Mce7 L2-Grs1 L3-Bub0 L7-V_z3 L4-Ytp1 \n\
L12-Ifh7 L10-Jp_2 L8-Bg_1 L5-Gkn9 L1-Akm2 L11-Ven4 L9-Mce7 L6-Grs1 L2-Ydl0 L3-Bus9 L7-Ytp1 L4-Gbx2 \n\
L12-Jp_2 L10-Bg_1 L8-Gkn9 L5-Akm2 L1-Yrd6 L11-Mce7 L9-Grs1 L6-Ydl0 L2-Kpc8 L3-Mqp4 L7-Gbx2 L4-Mjk3 \n\
L12-Bg_1 L10-Gkn9 L8-Akm2 L5-Yrd6 L1-Xw_0 L11-Grs1 L9-Ydl0 L6-Kpc8 L2-Jkk0 L3-Tun9 L7-Mjk3 L4-Ud_9 \n\
L12-Gkn9 L10-Akm2 L8-Yrd6 L5-Xw_0 L1-Gq_6 L11-Ydl0 L9-Kpc8 L6-Jkk0 L2-Tzn6 L3-Oze8 L7-Ud_9 L4-Tsh3 \n\
L12-Akm2 L10-Yrd6 L8-Xw_0 L5-Gq_6 L11-Kpc8 L9-Jkk0 L6-Tzn6 L2-Gq_6 L3-Dxr6 L7-Tsh3 L4-Z_x5 \n\
L12-Yrd6 L10-Xw_0 L8-Gq_6 L11-Jkk0 L9-Tzn6 L6-Gq_6 L3-Twq1 L7-Z_x5 L4-Gq_6 \n\
L12-Xw_0 L10-Gq_6 L11-Tzn6 L9-Gq_6 L3-Yza5 L7-Gq_6 \n\
L12-Gq_6 L11-Gq_6 L3-Gq_6 \n\
";
