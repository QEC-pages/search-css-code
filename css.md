make css.out
make[1]: Entering directory '/home/weileizeng/Documents/GitHub/search-css-code'
g++ -O2 -Wall -std=c++11 `pkg-config --cflags itpp` -o css.out css.c weilei_lib/mm_read.c weilei_lib/mmio.c weilei_lib/mm_write.c weilei_lib/lib.cpp weilei_lib/dist.c weilei_lib/concatenation_lib.c `pkg-config --libs itpp` -fopenmp
make[1]: Leaving directory '/home/weileizeng/Documents/GitHub/search-css-code'
./css.out mode=1  debug=2 n_low=5 n_high=10
input seed: 1 --> converted seed:732824261
wrote the matrix into file data/dist-size-0.mtx
wrote the matrix into file data/dist-size-1.mtx
wrote the matrix into file data/dist-size-2.mtx
wrote the matrix into file data/dist-size-3.mtx
wrote the matrix into file data/dist-size-4.mtx
wrote the matrix into file data/dist-size-5.mtx
wrote the matrix into file data/dist-size-6.mtx
wrote the matrix into file data/dist-size-7.mtx
wrote the matrix into file data/dist-size-8.mtx
wrote the matrix into file data/dist-size-9.mtx
wrote the matrix into file data/dist-size-10.mtx
wrote the matrix into file data/dist-size-11.mtx
wrote the matrix into file data/dist-size-12.mtx
wrote the matrix into file data/dist-size-13.mtx
wrote the matrix into file data/dist-size-14.mtx
wrote the matrix into file data/dist-size-15.mtx
wrote the matrix into file data/dist-size-16.mtx
wrote the matrix into file data/dist-size-17.mtx
wrote the matrix into file data/dist-size-18.mtx
wrote the matrix into file data/dist-size-19.mtx
wrote the matrix into file data/dist-size-20.mtx
wrote the matrix into file data/dist-size-21.mtx
wrote the matrix into file data/dist-size-22.mtx
wrote the matrix into file data/dist-size-23.mtx
wrote the matrix into file data/dist-size-24.mtx
wrote the matrix into file data/dist-size-25.mtx
wrote the matrix into file data/dist-size-26.mtx
wrote the matrix into file data/dist-size-27.mtx
wrote the matrix into file data/dist-size-28.mtx
wrote the matrix into file data/dist-size-29.mtx
wrote the matrix into file data/dist-size-30.mtx
wrote the matrix into file data/dist-size-31.mtx
wrote the matrix into file data/dist-size-32.mtx
wrote the matrix into file data/dist-size-33.mtx
wrote the matrix into file data/dist-size-34.mtx
wrote the matrix into file data/dist-size-35.mtx
wrote the matrix into file data/dist-size-36.mtx
wrote the matrix into file data/dist-size-37.mtx
wrote the matrix into file data/dist-size-38.mtx
wrote the matrix into file data/dist-size-39.mtx
wrote the matrix into file data/dist-size-40.mtx
wrote the matrix into file data/dist-size-41.mtx
wrote the matrix into file data/dist-size-42.mtx
wrote the matrix into file data/dist-size-43.mtx
wrote the matrix into file data/dist-size-44.mtx
wrote the matrix into file data/dist-size-45.mtx
wrote the matrix into file data/dist-size-46.mtx
wrote the matrix into file data/dist-size-47.mtx
wrote the matrix into file data/dist-size-48.mtx
wrote the matrix into file data/dist-size-49.mtx
wrote the matrix into file data/dist-size-50.mtx
wrote the matrix into file data/dist-size-51.mtx
wrote the matrix into file data/dist-size-52.mtx
wrote the matrix into file data/dist-size-53.mtx
wrote the matrix into file data/dist-size-54.mtx
wrote the matrix into file data/dist-size-55.mtx
wrote the matrix into file data/dist-size-56.mtx
wrote the matrix into file data/dist-size-57.mtx
wrote the matrix into file data/dist-size-58.mtx
wrote the matrix into file data/dist-size-59.mtx
wrote the matrix into file data/dist-size-60.mtx
wrote the matrix into file data/dist-size-61.mtx
wrote the matrix into file data/dist-size-62.mtx
wrote the matrix into file data/dist-size-63.mtx
wrote the matrix into file data/dist-size-64.mtx
wrote the matrix into file data/dist-size-65.mtx
wrote the matrix into file data/dist-size-66.mtx
wrote the matrix into file data/dist-size-67.mtx
wrote the matrix into file data/dist-size-68.mtx
wrote the matrix into file data/dist-size-69.mtx
wrote the matrix into file data/dist-size-70.mtx
wrote the matrix into file data/dist-size-71.mtx
wrote the matrix into file data/dist-size-72.mtx
wrote the matrix into file data/dist-size-73.mtx
wrote the matrix into file data/dist-size-74.mtx
wrote the matrix into file data/dist-size-75.mtx
wrote the matrix into file data/dist-size-76.mtx
wrote the matrix into file data/dist-size-77.mtx
wrote the matrix into file data/dist-size-78.mtx
wrote the matrix into file data/dist-size-79.mtx
wrote the matrix into file data/dist-size-80.mtx
wrote the matrix into file data/dist-size-81.mtx
wrote the matrix into file data/dist-size-82.mtx
wrote the matrix into file data/dist-size-83.mtx
wrote the matrix into file data/dist-size-84.mtx
wrote the matrix into file data/dist-size-85.mtx
wrote the matrix into file data/dist-size-86.mtx
wrote the matrix into file data/dist-size-87.mtx
wrote the matrix into file data/dist-size-88.mtx
wrote the matrix into file data/dist-size-89.mtx
wrote the matrix into file data/dist-size-90.mtx
wrote the matrix into file data/dist-size-91.mtx
wrote the matrix into file data/dist-size-92.mtx
wrote the matrix into file data/dist-size-93.mtx
wrote the matrix into file data/dist-size-94.mtx
wrote the matrix into file data/dist-size-95.mtx
wrote the matrix into file data/dist-size-96.mtx
wrote the matrix into file data/dist-size-97.mtx
wrote the matrix into file data/dist-size-98.mtx
wrote the matrix into file data/dist-size-99.mtx

n=5

| k\ d_x | 1| 2| 3| 4| 5|
|-|-|-|-|-|-|
|k=1|(1,4)|(2,2)|(3,1)|(4,1)|(5,0)|
|k=2|(1,2)|(2,2)|(3,0)|(4,0)|(5,0)|
|k=3|(1,2)|(2,1)|(3,0)|(4,0)|(5,0)|

n=6

| k\ d_x | 1| 2| 3| 4| 5| 6|
|-|-|-|-|-|-|-|
|k=1|(1,5)|(2,3)|(3,2)|(4,1)|(5,1)|(6,0)|
|k=2|(1,3)|(2,2)|(3,1)|(4,0)|(5,0)|(6,0)|
|k=3|(1,2)|(2,2)|(3,0)|(4,0)|(5,0)|(6,0)|
|k=4|(1,2)|(2,2)|(3,0)|(4,0)|(5,0)|(6,0)|

n=7

| k\ d_x | 1| 2| 3| 4| 5| 6| 7|
|-|-|-|-|-|-|-|-|
|k=1|(1,6)|(2,3)|(3,2)|(4,1)|(5,1)|(6,0)|(7,0)|
|k=2|(1,3)|(2,2)|(3,1)|(4,0)|(5,0)|(6,0)|(7,0)|
|k=3|(1,2)|(2,2)|(3,1)|(4,0)|(5,0)|(6,0)|(7,0)|
|k=4|(1,2)|(2,1)|(3,0)|(4,0)|(5,0)|(6,0)|(7,0)|
|k=5|(1,2)|(2,1)|(3,0)|(4,0)|(5,0)|(6,0)|(7,0)|

n=8

| k\ d_x | 1| 2| 3| 4| 5| 6| 7| 8|
|-|-|-|-|-|-|-|-|-|
|k=1|(1,6)|(2,3)|(3,2)|(4,2)|(5,1)|(6,1)|(7,0)|(8,0)|
|k=2|(1,4)|(2,3)|(3,2)|(4,1)|(5,0)|(6,0)|(7,0)|(8,0)|
|k=3|(1,3)|(2,2)|(3,1)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|
|k=4|(1,2)|(2,2)|(3,0)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|
|k=5|(1,2)|(2,2)|(3,0)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|
|k=6|(1,2)|(2,1)|(3,0)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|

n=9

| k\ d_x | 1| 2| 3| 4| 5| 6| 7| 8| 9|
|-|-|-|-|-|-|-|-|-|-|
|k=1|(1,7)|(2,4)|(3,2)|(4,2)|(5,1)|(6,1)|(7,1)|(8,0)|(9,0)|
|k=2|(1,4)|(2,3)|(3,2)|(4,2)|(5,0)|(6,0)|(7,0)|(8,0)|(9,0)|
|k=3|(1,4)|(2,3)|(3,1)|(4,1)|(5,0)|(6,0)|(7,0)|(8,0)|(9,0)|
|k=4|(1,3)|(2,2)|(3,1)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|(9,0)|
|k=5|(1,2)|(2,2)|(3,0)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|(9,0)|
|k=6|(1,2)|(2,1)|(3,0)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|(9,0)|
|k=7|(1,2)|(2,1)|(3,0)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|(9,0)|

n=10

| k\ d_x | 1| 2| 3| 4| 5| 6| 7| 8| 9| 10|
|-|-|-|-|-|-|-|-|-|-|-|
|k=1|(1,8)|(2,5)|(3,3)|(4,2)|(5,2)|(6,1)|(7,1)|(8,1)|(9,0)|(10,0)|
|k=2|(1,6)|(2,4)|(3,2)|(4,2)|(5,1)|(6,0)|(7,0)|(8,0)|(9,0)|(10,0)|
|k=3|(1,4)|(2,3)|(3,2)|(4,1)|(5,0)|(6,0)|(7,0)|(8,0)|(9,0)|(10,0)|
|k=4|(1,3)|(2,2)|(3,1)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|(9,0)|(10,0)|
|k=5|(1,3)|(2,2)|(3,1)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|(9,0)|(10,0)|
|k=6|(1,2)|(2,2)|(3,0)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|(9,0)|(10,0)|
|k=7|(1,2)|(2,1)|(3,0)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|(9,0)|(10,0)|
|k=8|(1,1)|(2,1)|(3,0)|(4,0)|(5,0)|(6,0)|(7,0)|(8,0)|(9,0)|(10,0)|

