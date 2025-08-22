# # Provided ga and gb from WSU ID: 11755265 from challenge.xlsx file
# ga = 833
# gb = 982
# # Given values
# q = 509
# P = 1019
# g = 3

# # To find the discrete logarithm value 
# def findDiscreteLogarithm(base, value, mod):
#     for x in range(q):
#         if pow(base, x, mod) == value:
#             return x
#     return None

# # To find the value of 𝑎 such that 𝑔^𝑎 ≡ 𝑔𝑎 (mod 𝑃)
# a = findDiscreteLogarithm(g, ga, P)
# # To find the value of b such that g^b = gb (mod P)
# b = findDiscreteLogarithm(g, gb, P)

# # To calculateg g^(ab) = gab (mod P)
# if a is not None and b is not None:
#     gab = pow(g, a * b, P)
# else:
#     gab = None
    
# # Display answer
# print(f"The values we found are: a = {a}, b = {b}, gab = {gab}")


##

import numpy as np
import scipy.cluster.hierarchy as sch
import matplotlib.pyplot as plt

# Given distance matrix (calculated from the similarity matrix)
distance_matrix = np.array([
    [0.00, 0.30, 0.35, 0.60, 0.80, 0.95],
    [0.30, 0.00, 0.05, 0.30, 0.50, 0.65],
    [0.35, 0.05, 0.00, 0.25, 0.45, 0.60],
    [0.60, 0.30, 0.25, 0.00, 0.20, 0.35],
    [0.80, 0.50, 0.45, 0.20, 0.00, 0.15],
    [0.95, 0.65, 0.60, 0.35, 0.15, 0.00]
])

# Perform hierarchical clustering using the MAX (Complete Linkage) method
Z = sch.linkage(distance_matrix, method='complete')

# Plot the dendrogram
plt.figure(figsize=(10, 5))
dendrogram = sch.dendrogram(Z, labels=['P1', 'P2', 'P3', 'P4', 'P5', 'P6'])
plt.title('Hierarchical Clustering Dendrogram (MAX - Complete Linkage)')
plt.xlabel('Points')
plt.ylabel('Distance')
plt.show()