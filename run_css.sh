make css.out

n_low=6
n_high=9
na_input=10
i=9
debug=1
num_core=16
num_trial=32000
echo "./css.out mode=1 sub_mode=$sub_mode title=$title debug=$debug n_low=$n_low n_high=$n_high seed=$i  note=$note na_input=$na_input num_core=$num_core num_trial=$num_trial"
./css.out mode=1 sub_mode=$sub_mode title=$title debug=$debug n_low=$n_low n_high=$n_high seed=$i  note=$note na_input=$na_input num_core=$num_core num_trial=$num_trial


