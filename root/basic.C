#include "Riostream.h"
#include "TH1F.h"
void makehist(const char* filename, TH1F *h1, Int_t& nlines) {
	string d;
	Double_t x,y,z, ecm_start, ecm_end;
	Int_t nbins;
	ifstream in;
	in.open(filename);
	
	// Read headers.
	in >> d >> d >> d >> d >> d >> d >> ecm_start >> d >> ecm_end >> d >> nbins >> d >> d >> d >> d;
	
	while (1) {
		in >> x >> y >> d >> z;
		if (!in.good()) break;
		if (nlines < 5) printf("line=%2i x=%8f, y=%8f, z=%8f\n",nlines,x,y,z);
		h1->SetBinContent(nlines+1,y);
		h1->SetBinError(nlines+1,z);
		nlines++;
	}
	
	printf(" found %d points\n",nlines);

	in.close();
}

void basic() {
	Double_t ecm_start=20., ecm_end=1820.;
	Int_t lines = 0, nbins=1500;
	
	TFile *f = new TFile("basic.root","RECREATE");
	
	TH1F *hist = new TH1F("hist","uu -> g -> dd",nbins,ecm_start,ecm_end);
	hist->GetXaxis()->SetTitle("E [GeV]");
    hist->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_uu_g_dd_20_320.txt", hist, lines);
	makehist("../data/v4_uu_g_dd_320_620.txt", hist, lines);
	makehist("../data/v4_uu_g_dd_620_920.txt", hist, lines);
	makehist("../data/v4_uu_g_dd_920_1220.txt", hist, lines);
	makehist("../data/v4_uu_g_dd_1220_1520.txt", hist, lines);
	makehist("../data/v4_uu_g_dd_1520_1820.txt", hist, lines);
	
	TH1F *hist2 = new TH1F("hist2","gg -> g -> uu",nbins,ecm_start,ecm_end);
	hist2->GetXaxis()->SetTitle("E [GeV]");
    hist2->GetYaxis()->SetTitle("cross section [pb]");
	lines = 0;
	makehist("../data/v4_gg_g_uu_20_320.txt", hist2, lines);
	makehist("../data/v4_gg_g_uu_320_620.txt", hist2, lines);
	makehist("../data/v4_gg_g_uu_620_920.txt", hist2, lines);
	makehist("../data/v4_gg_g_uu_920_1220.txt", hist2, lines);
	makehist("../data/v4_gg_g_uu_1220_1520.txt", hist2, lines);
	makehist("../data/v4_gg_g_uu_1520_1820.txt", hist2, lines);
	
	f->Write();
}

void drawhist() {
	TCanvas *c1 = new TCanvas("c1","uu -> g -> dd",1000,750);
	hist.Draw();
	TCanvas *c2 = new TCanvas("c2","gg -> g -> uu",1000,750);
	hist2.Draw();
}