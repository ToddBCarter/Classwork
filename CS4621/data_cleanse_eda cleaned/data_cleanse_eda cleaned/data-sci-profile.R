## Feb 20, 2024
## Title: An example showing data input/ouput in R and functions for exploratory data analysis
## Description: Dataset from a survey about each individual student's data science profile in the course CS479/579 Data Science of Spring 2024 at the Univeristy of Idaho, Moscow, ID
## Instructor: Xiaogang (Marshall) Ma, Email: max@uidaho.edu

#Set the working directory to the project directory: in RStudio menu: Session -> Set Working Directory -> To Project Directory

#read a csv file into a variable, build a data frame
ds.profile<-read.csv("data-science-profile.csv")

#read the same file in xlsx format
# install.packages('openxlsx')
# library(openxlsx)
# ds.profile<-read.xlsx("data-science-profile.xlsx",
#                       sheet=1, startRow=1)

#see the data type of the variable
class(ds.profile) 
#ds.profile <- data.frame(ds.profile) #covert a variable into data frame

#see the content and summary of the data frame
head(ds.profile, 5) #browse the top 5 rows
ds.profile
#View(ds.profile)
summary(ds.profile)

#Add metadata/documentation to data frame 
#There are many methods to add documetnion/metadata. Here we just use comment()
comment(ds.profile) <- "
## Feb 20, 2024
## Title: An example showing data input/ouput in R and functions for exploratory data analysis
## Description: Dataset from a survey about each individual student's data science profile in the course CS479/579 Data Science of Spring 2024 at the Univeristy of Idaho, Moscow, ID
## Instructor: Xiaogang (Marshall) Ma, Email: max@uidaho.edu
"

#show data frame documentation/metadata
cat(comment(ds.profile))

#show structure information of the data frame
str(ds.profile)

#change the first column from type number to character
ds.profile$ID<-as.character(ds.profile$ID)

#change the first column from type character to number
#ds.profile$ID<-as.numeric(ds.profile$ID)
#ds.profile$ID<-as.integer(ds.profile$ID)

#save the data frame into an R data file
save(ds.profile, file = "data-science-profile.rda")

#remove the data frame from workspace
ls()
rm(ds.profile)
ls()

#load a data frame from an R data file
load("data-science-profile.rda")
ls()

#show a histogram for a few columns in the data frame
hist(ds.profile$CS)
hist(ds.profile$Math)
hist(ds.profile$Stats)

#draw histograms for all variables
install.packages("psych")
library(psych)
# ds.profile[1] is Name and not a numeric value
multi.hist(ds.profile[2:8])

#show box plots for a few columns in the data frame
boxplot(ds.profile$ML)
boxplot(ds.profile$Domain.Expertise)
boxplot(ds.profile$Data.Viz)
boxplot(ds.profile$Comm)

#draw box plots for all variables
boxplot(ds.profile[2:8])

#show a few scatter plots of variable-pairs
#assume CS skill is correlated to Math skill
plot(ds.profile$CS, ds.profile$Math)
#assume Math skill is correlated to Stats skill
plot(ds.profile$Math, ds.profile$Stats)
#assume Data Viz skill is correlated to Communication skill
plot(ds.profile$Data.Viz, ds.profile$Comm.skills)

#draw a matrix of scatter plots for all the variable-pairs
pairs(ds.profile[2:8])

#draw scatterplots, histograms, and show correlations
pairs.panels(ds.profile[2:8])

#remove everything in the workspace
rm(list = ls())

