void dividehist() {
	hist1->Sumw2();
	hist2->Sumw2();
	TH1F *histdiv = hist1->Clone("histdiv");
	histdiv->SetTitle("Quotient");
	histdiv->Reset();
	histdiv->Divide(hist1,hist2,1,1);
	TCanvas *c3 = new TCanvas("c3"," \frac{uu -> g -> dd}{gg -> g -> uu}",1000,750);
	histdiv->Sumw2();
}