import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		String str = "";
		
		str = sc.next();

                StringBuffer sBuffer = new StringBuffer(str);
                String reversedString = sBuffer.reverse().toString();
	
		if(reversedString.equals(str)) {
			System.out.println("true");
		}else if(str.length() == 1){
			System.out.println("true");
		}else {
			System.out.println("false");
		}
	}

}
