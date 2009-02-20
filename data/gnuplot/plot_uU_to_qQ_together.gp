set xlabel "Mass{p3+p4}  from 20 to 500 N_bins= 300"
set ylabel "Diff. cross section [pb/GeV]"
set logscale y
plot "uU_to_dD_20_500.txt" with yerrorbars, "uU_to_uU_20_500.txt" with yerrorbars, "uU_to_sS_20_500.txt" with yerrorbars, "uU_to_cC_20_500.txt" with yerrorbars, "uU_to_bB_20_500.txt" with yerrorbars
