import java.io.*;
import java.util.*;
import java.util.Collections.*;

public class Main {
  static Integer N, M;
  static Integer movable[][] = new Integer[3][2];
  static void dp(int row, int col,Integer[][] maze, Integer[][]candies) {
    if((row==N-1) && (col==M-1)) return;
    int r = row, c = col;
    for(int i = 0; i < 3; i++) {
      r = row+movable[i][0];
      c = col+movable[i][1];
      if(r>=N) {
        continue;
      }
      if(c>=M) {
        continue;
      }
      if(candies[r][c]>candies[row][col]+maze[r][c]) continue; //어차피 최댓값을 찾는 거니까 굳이 값이 최대인데 떨구면 오히려 문제
      candies[r][c]=candies[row][col]+maze[r][c];
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//이동 가능 시나리오
//(r+1,c), (r,c+1), (r+1,c+1)
    //(r+1)
    movable[0][0] = 1;
    movable[0][1] = 0;
    //(c+1)
    movable[1][0] = 0;
    movable[1][1] = 1;
    //(r+1,c+1)
    movable[2][0] = movable[2][1] = 1;
    String[] sizeString = br.readLine().split(" ");
    N = Integer.parseInt(sizeString[0]);
    M = Integer.parseInt(sizeString[1]);
    Integer maze[][] = new Integer[N][M];
    Integer candies[][] = new Integer[N][M]; //캔디합을 위한 배열을 따로 만들어야함. 미로 값을 바로 쓰면 값 중복으로 오류가 남.
    for(Integer i = 0; i < N; i++) {
      String [] inp = br.readLine().split(" ");
      for(Integer j = 0; j < M; j++) {
        maze[i][j] = Integer.parseInt(inp[j]);
        if(!((i==0) && (j==0))) {
          candies[i][j] = 0;
        } else {
          candies[i][j] = maze[i][j];
        }
      }
    }
    for(Integer i = 0; i < N; i++) {
      for(Integer j = 0; j  < M; j++) {
        dp(i,j,maze,candies);
      }
    }

    bw.write(""+candies[N-1][M-1]);
    bw.flush();
    bw.close();
    br.close();
  }
}