import sys
sys.setrecursionlimit(100000)
class baekjoon11725:
    def ___init___(self):
        return
    def dfs(self,v):
        for i in self.lst[v]:
            if self.visited[i] == 0:
                self.visited[i] = v
                self.dfs(i)
    def main(self):
        n = int(input())
        self.lst = []
        self.visited = []
        for i in range(n+1):
            self.lst.append([])
            self.visited.append(0)
        for i in range(n-1):
            p, child = map(int,input().split())
            self.lst[p].append(child)
            self.lst[child].append(p)
        for i in range(1,n+1):
            if self.visited[i] == 0:
                self.dfs(i)
        for i in range(2,n+1):
            print(self.visited[i])
        
if __name__ == "__main__":
    baekjoon = baekjoon11725()
    baekjoon.main()