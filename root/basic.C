#include "Riostream.h"
#include "TH1F.h"
#include "TH2F.h"
#include "math.h"
void makehist(const char* filename, TH1F *h1, Int_t& nlines) {
	string d, pin, pout;
	Double_t x,y,z, ecm_start, ecm_end;
	Int_t nbins;
	ifstream in;
	in.open(filename);
	
	// Read headers.
	in >> pin >> d >> pout >> d >> d >> d >> ecm_start >> d >> ecm_end >> d >> nbins >> d >> d >> d >> d;
	
//	printf("Importing data for process: %3c -> %3c, starting at line %4i.\n",pin,pout,nlines);
	if (nlines < 1) {
		printf("Importing data for process: ");
		cout << pin;
		printf(" -> ");
		cout << pout;
		printf(".\n");
	}

	// Read data.
	while (1) {
		in >> x >> y >> d >> z;
		if (!in.good()) break;
		// if (nlines < 1) printf("First line is: x=%8f, y=%8f, z=%8f\n",x,y,z);
		h1->SetBinContent(nlines+1,y);
		h1->SetBinError(nlines+1,z);
		nlines++;
	}
	
	printf("%d points read\n",nlines);
	
	in.close();
}

void loadhist() {
	Double_t ecm_start=20., ecm_end=1820.;
	Int_t lines = 0, nbins=1800;
	
	TFile *f = new TFile("basic.root","RECREATE");
	
	TH1F *hist1 = new TH1F("hist1","u,u -> g -> d,d",nbins,ecm_start,ecm_end);
	hist1->GetXaxis()->SetTitle("E [GeV]");
	hist1->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_uu_g_dd_20_320.txt", hist1, lines);
	makehist("../data/v4_uu_g_dd_320_620.txt", hist1, lines);
	makehist("../data/v4_uu_g_dd_620_920.txt", hist1, lines);
	makehist("../data/v4_uu_g_dd_920_1220.txt", hist1, lines);
	makehist("../data/v4_uu_g_dd_1220_1520.txt", hist1, lines);
	makehist("../data/v4_uu_g_dd_1520_1820.txt", hist1, lines);
	
	TH1F *hist2 = new TH1F("hist2","g,g -> g -> u,u",nbins,ecm_start,ecm_end);
	hist2->GetXaxis()->SetTitle("E [GeV]");
	hist2->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_gg_g_uu_20_320.txt", hist2, lines);
	makehist("../data/v4_gg_g_uu_320_620.txt", hist2, lines);
	makehist("../data/v4_gg_g_uu_620_920.txt", hist2, lines);
	makehist("../data/v4_gg_g_uu_920_1220.txt", hist2, lines);
	makehist("../data/v4_gg_g_uu_1220_1520.txt", hist2, lines);
	makehist("../data/v4_gg_g_uu_1520_1820.txt", hist2, lines);
	
	TH1F *hist3 = new TH1F("hist3","u,u -> A -> d,d",nbins,ecm_start,ecm_end);
	hist3->GetXaxis()->SetTitle("E [GeV]");
	hist3->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_uu_a_dd_20_320.txt", hist3, lines);
	makehist("../data/v4_uu_a_dd_320_620.txt", hist3, lines);
	makehist("../data/v4_uu_a_dd_620_920.txt", hist3, lines);
	makehist("../data/v4_uu_a_dd_920_1220.txt", hist3, lines);
	makehist("../data/v4_uu_a_dd_1220_1520.txt", hist3, lines);
	makehist("../data/v4_uu_a_dd_1520_1820.txt", hist3, lines);
	
////// TOTAL MUON PRODUKTION VED Z
	TH1F *hist_sm_uu_z = new TH1F("hist_sm_uu_z","u,u -> Z -> mu,mu",nbins,ecm_start,ecm_end);
	hist_sm_uu_z->GetXaxis()->SetTitle("E [GeV]");
	hist_sm_uu_z->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_uu_z_mm_20_320.txt", hist_sm_uu_z, lines);
	makehist("../data/v4_uu_z_mm_320_620.txt", hist_sm_uu_z, lines);
	makehist("../data/v4_uu_z_mm_620_920.txt", hist_sm_uu_z, lines);
	makehist("../data/v4_uu_z_mm_920_1220.txt", hist_sm_uu_z, lines);
	makehist("../data/v4_uu_z_mm_1220_1520.txt", hist_sm_uu_z, lines);
	makehist("../data/v4_uu_z_mm_1520_1820.txt", hist_sm_uu_z, lines);
	
	TH1F *hist_sm_dd_z = new TH1F("hist_sm_dd_z","d,d -> Z -> mu,mu",nbins,ecm_start,ecm_end);
	hist_sm_dd_z->GetXaxis()->SetTitle("E [GeV]");
	hist_sm_dd_z->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_dd_z_mm_20_320.txt", hist_sm_dd_z, lines);
	makehist("../data/v4_dd_z_mm_320_620.txt", hist_sm_dd_z, lines);
	makehist("../data/v4_dd_z_mm_620_920.txt", hist_sm_dd_z, lines);
	makehist("../data/v4_dd_z_mm_920_1220.txt", hist_sm_dd_z, lines);
	makehist("../data/v4_dd_z_mm_1220_1520.txt", hist_sm_dd_z, lines);
	makehist("../data/v4_dd_z_mm_1520_1820.txt", hist_sm_dd_z, lines);
// 	
// 	TH1F *hist_sm_ss_z = new TH1F("hist_sm_ss_z","s,s -> Z -> mu,mu",nbins,ecm_start,ecm_end);
// 	hist_sm_ss_z->GetXaxis()->SetTitle("E [GeV]");
// 	hist_sm_ss_z->GetYaxis()->SetTitle("cross section [pb]");
// 	lines = 0;
// 	makehist("../data/v4_ss_z_mm_20_320.txt", hist_sm_ss_z, lines);
// 	makehist("../data/v4_ss_z_mm_320_620.txt", hist_sm_ss_z, lines);
// 	makehist("../data/v4_ss_z_mm_620_920.txt", hist_sm_ss_z, lines);
// 	makehist("../data/v4_ss_z_mm_920_1220.txt", hist_sm_ss_z, lines);
// 	makehist("../data/v4_ss_z_mm_1220_1520.txt", hist_sm_ss_z, lines);
// 	makehist("../data/v4_ss_z_mm_1520_1820.txt", hist_sm_ss_z, lines);
// 	
// 	TH1F *hist_sm_cc_z = new TH1F("hist_sm_cc_z","c,c -> Z -> mu,mu",nbins,ecm_start,ecm_end);
// 	hist_sm_cc_z->GetXaxis()->SetTitle("E [GeV]");
// 	hist_sm_cc_z->GetYaxis()->SetTitle("cross section [pb]");
// 	lines = 0;
// 	makehist("../data/v4_cc_z_mm_20_320.txt", hist_sm_cc_z, lines);
// 	makehist("../data/v4_cc_z_mm_320_620.txt", hist_sm_cc_z, lines);
// 	makehist("../data/v4_cc_z_mm_620_920.txt", hist_sm_cc_z, lines);
// 	makehist("../data/v4_cc_z_mm_920_1220.txt", hist_sm_cc_z, lines);
// 	makehist("../data/v4_cc_z_mm_1220_1520.txt", hist_sm_cc_z, lines);
// 	makehist("../data/v4_cc_z_mm_1520_1820.txt", hist_sm_cc_z, lines);
// 	
// 	TH1F *hist_sm_bb_z = new TH1F("hist_sm_bb_z","b,b -> Z -> mu,mu",nbins,ecm_start,ecm_end);
// 	hist_sm_bb_z->GetXaxis()->SetTitle("E [GeV]");
// 	hist_sm_bb_z->GetYaxis()->SetTitle("cross section [pb]");
// 	lines = 0;
// 	makehist("../data/v4_bb_z_mm_20_320.txt", hist_sm_bb_z, lines);
// 	makehist("../data/v4_bb_z_mm_320_620.txt", hist_sm_bb_z, lines);
// 	makehist("../data/v4_bb_z_mm_620_920.txt", hist_sm_bb_z, lines);
// 	makehist("../data/v4_bb_z_mm_920_1220.txt", hist_sm_bb_z, lines);
// 	makehist("../data/v4_bb_z_mm_1220_1520.txt", hist_sm_bb_z, lines);
// 	makehist("../data/v4_bb_z_mm_1520_1820.txt", hist_sm_bb_z, lines);
// 	
// ////// TOTAL MJUON PRODUKTION VED GAMMA
// 	TH1F *hist_sm_uu_a = new TH1F("hist_sm_uu_a","u,u -> A -> mu,mu",nbins,ecm_start,ecm_end);
// 	hist_sm_uu_a->GetXaxis()->SetTitle("E [GeV]");
// 	hist_sm_uu_a->GetYaxis()->SetTitle("cross section [pb]");
// 	lines = 0;
// 	makehist("../data/v4_uu_a_mm_20_320.txt", hist_sm_uu_a, lines);
// 	makehist("../data/v4_uu_a_mm_320_620.txt", hist_sm_uu_a, lines);
// 	makehist("../data/v4_uu_a_mm_620_920.txt", hist_sm_uu_a, lines);
// 	makehist("../data/v4_uu_a_mm_920_1220.txt", hist_sm_uu_a, lines);
// 	makehist("../data/v4_uu_a_mm_1220_1520.txt", hist_sm_uu_a, lines);
// 	makehist("../data/v4_uu_a_mm_1520_1820.txt", hist_sm_uu_a, lines);
// 
// 	TH1F *hist_sm_dd_a = new TH1F("hist_sm_dd_a","d,d -> A -> mu,mu",nbins,ecm_start,ecm_end);
// 	hist_sm_dd_a->GetXaxis()->SetTitle("E [GeV]");
// 	hist_sm_dd_a->GetYaxis()->SetTitle("cross section [pb]");
// 	lines = 0;
// 	makehist("../data/v4_dd_a_mm_20_320.txt", hist_sm_dd_a, lines);
// 	makehist("../data/v4_dd_a_mm_320_620.txt", hist_sm_dd_a, lines);
// 	makehist("../data/v4_dd_a_mm_620_920.txt", hist_sm_dd_a, lines);
// 	makehist("../data/v4_dd_a_mm_920_1220.txt", hist_sm_dd_a, lines);
// 	makehist("../data/v4_dd_a_mm_1220_1520.txt", hist_sm_dd_a, lines);
// 	makehist("../data/v4_dd_a_mm_1520_1820.txt", hist_sm_dd_a, lines);
// 
// 	TH1F *hist_sm_ss_a = new TH1F("hist_sm_ss_a","s,s -> A -> mu,mu",nbins,ecm_start,ecm_end);
// 	hist_sm_ss_a->GetXaxis()->SetTitle("E [GeV]");
// 	hist_sm_ss_a->GetYaxis()->SetTitle("cross section [pb]");
// 	lines = 0;
// 	makehist("../data/v4_ss_a_mm_20_320.txt", hist_sm_ss_a, lines);
// 	makehist("../data/v4_ss_a_mm_320_620.txt", hist_sm_ss_a, lines);
// 	makehist("../data/v4_ss_a_mm_620_920.txt", hist_sm_ss_a, lines);
// 	makehist("../data/v4_ss_a_mm_920_1220.txt", hist_sm_ss_a, lines);
// 	makehist("../data/v4_ss_a_mm_1220_1520.txt", hist_sm_ss_a, lines);
// 	makehist("../data/v4_ss_a_mm_1520_1820.txt", hist_sm_ss_a, lines);
// 
// 	TH1F *hist_sm_cc_a = new TH1F("hist_sm_cc_a","c,c -> A -> mu,mu",nbins,ecm_start,ecm_end);
// 	hist_sm_cc_a->GetXaxis()->SetTitle("E [GeV]");
// 	hist_sm_cc_a->GetYaxis()->SetTitle("cross section [pb]");
// 	lines = 0;
// 	makehist("../data/v4_cc_a_mm_20_320.txt", hist_sm_cc_a, lines);
// 	makehist("../data/v4_cc_a_mm_320_620.txt", hist_sm_cc_a, lines);
// 	makehist("../data/v4_cc_a_mm_620_920.txt", hist_sm_cc_a, lines);
// 	makehist("../data/v4_cc_a_mm_920_1220.txt", hist_sm_cc_a, lines);
// 	makehist("../data/v4_cc_a_mm_1220_1520.txt", hist_sm_cc_a, lines);
// 	makehist("../data/v4_cc_a_mm_1520_1820.txt", hist_sm_cc_a, lines);
// 
// 	TH1F *hist_sm_bb_a = new TH1F("hist_sm_bb_a","b,b -> A -> mu,mu",nbins,ecm_start,ecm_end);
// 	hist_sm_bb_a->GetXaxis()->SetTitle("E [GeV]");
// 	hist_sm_bb_a->GetYaxis()->SetTitle("cross section [pb]");
// 	lines = 0;
// 	makehist("../data/v4_bb_a_mm_20_320.txt", hist_sm_bb_a, lines);
// 	makehist("../data/v4_bb_a_mm_320_620.txt", hist_sm_bb_a, lines);
// 	makehist("../data/v4_bb_a_mm_620_920.txt", hist_sm_bb_a, lines);
// 	makehist("../data/v4_bb_a_mm_920_1220.txt", hist_sm_bb_a, lines);
// 	makehist("../data/v4_bb_a_mm_1220_1520.txt", hist_sm_bb_a, lines);
// 	makehist("../data/v4_bb_a_mm_1520_1820.txt", hist_sm_bb_a, lines);
	
	f->Write();
}

void test() {
	hist_sm_uu_z->Add(hist_sm_dd_z);
	hist_sm_uu_z->Draw();
}

void test2() {
	test();
}

void plot(TH1F *h1, const char* canvas, Int_t log) {
	TCanvas *c1 = new TCanvas(canvas,"Canvas 1",1000,750);
	if (log = 1) c1->SetLogy();
	h1->Draw("e");
}

void pdfratio(TH1F *hist_pdf) { 
	//// Calculating the PDF ratio
	hist1->Clone("hist_pdf"); // This is just to get the same number of bins, etc.
	hist_pdf->SetTitle("-1 x 64(gg -> g -> uu) / 9(uu -> g -> dd)");
	hist_pdf->GetXaxis()->SetTitle("GeV");
	hist_pdf->GetYaxis()->SetTitle("ratio");
	hist_pdf->Reset();
	
	// Divide the two histograms and divide by -9/64,
	// minus sign from taking only s-channel contribution.
	hist_pdf->Divide(hist2,hist1,-64,9);
	
	// // And plot the ratio distribution.
	// TCanvas *c1 = new TCanvas("c1","-1 x 64(gg -> g -> uu) / 9(uu -> g -> dd)",1000,750);
	// c1->SetLogy();
	// histdiv->Draw("e");
}

void calcsmtot() {
			// // // // // // // // // // // // // // // // // //
			// // // //  Plot Total SM Cross section // // // // // // // //
			// // // // // // // // // // // // // // // // // //	
			TH1F *hist_total_sm = hist1->Clone("hist_total_sm");
			hist_total_sm->SetTitle("Total cross section at LHC ordinary SM");
			hist_total_sm->GetXaxis()->SetTitle("E [GeV]");
			hist_total_sm->GetYaxis()->SetTitle("Number of events");
			hist_total_sm->Reset();
			
			// Adding z contributions
			hist_total_sm->Add(hist_sm_uu_z);
			hist_total_sm->Add(hist_sm_dd_z);
			// hist_total_sm->Add(hist_sm_cc_z);
			// hist_total_sm->Add(hist_sm_ss_z);
			// hist_total_sm->Add(hist_sm_bb_z);
			
			// // Adding gamma contributions
			// hist_total_sm->Add(hist_sm_uu_a);
			// hist_total_sm->Add(hist_sm_dd_a);
			// hist_total_sm->Add(hist_sm_cc_a);
			// hist_total_sm->Add(hist_sm_ss_a);
			// hist_total_sm->Add(hist_sm_bb_a);
			
			// Multiplying by two possible initial states per diagram
			hist_total_sm->Scale(2.);
			
			// Scale up to number of events at LHC running at 10 fb^-1 / year
			hist_total_sm->Scale(10000);
			
			Float_t bin, Int_t i;
			for (i = 1; i <= 1820; i++) {
				bin = hist_total_sm->GetBinContent(i);
				hist_total_sm->SetBinError(i,sqrt(bin));
			}
}

void calcncgfactor(TH1F *histmultiply, Float_t lambda) {
	Double_t ecm_start=20., ecm_end=1820.;
	Int_t lines = 0, nbins=1800, i;
	
	TH1F *hist_pdf = hist1->Clone("hist_pdf");
	hist_pdf->Reset(); 
	pdfratio(hist_pdf); // Call function to make PDF ratio.
	
	// // // // // // // // // // // // // // // // // // // //
	// Multiply histogram by NCG constant  // // // // // // //
	// // // // // // // // // // // // // // // // // // // //
	
	// Making the theta histogram.
	TH1F *histtheta = hist1->Clone("histtheta");
	histtheta->Reset();

	Int_t i;
	Double_t theta;
	for (i = 1; i <= nbins; i++) {
		theta = 1.*i*i / pow(lambda,4);
		histtheta->SetBinContent(i,theta);
	}
	
	// Doing the multiplication. (Here comes the fudge factor!)
		histmultiply -> Multiply(hist_pdf,histtheta,1.,1.);
	
	// Double_t x, y;
	// for (i = 1; i <= 1820; i++) {
	// 	x = hist_pdf->GetBinContent(i);
	// 	y = histtheta->GetBinContent(i);
	// 	histmultiply->SetBinContent(i,x*y);
	// }
	
	// // Lets draw it.
	// TCanvas *c2 = new TCanvas("c2","theta_NCG x -1 x 64(gg -> g -> uu) / 9(uu -> g -> dd)",1000,750);
	// c2->SetLogy();
	// histmultiply->Draw("e");
	
	// // // // // // // // // // // // // // // // // // 
	// Calculating (1+theta*P_gg/P_qq) = (histncgfactor).
	// // // // // // // // // // // // // // // // // // 
	
	// Making the 1 histogram.
	TH1F *histone = hist1->Clone("histone");
	histone->Reset();

	Double_t one = 1;
	for (i = 1; i <= nbins; i++) {
		histone->SetBinContent(i,1);
	}
	
	// Adding the one histogram into final histogram: the histncgfactor.
	
	histmultiply->Add(histone);
	
}

void calcncgtot(TH1F *hist_total_ncg, Float_t lambda) {

	TH1F *histncgfactor = hist1->Clone("histncgfactor");
	histncgfactor->Reset();

	calcncgfactor(histncgfactor,lambda); // Calculate NCG factor (1 + theta * pp_gg/pp_qq)

	// hist1->Clone("hist_total_ncg"); // This is just to get the same number of bins, etc.
	// hist_total_ncg->SetTitle("Total cross section at LHC including NCG");
	// hist_total_ncg->GetXaxis()->SetTitle("E [GeV]");
	// hist_total_ncg->GetYaxis()->SetTitle("Number of events");
	// hist_total_ncg->Reset();
	
	TH1F *h1 = hist1->Clone("h1");

		// Calculating sigma_qq*P_qq * (1+theta*P_gg/P_qq).
		h1->Reset();
		hist_sm_uu_z->Multiply(histncgfactor);
		hist_total_ncg->Add(hist_sm_uu_z);
		h1->Reset();
		hist_sm_dd_z->Multiply(histncgfactor);
		hist_total_ncg->Add(hist_sm_dd_z);
		// h1->Reset();
		// h1->Multiply(hist_sm_cc_z,histncgfactor,1,1);
		// hist_total_ncg->Add(h1);
		// h1->Reset();
		// h1->Multiply(hist_sm_ss_z,histncgfactor,1,1);
		// hist_total_ncg->Add(h1);

		// Adding gamma contributions
		// hist_total_ncg->Add(hist_sm_uu_a);
		// hist_total_ncg->Add(hist_sm_dd_a);
		// hist_total_ncg->Add(hist_sm_cc_a);
		// hist_total_ncg->Add(hist_sm_ss_a);
		// hist_total_ncg->Add(hist_sm_bb_a);
		
		// Multiplying by two possible initial states per diagram
		hist_total_ncg->Scale(2.);
		
		// Scale up to number of events at LHC running at 10 fb^-1 / year
		hist_total_ncg->Scale(10000);
}

void drawhist(Int_t nr) {
	
	switch(nr) {
		case 1:
			TCanvas *c1 = new TCanvas("c1","u,u -> g -> d,d",1000,750);
			c1->SetLogy();
			hist1->Draw("e");
			TCanvas *c2 = new TCanvas("c2","g,g -> g -> u,u",1000,750);
			hist2->Draw("e");
			TCanvas *c3 = new TCanvas("c3","u,u -> A -> d,d",1000,750);
			c3->SetLogy();
			hist3->Draw("e");
			TCanvas *c4 = new TCanvas("c4","u,u -> Z -> mu,mu",1000,750);
			c4->SetLogy();
			hist_sm_uu_z->Draw("e");
		break;

		case 2:
			
			// // // // // // // // // // // // // // // // // //
			// // // //  Integrated Cross-section  // // // // //
			// // // // // // // // // // // // // // // // // //

			Int_t uppercut=1400;
			TH1F *intcut = new TH1F("intcut","Integrated cross section for uu -> z -> mm vs. sqrt(s) cut",uppercut,20.,uppercut + 20.);
			intcut->GetXaxis()->SetTitle("sqrt(s) lower bin limit [GeV]");
			intcut->GetYaxis()->SetTitle("Number of events (luminosity = 10 fb^-1) / 10 GeV");

			Int_t i;
			for (i = 1; i <= uppercut; i++) {
				intcut->SetBinContent(i,hist_sm_uu_z->Integral(i,1820));
			}
			
			// // Scale to number of events at LCH running at 10 fb^-1 // //
			intcut->Scale(10000.);
			
			TCanvas *c1 = new TCanvas("c1","Integrated cross section vs. sqrt(s) cut",1000,750);
			c1->SetLogy();
			intcut->Draw();
			
		break;
			
		case 3:
		
		Double_t ecm_start=20., ecm_end=1820.;
		Int_t lines = 0, nbins=1800;
		
			// Plot total SM cross section (with statistical error-band) and NCG cross sections.

			// Calculate NCG total cross sections for different lambda.

			TH1F *ncg_200 = new TH1F("ncg_200","NCG 200",nbins,ecm_start,ecm_end);
			calcncgtot(ncg_200,200);
			
			TH1F *ncg_400 = new TH1F("ncg_400","NCG 400",nbins,ecm_start,ecm_end);
			calcncgtot(ncg_400,400);
			
			TH1F *ncg_600 = new TH1F("ncg_600","NCG 600",nbins,ecm_start,ecm_end);
			calcncgtot(ncg_600,600);
			
			TH1F *ncg_800 = new TH1F("ncg_800","NCG 800",nbins,ecm_start,ecm_end);
			calcncgtot(ncg_800,800);
			
			TH1F *ncg_1000 = new TH1F("ncg_1000","NCG 1000",nbins,ecm_start,ecm_end);
			calcncgtot(ncg_1000,1000);








			// TH1F *ncg_200 = hist_total_ncg->Clone("ncg_200");
			// calcncgtot(ncg_200,200);
			// 
			// TH1F *ncg_400 = hist_total_ncg->Clone("ncg_400");
			// calcncgtot(ncg_400,400);
			// 
			// TH1F *ncg_600 = hist_total_ncg->Clone("ncg_600");
			// calcncgtot(ncg_600,600);
			// 
			// TH1F *ncg_800 = hist_total_ncg->Clone("ncg_800");
			// calcncgtot(ncg_800,800);
			// 
			// TH1F *ncg_1000 = hist_total_ncg->Clone("ncg_1000");
			// calcncgtot(ncg_1000,1000);
			
			// Plot total NCG cross section as a function of lambda
			TCanvas *c1 = new TCanvas("c1","Total cross section at LHC",1000,750);
		//	c1->SetLogy();

			ncg_200->Draw("LPe0");
			ncg_400->Draw("LPe0");
			ncg_600->Draw("LPe0");
			ncg_800->Draw("LPe0");
			ncg_1000->Draw("LPe0");		
			
			// Calculate ordinary SM total cross section and plot it with statistical errors.
			
			calcsmtot();
			
			hist_total_sm->Draw("LPe0");
					
		break;

		// default:
		// 	cout << "Please enter a number from 1 to 2.";
	}

}
