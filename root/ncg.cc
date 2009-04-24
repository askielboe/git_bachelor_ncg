
void Analyze::Loop()
{
	double ecm, sigma, errorsigma;
	char signecm, signsigma, signerror;
	int potecm, potsigma, poterror;
	file = fopen(v3_uu_a_mm_20_500.txt, "r");
	fscanf(file, "%1.6f %s %2i %1.6f %s %2i %*s %1.6f %s %2i ", &ecm, &signecm, &potecm, &sigma, &signsigma, &potsigma, &errorsigma, &signerror, &poterror);
	
	
	
	printf("\n%f %f %f %s\t", ecm, y, z, string);
	
//	char str [45];
	// read characters from stdin until a newline
	// or 49 characters have been read
	
//	cin.getline(str,45);
	
	
	
//	char sentence []="Rudolph is 12 years old";
// 	char str [20];
//  	int i;

//  	sscanf (sentence,"%s %*s %d",str,&i);
//  	printf ("%s -> %d\n",str,i);

//  	return 0;



}