#Use K-means to conduct a clustering analysis of the data science profile of students 2020-2025
#03/04/2025, Marshall Ma, University of Idaho

data<-read.csv("data-science-profile20-25.csv")
data<-read.csv("data-science-profile25.csv")
head(data)

install.packages("psych")
library(psych)
pairs.panels(data[1:7])

#check correlation between CS and Math skills 
# from the summary we can see p-value of the model. 
#Usually, A low P-value (< 0.05) means that the coefficient is likely not to equal zero. 
#A high P-value (> 0.05) means that we cannot conclude that the explanatory variable affects the dependent variable.
#the summary function will show the P value
liner_reg_model <- lm(data$CS ~ data$Math)
liner_reg_model
summary(liner_reg_model) 

#check correlation between Math and Stats skills 
liner_reg_model <- lm(data$Math ~ data$Stats)
liner_reg_model
summary(liner_reg_model)

#check correlation between Math and Communication skills 
liner_reg_model <- lm(data$Math ~ data$Comm)
liner_reg_model
summary(liner_reg_model)

#check correlation between CS and Visualization skills 
liner_reg_model <- lm(data$CS ~ data$Data.Viz)
liner_reg_model
summary(liner_reg_model)

#check correlation between Math and Visualization skills 
liner_reg_model <- lm(data$Math ~ data$Data.Viz)
liner_reg_model
summary(liner_reg_model)

#check the correlation between multiple variables  
liner_reg_model <- lm(data$ML ~ data$CS + data$Math + data$Stats)
liner_reg_model
summary(liner_reg_model)


help(kmeans)

#K-Means for all the seven attributes in the data science profile - with the default algorithm "Hartigan-Wong"
#We want nine clusters in the result
km.result <- kmeans(data, 9, iter.max = 10, nstart = 1)
km.result

#Add the clustering result back to the data in a column 'Group'
data$Group = km.result$cluster
data

#If we only want two clusters in the results
km.result <- kmeans(data, 2, iter.max = 10, nstart = 1)
km.result

#K-Means for the first four attributes (CS, Math, Stats, ML) in the data science profile
km.result1 <- kmeans(data[, 1:4], 3, iter.max = 10, nstart = 1)
km.result1

#K-Means for the last three attributes (domainE, Viz and Commun.) in the data science profile
km.result2 <- kmeans(data[, 5:7], 3, iter.max = 10, nstart = 1)
km.result2

#K-Means for CS in the data science profile
km.result3 <- kmeans(data$CS, 3, iter.max = 10, nstart = 1)
km.result3


rm(list = ls())
