using System;
using System.Collections.Generic;
namespace Main {
  internal class Program {
    static void Main(string[] args) {
      var sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
      var n = Int32.Parse(sr.ReadLine());
      var dpArr = Enumerable.Repeat((int)0,12).ToArray();
      dpArr[0] = 0;
      dpArr[1] = 1;
      dpArr[2] = 2;
      dpArr[3] = 4;
      for(int i = 0; i < n; i++) {
        var num = Int32.Parse(sr.ReadLine());
        if(num<4) Console.WriteLine(dpArr[num]);
        else {
          for(int j = 4; j <= num; j++) {
            if(dpArr[j]!=0) continue;
            dpArr[j] = dpArr[j-1]+dpArr[j-2]+dpArr[j-3];
          }
          Console.WriteLine(dpArr[num]);
        }
      }
    }
  }
}