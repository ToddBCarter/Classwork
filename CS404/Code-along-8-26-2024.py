import pandas as pd
from matplotlib import pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

wine_df = pd.read_csv('winequality-white.csv', sep=';')



#Manual regression between alcohol and quality

n = len(wine_df.index)
sum_x = wine_df["alcohol"].sum()
sum_y = wine_df["quality"].sum()
#print(sum_x, sum_y)
x_mean = sum_x/n
y_mean = sum_y/n
#print(f"{x_mean} {y_mean}")
sum_x_times_y = (wine_df["alcohol"]*wine_df["quality"]).sum()
sum_x_squared = wine_df["alcohol"].pow(2).sum()
print(f"{sum_x_times_y} {sum_x_squared}")

#Calculate our numerator and denom for m
Sxy = sum_x_times_y - (sum_x*sum_y)/n
Sxx = sum_x_squared - (sum_x*sum_x)/n
print(f"Sxy: {Sxy} Sxx: {Sxx}")


#Get our line variables:
m = Sxy/Sxx
b = y_mean - m * x_mean
print(f"Regression Equation: y = {m}x + {b}")


#Now lets predict a value:
row = 5
alcohol_val = wine_df.loc[5, "alcohol"]
quality_val = wine_df.loc[5, "quality"]
predicted_quality = alcohol_val * m + b

print(f"For alcohol value {alcohol_val}, the predicted quality was {predicted_quality} and the actual value was {quality_val}")


#Coefficient of determination:
wine_df["predictions"] = wine_df["alcohol"] * m + b
residual_squares = (wine_df["quality"] - wine_df["predictions"]).pow(2).sum()
total_squares = (wine_df["quality"] - y_mean).pow(2).sum()
r_squared = 1 - (residual_squares / total_squares)
print(f"Coefficient of determinat: {r_squared}")


#Now lets run the model scikit learn:
linear_regression_model = LinearRegression()
#Expects a list of x variables since it can multiple regression
#Which is why we got fancy with the brackets there
linear_regression_model.fit(wine_df[["alcohol"]], wine_df[["quality"]])
model_m = linear_regression_model.coef_[0][0]
model_b = linear_regression_model.intercept_[0]
print("Scikit learn regression model:")
print(f"Regression Equation: y = {model_m}x + {model_b}")


#Predict the same value as our regression:
predicted_model_quality = linear_regression_model.predict([[alcohol_val]])
print(f"For alcohol value {alcohol_val}, the predicted quality was {predicted_model_quality} and the actual value was {quality_val}")

score = linear_regression_model.score(wine_df[["alcohol"]], wine_df[["quality"]])
print(f"Coefficient of determination: {score}")

#Plot the best fit line:
plt.scatter(wine_df["alcohol"], wine_df["quality"])
plt.plot(wine_df["alcohol"], wine_df["predictions"], linestyle="solid")
plt.xlabel("alcohol")
plt.ylabel("quality")
plt.title("Alcohol vs Quality")
plt.show()






#Test and training set
training_set, testing_set = train_test_split(wine_df, test_size=0.1)
#Repeat our Linear Regression with training and test sets
lr_model_2 = LinearRegression()
lr_model_2.fit(training_set[["alcohol"]], training_set[["quality"]])
model_m = lr_model_2.coef_[0][0]
model_b = lr_model_2.intercept_[0]
print("training model")
print(f"Regression Equation: y = {model_m}x + {model_b}")
#Get the coefficient of detemrination
score = lr_model_2.score(testing_set[["alcohol"]], testing_set[["quality"]])
print(f"Coefficient of determination: {score}")


wine_df = pd.read_csv('winequality-white.csv', sep=':')
regression_list = ["alcohol", "pH", "sulphates"]
outcome_variable = wine_df["quality"]
regression_df = wine_df[regression_list]

linear_regression_model = LinearRegression()
linear_regression_model.fit(regression_df, outcome_variable)
model_ms = linear_regression_model.coef_
model_b = linear_regression_model.intercept_

print(f"Model coefficients {model_ms}")
print(f"Model intercept {model_b}")

row_5_prediction_values = wine_df.loc[5, :]
row_5_prediction_values = [row_5_prediction_values[regression_list]]
row_5_quality_value = wine_df.loc[5, "quality"].item()

predicted_quality = linear_regression_model.predict(row_5_prediction_value)
print(predicted_quality)
