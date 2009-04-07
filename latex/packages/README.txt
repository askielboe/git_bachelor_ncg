Her er link til en masse pakker: https://svn.kwarc.info/repos/arXMLiv/trunk/sty/

[------- For at installere en .sty pakke til LaTeX på MAC: -------]

.sty filerne ligges i mapper med samme navn som .sty-filen i
/usr/local/texlive/2008/texmf-dist/tex/latex

Så hvis man f.eks. skal installere sparticles.sty skal den lægges her:
/usr/local/texlive/2008/texmf-dist/tex/latex/sparticles/sparticles.sty

For at få adgang til mappen skal man nok have root-adgang. Dvs. man skal skrive sudo foran mv / cp kommandoen. F.eks.

sudo mkdir /usr/local/texlive/2008/texmf-dist/tex/latex/sparticles
sudo mv sparticles.sty /usr/local/texlive/2008/texmf-dist/tex/latex/sparticles/sparticles.sty

Bagefter køres kommandoen (også med sudo):
sudo mktexlsr

Og så skulle det virke!