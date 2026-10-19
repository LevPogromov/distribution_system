#!/usr/bin/env python3

import subprocess
import re
import statistics

MACHINE = "Intel Core i7-10870H, x86_64"

THREADS = ["4", "8", "16"]

INPUT_FILES = {
    100: "inputs/input_100.csv",
    1000: "inputs/input_1000.csv",
    1500: "inputs/input_1500.csv",
}

T_END_VALUES = [100, 500, 1000]

REALIZATIONS = [
    ("basic", "./build/task2_orig"),
    ("Pthread", "./build/task2"),
]

ATTEMPTS = 10

def run_once(program, input_file, t_end, threads=None):
    if threads is None:
        command = [program, str(t_end), input_file]
    else:
        command = [program, threads, str(t_end), input_file]

    result = subprocess.run(
        command,
        text=True,
        capture_output=True,
        check=True,
    )

    match = re.search(
        r"Time spent:\s*([0-9.eE+-]+)",
        result.stdout,
    )

    return float(match.group(1))

def main():
    results = []

    for n, input_file in INPUT_FILES.items():
        for t_end in T_END_VALUES:
            for realization, program in REALIZATIONS:
                thread_counts = ([None] if realization == "basic" else THREADS)
                for threads in thread_counts:
                    times = []
                    for i in range(ATTEMPTS):
                        elapsed = run_once(program, input_file, t_end, threads)
                        times.append(elapsed)
                    results.append({
                        "machine": MACHINE,
                        "realization": realization,
                        "attempts": ATTEMPTS,
                        "params": (
                            f"N={n}, t_end={t_end}, "
                            f"threads={threads if threads is not None else 1}"
                        ),
                        "min": min(times),
                        "max": max(times),
                        "avg": statistics.mean(times),
                        "median": statistics.median(times),
                    })

    print("| Machine | Realization | Attemps | Params | Min(sec) | Max(sec) | Avg(sec) | Median(sec) |")
    print("|---------|-------------|---------|--------|----------|----------|----------|-------------|")

    for result in results:
        print(
            f"| {result['machine']} "
            f"| {result['realization']} "
            f"| {result['attempts']} "
            f"| {result['params']} "
            f"| {result['min']:.9f} "
            f"| {result['max']:.9f} "
            f"| {result['avg']:.9f} "
            f"| {result['median']:.9f} |"
        )

if __name__ == "__main__":
    main()