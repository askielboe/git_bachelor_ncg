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
		printf("\n");		
		printf("----------- Importing data for process -----------\n");
		printf("-------------------- ");
		cout << pin;
		printf(" -> ");
		cout << pout;
		printf(" ------------------\n");
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
	
	printf("Read from %i to %i GeV (%d points total)\n",ecm_start,ecm_end,nlines);
	
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
	
	// TH1F *hist3 = new TH1F("hist3","u,u -> A -> d,d",nbins,ecm_start,ecm_end);
	// hist3->GetXaxis()->SetTitle("E [GeV]");
	// hist3->GetYaxis()->SetTitle("cross section [pb]");
	// lines = 0;
	// makehist("../data/v4_uu_a_dd_20_320.txt", hist3, lines);
	// makehist("../data/v4_uu_a_dd_320_620.txt", hist3, lines);
	// makehist("../data/v4_uu_a_dd_620_920.txt", hist3, lines);
	// makehist("../data/v4_uu_a_dd_920_1220.txt", hist3, lines);
	// makehist("../data/v4_uu_a_dd_1220_1520.txt", hist3, lines);
	// makehist("../data/v4_uu_a_dd_1520_1820.txt", hist3, lines);
	
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
	
	// TH1F *hist_sm_dd_z = new TH1F("hist_sm_dd_z","d,d -> Z -> mu,mu",nbins,ecm_start,ecm_end);
	// hist_sm_dd_z->GetXaxis()->SetTitle("E [GeV]");
	// hist_sm_dd_z->GetYaxis()->SetTitle("cross section [pb]");
	// lines = 0;
	// makehist("../data/v4_dd_z_mm_20_320.txt", hist_sm_dd_z, lines);
	// makehist("../data/v4_dd_z_mm_320_620.txt", hist_sm_dd_z, lines);
	// makehist("../data/v4_dd_z_mm_620_920.txt", hist_sm_dd_z, lines);
	// makehist("../data/v4_dd_z_mm_920_1220.txt", hist_sm_dd_z, lines);
	// makehist("../data/v4_dd_z_mm_1220_1520.txt", hist_sm_dd_z, lines);
	// makehist("../data/v4_dd_z_mm_1520_1820.txt", hist_sm_dd_z, lines);
	//  	
	//  	TH1F *hist_sm_ss_z = new TH1F("hist_sm_ss_z","s,s -> Z -> mu,mu",nbins,ecm_start,ecm_end);
	//  	hist_sm_ss_z->GetXaxis()->SetTitle("E [GeV]");
	//  	hist_sm_ss_z->GetYaxis()->SetTitle("cross section [pb]");
	// lines = 0;
	// makehist("../data/v4_ss_z_mm_20_320.txt", hist_sm_ss_z, lines);
	// makehist("../data/v4_ss_z_mm_320_620.txt", hist_sm_ss_z, lines);
	// makehist("../data/v4_ss_z_mm_620_920.txt", hist_sm_ss_z, lines);
	// makehist("../data/v4_ss_z_mm_920_1220.txt", hist_sm_ss_z, lines);
	// makehist("../data/v4_ss_z_mm_1220_1520.txt", hist_sm_ss_z, lines);
	// makehist("../data/v4_ss_z_mm_1520_1820.txt", hist_sm_ss_z, lines);
	// 
	// TH1F *hist_sm_cc_z = new TH1F("hist_sm_cc_z","c,c -> Z -> mu,mu",nbins,ecm_start,ecm_end);
	// hist_sm_cc_z->GetXaxis()->SetTitle("E [GeV]");
	// hist_sm_cc_z->GetYaxis()->SetTitle("cross section [pb]");
	// lines = 0;
	// makehist("../data/v4_cc_z_mm_20_320.txt", hist_sm_cc_z, lines);
	// makehist("../data/v4_cc_z_mm_320_620.txt", hist_sm_cc_z, lines);
	// makehist("../data/v4_cc_z_mm_620_920.txt", hist_sm_cc_z, lines);
	// makehist("../data/v4_cc_z_mm_920_1220.txt", hist_sm_cc_z, lines);
	// makehist("../data/v4_cc_z_mm_1220_1520.txt", hist_sm_cc_z, lines);
	// makehist("../data/v4_cc_z_mm_1520_1820.txt", hist_sm_cc_z, lines);
// 	
// ////// TOTAL MUON PRODUKTION VED GAMMA
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
}

void calcsmtot() {
			TH1F *hist_total_sm = hist1->Clone("hist_total_sm");
			hist_total_sm->SetTitle("Total cross section at LHC ordinary SM");
			hist_total_sm->GetXaxis()->SetTitle("E [GeV]");
			hist_total_sm->GetYaxis()->SetTitle("Number of events");
			hist_total_sm->Reset();
			
			// Adding z contributions
			hist_total_sm->Add(hist_sm_uu_z);
			// hist_total_sm->Add(hist_sm_dd_z);
			// hist_total_sm->Add(hist_sm_ss_z);
			// hist_total_sm->Add(hist_sm_cc_z);
			
			// // Adding gamma contributions
			// hist_total_sm->Add(hist_sm_uu_a);
			// hist_total_sm->Add(hist_sm_dd_a);
			// hist_total_sm->Add(hist_sm_cc_a);
			// hist_total_sm->Add(hist_sm_ss_a);
			
			// Multiplying by two possible initial states per diagram
			hist_total_sm->Scale(2.);
			
			// Scale up to number of events at LHC running at 10 fb^-1 / year
			hist_total_sm->Scale(10000.);
			
			// Set error of 1/sqrt(events) per bin
			Float_t bin, Int_t i;
			for (i = 1; i <= 1820; i++) {
				bin = hist_total_sm->GetBinContent(i);
				hist_total_sm->SetBinError(i,sqrt(bin));
			}
}

void calcncgfactor(TH1F *histmultiply, Float_t lambda, Int_t gen) {
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
	Float_t s;
	Float_t Zmass = 91.1876, alphazmass = 1./128., sinw = 0.480832611, cosw = 0.876740947, Kgg = 0.2, Pi = 3.14159265;
	Float_t Zwidthfull = 2.4952, Zwidthfracmu = 0.03366, Zwidthfracuc = 0.116, Zwidthfracdsb = 0.156;
	Double_t theta, Ggg, Crossqq, gz;
	
	Ggg = (pow(8./12. * alphazmass,1/2) * sinw * Kgg * 1./pow(lambda,2));
	
	for (i = 1; i <= nbins; i++) {
		s = pow(i+20.,2);
		gz = pow(4.*Pi*alphazmass,1/2) * (0.5 - 2./3.*pow(sinw,2)) / (sinw * cosw);
		if (gen = 1) {
			Crossqq = (12 * Pi / pow(Zmass,2) * Zwidthfracmu * Zwidthfracuc * s * pow(Zwidthfull,2));
			Crossqq = Crossqq / (pow(s - pow(Zmass,2),2) + pow(s,2) * pow(Zwidthfull,2) / pow(Zmass,2));
		}
		else if (gen = 2) {
			Crossqq = (12. * Pi / pow(Zmass,2) * Zwidthfracmu * Zwidthfracdsb * s * pow(Zwidthfull,2));
			Crossqq = Crossqq / (pow(s - pow(Zmass,2),2) + pow(s,2) * pow(Zwidthfull,2) / pow(Zmass,2));	
		}
		theta = pow(Ggg,2) * s * pow(gz,2) / Crossqq;
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

	hist_total_ncg->Reset();
	
	TH1F *histncgfactor = hist1->Clone("histncgfactor");
	histncgfactor->Reset();	
	TH1F *h1 = hist1->Clone("h1");

		// Calculating sigma_qq*P_qq * (1+theta*P_gg/P_qq).

		calcncgfactor(histncgfactor,lambda,1); 	 // Calculate NCG factor (1 + theta * pp_gg/pp_qq)

		TCanvas *c6 = new TCanvas("c6","histncgfactor before multiply",1000,750);				
		c6->SetLogy();
		histncgfactor->Draw();

		h1->Multiply(hist_sm_uu_z,histncgfactor,1.,1.);
		hist_total_ncg->Add(h1);
			
			TCanvas *c2 = new TCanvas("c2","hist_sm_uu_z",1000,750);	
			c2->SetLogy();
			hist_sm_uu_z->Draw();
			
			TCanvas *c3 = new TCanvas("c3","histncgfactor after multiply",1000,750);				
			c3->SetLogy();
			histncgfactor->Draw();
						
			TCanvas *c4 = new TCanvas("c4","hist_total_ncg",1000,750);
			c4->SetLogy();
			hist_total_ncg->Draw();
			
			TCanvas *c5 = new TCanvas("c5","h1",1000,750);
			c5->SetLogy();
			h1->Draw();			

		// hist_sm_cc_z->Multiply(histncgfactor);
		// hist_total_ncg->Add(hist_sm_cc_z);
		// 
		// histncgfactor->Reset();
		// calcncgfactor(histncgfactor,lambda,2); 	 // Calculate NCG factor (1 + theta * pp_gg/pp_qq)
		// 
		// hist_sm_dd_z->Multiply(histncgfactor);
		// hist_total_ncg->Add(hist_sm_dd_z);
		// 
		// hist_sm_ss_z->Multiply(histncgfactor);
		// hist_total_ncg->Add(hist_sm_ss_z);

		// Adding gamma contributions
		// hist_total_ncg->Add(hist_sm_uu_a);
		// hist_total_ncg->Add(hist_sm_dd_a);
		// hist_total_ncg->Add(hist_sm_cc_a);
		// hist_total_ncg->Add(hist_sm_ss_a);
		
		// Multiplying by two possible initial states per diagram
		hist_total_ncg->Scale(2.);
		
		// Scale up to number of events at LHC running at 10 fb^-1 / year
		hist_total_ncg->Scale(10000.);
}

void drawhist(Int_t nr) {
	
	switch(nr) {
		// case 1:
		// 	TCanvas *c1 = new TCanvas("c1","u,u -> g -> d,d",1000,750);
		// 	c1->SetLogy();
		// 	hist1->Draw("e");
		// 	TCanvas *c2 = new TCanvas("c2","g,g -> g -> u,u",1000,750);
		// 	hist2->Draw("e");
		// 	// TCanvas *c3 = new TCanvas("c3","u,u -> A -> d,d",1000,750);
		// 	// c3->SetLogy();
		// 	// hist3->Draw("e");
		// 	TCanvas *c4 = new TCanvas("c4","u,u -> Z -> mu,mu",1000,750);
		// 	c4->SetLogy();
		// 	hist_sm_uu_z->Draw("e");
		// break;

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

			// TH1F *ncg_test = new TH1F("ncg_test","NCG TEST",nbins,ecm_start,ecm_end);
			// calcncgtot(ncg_test,200.);

			TH1F *ncg_130 = new TH1F("ncg_130","NCG 130",nbins,ecm_start,ecm_end);
			calcncgtot(ncg_130,130.);
			
			// TH1F *ncg_200 = new TH1F("ncg_200","NCG 200",nbins,ecm_start,ecm_end);
			// calcncgtot(ncg_200,200.);
			// 
			// TH1F *ncg_400 = new TH1F("ncg_400","NCG 400",nbins,ecm_start,ecm_end);
			// calcncgtot(ncg_400,400.);
			// 
			// TH1F *ncg_600 = new TH1F("ncg_600","NCG 600",nbins,ecm_start,ecm_end);
			// calcncgtot(ncg_600,600.);
			// 
			// TH1F *ncg_800 = new TH1F("ncg_800","NCG 800",nbins,ecm_start,ecm_end);
			// calcncgtot(ncg_800,800.);
			// 
			// TH1F *ncg_1000 = new TH1F("ncg_1000","NCG 1000",nbins,ecm_start,ecm_end);
			// calcncgtot(ncg_1000,1000.);
			
			// Plot total NCG cross section as a function of lambda
			TCanvas *c1 = new TCanvas("c1","Total cross section at LHC",1000,750);
		    c1->SetLogy();

			calcsmtot();
			hist_total_sm->SetLineColor(18);
			hist_total_sm->Draw("e0");
			
			// ncg_test->SetLineColor(9);
			// ncg_test->Draw("same");
			
			ncg_130->SetLineColor(9);
			ncg_130->Draw("same");
			
			// ncg_200->SetLineColor(9);
			// ncg_200->Draw("same");
			// 
			// ncg_400->SetLineColor(9);
			// ncg_400->Draw("same");
			// 
			// ncg_600->SetLineColor(9);
			// ncg_600->Draw("same");
			// 
			// ncg_800->SetLineColor(9);
			// ncg_800->Draw("same");
			// 
			// ncg_1000->SetLineColor(9);
			// ncg_1000->Draw("same");
			
			// Calculate ordinary SM total cross section and plot it with statistical errors.
					
		break;

		// default:
		// 	cout << "Please enter a number from 1 to 2.";
	}

}
