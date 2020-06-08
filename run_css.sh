make css.out

n_low=20
n_high=30
#na_input=10
seed=999
debug=2
num_core=15
num_trial=1000000
echo "./css.out mode=1 sub_mode=$sub_mode title=$title debug=$debug n_low=$n_low n_high=$n_high seed=$i  note=$note na_input=$na_input num_core=$num_core num_trial=$num_trial"
./css.out mode=1 sub_mode=$sub_mode title=$title debug=$debug n_low=$n_low n_high=$n_high seed=$seed note=$note na_input=$na_input num_core=$num_core num_trial=$num_trial

echo no segmentation fault
