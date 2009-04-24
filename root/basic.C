#include "Riostream.h"
void basic() {
	string d;
	Double_t x,y,z, ecm_start, ecm_end;
	Int_t nlines = 0, nbins;
	TFile *f = new TFile("basic.root","RECREATE");
	TH1F *h1 = new TH1F("h1","x distribution",300,0,500);

	ifstream in;
	in.open("compbasic.dat");
	
	// Read headers.
	in >> d >> d >> d >> d >> d >> d >> ecm_start >> d >> ecm_end >> d >> nbins >> d >> d >> d >> d;

	while (1) {
		in >> x >> y >> d >> z;
		if (!in.good()) break;
		if (nlines > 295) printf("line=%2i x=%8f, y=%8f, z=%8f\n",nlines,x,y,z);
		h1->SetBinContent(nlines,y);
		h1->SetBinError(nlines,z);
		nlines++;
	}
	
	printf(" found %d points\n",nlines);

	in.close();


	f->Write();
}