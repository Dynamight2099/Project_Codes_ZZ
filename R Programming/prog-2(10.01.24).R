#Data frame
empid <- c(1,2,3,4,5,6,7,8,9,10)
empid

age= c(30,37,23,45,23,46,36,37,54,25)
age

gender = c(0,1,1,1,0,1,0,1,1,0)
gender

status = c(1,2,2,1,2,1,2,1,2,1)
status

empinfo= data.frame(empid,age,gender,status)
empinfo

#changing values of numeric

empinfo$gender = factor(empinfo$gender,labels=c("male","female"))
empinfo$gender

empinfo$status = factor(empinfo$status,labels=c("staff","faculty"))
empinfo$status

#extract specific data
male =subset(empinfo,empinfo$gender=="male")
male

female =subset(empinfo,empinfo$gender=="female")
female

staff =subset(empinfo,empinfo$status=="staff")
staff

staff =subset(empinfo,empinfo$status=="faculty")
staff

summary(empinfo)
summary(male)
summary(female)

#creating tables(one way)
table1= table(empinfo$gender)
table1

table2= table(empinfo$status)
table2

#table 2-way
table3= table(empinfo$gender,empinfo$status)
table3

#graphical representation
plot(empinfo$empid,empinfo$age,type="l",main="age of Employees", xlab="empid",ylab="age in years",col="blue")


#pie chart
pie(table1)

# bar plots
barplot(table3,beside=T,xlim=c(1,10),ylim=c(0,8),col=c("red","blue"))
legend("topright",legend=rownames(table3),fill = c("blue","red"),bty="n")

boxplot(empinfo$status~empinfo$age,col=c("red","blue"))












