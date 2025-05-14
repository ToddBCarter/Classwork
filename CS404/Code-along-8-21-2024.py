import pandas as pd

#Read the dataset into the "wine_df" variable

wine_df = pd.read_csv("winequality-white.csv", sep=";")

#Get an overview of the data
print(wine_df.head())

#Print the columns - method 1
print("Columns Index")
print(wine_df.columns)

#Print the columns - methods
print("Columns as a list")
print(list(wine_df.columns))

#Describe the data
#Give the cols, the count, the mean, sd, max, min, etc.
print("Describe the data")
print(wine_df.describe())

#Indexing
#Return a series object, a filtered view of a pandas data frame
#with only the quality column of the dataset
quality_series = wine_df['quality']
print("Quality Series")
print(quality_series)

quality_list = wine_df['quality'].values.tolist()
print("Quality List")
print(quality_list)

#Using .loc
#Get everything in the quality column
print("Entire quality column:")
print(wine_df.loc[:, "quality"])  #slice everything, all rows, just quality col

#Get the first quality value:
print("First quality value")
print(wine_df.loc[0, "quality"])

#Slice
print("First and up to 5-index quality value")
print(wine_df.loc[0:5, "quality"])

print("Everything before and up to the 5th indexed quality value")
print(wine_df.loc[:5, "quality"])

print("Everything after the 4890th-indexed quality value")
print(wine_df.loc[4890:, ["quality", "sulphates"]])


