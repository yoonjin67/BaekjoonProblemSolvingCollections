using System;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace Main {
  internal class Program {
    static void Main(string[] args) {
      StreamReader sr = new StreamReader(new BufferedStream(Console.OpenStandardInput()));
      StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput()));
      string []firstLine = sr.ReadLine().Split();
      var hash = new Dictionary<string,string>();
      var rev_hash = new Dictionary<string,List<string>>();
      if(firstLine.Length<2) return;
      int girlgroups = Int32.Parse(firstLine[0]);
      int quiz_len   = Int32.Parse(firstLine[1]);
      for(int i = 0; i < girlgroups; i++) {
        string girlgroup = sr.ReadLine();
        int    members   = Int32.Parse(sr.ReadLine());
        for(int j = 0; j < members; j++) {
          string member       = sr.ReadLine();
          hash.Add               ( member, girlgroup );
          if(!rev_hash.ContainsKey(girlgroup)) {
            rev_hash[girlgroup] = new List<string>();
          }
          rev_hash[girlgroup].Add( member );
        }
      }
      foreach(string key in rev_hash.Keys) {
        rev_hash[key].Sort();
      }
      for(int i = 0; i < quiz_len; i++) {
        string query  = sr.ReadLine();
        int quiz_type = Int32.Parse(sr.ReadLine());
        if(quiz_type == 1) {
          sw.WriteLine(hash[query]);
        } else {
          for(int j = 0; j < rev_hash[query].Count; j++) {
            sw.WriteLine(rev_hash[query][j]);
          }
        }
      }
      sr.Close();
      sw.Close();
    }
  }
}