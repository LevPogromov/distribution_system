# Task 3

В файле `task3.c` содержится собственная реализация rwlock. В файле `pth_ll_rwl_custom.c` содержится апробация на связном списке.

## Results

Attemps: 1

| Machine | Algorithm | Time (sec) |
| -------- |-----------|----- |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Pthread | 2.115901e-01 |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Custom | 1.947100e-01 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Pthread | 5.633143e+00 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Custom | 5.353818e+00 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Pthread | 2.825281e+00 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Custom | 2.664295e+00 |

## Logs

### Machine: Macbook air M4, MacOS 26.5.2, Chip M4, ARM64

Test pthread realization:

    ``` bash
    ./build/task3_orig 8
    How many keys should be inserted in the main thread?
    10000
    How many ops total should be executed?
    10000
    Percent of ops that should be searches? (between 0 and 1)
    0.2
    Percent of ops that should be inserts? (between 0 and 1)
    0.5
    Inserted 10000 keys in empty list
    Elapsed time = 2.115901e-01 seconds
    Total ops = 10000
    member ops = 2057
    insert ops = 4925
    delete ops = 3018
    ```

Test custom realization:

    ``` bash
    ./build/task3_custom 8
    How many keys should be inserted in the main thread?
    10000
    How many ops total should be executed?
    10000
    Percent of ops that should be searches? (between 0 and 1)
    0.2
    Percent of ops that should be inserts? (between 0 and 1)
    0.5
    Inserted 10000 keys in empty list
    Elapsed time = 1.947100e-01 seconds
    Total ops = 10000
    member ops = 2057
    insert ops = 4925
    delete ops = 3018
    ```

### Machine: Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V


Test pthread realization:

    ``` bash
    ./build/task3_orig 8
    How many keys should be inserted in the main thread?
    10000
    How many ops total should be executed?
    10000
    Percent of ops that should be searches? (between 0 and 1)
    0.2
    Percent of ops that should be inserts? (between 0 and 1)
    0.5
    Inserted 10000 keys in empty list
    Elapsed time = 5.633143e+00 seconds
    Total ops = 10000
    member ops = 2057
    insert ops = 4925
    delete ops = 3018
    ```

Test custom realization:

    ```bash 
    ./build/task3_custom 8
    How many keys should be inserted in the main thread?
    10000
    How many ops total should be executed?
    10000
    Percent of ops that should be searches? (between 0 and 1)
    0.2
    Percent of ops that should be inserts? (between 0 and 1)
    0.5
    Inserted 10000 keys in empty list
    Elapsed time = 5.353818e+00 seconds
    Total ops = 10000
    member ops = 2057
    insert ops = 4925
    delete ops = 3018
    ```

### Machine: Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V


Test pthread realization:

    ``` bash
    ./build/task3_orig 8
    How many keys should be inserted in the main thread?
    10000
    How many ops total should be executed?
    10000
    Percent of ops that should be searches? (between 0 and 1)
    0.2
    Percent of ops that should be inserts? (between 0 and 1)
    0.5
    Inserted 10000 keys in empty list
    Elapsed time = 2.825281e+00 seconds
    Total ops = 10000
    member ops = 2057
    insert ops = 4925
    delete ops = 3018
    ```

Test custom realization:

    ```bash 
    ./build/task3_custom 8
    How many keys should be inserted in the main thread?
    10000
    How many ops total should be executed?
    10000
    Percent of ops that should be searches? (between 0 and 1)
    0.2
    Percent of ops that should be inserts? (between 0 and 1)
    0.5
    Inserted 10000 keys in empty list
    Elapsed time = 2.664295e+00 seconds
    Total ops = 10000
    member ops = 2057
    insert ops = 4925
    delete ops = 3018
    ```

## Benchmarking

| Machine | Realization | Attemps | Params | Min(sec) | Max(sec) | Avg(sec) | Median(sec) |
|---------|-------------|---------|--------|----------|----------|----------|-------------|
|Macbook air M4, MacOS 26.5.2, Chip M4, ARM64| Pthread | 100 | 2, 10000, 10000, 0.2, 0.5 | 0.142577200 | 0.190249000 | 0.148007388 | 0.146031100 |
|Macbook air M4, MacOS 26.5.2, Chip M4, ARM64| Custom | 100 | 2, 10000, 10000, 0.2, 0.5 | 0.126572100 | 0.161752900 | 0.132018544 | 0.129942200 |
|Macbook air M4, MacOS 26.5.2, Chip M4, ARM64| Pthread | 100 | 4, 10000, 10000, 0.2, 0.5 | 0.169235000 | 0.241265100 | 0.175419252 | 0.173445900 |
|Macbook air M4, MacOS 26.5.2, Chip M4, ARM64| Custom | 100 | 4, 10000, 10000, 0.2, 0.5 | 0.162714000 | 0.210891000 | 0.170041745 | 0.168800800 |
|Macbook air M4, MacOS 26.5.2, Chip M4, ARM64| Pthread | 100 | 8, 10000, 10000, 0.2, 0.5 | 0.181911000 | 0.245281000 | 0.187118457 | 0.185747900 |
|Macbook air M4, MacOS 26.5.2, Chip M4, ARM64| Custom | 100 | 8, 10000, 10000, 0.2, 0.5 | 0.176239000 | 0.229551100 | 0.182182792 | 0.181371000 |
|Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V| Pthread | 100 | 4, 10000, 10000, 0.2, 0.5 | 2.841351000 | 5.009806000 | 4.666033320 | 4.696493000 |
|Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V| Custom | 100 | 4, 10000, 10000, 0.2, 0.5 | 2.913200000 | 4.755957000 | 4.458640880 | 4.474904000 |
|Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V| Pthread | 100 | 8, 10000, 10000, 0.2, 0.5 | 5.163628000 | 5.633967000 | 5.285062660 | 5.275908000 |
|Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V| Custom | 100 | 8, 10000, 10000, 0.2, 0.5 | 4.887433000 | 5.225200000 | 5.035182550 | 5.028210000 |
|Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V| Pthread | 100 | 4, 10000, 10000, 0.2, 0.5 | 2.420579000 | 2.723288000 | 2.495965090 | 2.467225000 |
|Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V| Custom | 100 | 4, 10000, 10000, 0.2, 0.5 | 2.245941000 | 2.608129000 | 2.326503530 | 2.312386000 |
|Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V| Pthread | 100 | 8, 10000, 10000, 0.2, 0.5 | 2.641357000 | 2.940952000 | 2.742136200 | 2.730703000 |
|Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V| Custom | 100 | 8, 10000, 10000, 0.2, 0.5 | 2.510140000 | 2.940922000 | 2.685262570 | 2.675115000 |

After fix

| Machine | Realization | Attemps | Params | Min(sec) | Max(sec) | Avg(sec) | Median(sec) |
|---------|-------------|---------|--------|----------|----------|----------|-------------|
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Pthread | 100 | 2, 10000, 10000, 0.99, 0.005 | 0.048350100 | 0.094024180 | 0.055078959 | 0.054627535 |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Custom | 100 | 2, 10000, 10000, 0.99, 0.005 | 0.001085043 | 0.002697945 | 0.001220498 | 0.001188397 |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Pthread | 100 | 2, 10000, 10000, 0.2, 0.5 | 0.140946100 | 0.424449900 | 0.153496315 | 0.145204550 |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Custom | 100 | 2, 10000, 10000, 0.2, 0.5 | 0.075176000 | 0.143632900 | 0.087214967 | 0.083606485 |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Pthread | 100 | 4, 10000, 10000, 0.99, 0.005 | 0.028616910 | 0.060552120 | 0.031968839 | 0.029431465 |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Custom | 100 | 4, 10000, 10000, 0.99, 0.005 | 0.001275063 | 0.002411127 | 0.001490798 | 0.001445532 |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Pthread | 100 | 4, 10000, 10000, 0.2, 0.5 | 0.175329200 | 0.206543900 | 0.180970830 | 0.179927950 |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Custom | 100 | 4, 10000, 10000, 0.2, 0.5 | 0.131178900 | 0.168086100 | 0.151232538 | 0.152143450 |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Pthread | 100 | 8, 10000, 10000, 0.99, 0.005 | 0.023073910 | 0.027284860 | 0.024376032 | 0.024373530 |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Custom | 100 | 8, 10000, 10000, 0.99, 0.005 | 0.002115965 | 0.002674818 | 0.002444680 | 0.002449036 |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Pthread | 100 | 8, 10000, 10000, 0.2, 0.5 | 0.186024000 | 0.223182900 | 0.192172443 | 0.190556000 |
| Macbook air M4, MacOS 26.5.2, Chip M4, ARM64 | Custom | 100 | 8, 10000, 10000, 0.2, 0.5 | 0.184385100 | 0.204238900 | 0.193127363 | 0.193228000 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Pthread | 100 | 2, 10000, 10000, 0.99, 0.005 | 1.825109000 | 3.246229000 | 2.440776410 | 1.976128500 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Custom | 100 | 2, 10000, 10000, 0.99, 0.005 | 1.837730000 | 3.221136000 | 2.479371070 | 1.980267000 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Pthread | 100 | 2, 10000, 10000, 0.2, 0.5 | 2.270227000 | 4.831683000 | 3.601579420 | 3.094637000 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Custom | 100 | 2, 10000, 10000, 0.2, 0.5 | 2.451801000 | 4.462201000 | 3.632574690 | 3.999635500 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Pthread | 100 | 4, 10000, 10000, 0.99, 0.005 | 1.770023000 | 2.845857000 | 2.467800810 | 2.501805500 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Custom | 100 | 4, 10000, 10000, 0.99, 0.005 | 1.345695000 | 1.733033000 | 1.613219180 | 1.631669000 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Pthread | 100 | 4, 10000, 10000, 0.2, 0.5 | 2.849463000 | 5.002620000 | 4.642493440 | 4.682354000 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Custom | 100 | 4, 10000, 10000, 0.2, 0.5 | 3.846633000 | 4.795254000 | 4.463672210 | 4.477432500 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Pthread | 100 | 8, 10000, 10000, 0.99, 0.005 | 2.189579000 | 2.626607000 | 2.458251140 | 2.458932500 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Custom | 100 | 8, 10000, 10000, 0.99, 0.005 | 0.945766900 | 0.973666900 | 0.960147692 | 0.960414150 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Pthread | 100 | 8, 10000, 10000, 0.2, 0.5 | 5.086217000 | 5.646216000 | 5.297330760 | 5.287871000 |
| Banana PI 3, Ubuntu 22.04, SpacemiT K1, RISC-V | Custom | 100 | 8, 10000, 10000, 0.2, 0.5 | 4.789676000 | 5.086703000 | 4.932334860 | 4.931597000 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Pthread | 100 | 2, 10000, 10000, 0.99, 0.005 | 0.726722000 | 0.765687000 | 0.731935421 | 0.731406450 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Custom | 100 | 2, 10000, 10000, 0.99, 0.005 | 0.727235100 | 0.741317000 | 0.733074887 | 0.733094550 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Pthread | 100 | 2, 10000, 10000, 0.2, 0.5 | 1.568219000 | 1.768664000 | 1.607944520 | 1.593582000 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Custom | 100 | 2, 10000, 10000, 0.2, 0.5 | 1.473800000 | 1.566412000 | 1.496875600 | 1.490588500 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Pthread | 100 | 4, 10000, 10000, 0.99, 0.005 | 0.729078100 | 0.793143000 | 0.764250882 | 0.765285500 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Custom | 100 | 4, 10000, 10000, 0.99, 0.005 | 0.405674000 | 0.424286100 | 0.409827951 | 0.409251450 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Pthread | 100 | 4, 10000, 10000, 0.2, 0.5 | 1.760925000 | 1.990591000 | 1.830251970 | 1.821377000 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Custom | 100 | 4, 10000, 10000, 0.2, 0.5 | 1.581321000 | 1.876617000 | 1.646330100 | 1.627892500 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Pthread | 100 | 8, 10000, 10000, 0.99, 0.005 | 0.697692900 | 0.765888000 | 0.728336243 | 0.726353500 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Custom | 100 | 8, 10000, 10000, 0.99, 0.005 | 0.412633200 | 0.453162900 | 0.430838393 | 0.429786550 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Pthread | 100 | 8, 10000, 10000, 0.2, 0.5 | 1.925533000 | 2.181470000 | 2.013321580 | 2.001473000 |
| Lichee PI 4a, Ubuntu 22.04, T-Head TH1520, RISC-V | Custom | 100 | 8, 10000, 10000, 0.2, 0.5 | 1.812458000 | 2.153785000 | 1.936835250 | 1.926914500 |
| T-Head TH1520, RISC-V | basic | 10 | N=100, t_end=100, threads=1 | 0.052919000 | 0.053898000 | 0.053133100 | 0.052974500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=100, t_end=100, threads=2 | 0.035462000 | 0.038552000 | 0.036944600 | 0.036899500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=100, t_end=100, threads=4 | 0.037504000 | 0.066947000 | 0.044945400 | 0.043245500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=100, t_end=100, threads=8 | 0.047086000 | 0.053192000 | 0.048530000 | 0.047638500 |
| T-Head TH1520, RISC-V | basic | 10 | N=100, t_end=500, threads=1 | 0.263933000 | 0.268298000 | 0.264683800 | 0.264211500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=100, t_end=500, threads=2 | 0.173201000 | 0.175905000 | 0.174109400 | 0.173947500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=100, t_end=500, threads=4 | 0.122645000 | 0.161260000 | 0.140001500 | 0.136678500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=100, t_end=500, threads=8 | 0.159211000 | 0.270785000 | 0.208928100 | 0.216292500 |
| T-Head TH1520, RISC-V | basic | 10 | N=100, t_end=1000, threads=1 | 0.527803000 | 0.530122000 | 0.528686600 | 0.528265500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=100, t_end=1000, threads=2 | 0.345278000 | 0.351150000 | 0.347358100 | 0.346938500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=100, t_end=1000, threads=4 | 0.217609000 | 0.285542000 | 0.242331800 | 0.238177500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=100, t_end=1000, threads=8 | 0.305264000 | 0.456621000 | 0.364780700 | 0.350023000 |
| T-Head TH1520, RISC-V | basic | 10 | N=1000, t_end=100, threads=1 | 6.438116000 | 6.531786000 | 6.463452100 | 6.455866000 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1000, t_end=100, threads=2 | 2.933843000 | 2.986826000 | 2.962611600 | 2.963038500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1000, t_end=100, threads=4 | 1.502762000 | 1.635109000 | 1.551342300 | 1.548115000 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1000, t_end=100, threads=8 | 1.510479000 | 1.667403000 | 1.575633400 | 1.580619000 |
| T-Head TH1520, RISC-V | basic | 10 | N=1000, t_end=500, threads=1 | 32.233099000 | 32.851989000 | 32.395324900 | 32.338242000 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1000, t_end=500, threads=2 | 14.609401000 | 14.963530000 | 14.807917100 | 14.818882500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1000, t_end=500, threads=4 | 7.413156000 | 7.618680000 | 7.523577400 | 7.542448000 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1000, t_end=500, threads=8 | 7.550033000 | 7.836540000 | 7.720749200 | 7.729865000 |
| T-Head TH1520, RISC-V | basic | 10 | N=1000, t_end=1000, threads=1 | 64.377563000 | 64.795066000 | 64.625371800 | 64.636819000 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1000, t_end=1000, threads=2 | 29.288650000 | 30.106288000 | 29.644086400 | 29.595329000 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1000, t_end=1000, threads=4 | 14.892798000 | 15.223364000 | 15.038610100 | 15.019723000 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1000, t_end=1000, threads=8 | 15.150265000 | 15.591913000 | 15.400640900 | 15.462982500 |
| T-Head TH1520, RISC-V | basic | 10 | N=1500, t_end=100, threads=1 | 14.525783000 | 14.594048000 | 14.559968400 | 14.554783500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1500, t_end=100, threads=2 | 6.669373000 | 6.712310000 | 6.688526600 | 6.687235000 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1500, t_end=100, threads=4 | 3.377701000 | 3.591699000 | 3.438324500 | 3.429358000 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1500, t_end=100, threads=8 | 3.374039000 | 3.484658000 | 3.410942100 | 3.408587000 |
| T-Head TH1520, RISC-V | basic | 10 | N=1500, t_end=500, threads=1 | 72.567185000 | 73.647207000 | 72.835988600 | 72.756895000 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1500, t_end=500, threads=2 | 33.277649000 | 33.531958000 | 33.374490600 | 33.346219000 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1500, t_end=500, threads=4 | 16.860627000 | 17.393510000 | 17.113646200 | 17.069039500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1500, t_end=500, threads=8 | 16.894302000 | 17.544425000 | 17.100434600 | 17.011377500 |
| T-Head TH1520, RISC-V | basic | 10 | N=1500, t_end=1000, threads=1 | 145.283827000 | 145.774946000 | 145.608067600 | 145.651260000 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1500, t_end=1000, threads=2 | 66.597332000 | 66.929793000 | 66.747970600 | 66.754781500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1500, t_end=1000, threads=4 | 33.551045000 | 34.556447000 | 34.061772600 | 34.114194500 |
| T-Head TH1520, RISC-V | Pthread | 10 | N=1500, t_end=1000, threads=8 | 33.948291000 | 35.034867000 | 34.394726300 | 34.392088000 |
| Spacemit K1, RISC-V | basic | 10 | N=100, t_end=100, threads=1 | 0.079259000 | 0.081602000 | 0.080878100 | 0.081462000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=100, t_end=100, threads=2 | 0.064224000 | 0.067972000 | 0.066708300 | 0.067397500 |
| Spacemit K1, RISC-V | Pthread | 10 | N=100, t_end=100, threads=4 | 0.040280000 | 0.042123000 | 0.041041500 | 0.041007000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=100, t_end=100, threads=8 | 0.037816000 | 0.062908000 | 0.053552500 | 0.054222500 |
| Spacemit K1, RISC-V | basic | 10 | N=100, t_end=500, threads=1 | 0.406412000 | 0.406642000 | 0.406553700 | 0.406570000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=100, t_end=500, threads=2 | 0.318901000 | 0.335504000 | 0.329133100 | 0.329918000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=100, t_end=500, threads=4 | 0.194462000 | 0.204101000 | 0.201470400 | 0.202256000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=100, t_end=500, threads=8 | 0.196727000 | 0.273127000 | 0.231581200 | 0.226597500 |
| Spacemit K1, RISC-V | basic | 10 | N=100, t_end=1000, threads=1 | 0.788017000 | 0.813189000 | 0.807945000 | 0.812820500 |
| Spacemit K1, RISC-V | Pthread | 10 | N=100, t_end=1000, threads=2 | 0.645682000 | 0.675175000 | 0.660944200 | 0.659107000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=100, t_end=1000, threads=4 | 0.396724000 | 0.406555000 | 0.402921100 | 0.403875000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=100, t_end=1000, threads=8 | 0.365562000 | 0.453608000 | 0.397960000 | 0.390744500 |
| Spacemit K1, RISC-V | basic | 10 | N=1000, t_end=100, threads=1 | 9.215154000 | 9.497128000 | 9.438535700 | 9.492429000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1000, t_end=100, threads=2 | 6.687549000 | 6.910909000 | 6.835356000 | 6.855867000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1000, t_end=100, threads=4 | 3.362099000 | 3.419584000 | 3.396237900 | 3.395118000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1000, t_end=100, threads=8 | 1.720096000 | 1.739742000 | 1.730115800 | 1.730573500 |
| Spacemit K1, RISC-V | basic | 10 | N=1000, t_end=500, threads=1 | 46.035099000 | 47.505352000 | 47.186318800 | 47.452330500 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1000, t_end=500, threads=2 | 32.384471000 | 34.762069000 | 33.829669900 | 34.155219000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1000, t_end=500, threads=4 | 16.782699000 | 17.074569000 | 16.963242500 | 17.024321500 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1000, t_end=500, threads=8 | 8.588596000 | 9.181227000 | 8.711071300 | 8.661880000 |
| Spacemit K1, RISC-V | basic | 10 | N=1000, t_end=1000, threads=1 | 92.094854000 | 94.990859000 | 94.643894600 | 94.919447500 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1000, t_end=1000, threads=2 | 66.767795000 | 68.665794000 | 67.957035000 | 68.281070500 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1000, t_end=1000, threads=4 | 33.660284000 | 34.053666000 | 33.957226700 | 33.987989500 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1000, t_end=1000, threads=8 | 17.230866000 | 17.364914000 | 17.302543100 | 17.303933500 |
| Spacemit K1, RISC-V | basic | 10 | N=1500, t_end=100, threads=1 | 20.694777000 | 21.318416000 | 21.069680600 | 21.309825500 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1500, t_end=100, threads=2 | 15.315115000 | 15.458892000 | 15.368860200 | 15.354691500 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1500, t_end=100, threads=4 | 7.599182000 | 7.634906000 | 7.622361500 | 7.622734500 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1500, t_end=100, threads=8 | 3.842770000 | 3.870364000 | 3.857268700 | 3.855963500 |
| Spacemit K1, RISC-V | basic | 10 | N=1500, t_end=500, threads=1 | 103.414521000 | 105.685834000 | 103.746952000 | 103.449423000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1500, t_end=500, threads=2 | 76.708290000 | 77.434949000 | 76.871863900 | 76.785829000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1500, t_end=500, threads=4 | 37.992765000 | 38.151331000 | 38.099559800 | 38.120356000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1500, t_end=500, threads=8 | 19.229174000 | 19.853954000 | 19.367582500 | 19.332841000 |
| Spacemit K1, RISC-V | basic | 10 | N=1500, t_end=1000, threads=1 | 206.798307000 | 213.050817000 | 209.389511000 | 207.043742500 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1500, t_end=1000, threads=2 | 153.325792000 | 154.614159000 | 153.599200800 | 153.497372000 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1500, t_end=1000, threads=4 | 75.917225000 | 76.346839000 | 76.118411800 | 76.124528500 |
| Spacemit K1, RISC-V | Pthread | 10 | N=1500, t_end=1000, threads=8 | 38.518888000 | 39.116338000 | 38.696267700 | 38.663885000 |
