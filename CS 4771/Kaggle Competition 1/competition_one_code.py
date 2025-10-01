"""
CS4771 - Python for Machine Learning
Kaggle Competition Assignment 1
Todd Carter
V01187982
9-30-2025

"""

import pandas as pd
import numpy as np

from sklearn.datasets import make_regression
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

train = pd.read_csv("train.csv")
test = pd.read_csv("test.csv")
sample = pd.read_csv("sample_submission.csv")

#Print headers just to see:
print(train.head())
print(train.info())
print(test.head())
print(test.info())
print(sample.head())

#Encode the data for the regression:
train["sex"] = train["sex"].map({"female": 0, "male": 1})
train["smoker"] = train["smoker"].map({"no": 0, "yes": 1})

#pd.get_dummies() rebuilds non integer data into 0,1 format for linear regressions
train = pd.get_dummies(train, columns=["region"], drop_first=True)

test["sex"] = test["sex"].map({"female": 0, "male": 1})
test["smoker"] = test["smoker"].map({"no": 0, "yes": 1})

test = pd.get_dummies(test, columns=["region"], drop_first=True)

X = train.drop("charges", axis=1)
y = train["charges"]

X_test = test.copy()
X_test = test.drop("ID", axis=1)

#test prints to make sure encoding worked:
print(train.head())
print(train.info())
print(sample.head())

#Produce the model:
model = LinearRegression()

model.fit(X, y)

preds = model.predict(X_test)

#Produce the submission:
submission = sample.copy()
submission["charges"] = preds
submission["ID"] = test["ID"]
submission.to_csv("submission.csv", index=False)
