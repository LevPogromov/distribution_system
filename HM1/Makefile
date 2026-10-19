task3_orig: pth_ll_rwl/pth_ll_rwl.c
	mkdir -p build
	gcc -o build/task3_orig -Ipth_ll_rwl pth_ll_rwl/my_rand.c pth_ll_rwl/pth_ll_rwl.c -lpthread -O3

task3_custom: pth_ll_rwl/pth_ll_rwl_custom.c
	mkdir -p build
	gcc -o build/task3_custom -Ipth_ll_rwl pth_ll_rwl/my_rand.c pth_ll_rwl/pth_ll_rwl_custom.c -lpthread -O3

task1_multi: task1_multi.c
	mkdir -p build
	gcc -o build/task1_multi -lpthread -O3 task1_multi.c
	cp generate.py build/

task1_mono: task1_mono.c
	mkdir -p build
	gcc -o build/task1_mono -lpthread -O3 task1_mono.c
	cp generate.py build/

task2: task2.c
	mkdir -p build
	gcc -o build/task2 task2.c -pthread -lm

task2_orig:
	mkdir -p build
	gcc -o build/task2_orig task2_orig.c -lm

task1: task1_mono task1_multi
