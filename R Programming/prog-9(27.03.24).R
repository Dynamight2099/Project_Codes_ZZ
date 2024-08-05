#Q1
s = c(578,572,570,568,572,570,570,572,596,584)
u= 577
n=10

xbar = mean(s)
xbar

vari = var(s)
vari

sd= sqrt(vari)
sd

alpha = 0.05
talpha = qt(0.95,9)#(complement of alpha, degrees of freedom)
talpha

t = (xbar-u)/((sd)/sqrt(n-1))
t

if(t<=talpha){print("Accept Null Hypothesis")}else{print("Reject Null Hypothesis")}

#Q2(t test)
s1 = c(19,17,15,21,16,18,16,14)
s2 = c(15,14,15,19,15,18,16)
n1=8
n2=7

t.test(s1,s2)
t=abs(t)
t

alpha=0.05
talpha = qt(0.95,n1+n2-2)
if(t<=talpha){print("Accept Null Hypothesis")}else{print("Reject Null Hypothesis")}


