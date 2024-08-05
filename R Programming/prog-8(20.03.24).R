# Proportions using mean
#Q1
xbar=20
xbar

ybar=15
ybar

sigma=4
sigma

n1=500
n2=400

#Test Statistics
z=(xbar-ybar)/(sigma*sqrt((1/n1)+(1/n2)))
z

#level of significance
alpha = 0.05
alpha

#two tailed critical value
zalpha = qnorm(1-(alpha/2))
zalpha

#conclusionQ1
if(z<=zalpha){print("Accept Null Hypothesis(H0)")} else{print("Reject Null Hypothesis(H0)")}
#------------------------------------------------------------------------------------
#Proportions Sample difference 
#Q2
p1=0.2
p2=0.185
n1=900
n2=1600

P=((n1*p1)+(n2*p2))/(n1+n2)
P
Q=1-P
Q

#Test Statistic
Z=(p1-p2)/sqrt(P*Q*((1/n1)+(1/n2)))
Z

#level of significance
alpha = 0.05
alpha

#two tailed critical value
zalpha = qnorm(1-(alpha/2))
zalpha

#conclusionQ2
if(z<=zalpha){print("Accept Null Hypothesis(H0)")} else{print("Reject Null Hypothesis(H0)")}

#for one tailed critical value
zalpha1= qnorm(1-alpha)
zalpha1

#conclusionQ2(Single tailed)
if(z<=zalpha1){print("Accept Null Hypothesis(H0)")} else{print("Reject Null Hypothesis(H0)")}
#-------------------------------------------------------------------
#General Test
#Q3
#sample mean
xbar = 14.6
xbar

#Population mean
mu0= 15.4
mu0

sigma= 2.5
n=35

#test Statistic
z= abs((xbar-mu0)/(sigma/sqrt(n)))
z

alpha = 0.05
#two tailed test
zalpha= qnorm(1-(alpha/2))
zalpha

#conclusion
if(z<=zalpha){print("Accept Null Hypothesis(H0)")} else{print("Reject Null Hypothesis(H0)")}

#----------------------------------------------------------
#Q4
#size of sample
n=640

#Sample Proportion
p=63/n
P=0.1726
Q=1-P

Z2=abs((p-P)/(sqrt((P*Q)/n)))
Z2

alpha = 0.05
zalpha = (1-alpha)#1 tailed test

#conclusion
if(Z2<=zalpha){print("Accept Null Hypothesis(H0).Hospital is inefficeint")} else{print("Reject Null Hypothesis(H0).Hospital is efficient")}
#-------------------------------------------------------------------------




