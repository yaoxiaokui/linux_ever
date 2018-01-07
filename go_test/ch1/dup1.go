package main
import(
    "fmt"
    "bufio"
    "os"
)

func main(){
    counts := make(map[string]int)
    input := bufio.NewScanner(os.Stdin)
    for input.Scan(){
        counts[input.Text()]++
    }

    fmt.Println("--------------------------")
    fmt.Printf("%s\t%s\n", "count", "string")
    for line, n := range counts {
        if n > 1 {
            fmt.Printf("%d\t%s\n", n, line)
        }
    }
}
