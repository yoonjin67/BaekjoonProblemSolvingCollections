import java.util.Scanner;
class Main {
	public static void main (String[] args) {
	    Scanner stdInput = new Scanner(System.in);
	    
	    String a = stdInput.next();
	    String b = stdInput.next();
	    
	    if(a.length()>b.length()) {
	        String tmp = a;
	        a=b;
	        b=tmp;
	    }
        for(int i=b.length()-1;i>=a.length();i--) {
            System.out.print((int)b.charAt(b.length()-1-i)-48);
        }
        for(int i=a.length()-1;i>=0;i--) {
            int X = (int)a.charAt(a.length()-1-i)+(int)b.charAt(b.length()-1-i)-96;
            System.out.print(X);
        }
	}
}