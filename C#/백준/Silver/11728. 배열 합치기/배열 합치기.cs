using System;

namespace Main {
  internal class Program {
    static void Main(string[] args) {
      var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
      var sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
      var lst = new List<int>();
      string s = sr.ReadLine();
      var input = s.Split(' ');
      int a= Int32.Parse(input[0])+Int32.Parse(input[1]);
      for(int i = 0; i < 2; i++) {
        var str = sr.ReadLine();
        var numbers = str.Split(' ');
        foreach(var num in numbers) {
          lst.Add(Int32.Parse(num));
        }
      }
      lst.Sort();
      for(var i = 0; i < a; i++) {
        sw.Write(lst[i]+"");
        if(i<a-1) sw.Write(" ");
      }
      sw.Flush();
    }
  }
}
