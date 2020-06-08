make css.out

n_low=30
n_high=50
# na_input=10
seed=999
debug=0
num_core=15
num_trial=1000000

# ./css.out mode=1 sub_mode=$sub_mode title=$title debug=$debug n_low=$n_low n_high=$n_high seed=$seed note=$note na_input=$na_input num_core=$num_core num_trial=$num_trial

./css.out mode=1  debug=$debug n_low=$n_low n_high=$n_high seed=$seed  num_core=$num_core num_trial=$num_trial

#echo There is no segmentation fault is you see this message
