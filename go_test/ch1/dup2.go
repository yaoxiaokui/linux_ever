package main
import(
    "fmt"
    "bufio"
    "os"
)

func main(){
    counts := make(map[string]int)
    files := os.Args[1:]

    if len(files) == 0 {
        CountLines(os.Stdin, counts)
    }else {
        for _, arg := range files {
            f, err := os.Open(arg)
            if err != nil {
                fmt.Fprintf(os.Stderr, "dup2: %v\n", err)
                continue
            }
            CountLines(f, counts)
            f.Close()
        }
    }
}

func CountLines(f *os.File, counts map[string]int) {
    input := bufio.NewScanner(f)
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
