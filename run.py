import re
import subprocess
import sys

def run(iters):
    counter_count = {}
    for i in range(iters):
        if (i % 1000 == 0):
           print(f"Running iteration {i}...")

        process = subprocess.run('./race', stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        counter = int(re.findall("[0-9]+", process.stdout.decode("utf-8"))[0])
        if counter not in counter_count:
            counter_count[counter] = 1
        else:
            counter_count[counter] += 1

    print("\nResults:")
    for counter, count in sorted(counter_count.items()):
        print(f"counter = {counter} occurred {count} times")


# to specify number of iterations on command line, python3 run.py <number of iterations>
if __name__ == '__main__':
    iters = 0
    if len(sys.argv) == 2:
        iters = sys.argv[1]
    else:
        iters = input("How many iterations? ")

    run(int(iters))
