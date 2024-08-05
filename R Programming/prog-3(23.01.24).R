#co-variance and correlation  
x=c(15,18,25,27,30,35)
y=c(50,65,82,95,110,120)
a=cor(x,y)
a

cor.test(x,y,method="pearson")

var(x,y)
b=cov(x,y)
b
e=var(x)
e
f=sqrt(var(x))
f
g=var(y)
g
h=sqrt(var(y))
h
r=b/(f*h)
r

#using dataset and finding co-relation

data<-cars
data
m<- data$speed
n<-data$dist
z=cor(m,n)
z
summary(data)
summary (data$speed)

plot(data)

x=c(15,26,27,25,25.5,27,32,18,22,20,26,24)
y=c(13.35,16.12,16.74,16,13.59,15.73,15.65,13.85,16.07,12.8,13.65,14.42)
a=cor(x,y)
a


