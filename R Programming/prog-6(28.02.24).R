n= 4 
p=0.5
q=1-p

#two heads
#using binom
a=dbinom(2,n,p)
a

#using combination
r=2
prob = choose(n,r)*((p)^r)*((q)^(n-r))
prob


#using factorial
probf = (factorial(n)/(factorial(r)*(factorial(n-r)) ))*((p)^r)*((q)^(n-r))
probf

#atmost Two heads
#using pbinom
a=pbinom(2,n,p)
a

#using sum
s= sum(dbinom(0:2,n,p))
s

#atleast two head
#using pbinom 
a= 1- pbinom(1,n,p)
a

#using sum
s= sum (dbinom(2:4,n,p))
s

#Expectations of x
x=0:n
px = dbinom(x,n,p)
Ex=weighted.mean(x,px)
Ex

#Mean
mean = n*p
mean

#Variance
var= weighted.mean(x*x,px)-(weighted.mean(x,px))^2
var

#Visualize the probability distribution
plot(x,px,type="h",xlab="Values of X",ylab="Probability Distributuion Of X",
     main="Binomial Distribution")
rounded=round(px,digits=3)
rounded
#Dataframe
table=data.frame(x,px,rounded)
table

#10th, 20th quartiles of Bin(10,1/3) distribution
qbinom(0.1,10,1/3)
qbinom(0.2,10,1/3)

#how many heads will have a prob of 0.25 will come out when a coin is tossed 51 times
qbinom(0.25,51,1/2)

#Find 8 random values from a sample of 150 with prob of 0.4 
x=rbinom(8,150,0.4)
x
