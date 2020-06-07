INC_DIR=weilei_lib
#INC_DIR=~/working/weilei_lib
CXX=g++ -O2 -Wall -std=c++11
### -O2 -O5 -Os
#g++ `pkg-config --cflags itpp` -o hello.out hello.cpp `pkg-config --libs itpp`

START=`pkg-config --cflags itpp`
END=`pkg-config --libs itpp`
files=$(INC_DIR)/mm_read.c $(INC_DIR)/mm_read.h $(INC_DIR)/mmio.c $(INC_DIR)/mmio.h $(INC_DIR)/mm_write.c $(INC_DIR)/mm_write.h $(INC_DIR)/lib.cpp $(INC_DIR)/lib.h $(INC_DIR)/dist.c $(INC_DIR)/dist.h $(INC_DIR)/concatenation_lib.c $(INC_DIR)/concatenation_lib.h $(INC_DIR)/my_lib.h makefile
command=$(CXX) $(START) -o $@ $< $(word 2,$^) $(word 4, $^) $(word 6, $^) $(word 8, $^) $(word 10, $^) $(word 12, $^) $(END)

###include all headfiles into my_lib.h
#counter_concatenation.out:counter_concatenation.c $(files)
#	$(command)
css.out:css.c $(files)
	$(command) -fopenmp

test.out:test.c $(files)
	$(command)


sbatch-dry-run:
	sbatch --test product.sh
sbatch:
	sbatch product.sh
pkill-product:
	pkill .product
