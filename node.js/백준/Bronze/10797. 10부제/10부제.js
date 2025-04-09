let fs = require('fs');
let date = fs.readFileSync('/dev/stdin').toString().split('\n')
let input = date[1]
date = date[0]
input = input.split(' ')
let sum = 0
date = Number(date)
date %= 10
for(let i=0;i<input.length;i++) {
    input[i]=Number(input[i])
    if (input[i]==date) {
        sum++
    }
}
console.log(sum)