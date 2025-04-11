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
      string s;
      s = sr.ReadLine();
      int ans = Int32.Parse(s);

      int n;
      for(n = 1; n <= ans; n++) {
       int tmp = n;
       string tmpStr = n.ToString();
       foreach(var c in tmpStr) {
         tmp += c-'0';
       }
       if(tmp==ans) break;
      }
      if(ans<n) {
          sw.WriteLine("0");
          sw.Flush();
          return;
      }
      sw.WriteLine(n+"");
      sw.Flush();
    }
  }
}