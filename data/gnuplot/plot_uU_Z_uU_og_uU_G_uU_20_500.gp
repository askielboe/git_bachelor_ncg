set xlabel "Mass{p3+p4}  from 20 to 500 N_bins= 300"
set ylabel "Diff. cross section [pb/GeV]"

set logscale y

plot "uU_to_uU_20_500.txt" with lines, "uU_Z_uU_20_500_gnu.txt" with lines
