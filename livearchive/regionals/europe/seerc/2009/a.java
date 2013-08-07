// seerc 2009 a
import java.math.BigInteger;
import java.util.Scanner;

class a {
	public static BigInteger sqrt(BigInteger a) 
	{
		BigInteger l = BigInteger.ZERO;
		BigInteger h = a;
		BigInteger v, m;
		while(l.compareTo(h) < 0)
		{
			m = l.add(h).shiftRight(1);
			v = m.multiply(m);
			if(v.compareTo(a) < 0) l = m.add(BigInteger.ONE);
			else if(v.compareTo(a) == 0) return m;
			else h = m;
		}
		return l.subtract(BigInteger.ONE);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextBigInteger())
		{
			BigInteger n = sc.nextBigInteger();
			BigInteger k = sc.nextBigInteger();
			BigInteger r = sqrt(n.multiply(k).add(BigInteger.TEN.pow(10).shiftRight(2)));
			r = BigInteger.valueOf(2).max(r.subtract(BigInteger.TEN.pow(5).shiftRight(1)));
			for(int i=0;i<100000;i++)
			{
				if(n.remainder(r).equals(BigInteger.ZERO))
				{
					BigInteger p = r.min(n.divide(r));
					BigInteger q = r.max(n.divide(r));
					System.out.println(p + " * " + q);
					break;
				}
				else r = r.add(BigInteger.ONE);
			}
		}
	}
}