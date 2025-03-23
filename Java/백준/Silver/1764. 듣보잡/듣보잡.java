import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        HashSet<String> set = new HashSet<>();
        String [] inputValue = br.readLine().split(" ");
        if(inputValue.length<2) System.exit(0);
        int neverHeard = Integer.parseInt(inputValue[0]);
        int neverSeen = Integer.parseInt(inputValue[1]);
        for(int i = 0; i < neverHeard; i++) {
            set.add(br.readLine());
        }
        ArrayList<String> arr = new ArrayList<>();
        int len = 0;
        for(int i = 0; i < neverSeen; i++) {
            String s = br.readLine();
            if(set.contains(s)) {
                arr.add(s);
            }
        }
        Collections.sort(arr);
        bw.write(""+arr.size()+"\n");
        for(String s : arr) {
            bw.write(s+"\n");
        }
        bw.close();
        br.close();

    }
}