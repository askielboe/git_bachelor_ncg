#include "Riostream.h"
#include "TH1F.h"
#include "TH2F.h"
#include "math.h"
void main() {

Double_t ecm_start=20., ecm_end=1820.;
Int_t lines = 0, nbins=1800;
TH1F *hist1 = new TH1F("hist1","u,u -> g -> d,d",nbins,ecm_start,ecm_end);
TH1F *histtheta = hist1->Clone("histtheta");
histtheta->Reset();

Int_t i, gen = 1;
Float_t gz, s, Crossqq, lambda = 200.;
Float_t Zmass = 91.1876, alphazmass = 1./128., sinw = 0.480832611, cosw = 0.876740947, Kgg = 0.2, Pi = 3.14159265;
Float_t Zwidthfull = 2.4952, Zwidthfracmu = 3.366, Zwidthfracuc = 11.6, Zwidthfracdsb = 15.6;
Double_t theta, Ggg;

Ggg = (pow(8./12. * alphazmass,1/2) * sinw * Kgg * 1./pow(lambda,2));

printf("Ggg = ");
cout << Ggg;
printf("\n");

for (i = 1; i <= 1820; i++) {
	s = pow(i+20,2);
	printf("s = ");
	cout << s;
	printf("\n");
	
	gz = pow(4.*Pi*alphazmass,1/2) * (0.5 - 2./3. * pow(sinw,2)) / (sinw * cosw);
	printf("gz = ");
	cout << gz;
	printf("\n");
	
	if (gen = 1) {
		Crossqq = (12 * Pi / pow(Zmass,2) * Zwidthfracmu * Zwidthfracuc * s * pow(Zwidthfull,2));
		Crossqq = Crossqq / (pow(s - pow(Zmass,2),2) + pow(s,2) * pow(Zwidthfull,2) / pow(Zmass,2));
		printf("Crossqq = ");
		cout << Crossqq;
		printf("\n");
	}
	else if (gen = 2) {
		Crossqq = (12 * Pi / pow(Zmass,2) * Zwidthfracmu * Zwidthfracdsb * s * pow(Zwidthfull,2));
		Crossqq = Crossqq / (pow(s - pow(Zmass,2),2) + pow(s,2) * pow(Zwidthfull,2) / pow(Zmass,2));	
	}
	theta = pow(Ggg,2) * s * pow(gz,2) / Crossqq; // Not taking gz^2 !
	printf("theta = ");
	cout << theta;
	printf("\n");
	
	histtheta->SetBinContent(i,theta);
}
}