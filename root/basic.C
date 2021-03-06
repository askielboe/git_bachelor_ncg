#include "Riostream.h"
#include "TFile.h"
#include "TH1F.h"
#include "TF1.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "math.h"
#include "TRandom.h"

TH1F *hist1;
TH1F *hist2;
TH1F *hist_sm_uu_z;
TH1F *hist_sm_dd_z;
TH1F *hist_sm_ss_z;
TH1F *hist_sm_cc_z;
TH1F *hist_sm_uu_a;
TH1F *hist_sm_dd_a;
TH1F *hist_sm_cc_a;
TH1F *hist_sm_ss_a;
TH1F *hist_total_sm;
//TH1F *;



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
	
	printf("Reading from file %s, ",filename);
	printf("loading bins from %f to %f GeV (%d points total)\n",ecm_start,ecm_end,nlines);
	
	in.close();
}

void loadhist() {
	Double_t ecm_start=20., ecm_end=1820.;
	Int_t lines = 0, nbins=1800;
	
	TFile *f = new TFile("basic.root","RECREATE");
	
	hist1 = new TH1F("hist1","u,u -> g -> d,d",nbins,ecm_start,ecm_end);
	hist1->GetXaxis()->SetTitle("E [GeV]");
	hist1->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_uu_g_dd_20_320.txt", hist1, lines);
	makehist("../data/v4_uu_g_dd_320_620.txt", hist1, lines);
	makehist("../data/v4_uu_g_dd_620_920.txt", hist1, lines);
	makehist("../data/v4_uu_g_dd_920_1220.txt", hist1, lines);
	makehist("../data/v4_uu_g_dd_1220_1520.txt", hist1, lines);
	makehist("../data/v4_uu_g_dd_1520_1820.txt", hist1, lines);
	
	hist2 = new TH1F("hist2","g,g -> g -> u,u",nbins,ecm_start,ecm_end);
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
	hist_sm_uu_z = new TH1F("hist_sm_uu_z","u,u -> Z -> mu,mu",nbins,ecm_start,ecm_end);
	hist_sm_uu_z->GetXaxis()->SetTitle("E [GeV]");
	hist_sm_uu_z->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_uu_z_mm_20_320.txt", hist_sm_uu_z, lines);
	makehist("../data/v4_uu_z_mm_320_620.txt", hist_sm_uu_z, lines);
	makehist("../data/v4_uu_z_mm_620_920.txt", hist_sm_uu_z, lines);
	makehist("../data/v4_uu_z_mm_920_1220.txt", hist_sm_uu_z, lines);
	makehist("../data/v4_uu_z_mm_1220_1520.txt", hist_sm_uu_z, lines);
	makehist("../data/v4_uu_z_mm_1520_1820.txt", hist_sm_uu_z, lines);
	
	hist_sm_dd_z = new TH1F("hist_sm_dd_z","d,d -> Z -> mu,mu",nbins,ecm_start,ecm_end);
	hist_sm_dd_z->GetXaxis()->SetTitle("E [GeV]");
	hist_sm_dd_z->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_dd_z_mm_20_320.txt", hist_sm_dd_z, lines);
	makehist("../data/v4_dd_z_mm_320_620.txt", hist_sm_dd_z, lines);
	makehist("../data/v4_dd_z_mm_620_920.txt", hist_sm_dd_z, lines);
	makehist("../data/v4_dd_z_mm_920_1220.txt", hist_sm_dd_z, lines);
	makehist("../data/v4_dd_z_mm_1220_1520.txt", hist_sm_dd_z, lines);
	makehist("../data/v4_dd_z_mm_1520_1820.txt", hist_sm_dd_z, lines);
	 	
	hist_sm_ss_z = new TH1F("hist_sm_ss_z","s,s -> Z -> mu,mu",nbins,ecm_start,ecm_end);
	hist_sm_ss_z->GetXaxis()->SetTitle("E [GeV]");
	hist_sm_ss_z->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_ss_z_mm_20_320.txt", hist_sm_ss_z, lines);
	makehist("../data/v4_ss_z_mm_320_620.txt", hist_sm_ss_z, lines);
	makehist("../data/v4_ss_z_mm_620_920.txt", hist_sm_ss_z, lines);
	makehist("../data/v4_ss_z_mm_920_1220.txt", hist_sm_ss_z, lines);
	makehist("../data/v4_ss_z_mm_1220_1520.txt", hist_sm_ss_z, lines);
	makehist("../data/v4_ss_z_mm_1520_1820.txt", hist_sm_ss_z, lines);
	
	hist_sm_cc_z = new TH1F("hist_sm_cc_z","c,c -> Z -> mu,mu",nbins,ecm_start,ecm_end);
	hist_sm_cc_z->GetXaxis()->SetTitle("E [GeV]");
	hist_sm_cc_z->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_cc_z_mm_20_320.txt", hist_sm_cc_z, lines);
	makehist("../data/v4_cc_z_mm_320_620.txt", hist_sm_cc_z, lines);
	makehist("../data/v4_cc_z_mm_620_920.txt", hist_sm_cc_z, lines);
	makehist("../data/v4_cc_z_mm_920_1220.txt", hist_sm_cc_z, lines);
	makehist("../data/v4_cc_z_mm_1220_1520.txt", hist_sm_cc_z, lines);
	makehist("../data/v4_cc_z_mm_1520_1820.txt", hist_sm_cc_z, lines);
// 	
////// TOTAL MUON PRODUKTION VED GAMMA
	hist_sm_uu_a = new TH1F("hist_sm_uu_a","u,u -> A -> mu,mu",nbins,ecm_start,ecm_end);
	hist_sm_uu_a->GetXaxis()->SetTitle("E [GeV]");
	hist_sm_uu_a->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_uu_a_mm_20_320.txt", hist_sm_uu_a, lines);
	makehist("../data/v4_uu_a_mm_320_620.txt", hist_sm_uu_a, lines);
	makehist("../data/v4_uu_a_mm_620_920.txt", hist_sm_uu_a, lines);
	makehist("../data/v4_uu_a_mm_920_1220.txt", hist_sm_uu_a, lines);
	makehist("../data/v4_uu_a_mm_1220_1520.txt", hist_sm_uu_a, lines);
	makehist("../data/v4_uu_a_mm_1520_1820.txt", hist_sm_uu_a, lines);

	hist_sm_dd_a = new TH1F("hist_sm_dd_a","d,d -> A -> mu,mu",nbins,ecm_start,ecm_end);
	hist_sm_dd_a->GetXaxis()->SetTitle("E [GeV]");
	hist_sm_dd_a->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_dd_a_mm_20_320.txt", hist_sm_dd_a, lines);
	makehist("../data/v4_dd_a_mm_320_620.txt", hist_sm_dd_a, lines);
	makehist("../data/v4_dd_a_mm_620_920.txt", hist_sm_dd_a, lines);
	makehist("../data/v4_dd_a_mm_920_1220.txt", hist_sm_dd_a, lines);
	makehist("../data/v4_dd_a_mm_1220_1520.txt", hist_sm_dd_a, lines);
	makehist("../data/v4_dd_a_mm_1520_1820.txt", hist_sm_dd_a, lines);

	hist_sm_ss_a = new TH1F("hist_sm_ss_a","s,s -> A -> mu,mu",nbins,ecm_start,ecm_end);
	hist_sm_ss_a->GetXaxis()->SetTitle("E [GeV]");
	hist_sm_ss_a->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_ss_a_mm_20_320.txt", hist_sm_ss_a, lines);
	makehist("../data/v4_ss_a_mm_320_620.txt", hist_sm_ss_a, lines);
	makehist("../data/v4_ss_a_mm_620_920.txt", hist_sm_ss_a, lines);
	makehist("../data/v4_ss_a_mm_920_1220.txt", hist_sm_ss_a, lines);
	makehist("../data/v4_ss_a_mm_1220_1520.txt", hist_sm_ss_a, lines);
	makehist("../data/v4_ss_a_mm_1520_1820.txt", hist_sm_ss_a, lines);

	hist_sm_cc_a = new TH1F("hist_sm_cc_a","c,c -> A -> mu,mu",nbins,ecm_start,ecm_end);
	hist_sm_cc_a->GetXaxis()->SetTitle("E [GeV]");
	hist_sm_cc_a->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_cc_a_mm_20_320.txt", hist_sm_cc_a, lines);
	makehist("../data/v4_cc_a_mm_320_620.txt", hist_sm_cc_a, lines);
	makehist("../data/v4_cc_a_mm_620_920.txt", hist_sm_cc_a, lines);
	makehist("../data/v4_cc_a_mm_920_1220.txt", hist_sm_cc_a, lines);
	makehist("../data/v4_cc_a_mm_1220_1520.txt", hist_sm_cc_a, lines);
	makehist("../data/v4_cc_a_mm_1520_1820.txt", hist_sm_cc_a, lines);
	
	f->Write();
}

void pdfratio(TH1F *hist_pdf) { 
	//// Calculating the PDF ratio
	hist_pdf->SetTitle("-1 x 64(gg -> g -> uu) / 9(uu -> g -> dd)");
	hist_pdf->GetXaxis()->SetTitle("GeV");
	hist_pdf->GetYaxis()->SetTitle("ratio");
	hist_pdf->Reset();
	
	// Divide the two histograms and divide by -9/64,
	// minus sign from taking only s-channel contribution.
	hist_pdf->Divide(hist2,hist1,-64,9);
}

double pdfratiobin(int ibin) { 
	//// Calculating the PDF ratio	
	return -64.*hist2->GetBinContent(ibin)/hist1->GetBinContent(ibin)/9.;
	// Divide the two histograms and divide by -9/64,
	// minus sign from taking only s-channel contribution.
}

void calcsmtot() {
			hist_total_sm = (TH1F*)hist1->Clone("hist_total_sm");
			hist_total_sm->Reset();
			
			// Adding z contributions
			hist_total_sm->Add(hist_sm_uu_z);
			hist_total_sm->Add(hist_sm_dd_z);
			hist_total_sm->Add(hist_sm_ss_z);
			hist_total_sm->Add(hist_sm_cc_z);
			
			// Adding gamma contributions
			hist_total_sm->Add(hist_sm_uu_a);
			hist_total_sm->Add(hist_sm_dd_a);
			hist_total_sm->Add(hist_sm_cc_a);
			hist_total_sm->Add(hist_sm_ss_a);
			
			// Multiplying by two possible initial states per diagram
			hist_total_sm->Scale(2.);
			
			// Scale up to number of events at LHC running at 10 fb^-1 / year
			hist_total_sm->Scale(10000.);
			
			// Set error of 1/sqrt(events) per bin
			Float_t bin;
			Int_t i;
			for (i = 1; i <= 1820; i++) {
				bin = hist_total_sm->GetBinContent(i);
				hist_total_sm->SetBinError(i,1.64*sqrt(bin));
			}
}

void calcncgfactor(TH1F *histncgfactor, Float_t lambda, Int_t gen) {
	Int_t nbins=1800, i;
	
	TH1F *hist_pdf = (TH1F*)hist1->Clone("hist_pdf");
	hist_pdf->Reset(); 
	pdfratio(hist_pdf); // Call function to make PDF ratio.
	
	// // // // // // // // // // // // // // // // // // // //
	// Multiply histogram by NCG constant  // // // // // // //
	// // // // // // // // // // // // // // // // // // // //
	
	// Making the theta histogram.
	TH1F *histtheta = (TH1F*)hist1->Clone("histtheta");
	histtheta->Reset();

	Double_t s, l = lambda;
	Double_t m = 91.1876, alpha = 1./128., sinw = 0.480832611, cosw = 0.876740947, kgg = 0.2, pi = 3.14159265;
	Double_t w = 2.4952, wfmu = 0.03366, wfuc = 0.101, wfdsb = 0.166;
	Double_t theta=0.0;

	// Squaring functions
	Double_t m2, alpha2, sinw2, cosw2, kgg2, w2, cz, cz2, l2, l4;
	
		m2 = m*m;
		alpha2 = alpha*alpha;
		sinw2 = sinw*sinw;
		cosw2 = cosw*cosw;
		kgg2 = kgg*kgg;
		cz = (1./2. - (2./3.)*sinw2);
		cz2 = cz*cz;
		l2 = l*l;
		l4 = l2*l2;
		w2 = w*w;
	
	for (i = 1; i <= nbins; i++) {
		s = (i+20)*(i+20);
		if (gen == 1) {
			theta = 32.0*pi/12.0*sinw2/(sinw2*cosw2)*alpha2*cz2*kgg2*s/l4/((12.0*pi/m2*wfmu*wfuc*s*w2)/((s - m2)*(s - m2) + s*s*w2/m2));
		}
		else if (gen == 2) {
			theta = 32.0*pi/12.0*sinw2/(sinw2*cosw2)*alpha2*cz2*kgg2*s/l4/((12.0*pi/m2*wfmu*wfdsb*s*w2)/((s - m2)*(s - m2) + s*s*w2/m2));
		}
		histtheta->SetBinContent(i,theta);
	}
	
	// Doing the multiplication. (Here comes the fudge factor!)
		histncgfactor -> Multiply(hist_pdf,histtheta,1.,1.);
	
	// Making the 1 histogram.
	TH1F *histone = (TH1F*)hist1->Clone("histone");
	histone->Reset();

	for (i = 1; i <= nbins; i++) {
		histone->SetBinContent(i,1.);
	}
	
	// Adding the one histogram into final histogram: the histncgfactor.
	
	histncgfactor->Add(histone);
	
}

double calcncgfactorbin(int ibin, double oneoverlambda, Int_t gen) {
	Int_t i;
	
	double ThePdf=pdfratiobin(ibin);
	//printf("ThePdf=%f\n",ThePdf);

	Double_t s, l = oneoverlambda;
	Double_t m = 91.1876, alpha = 1./128., sinw = 0.480832611, cosw = 0.876740947, kgg = 0.2, pi = 3.14159265;
	Double_t w = 2.4952, wfmu = 0.03366, wfuc = 0.101, wfdsb = 0.166;
	Double_t theta=0.0;

	// Squaring functions
	Double_t m2, alpha2, sinw2, cosw2, kgg2, w2, cz, cz2, l2, l4;
	
		m2 = m*m;
		alpha2 = alpha*alpha;
		sinw2 = sinw*sinw;
		cosw2 = cosw*cosw;
		kgg2 = kgg*kgg;
		cz = (1./2. - (2./3.)*sinw2);
		cz2 = cz*cz;
		l2 = l*l;
		l4 = l2*l2;
		w2 = w*w;
		i=ibin;
	//for (i = 1; i <= nbins; i++) {
		s = (i+20)*(i+20);
		if (gen == 1) {
			theta = 32*pi/12*sinw2/(sinw2*cosw2)*alpha2*cz2*kgg2*s*l4/((12*pi/m2*wfmu*wfuc*s*w2)/((s - m2)*(s - m2) + s*s*w2/m2));
		}
		else if (gen == 2) {
			theta = 32*pi/12*sinw2/(sinw2*cosw2)*alpha2*cz2*kgg2*s*l4/((12*pi/m2*wfmu*wfdsb*s*w2)/((s - m2)*(s - m2) + s*s*w2/m2));
		}
		//histtheta->SetBinContent(i,theta);
	//}
		return ThePdf*theta+1.0;
}

void calcncgtot(TH1F *hist_total_ncg, Float_t lambda) {

	hist_total_ncg->Reset();
	
	TH1F *histncgfactor = (TH1F*)hist1->Clone("histncgfactor");
	histncgfactor->Reset();	
	TH1F *h1 = (TH1F*)hist1->Clone("h1");

		// Calculating sigma_qq*P_qq * (1+theta*P_gg/P_qq).

		calcncgfactor(histncgfactor,lambda,1); 	 // Calculate NCG factor (1 + theta * pp_gg/pp_qq)

		h1->Reset();
		h1->Multiply(hist_sm_uu_z,histncgfactor,1.,1.);
		hist_total_ncg->Add(h1);
		//printf("ibin520: histncgfactor=%f, hist_total_ncg=%f\n",histncgfactor->GetBinContent(520),hist_total_ncg->GetBinContent(520));
		
		h1->Reset();
		h1->Multiply(hist_sm_cc_z,histncgfactor,1.,1.);
		hist_total_ncg->Add(h1);
		
		histncgfactor->Reset();
		calcncgfactor(histncgfactor,lambda,2); 	 // Calculate NCG factor (1 + theta * pp_gg/pp_qq)

		h1->Reset();		
		h1->Multiply(hist_sm_dd_z,histncgfactor,1.,1.);
		hist_total_ncg->Add(h1);

		h1->Reset();				
		h1->Multiply(hist_sm_ss_z,histncgfactor,1.,1.);
		hist_total_ncg->Add(h1);

		// Adding gamma contributions
		hist_total_ncg->Add(hist_sm_uu_a);
		hist_total_ncg->Add(hist_sm_dd_a);
		hist_total_ncg->Add(hist_sm_cc_a);
		hist_total_ncg->Add(hist_sm_ss_a);
		
		// Multiplying by two possible initial states per diagram
		hist_total_ncg->Scale(2.);
		
		// Scale up to number of events at LHC running at 10 fb^-1 / year
		hist_total_ncg->Scale(10000.);
		//printf("ibin520_2: histncgfactor=%f, hist_total_ncg=%f\n",histncgfactor->GetBinContent(520),hist_total_ncg->GetBinContent(520));
}

double calcncgtotbin(double xval, double oneoverlambda) {
	
	int ibin=hist1->FindBin((Float_t)xval);
	double thehistncgfactor=calcncgfactorbin(ibin,oneoverlambda,1);
	double result=hist_sm_uu_z->GetBinContent(ibin)*thehistncgfactor;
	//if (ibin==520) printf("calcncgtotbin1: thehistncgfactor=%f, ibin=%d, hist_sm_uu_z->GetBinContent(ibin)=%f, prelimresult=%f\n",thehistncgfactor,ibin,hist_sm_uu_z->GetBinContent(ibin),result);
	result+=hist_sm_cc_z->GetBinContent(ibin)*thehistncgfactor;
	thehistncgfactor=calcncgfactorbin(ibin,oneoverlambda,2);
	result+=hist_sm_dd_z->GetBinContent(ibin)*thehistncgfactor;
	result+=hist_sm_ss_z->GetBinContent(ibin)*thehistncgfactor;
	result+=hist_sm_uu_a->GetBinContent(ibin)+hist_sm_dd_a->GetBinContent(ibin)+hist_sm_cc_a->GetBinContent(ibin)+hist_sm_ss_a->GetBinContent(ibin);
	//if (ibin==520) printf("calcncgtotbin2: thehistncgfactor=%f, smcontent=%f, hist_sm_uu_z->GetBinContent(ibin)=%f, prelimresult=%f\n",thehistncgfactor,hist_sm_uu_a->GetBinContent(ibin)+hist_sm_dd_a->GetBinContent(ibin)+hist_sm_cc_a->GetBinContent(ibin)+hist_sm_ss_a->GetBinContent(ibin),hist_sm_uu_z->GetBinContent(ibin),result);
	return result*20000.;
}

double thefitfunc(double *x, double *par){
	double result=calcncgtotbin(x[0],par[0]);
	//printf("FitFunc: x=%f, OneOverLambda=%f, result=%f\n",x[0],par[0],result);
	return result;
}

void drawhist(Int_t nr) {
	TCanvas *c1;
	Double_t ecm_start=20., ecm_end=1820.;
	Int_t nbins=1800;
	Int_t uppercut=1400;
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

			TH1F *intcut = new TH1F("intcut","Integrated cross section for uu -> z -> mm vs. sqrt(s) cut",uppercut,20.,uppercut + 20.);
			intcut->GetXaxis()->SetTitle("sqrt(s) lower bin limit [GeV]");
			intcut->GetYaxis()->SetTitle("Number of events (luminosity = 10 fb^-1) / 10 GeV");

			Int_t i;
			for (i = 1; i <= uppercut; i++) {
				intcut->SetBinContent(i,hist_sm_uu_z->Integral(i,1820));
			}
			
			// // Scale to number of events at LCH running at 10 fb^-1 // //
			intcut->Scale(10000.);
			
			c1 = new TCanvas("c1","Integrated cross section vs. sqrt(s) cut",1000,750);
			c1->SetLogy();
			intcut->Draw();
			
		break;
			
		case 3:
				
			// Plot total SM cross section (with statistical error-band) and NCG cross sections.

			// Calculate NCG total cross sections for different lambda.
			
			TH1F *ncg_500 = new TH1F("ncg_500","NCG 500",nbins,ecm_start,ecm_end);
			calcncgtot(ncg_500,500.);
			
			TH1F *ncg_900 = new TH1F("ncg_900","NCG 900",nbins,ecm_start,ecm_end);
			calcncgtot(ncg_900,900.);
			
			TH1F *ncg_1500 = new TH1F("ncg_1500","NCG 1500",nbins,ecm_start,ecm_end);
			calcncgtot(ncg_1500,1500.);
			
			TH1F *ncg_2000 = new TH1F("ncg_2000","NCG 2000",nbins,ecm_start,ecm_end);
			calcncgtot(ncg_2000,2000.);
			
			// Plot total NCG cross sections with SM cross section, as a function of lambda
			c1 = new TCanvas("c1","Total cross section at LHC",1000,750);
		    c1->SetLogy();

			// Calculate ordinary SM total cross section and plot it with statistical errors.
			calcsmtot();
			hist_total_sm->SetLineColor(18);
			hist_total_sm->Draw("e0");
			
			ncg_500->SetLineColor(9);
			ncg_500->Draw("same");
			
			ncg_900->SetLineColor(9);
			ncg_900->Draw("same");
			
			ncg_1500->SetLineColor(9);
			ncg_1500->Draw("same");
			
			ncg_2000->SetLineColor(9);
			ncg_2000->Draw("same");

					
		break;
		
		case 4:
		
			calcsmtot();
			
			TH1F *ncg_tot = new TH1F("ncg_tot","NCG 500",nbins,ecm_start,ecm_end);
			calcncgtot(ncg_tot,2000.);

			// Plot total NCG cross section as a function of lambda
			c1 = new TCanvas("c1","Total cross section at LHC",1000,750);
		    c1->SetLogy();
			hist_total_sm->SetTitle("Total cross section at LHC, #Lambda = 2000");
			hist_total_sm->GetXaxis()->SetTitle("#sqrt{s} [GeV]");
			hist_total_sm->GetYaxis()->SetTitle("Number of events");
			hist_total_sm->SetLineColor(18);
			//gStyle->SetOptStat(0);
			hist_total_sm->Draw("e0");
			
			ncg_tot->SetLineColor(9);
			ncg_tot->Draw("same");
									
			break;

	}

}

void DoFit(Float_t lambda){
	TCanvas *c1;
	if (lambda == 0) {
		calcsmtot();
		TF1 *AFitFunc= new TF1("AFitFunc",thefitfunc,140.,150.,1);
		int npseudo=500;
		TH1F* fitdist=new TH1F("fitdist","fitdist",100,0.,0.001);
		TH1F* hist_total_fit=(TH1F*)hist1->Clone("hist_total_sm");
		c1 = new TCanvas("c1","Fit to SM",1000,750);
		c1->SetLogy();
		c1->Divide(1,2);
		c1->cd(1);
		for (int i=1;i<npseudo;++i){
			printf("fit nummer: %d\n",i);
			hist_total_fit->Reset();
			Float_t nevt=hist_total_sm->Integral();
			nevt=nevt+gRandom->Gaus(0,1)*sqrt(nevt);
			//printf("nevt: %d (%d)\n",int(nevt),int(hist_total_sm->Integral()));
			hist_total_fit->FillRandom(hist_total_sm,int(nevt));	
			AFitFunc->SetParName(0,"OneOverLambda");
			AFitFunc->SetParameter(0,0.01);
			hist_total_fit->Fit("AFitFunc","R");
			//printf("result: %f\n",AFitFunc->GetParameter(0));
			fitdist->Fill(fabs(AFitFunc->GetParameter(0)));
			hist_total_fit->Draw();
		}
		/*hist_total_sm->Fit("AFitFunc","RVLL");
		c1->SetLogy();*/
		hist_total_sm->SetLineColor(18);
		hist_total_sm->Draw("SAME");
		c1->cd(2);
		fitdist->Draw();		
	}
	else if (lambda >= 1) {
		TH1F *ncg_tot_lambda = (TH1F*)hist1->Clone("ncg_tot_lambda");
		calcncgtot(ncg_tot_lambda,lambda);
		
		TF1 *AFitFunc= new TF1("AFitFunc",thefitfunc,100.,1800.,1);
		AFitFunc->SetParName(0,"OneOverLambda");
		AFitFunc->SetParameter(0,0.001);	
		ncg_tot_lambda->Fit("AFitFunc","RVLL");
		c1 = new TCanvas("c1","Fit to lambda",1000,750);
		c1->SetLogy();
		ncg_tot_lambda->Draw("e0");
	}

}