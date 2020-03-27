import numpy as np
def print_ones(rows, cols):
    A = np.ones(shape=(rows, cols), dtype=float)
    print(A)

    num_elements = rows * cols
    return(num_elements)