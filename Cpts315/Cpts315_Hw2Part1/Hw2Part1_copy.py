import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

                                            ## Problem 2 
                      
        # Question a) Data after standardization 

# At first we would want to read the data, so we put 'automobiles.csv' into the same directory as our main python file
dataset = pd.read_csv("automobiles.csv") # read the file data using read_csv() of pandas

# Now we want to use these five feature columns: curb-weight, horse power, city-mpg, highway-mpg, price to obtain a subdataset
five_features_columns = ['curb-weight','horsepower', 'city-mpg', 'highway-mpg', 'price'] # Create list of the 5 features we want

# Make use of the dataset and the five features colums we have to get the subdataset of the information we want
subdataset = dataset[five_features_columns]

# Standalization formula: z = (x - u) / s where x is oberseved value, u is the mean and s is the standard deviation
standardized_data = (subdataset - subdataset.mean()) / subdataset.std(ddof=0) # Making use of the pandas mean() and std() tools

#print("Data after standardization:\n", standardized_data, "\n") # Print the data after standardization

       # Question b) Covariance matrix of the standardized Dataset

# We will use .cov() tool in numpyb to get the covariance matrix of the standardized Dataset, however,
# standardized_data has for type DataFrame, but .cov() takes a parameter that is an array_like

# From VS Code, description of the parameter of .cov(), we get => 
# m : array_like => A 1-D or 2-D array containing multiple variables and observations. Each row of m represents a variable, 
# and each column a single observation of all those variables. Also see rowvar below.

# So we will to make some transformations to standardized_data to adhere with .cov() parameter, where .values helps us get all the values
# from the standardized_data, without column names and title of features. As well as making it as a array and a numpy array as well
# .T helps us to transpose the array we got so that it adheres with the parameter format of .cov()

array_standardized_data = standardized_data.values # Array of the values of standardized_data
transformed_standardized_data = array_standardized_data.T
covariance_matrix = np.cov(transformed_standardized_data) # Getting the Covariance matrix of the standardized Dataset
#print("Covariance matrix:\n", covariance_matrix, "\n") # Print the Covariance matrix of the standardized Dataset

               
       # Question c)  First principal component and second principal component of this dataset

# From online sources, I learned that the steps to find the first principal component and second principal component are:
# - 1) Perform eigendecomposition on the covariance matrix to get eigenvectors (principal components) and eigenvalues
# - 2) Sort the eigenvectors based on their eigenvalues from highest to lowest

# So let's execute those steps:
#  1) Perform eigendecomposition on the covariance matrix to get eigenvectors and eigenvalues
eigenvalues, eigenvectors = np.linalg.eig(covariance_matrix)

#  2) Sort the eigenvectors based on their eigenvalues from highest to lowest
decreasing_order = np.argsort(eigenvalues)[::-1] # [::-1] helps having a sort descending order by reversing the list because of the feature of .argsort()
decreasing_eigenvalues = eigenvalues[decreasing_order] # Sorting the eigenvalues in desceneding order using decreasing_order above
decreasing_eigenvectors = eigenvectors[:,decreasing_order] # Sorting the eigenvectors in desceneding order using decreasing_order above, dealing with the columns

# For the next, we will extract the first and second principal components from the decreasing_eigenvectors
first_principal_component = decreasing_eigenvectors[:, 0]
#print("First principal component:\n",first_principal_component , "\n") # Print the First principal component
second_principal_component = decreasing_eigenvectors[:, 1]
#print("Second principal component:\n", second_principal_component, "\n") # Print the Second principal component



                                            ## Problem 3
                      
        # Question a)  Separate the 40 experiments into two groups via a binning method where one group
            # has low water quality (Group 1) and one group has high water quality (Group 2).
            

# Let's copy the water pollution values from the table into an array - in the order it has been given
water_pollution_array = np.array([11.5, 17.7, 73.4, 11.2, 74.9, 6, 15.2, 64.9, 14.1, 76.8,
                                   11.3, 9.4, 13.8, 55.5, 61.4, 21.4, 90.7, 70.1, 60, 6.7,
                                   13.0, 80.1, 8.4, 64.9, 9.3, 9.6, 11.5, 7.5, 77, 11.9,
                                   81.2, 14.9, 83.8, 15.8, 16.5, 69, 7.6, 10.6, 77.9, 62.1])

bin_width_W = (np.max(water_pollution_array) - np.min(water_pollution_array)) / 2  # Calculation of the bin width: W; We get: (90.7 - 6) / 2 = 42.35
print("Bin Width:", bin_width_W, "\n")

# Now we need to get the boundaries for the bins
boundary = (np.min(water_pollution_array) + bin_width_W) # Calculation of the boundary: (6 + 42.35) = 48.35

# Extracting the bins/groups based on the boundary and the array
bin1 = water_pollution_array[water_pollution_array <= boundary]
bin2 = water_pollution_array[water_pollution_array > boundary]

# However, when dealing with integer like 6, the result ends up being 6. with any 0 at the end, so to match, the exact way 
# it has been given in the table, let's convert those integer correctly
bin1 = [int(val) if val.is_integer() else val for val in bin1]
bin2 = [int(val) if val.is_integer() else val for val in bin2]

print("Bin1 => Group 1 (Low Water Quality):", bin1, "\n")
print("Bin2 => Group 2 (High Water Quality):", bin2, "\n")

            # Question b)  Normalize the Substance A and Substance B amounts based on 
            #                min-max normal-ization for each group and report the normalized values.
                    
#  Let's copy the substances A and B values from the table into an array - in the order it has been given

substanceA_bin1 = np.array([ 2.84, 9.34, 0.21, 2.77, 4.41, 9.94, 0.66, 2.73, 2.14, 7.36, 9.79,
                             5.07, 9.83, 5.76, 0.17, 7.9, 9.29, 2, 7.21, 8.7, 3.05, 3.41, 7.5])

substanceB_bin1 = np.array([ 78.9, 52.6, 39.6, 98.1, 4.8, 16.4, 61.6, 67.2, 85, 13, 16.8,
                             87.9, 55.3, 94.4, 41.9, 15.5, 13.6, 93.3, 20.6, 48.3, 86.3, 1.6, 22.7 ])

substanceA_bin2 = np.array([ 7.59, 7.31, 7.34, 7.17,77.9, 0.63, 7.21, 6.14, 4.24,
                             0.67, 1.44, 2.99, 8.62, 7.44, 1.74, 2.84, 1.43 ])

substanceB_bin2 = np.array([ 76.7, 58.4, 83.4, 86.9, 61.4, 11.3, 88, 35.4, 53.3, 
                             9.2, 32.9, 20.6, 78.9, 98.8, 12.7, 33.6, 26.2 ])

normalized_values_group1_substanceA = (substanceA_bin1 - np.min(substanceA_bin1)) / (np.max(substanceA_bin1) - np.min(substanceA_bin1))  # Include only elments of group 1
normalized_values_group1_substanceB = (substanceB_bin1 - np.min(substanceB_bin1)) / (np.max(substanceB_bin1) - np.min(substanceB_bin1))  #   # Include only elments of group 1
normalized_values_group2_substanceA = (substanceA_bin2 - np.min(substanceA_bin2)) / (np.max(substanceA_bin2) - np.min(substanceA_bin2))  # 
normalized_values_group2_substanceB = (substanceB_bin2 - np.min(substanceB_bin2)) / (np.max(substanceB_bin2) - np.min(substanceB_bin2))  # 



#print
print("Min, substance A, bin 1: ", np.min(substanceA_bin1))
print("Max, substance B, bin 1: ", np.max(substanceB_bin1))
print("Min, substance A, bin 2: ", np.min(substanceA_bin2))
print("Max, substance B, bin 2: ", np.min(substanceB_bin2))
print("Normalized values of group 1 for substance A:\n", normalized_values_group1_substanceA, "\n")
print("Normalized values of group 1 for substance B:\n", normalized_values_group1_substanceB, "\n")
print("Normalized values of group 2 for substance A:\n", normalized_values_group2_substanceA, "\n")
print("Normalized values of group 2 for substance B:\n", normalized_values_group2_substanceB, "\n")

             # Question d) Calculate the correlation coefficient (population level) between the normalized sub-stance A
             # and normalized substance B for each group.

# correlation coefficient with numpy
correlation_coefficient_group1 = np.corrcoef(normalized_values_group1_substanceA, normalized_values_group1_substanceB)[0, 1]
correlation_coefficient_group2 = np.corrcoef(normalized_values_group2_substanceA, normalized_values_group2_substanceB)[0, 1]

print("Correlation coefficient for group 1:", correlation_coefficient_group1, "\n")
print("Correlation coefficient for group 2:", correlation_coefficient_group2, "\n")

            # Question c) raw scatter plots of the normalized substance A and normalized substance B for each group
     
plt.figure(figsize=(9, 6))
plt.subplot(1, 2, 1)
plt.scatter(normalized_values_group1_substanceA, normalized_values_group1_substanceB, c='purple', label='Group 1')
plt.title('Group1')
plt.xlabel('Normalized Substance A')
plt.ylabel('Normalized Substance B')
plt.legend()

# The plt.subplot have different inputs, to make sure they are side by side

plt.subplot(1, 2, 2)
plt.scatter(normalized_values_group2_substanceA, normalized_values_group2_substanceB, c='pink', label='Group 2')
plt.title('Group2')
plt.xlabel('Normalized Substance A')
plt.ylabel('Normalized Substance B')
plt.legend()
plt.tight_layout()
plt.show()   # I commented out to terminate the code, if you want to check this, please uncomment
