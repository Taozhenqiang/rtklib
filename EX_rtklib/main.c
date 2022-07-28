#include "src/rtklib.h"

void main()
{
	//char exsats[1024]=EXBDS_2;
	//double start[] = { 2021,12,20,0,0,0 };
	//double end[] = { 2021,12,20,24,0,0 };
	//gtime_t ts = epoch2time(start), te = epoch2time(end);
	gtime_t ts = { 0 }, te = { 0 };
	prcopt_t opt = prcopt_default;
	solopt_t sopt = solopt_default;
	filopt_t fopt = {""};
		//{""},
		//{"D:\\data\\tbl\\igs14.atx"},
		////{""},
	 //   {"D:\\data\\tbl\\igs14.atx"},
		//{"E:\\GNSS定位原理实习资料\\练习资料\\stations.pos"},
	 //   {""},{"D:\\data\\ion\\igsg3480.21i"},
		//{"D:\\data\\dcb\\P2C22112.DCB"}
	//};

	//char* infile[] = {
	//  {"D:\\data\\obc\\2021\\348\\daily\\uwa03480.21o"},
	//  {"D:\\data\\obm\\2021\\348\\daily\\cut03480.21o"},
	//  {"D:\\data\\nav\\2021\\348\\daily\\brdm3480.21p"}
	//                 };
	//char* ofile = { "D:\\data\\短基线解算结果\\S_f4_GB-GEO_con+lock_uwa03480.pos" };

	char* infile[] = {
	  {"D:\\data\\obm\\2022\\002\\daily\\kir80020.22o"},
	  {"D:\\data\\obm\\2022\\002\\daily\\kiru0020.22o"},
	  //{"D:\\data\\obm\\2022\\002\\daily\\krgg0020.22o"},
	  //{"E:\\实习资料\\hour0020.22p"},
	  {"D:\\data\\nav\\2022\\002\\daily\\brdm0020.22p"},
	  //{"C:\\Users\\tzq\\Desktop\\isc08346.sp3\\isc08346.sp3"},
	 /* {"D:\\data\\obm\\2021\\010\\daily\\mar70100.21o"},
	  {"D:\\data\\obm\\2021\\010\\daily\\mar60100.21o"},
	  {"D:\\data\\nav\\2021\\010\\daily\\brdm0100.21p"},*/
	  //{"D:\\data\\tbl\\igs14.atx"},
	  //{"D:\\data\\dcb\\P2C22112.DCB"},
	  //{"E:\\GNSS定位原理实习资料\\练习资料\\stations.pos"}
	                 };
	char* ofile = { "E:\\GNSS定位原理实习资料\\练习资料\\kir80020.pos" };
	char *Rovers, *Base;

	//char* infile[] = {
	//  {"E:\\实习资料\\练习资料\\wuh23480.obs"},
	//  {"E:\\实习资料\\练习资料\\jfng3480.obs"},
	//  {"D:\\data\\nav\\2021\\348\\daily\\brdm3480.21p"}
	//                 };
	//char* ofile = { "E:\\实习资料\\练习资料\\S_Bb_in_wuh23480.pos" };
	opt.ionoopt = IONOOPT_BRDC;
	opt.tropopt = TROPOPT_SAAS;
	opt.nf = 1;
	opt.navsys = SYS_CMP | SYS_GPS;
	opt.mode = PMODE_MOVEB;
	opt.refpos = 3;
	opt.minlock = 40;
	opt.elmin = 7*D2R;
	//opt.posopt[4] = 1;
	//opt.tidecorr = 1;
	sopt.posf = SOLF_XYZ;
	opt.modear = 1;
	//opt.baseline[0]=1000;
	//opt.baseline[1] = 10;
	//sopt.outhead = 1;
	sopt.outopt = 1;
	//sopt.outvel = 1;
	//sopt.sstat = 2;
	//sopt.trace = 2;
	tracelevel(2);
	//excludesats(exsats, &opt);
	
	Rovers = "kiru krgg pert";
	Base = "";
   	postpos(ts, te, 0, 0, &opt, &sopt, &fopt, infile, 3, ofile, "", "");
	traceclose();
	//rtklib测试 -by Tzq_aust
}
