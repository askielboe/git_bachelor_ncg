#include "Riostream.h"
#include "TH1F.h"
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
	
	TH1F *hist4 = new TH1F("hist4","u,u -> Z -> mu,mu",nbins,ecm_start,ecm_end);
	hist4->GetXaxis()->SetTitle("E [GeV]");
	hist4->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_uu_z_mm_20_320.txt", hist4, lines);
	makehist("../data/v4_uu_z_mm_320_620.txt", hist4, lines);
	makehist("../data/v4_uu_z_mm_620_920.txt", hist4, lines);
	makehist("../data/v4_uu_z_mm_920_1220.txt", hist4, lines);
	makehist("../data/v4_uu_z_mm_1220_1520.txt", hist4, lines);
	makehist("../data/v4_uu_z_mm_1520_1820.txt", hist4, lines);
	
	f->Write();
}

void drawhist(Int_t nr) {
	
	switch(nr) {
		case 1:
			TCanvas *c1 = new TCanvas("c1","u,u -> g -> d,d",1000,750);
			hist1->Draw("e");
			TCanvas *c2 = new TCanvas("c2","g,g -> g -> u,u",1000,750);
			hist2->Draw("e");
			TCanvas *c3 = new TCanvas("c3","u,u -> A -> d,d",1000,750);
			hist3->Draw("e");
			TCanvas *c4 = new TCanvas("c4","u,u -> Z -> mu,mu",1000,750);
			hist4->Draw("e");
			break;
	
		case 2:
			TH1F *histdiv = hist1->Clone("histdiv"); // This is just to get the same number of bins, etc.
			histdiv->SetTitle("-1 x 64(gg -> g -> uu) / 9(uu -> g -> dd)");
			histdiv->GetXaxis()->SetTitle("GeV");
			histdiv->GetYaxis()->SetTitle("ratio");
			histdiv->Reset();
			
			// // // // // // // // // // // // // // // // // // //
			// Divide the two histograms and divide by -9/64,     //
			// minus sign from taking only s-channel contribution.//
			// // // // // // // // // // // // // // // // // // //
			histdiv->Divide(hist2,hist1,-64,9);
			
			// And plot the ratio distribution.
			TCanvas *c1 = new TCanvas("c1","-1 x 64(gg -> g -> uu) / 9(uu -> g -> dd)",1000,750);
			c1->SetLogy();
			histdiv->Draw("e");
			
			// // // // // // // // // // // // // // // // // // // //
			// Multiply histogram by NCG constant (is it constant??).//
			// // // // // // // // // // // // // // // // // // // //
			TH1F *histmultiply = hist1->Clone("histmultiply"); // This is just to get the same number of bins, etc.
			histmultiply->SetTitle("theta_NCG x -1 x 64(gg -> g -> uu) / 9(uu -> g -> dd)");
			histmultiply->GetXaxis()->SetTitle("GeV");
			histmultiply->GetYaxis()->SetTitle("theta_NCG x ratio");
			histmultiply->Reset();
			
			// Making the theta histogram.
			Double_t theta = 2;
			TH1F *histtheta = hist1->Clone("histtheta");
			histtheta->Reset();

			Int_t i;
			for (i = 1; i <= 1820; i++) {
				histtheta->SetBinContent(i,theta);
			}
			
			// Doing the multiplication.
			histmultiply->Multiply(histdiv,histtheta,1,1);
			
			// Lets draw it.
			TCanvas *c2 = new TCanvas("c2","theta_NCG x -1 x 64(gg -> g -> uu) / 9(uu -> g -> dd)",1000,750);
			c2->SetLogy();
			histmultiply->Draw("e");
			
			// // // // // // // // // // // // // // // // // // 
			// Calculating (1+theta*P_gg/P_qq).                //
			// // // // // // // // // // // // // // // // // // 
			TH1F *histaddone = hist1->Clone("histaddone"); // This is just to get the same number of bins, etc.
			histaddone->Reset();
			
			// Making the 1 histogram.
			Double_t one = 2;
			TH1F *histone = hist1->Clone("histone");
			histone->Reset();

			Int_t i;
			for (i = 1; i <= 1820; i++) {
				histone->SetBinContent(i,1);
			}
			
			// Adding the one histogram.
			histaddone->Add(histone);
			
			// // // // // // // // // // // // // // // // // // 
			// Calculating sigma_qq*P_qq * (1+theta*P_gg/P_qq).//
			// // // // // // // // // // // // // // // // // //
			TH1F *histqqgg = hist1->Clone("histqqgg"); // This is just to get the same number of bins, etc.
			histqqgg->SetTitle("|A_qq|^2 + |A_gg|^2 = sigma_qq*P_qq * (1 + theta*P_gg/P_qq)");
			histqqgg->GetXaxis()->SetTitle("GeV");
			histqqgg->GetYaxis()->SetTitle("cross section");
			histqqgg->Reset();
			
			// Doing the multiplication.
			histqqgg->Multiply(hist4,histaddone,1,1);
			
			// Drawing the result!
			TCanvas *c3 = new TCanvas("c3","|A_qq|^2 + |A_gg|^2 = sigma_qq*P_qq * (1 + theta*P_gg/P_qq)",1000,750);
			c3->SetLogy();
			histqqgg->Draw("e");
			
			break;

		// default:
		// 	cout << "Please enter a number from 1 to 2.";
	}
}