 BEGIN {
  getline r;
  for(i = 1; i <= r; i++) {
    for(j = 0; j < i; j++) {
      printf "*"
    }
    printf "\n";
  }
}