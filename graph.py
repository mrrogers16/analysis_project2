# Python script for sorting algorithm analysis with matplotlib
# Script assistance provided by OpenAI's ChatGPT
# October 31, 2024
import matplotlib.pyplot as plt
import numpy as np

# Data from the first table
input_patterns = ["Ascending", "Descending", "Vee", "Zigzag", "Random"]
merge_sort_100k = [853904, 815024, 859464, 836672, 994383]
quick_sort_100k = [4999950000, 4999950000, 2500000000, 1584664015, 2003731]
insertion_sort_100k = [199998, 4999950000, 2500099998, 2500199996, 2499769285]

# Data from the second table
n_values = [10, 100, 1000, 10000, 100000, 200000, 400000, 800000]
merge_sort_random = [16, 382, 6269, 81362, 993720, 2144152, 4427496, 9783203]
quick_sort_random = [27, 588, 11058, 152424, 1928530, 4301698, 9799198, 19267322]
insertion_sort_random = [
    38,
    2546,
    261232,
    25110509,
    2497215209,
    10004997070,
    39967955117,
    159978254596,
]

# Step 1: Create the Bar Chart for the First Table
plt.figure(figsize=(10, 6))
bar_width = 0.2
x = np.arange(len(input_patterns))

# Plot each sorting algorithm with a different color
plt.bar(x - bar_width, merge_sort_100k, width=bar_width, label="Merge Sort")
plt.bar(x, quick_sort_100k, width=bar_width, label="Quick Sort")
plt.bar(x + bar_width, insertion_sort_100k, width=bar_width, label="Insertion Sort")

plt.xlabel("Input Patterns")
plt.ylabel("Number of Comparisons")
plt.title("Sorting Comparisons for Different Input Patterns (N = 100,000)")
plt.xticks(x, input_patterns)
plt.legend()
plt.yscale("log")  # Log scale for better readability of large numbers
plt.show()

# Step 2: Create the Line Chart for the Second Table
plt.figure(figsize=(10, 6))

# Plot each sorting algorithm with a different line
plt.plot(n_values, merge_sort_random, marker="o", label="Merge Sort")
plt.plot(n_values, quick_sort_random, marker="o", label="Quick Sort")
plt.plot(n_values, insertion_sort_random, marker="o", label="Insertion Sort")

plt.xlabel("N (Size of Input)")
plt.ylabel("Number of Comparisons")
plt.title("Sorting Comparisons for Random Data")
plt.legend()
plt.xscale("log")
plt.yscale("log")  # Log-log scale for better readability across large ranges
plt.grid(True, which="both", ls="--")
plt.show()
