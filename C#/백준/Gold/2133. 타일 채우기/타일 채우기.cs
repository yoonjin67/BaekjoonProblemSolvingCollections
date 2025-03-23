using System;
namespace Main {
  internal class Program {
    static void Main(string[] args) {
      StreamReader sr = new StreamReader(
          new BufferedStream(
            Console.OpenStandardInput()
            )
          );
      StreamWriter sw = new StreamWriter(
          new BufferedStream(
            Console.OpenStandardOutput()
            )
          );
      int n;
      string s = sr.ReadLine();
      n = Int32.Parse(s);
      if(n%2 == 1 || n == 1) {
        sw.WriteLine("0");
        sw.Flush();
        return;
      } else {
        var tile = new int[n+1];
        tile[0] = 1;
       
        for(int i=2; i<=n; i+=2){ 
          tile[i] = tile[i-2]*3; //3*2의 부분에서 만들 수 있는 모든 조합.
          for(int j=i-4; j>=0; j-=2){ //3*4에서 최초 생성되는 특별한 타일의 수를 포함시키려고 이걸 넣는다는데, 특별한 타일의 유형은 2가지
            tile[i] += tile[j]*2; //그래서 2를 곱해준다는데, 뭐 그렇게 해서 3*8, 3*6, 3*4 이런식으로 누적한다고?
            //솔직히 못 알아먹겠음;;
          }
          /*
          타일은 짝수마다 만들어 낼 수 있으며
    1) 이전에 만들어진 짝수번째 타일의 개수 X 3
    2) 그 전전의 전체 타일 개수 X 이전타일의 특별한 타일 개수
    3) 해당 위치에서 만들어지는 특별한 타일 개수
    출처: https://hello-backend.tistory.com/156
    라는데 뭐임?
          */
        }
      sw.WriteLine(""+tile[n]);
      sw.Flush();
      }
    }
  }
}
