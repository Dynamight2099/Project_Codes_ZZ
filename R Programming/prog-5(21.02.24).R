X1= c(30,40,20,50,60,40,20,60) 
X1

X2= c(11,10,7,15,19,12,8,14) 
X2

Y= c(110,80,70,120,150,90,70,120) 
Y

regmodel = lm(Y~X1+X2)
regmodel

summary(regmodel)

install.packages("scatterplot3d")
library(scatterplot3d)
scatterplot3d(Y,X1,X2)


#cars dataset regression
data=mtcars
data
Y= data$mpg
X1= data$cyl
X2 = data$hp
Regmodel = lm (Y~X1+X2)
Regmodel
scatterplot3d(Y,X1,X2)


