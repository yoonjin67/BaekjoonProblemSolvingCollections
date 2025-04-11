import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        HashMap<Integer,Integer> map = new HashMap<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Integer cards;
        cards = Integer.parseInt(br.readLine());
        StringTokenizer r = new StringTokenizer(br.readLine());
        for(Integer k = 0; k < cards; k++) {
            Integer i = Integer.parseInt(r.nextToken());
            map.put(i,1);
        }
        cards = Integer.parseInt(br.readLine());
        r = new StringTokenizer(br.readLine());
        for(Integer k = 0; k < cards; k++) {
            Integer i = Integer.parseInt(r.nextToken());
            if(map.get(i)==null) {
                bw.write("0");
            } else {
                bw.write("1");
            }
            if(i!=cards-1) {
                bw.write(" ");
            }
        }
        br.close();
        bw.flush();
        bw.close();
    }
}