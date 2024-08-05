import java.util.*;

class func
{
    int num;
    public func(int num)
    {
        this.num=num;
    }
    public int prime(int n)//function to check if prime
    {
        int count=0;
        for(int i=1;i<n;i++)
        {
            if(n%i==0)
            {
                count++;
            }
        }
        if(count==1)
        {
            return 1;
        }
        else {
            return 0;
        }
    }
    public int Size()//function for size
    {
        int a=num,c=0;
        while(a>0)
        {
            a=a/10;
            c++;
        }
        return c;
    }
    public int[] mArr(int s)//make the number into array
    {
        int a=num,i=0;
        int C[] = new int[s];
        while(a>0)
        {
            int c=a%10;
            C[i]=c;
            a=a/10;
            i++;

        }
        return C;
    }
    public int[] shift(int [] A,int s)
    {
        int B[] = new int[s];
        for(int i=0;i<s-1;i++)
        {
            B[i]= A[i+1];
        }
        B[s-1]=A[0];
        return B;
    }
}
class Main
{
    public static void main(String args[])
    {

        Scanner obj = new Scanner(System.in);
        int num = obj.nextInt();
        func F = new func(num);
        int size=F.Size();//number of digits
        int M[]= F.mArr(size);//for the digits
        int N[]= new int[size];//for the final numbers

        for(int i=0;i<size;i++)
        {
            int z=0,j=0,k=1;
            while(j<size)
            {
                z+=M[j]*k;
                j++;
                k=k*10;
            }
            N[i]=z;
            M = F.shift(M,size);
        }
        int f=0;
        for(int i=0;i<size;i++)
        {
            if(F.prime(N[i])==1)
            {
                f++;
            }
        }
        if(f==size)
        {
            System.out.println("The number is circular Prime");
        }
        else
        {
            System.out.println("Not Circular Prime");
        }
    }
}