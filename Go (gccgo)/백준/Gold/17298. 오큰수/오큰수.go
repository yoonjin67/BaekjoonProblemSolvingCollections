package main
import (
	"fmt"
	"os"
	"bufio"
)
func main() {
	br := bufio.NewReader(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)
	defer bw.Flush()
	var n int
	fmt.Fscan(br,&n);
	v := make([]int, n)
	st := make([]int,0)
	res := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(br,&v[i])
	}
	for i := n-1; i >= 0; i-- {
		tmp := -1
		for len(st) > 0 && st[len(st)-1] <= v[i] {
			st = st[:len(st)-1]
		}
		if len(st) > 0 {
			tmp = st[len(st)-1]
		}
		res[i] = tmp
		st = append(st,v[i])
	}
	for _, ans := range res {
		fmt.Fprintf(bw,"%d ", ans);
	}
}