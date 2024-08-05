x=c(5,15,20,17,13)
y=c(20,15,22,23,25)
a=lm(x~y)
a
b=lm(y~x)
b
plot(x,y)
abline(a)
abline(b)


data<- cars
data
x=data$speed
y=data$dist
a=lm(x~y)
b=lm(y~x)
plot(x,y)
abline(a)
abline(b)