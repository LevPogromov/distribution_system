task1_single:
	mkdir -p build/
	gcc-16 -Iutils -o build/task1_single task1.c

task1_openmp:
	mkdir -p build/
	gcc-16 -Iutils -fopenmp -o build/task1_openmp task1_openmp.c

task2_openmp:
	/opt/homebrew/opt/llvm/bin/clang++ \
	-fopenmp \
	-I/opt/homebrew/opt/libomp/include \
	-L/opt/homebrew/opt/libomp/lib \
	task2_openmp.cpp -o build/task2_openmp

task4_single:
	mkdir -p build/
	gcc-16 -Iutils -o build/task4_single task4.c

task4_openmp:
	mkdir -p build/
	gcc-16 -Iutils -fopenmp -o build/task4_openmp task4_openmp.c
