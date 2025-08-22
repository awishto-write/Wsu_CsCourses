import pandas as pd
import numpy as np

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
print("Covariance matrix:\n", covariance_matrix, "\n") # Print the Covariance matrix of the standardized Dataset

               
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
print("First principal component:\n",first_principal_component , "\n") # Print the First principal component
second_principal_component = decreasing_eigenvectors[:, 1]
print("Second principal component:\n", second_principal_component, "\n") # Print the Second principal component                                   