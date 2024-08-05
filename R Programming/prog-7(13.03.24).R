#Poissons Distribution 
#Q1
#number of trials 
m=20

#probability of success
p=0.02
lambda= m*p

#atleast 2 defectives
p1= sum (dpois(2:m,lambda))
p1

#number of boxes contining atleast 2 defectives
round(1000*p1)

#exactly 2 defectives
p2=dpois(2,lambda)
p2

#number of boxes contining excactly 2 defectives
round(1000*p2)

#atmost 2 defectives
p3 = sum(dpois(0:2,lambda))
p3

#number of boxes containing at most 2 defective
round(1000*p3)

#plotting distribution
x1=0:m
px1=dpois(x1,lambda)
plot(x1,px1,type="h",xlab="values of x",ylab="Probability distribution of X",
     main="Poissons Dsitribution")
#Dataframe
rounded= round(px1,digits=5)
data.frame(x1,px1,rounded)

#mean, variance, expectation
mean = 1/lambda
mean

Ex1= weighted.mean(x1,px1)
Ex1

Varx1= weighted.mean(x1*x1,px1)-(weighted.mean(x1,px1))^2
Varx1

#Quartiles of poissons distribution
qpois(0.95,2.5)

#Random numbers from poissons 
rpois(2,3)

#Normal Distributions
#Q2
#generating the data 
x=seq(0,40)
x
#find the density function of x
y= dnorm(x,mean=20,sd=5)
y
#plot normal distribution
plot(x,y,type="l")

#proportion of jobs less than 15 min
p1=pnorm(15,mean=20,sd=5)
p1

x2=seq(0,15)
x2

y2=dnorm(x2, mean=20,sd=5)
y2

polygon(c(0,x2,15),c(0,y2,0),col="light green")

#proportion of jobs takes maore than 25 min
p2= pnorm(40,mean=20,sd=5)-pnorm(25,mean=20,sd=5)
p2

x1=seq(25,40)
x1

y1=dnorm(x1,mean=20,sd=5)
y1
polygon(c(25,x1,40),c(0,y1,0),col="light blue")

#proportion of jobs between 15 and 20 min
p3=pnorm(25,mean=20,sd=5)-pnorm(15,mean=20,sd=5)
p3

x3=seq(15,25)
x3

y3=dnorm(x3,mean=20,sd=5)
y3

polygon(c(15,x3,25),c(0,y3,0),col=" blue")

#probability distribution
data.frame(p1,p2,p3)

a <- seq(15,150,15)
a

b<- seq(15,150,by=15)
b

b=sum(b)
b

a = matrix(1:1,nrow=4)
a


