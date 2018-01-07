package main
import(
    "fmt"
    "os"
    "io/ioutil"
    "strings"
)

func main(){
    counts := make(map[string]int)
    files := os.Args[1:]

    for _, fileName := range files {
        data, err := ioutil.ReadFile(fileName)
        if err != nil {
            fmt.Fprintf(os.Stderr, "dup3: %v\n", err)
            continue
        }

        for _, line := range strings.Split(string(data), "\n"){
            counts[line]++
        }
    }

    fmt.Println("--------------------------")
    fmt.Printf("%s\t%s\n", "count", "string")
    for line, n := range counts {
        if n > 1 {
            fmt.Printf("%d\t%s\n", n, line)
        }
    }

}
