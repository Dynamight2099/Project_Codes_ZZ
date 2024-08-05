# Question 1
coeff = matrix(c(4,3,1,1),nrow=2,byrow=TRUE)
coeff

const = c(17,5)
const

values = solve(coeff,const)
values

#Question 2
x=c(1,3,5,7,8)
y=c(7,11,18,12,13)

plot(x,y,type='l',main="Line Graph",xlab="Values of x",ylab="Values of y")

plot(x,y,type='p',main="Point Graph",xlab="Values of x",ylab="Values of y")

length(x)
sum(y)

z=x+y
z

#Question 3
mat1 = matrix(1:9,nrow=3,byrow=TRUE)
mat2 = matrix(10:18,nrow=3,byrow=TRUE)
sum = mat1+mat2
sum

inverse= solve(mat1)
inverse

transpose = t(sum)
transpose

#question 4
matrix = matrix(1:16,nrow=4)
matrix

trace = sum(diag(matrix))
trace

inverse = solve(matrix)
inverse

transpose = t(matrix)
transpose  

#Question 5
x = c(12,13,20,21,19,18,17,16,11)
y = c(20,23,24,25,26,36,32,29,28)

plot(x,y,type='l',main="line graph",xlab="x values",ylab="yvalues")
plot(x,y,type='h',main="histogram graph",xlab="x values",ylab="yvalues",col='yellow')

cor = cor(x,y)
cor

a=lm(x~y)
a
b=lm(y~x)
b

summary(a)
summary(b)

length(x)
length(y)

#question 6
n=6
p=0.25
q=0.75
r=4

x= dbinom(4,n,p)
x
prob=choose(n,4)*((p)^r)*(q)^(n-r)
prob


atleast1=1-(pbinom(0,n,p))
atleast1
atleastt1=sum(dbinom(1:6,n,p))
atleastt1

x=0:6
px=dbinom(x,n,p)
plot(x,px,type="l",xlab="values of x",ylab="Probability distribution of
x",main="Binomial distribution")

#Question 7
xbar1= 3.5
xbar2 = 3.1
n=50
sig1= 2
sig2= 1.5

z= (xbar1-xbar2)/(sqrt((sig)))



