class Queue {
    constructor() {
        this.raw = []
    }
    push(val) {
        this.raw.push(val)
    }
    pop() {
        if(this.raw.length==0) {
            return -1;
        }
        return this.raw.shift();
    }
    len() {
        return this.raw.length;
    }
}

class Map {
    constructor(height,width) {
        this.map = []
        this.direcs = [ [-1,0], [1,0], [0,-1], [0,1] ]
        for(let i = 0; i < height; i++) {
            let row = new Array(width).fill(0);
            this.map.push(row);
        }
        this.h = height;
        this.w = width;
    }
    setRect(x1,y1,x2,y2) {
        for(let i = y1; i < y2; i++) {
            for(let j = x1; j < x2; j++) {
                this.map[i][j] = 1;
            }
        }
    }
    bfs(initX,initY) {
        let area = 0;
        let q = new Queue();
        q.push([initX,initY]);
        while(q.len()>0) {
            let p = q.pop();
            if(p==-1) break;
            area++;
            this.map[p[0]][p[1]] = 1;
            for(let i = 0; i < this.direcs.length; i++) {
                let coord = this.direcs[i];
                let np = [ p[0]+coord[0], p[1]+coord[1] ]
                if ((np[0] < 0) || (np[0] >= this.h)) {
                    continue;
                }
                if ((np[1] < 0) || (np[1] >= this.w)) {
                    continue;
                }
                if(this.map[np[0]][np[1]]==1) {
                    continue;
                }
                this.map[np[0]][np[1]] = 1;
                q.push(np);
            }
        }
        return area;
    }
    traverse() {
        let areas = [];
        for(let i = 0; i < this.h; i++) {
            for(let j = 0; j < this.w; j++) {
                if(this.map[i][j]==0) {
                    let area = this.bfs(i,j);
                    areas.push(area);
                }
            }
        }
       
        return areas.sort((l,r)=>l-r);
    }
}

let fs = require('fs');
let inputString = fs.readFileSync("/dev/stdin").toString().split('\n');
for(let i = 0; i < inputString.length; i++) {
    inputString[i] = inputString[i].trim();
}
let [height, width, rects] = inputString[0].split(' ').map(Number);
let m = new Map(height,width);
for(let i = 0; i < rects; i++) {
    if(inputString[i+1] != undefined) {
        [x1,y1,x2,y2] = inputString[i+1].split(' ').map(Number);
     }
     m.setRect(x1,y1,x2,y2);
}
let areas = m.traverse();
console.log(areas.length);
for(let i = 0; i < areas.length; i++) {
    process.stdout.write(areas[i].toString());
    if(i<areas.length-1) {
        process.stdout.write(" ");
    }
}
