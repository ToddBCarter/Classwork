#A example showing how to run KNN algorithm in the R environment.
#Built for the CS479/579 class in Spring 2025, by Xiaogang (Marshall) Ma
#Raw dataset is the data science profile filled by students

install.packages('FNN')
library(FNN)

help(knn)

#read a csv file into a variable, build a data frame
data<-read.csv("data-science-profile20-25.csv")
data
head(data)

#Use Kmeans to cluster the students into five groups, and assign the group number to a new column data$Group 
km.result1 <- kmeans(data, 5, iter.max = 10, nstart = 1)
km.result1
data$Group = km.result1$cluster
data


#Now we start the process of KNN 
n.points <- nrow(data) # number of rows in the dataset

#We choose a sampling rate of 60% for the training dataset
sampling.rate <- 0.6

# we need the number of points in the test set to calculate
# the misclassification rate
num.test.set.labels <- n.points * (1 - sampling.rate)

# randomly sample which rows will go in the training set
training <- sample(1:n.points, sampling.rate * n.points, 
                   replace=FALSE) #return the row numbers of the sample records
train <- subset(data[training, ], select = c(CS, Math, Stats, ML, Domain.Expertise, Data.Viz, Comm)) #define the training set to be those rows


# the other rows are going into the test set
testing <- setdiff(1:n.points, training) #return the row numbers of other records
test <- subset(data[testing, ], select = c(CS, Math, Stats, ML, Domain.Expertise, Data.Viz, Comm)) # define the test set to be the other rows

cl <- data$Group[training] # this is the subset of Group/Category labels for the training set
true.labels <- data$Group[testing] # subset of Group/Category labels for the test set, we're withholding these


# we'll loop through and see what the misclassification rate is for different values of k
for (k in 1:10) {
  print(k)
  predicted.labels <- knn(train, test, cl, k) #return the predicated Group for the test dataset
  # We're using the R function knn()
  num.incorrect.labels <- sum(predicted.labels != true.labels)
  misclassification.rate <- num.incorrect.labels /
    num.test.set.labels
  print(misclassification.rate)
}

#Now assume we have the data science profile of a new student  
#Which group will the student belong to?
newstudent <- c(2,3,3,0,4,4,2)
knn(train,newstudent,cl, k = 8)

newstudent <- c(5,4,4,2,2,1,2)
knn(train,newstudent,cl, k = 9)

newstudent <- c(4,4,3,3,4,3,3)
knn(train,newstudent,cl, k = 9)

newstudent <- c(4,5,4,3,5,4,4)
knn(train,newstudent,cl, k = 9)

rm (list = ls())
