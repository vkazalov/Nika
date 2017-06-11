clc
clear

load d:\Cloud\Dropbox\G4\TestPPD\near\Ra226\nPPD_Ra226_confORTO_651sec.dat
spceRa226=nPPD_Ra226_confORTO_651sec;

%figure(11);stairs(spceRa226);grid on;

load d:\Cloud\Dropbox\G4\TestPPD\near\fonNearPPD_1060h.dat
spcNIKA=fonNearPPD_1060h;

figure(12);stairs(spcNIKA,'k');grid on;

load d:\Cloud\Dropbox\G4\TestPPD\near\Ra226\nPPD_Ra226_confDIA_610sec.dat
spceRa226_2=nPPD_Ra226_confDIA_610sec;

%figure(13);stairs(spceRa226_2);grid on;

load d:\Work_DATA\HPGe_Baksan\NIKA\U-235\KoreanCaCO3_14-15\14CaCO3UnPurif_118.75h.dat
UnPurCaCO32014=X14CaCO3UnPurif_118_75h;

%figure(14);stairs(UnPurCaCO32014,'m');grid on;

load d:\Work_DATA\HPGe_Baksan\NIKA\U-235\KoreanCaCO3_14-15\15CaCO3UnPurif_74.5h.dat
UnPurCaCO32015=X15CaCO3UnPurif_74_5h;

%figure(15);stairs(UnPurCaCO32015,'r');grid on;

load d:\Work_DATA\HPGe_Baksan\SNEG\карб14-15дал\15CaCO3Purif_164h.dat
CaCO32015Pur=X15CaCO3Purif_164h;
%figure(21);stairs(CaCO32015Pur,'r');grid on;


%figure(22);stairs(CaCO32015Pur/164,'r');hold on;stairs(UnPurCaCO32015/74.5,'k');hold off;grid on;

%%%------------------------

load d:\Work_DATA\HPGe_Baksan\NIKA\U-235\№1_1CaCO3\CaCO3_557h.dat
CaCO3_2009_PrN7=CaCO3_557h;

%figure(31);stairs(CaCO3_2009_PrN7,'r');grid on;


load d:\Work_DATA\HPGe_Baksan\NIKA\U-235\N2_2CaCo3\comp542h_2.dat
CaCO3_2010_PrN10=comp542h_2;

%figure(32);stairs(CaCO3_2010_PrN10,'r');grid on;

load d:\Work_DATA\HPGe_Baksan\NIKA\U-235\N3_3CaCO3\carb3_833h.dat
CaCO3_2011_PrN36=carb3_833h;

%figure(33);stairs(CaCO3_2011_PrN36,'r');grid on;

load d:\Work_DATA\HPGe_Baksan\NIKA\U-235\N4_карбон_дек14\CaCO3_745h11.dat
CaCO3_2014_PrN81=CaCO3_745h11;

%figure(34);stairs(CaCO3_2014_PrN81,'r');grid on;


load d:\Work_DATA\HPGe_Baksan\NIKA\U-235\N5_CaCO3_11_13\CaCO3_522h.dat
CaCO3_2013_PrN61=CaCO3_522h;

%figure(35);stairs(CaCO3_2013_PrN61,'r');grid on;

load d:\Work_DATA\HPGe_Baksan\NIKA\U-235\N6_Moxide\MoO3_740h.dat
MoO3_2009_PrN6=MoO3_740h;

%figure(36);stairs(MoO3_2009_PrN6,'r');grid on;

load d:\Work_DATA\HPGe_Baksan\NIKA\U-235\N_7формиат\formiat_333h.dat
formiat_2009_PrN5=formiat_333h;

%figure(37);stairs(formiat_2009_PrN5,'r');grid on;

load d:\Work_DATA\HPGe_Baksan\NIKA\U-235\N8_Ш№1\shikhtaNo1_830h.dat
CaMoO4Sh_2014_PrN65=shikhtaNo1_830h;

%figure(38);stairs(CaMoO4Sh_2014_PrN65,'r');grid on;



load d:\Work_DATA\HPGe_Baksan\NIKA\NewData_21.12.2015\co60_testgeantandmoo3_proba3292\MoO3_proba2_667h_300gr.dat
MoO3_2015_N1_ECP=MoO3_proba2_667h_300gr;

figure(39);stairs(MoO3_2015_N1_ECP,'r');grid on;

%%----------------------------

load d:\Work_DATA\HPGe_Baksan\SNEG\MOx618\MoO3_M68_618gr__806h.dat
spcMoliO=MoO3_M68_618gr__806h;
%figure(31);stairs(spcMoliO,'r');grid on;
