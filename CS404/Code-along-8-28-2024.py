import pandas as pd
import matplotlib.pyplot as plt
from sklearn.naive_bayes import GaussianNB
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn import tree
import graphviz
import seaborn as sns

df = pd.read_csv("faults.csv")

print(df.head())

###Visualize correlation
##print(df.corr())
##plot = sns.heatmap(df.corr())
##plt.show()
##plt.clf()
##

#k scatch is spelled correctly
faults = ["Pastry", "Z_Scratch", "K_Scatch", "Stains", "Dirtiness", "Bumps", "Other_Faults"]

#Create a new col
df['fault'] = 0
print(df.columns)
print(df.head())

#Lets create a new categorical variable for each fault
#This will be an integer
for i in range(0, len(faults)):
    #Build and indexes list where there are faults
    true_fault_indexes = df.loc[df[faults[i]] == 1].index.tolist()
    df.loc[true_fault_indexes, "fault"] = i+1

print(df["fault"])

#Create our dataset - training/test x and y features and outcomes
drop_features = ["fault"] + faults
features = df.drop(drop_features, axis=1)
outcomes = df["fault"]  #restricted to just this variable


print(features.columns)
print(outcomes.head())

training_features, test_features, training_outcomes, test_outcomes = train_test_split(features, outcomes, test_size=0.1)
#bayes_classifier = GaussianNB()
#bayes_classifier = tree.DecisionTreeClassifier()
bayes_classifier = RandomForestClassifier()
bayes_classifier.fit(training_features, training_outcomes)

#Score it
print("Test Accuracy")
mean_accuracy = bayes_classifier.score(test_features, test_outcomes)
print(mean_accuracy)
print("Training Accuracy")
train_accuracy = bayes_classifier.score(training_features, test_outcomes)
print(train_accuracy)

#Predict a random value
test_features.reset_index(inplace=True)
number = 3
random_features = pd.DataFrame([test_features.iloc[number]])
random_features = random_features.drop(["index"], axis=1)
random_outcome = test_outcomes.tolist()[number]
outcome_prediction = bayes_classifier.predict(random_features)
#Print
print("features")
print(random_features)
print("Acutal Outcome")
print(random_outcome)
print("Model predicted")
print(outcome_prediction[0])
print(f"Predicted fault: {faults[outcome_prediction[0] -1]}, Actual Fault: {faults[random_outcome -1]}")

#Get the log probability
#log_probs = bayes_classifier.predict_log_proba(random_features)
#print("Log Probabilities")
#print(log_probs)  #Probability of each individual fault

#dot_data = tree.export_graphviz(bayes_classifier, out_file=None)
#graph = graphviz.Source(dot_data)
#graph.render("decision_tree")
