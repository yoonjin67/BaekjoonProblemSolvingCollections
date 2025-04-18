package main
import (
	"fmt"
    "bufio"
    "os"
)
func main () {
	var testcases int
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()
    fmt.Fscan(reader, &testcases)
	for i := 0; i < testcases; i++ {
        kinds := make([]string,0,30)
		var clothings int
        m := make(map[string]int)
        fmt.Fscan(reader, &clothings)
		for j := 0; j < clothings; j++ {
			var cloth, kind string
			fmt.Fscan(reader, &cloth, &kind)
			_, ok := m[kind]
			if ok == false {
				m[kind] = 2
                kinds = append(kinds,kind)
            } else {
                m[kind]++
            }
		}
		res := 1
		for _, kind := range kinds {
			res *= m[kind]
	    }
		res -= 1
        fmt.Fprintf(writer, "%d\n", res)
	}
}