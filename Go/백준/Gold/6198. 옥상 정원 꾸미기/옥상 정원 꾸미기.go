package main
import (
	"bufio"
	"fmt"
	"os"
    "runtime/debug"
)
func main () {
    debug.SetGCPercent(1)
	br := bufio.NewReader(os.Stdin)
	bw := bufio.NewWriter(os.Stdout)
	defer bw.Flush()
	var N int
	fmt.Fscan(br, &N)
	buildings := make([]uint64, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(br,&buildings[i])
	}
    stack := make([]uint64,0,N)
	res := uint64(0)
	for i := 0; i < N; i++ {
		itm := buildings[i]
        for (len(stack) > 0) && itm >= stack[len(stack)-1] {
            stack = stack[:len(stack)-1]
		}
        res += uint64(len(stack))
        stack = append(stack, itm)
	}
	fmt.Fprintln(bw,res)
}