#include "Riostream.h"
#include "TH1F.h"
#include "TH2F.h"
#include "math.h"
void main() {

Double_t ecm_start=20., ecm_end=1820.;
Int_t lines = 0, nbins=1800;

TH1F *hist1 = new TH1F("hist1","histtheta",nbins,ecm_start,ecm_end);
TH1F *histtheta = hist1->Clone("histtheta");
histtheta->Reset();

	Int_t i, gen = 1;
	Double_t s, l = 200.;
	Double_t m = 91.1876, alpha = 1./128., sinw = 0.480832611, cosw = 0.876740947, kgg = 0.2, pi = 3.14159265;
	Double_t w = 2.4952, wfmu = 0.03366, wfuc = 0.101, wfdsb = 0.166;
	Double_t theta, Ggg, Crossqq, gz;
	
	// Ggg = (pow(8./12. * alphazmass,1/2) * sinw * Kgg * 1./pow(lambda,2));
	// 	printf("Ggg = ");
	// 	cout << Ggg;
	// 	printf("\n");
	
	// Squaring functions
	Double_t m2, alpha2, sinw2, cosw2, kgg2, pi2, w2, cz, cz2, l2, l4, w2;
	
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
		// gz = pow(4.*Pi*alphazmass,1/2) * (0.5 - 2./3. * pow(sinw,2)) / (sinw * cosw);
		// 	printf("gz = ");
		// 	cout << gz;
		// 	printf("\n");
		if (gen = 1) {
			theta = 32*pi/12*sinw2/(sinw2*cosw2)*alpha2*cz2*kgg2*s/l4/((12*pi/m2*wfmu*wfuc*s*w2)/((s - m2)*(s - m2) + s*s *w2/m2));
		}
		else if (gen = 2) {
			theta = 32*pi/12*sinw2/(sinw2*cosw2)*alpha2*cz2*kgg2*s/l4/((12*pi/m2*wfmu*wfdsb*s*w2)/((s - m2)*(s - m2) + s*s *w2/m2));
		}
		
	//	theta = pow(Ggg,2) * s * pow(gz,2) / Crossqq;
			printf("theta = ");
			cout << theta;
			printf("\n");
		histtheta->SetBinContent(i,theta);
	}
	
	histtheta->Draw();
	
}
