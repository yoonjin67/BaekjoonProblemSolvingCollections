#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
uint8_t ** map;
uint64_t ** visited;
uint8_t n;

bool is_avail_single(uint8_t x) {
  if(x<0) return false;
  if(x>=n) return false;
  return true;
}
bool is_avail(uint8_t x, uint8_t y) {
  if(!is_avail_single(x) || !is_avail_single(y)) return false;
  return true;
}
uint64_t visit(uint8_t x, uint8_t y) {
  if(!is_avail(x,y)) return 0;
  if((x==n-1) && (x==y)) {
    return 1;
  }
  if(!map[x][y]) return 0;
  uint8_t nx = x+map[x][y];
  uint8_t ny = y+map[x][y];
  if(!visited[x][y]) visited[x][y] = visit(nx,y)+visit(x,ny);

  return visited[x][y];
}


int main() {
  scanf("%hu", &n);
  map = calloc(n,sizeof(int *));
  visited = calloc(n,sizeof(uint64_t *));
  for(int i = 0; i < n; i++) {
    map[i] = calloc(n,sizeof(int));
    visited[i] = calloc(n,sizeof(uint64_t));
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%hu", &map[i][j]);
    }
  }

  printf("%lu", visit(0,0));
  free(visited);
  free(map);
  return 0;
}