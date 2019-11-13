new p5(function (sketch) {
    let lem_in;
    sketch.setup = () => {
        sketch.createCanvas(800, 800);
        sketch.background(0);
        sketch.stroke(255);
        sketch.strokeWeight(0);
        sketch.fill(255);
        sketch.ellipseMode(sketch.CENTER);
        lem_in = new LemIn(data);
    };
    sketch.draw = () => {
        lem_in.draw(sketch);
    };
}, document.getElementById("sketch"));

function defaultdict(default_f) {
    return new Proxy({}, {
        get: function (obj, key) {
            if (!(key in obj))
                obj[key] = default_f();
            return obj[key];
        }
    })
}

class Move {
    constructor(s) {
        let split = s.split('-');
        this.ant = split[0];
        this.room = split[1];
    }
}

class Moves {
    constructor(data) {
        this.moves_per_ant = defaultdict(() => ([]));
        this.lines = [];
        for (let line of data.trim().split("\n")) {
            let l = [];
            this.lines.push(l);
            for (let move_s of line.trim().split(" ")) {
                let move = new Move(move_s);
                l.push(move);
                this.moves_per_ant[move.ant].push(move.room);
            }
        }
    }
}

class LemIn {
    constructor(data) {
        let graph_data;
        let moves_data;
        [graph_data, moves_data] = data.split("\n\n");
        this.moves = new Moves(moves_data);
        // this.graph = new Graph(graph_data);
        this.paths = [];
        let mm = this.moves;
        console.log("first line:", mm.lines[0]);
        let first_ants = [];
        for (let move of mm.lines[0]) {
            first_ants.push(move.ant);
        }
        console.log(first_ants);
        for (let first_ant of first_ants) {
            this.paths.push(mm.moves_per_ant[first_ant]);
        }
        console.log("paths:", this.paths);
        console.log("first move ever:", mm.lines[0][0]);
    }

    draw(sketch) {
        let paths = this.paths;
        let start = [CENTER, TOP];
        let end = [CENTER, BOTTOM];
        sketch.ellipse(...start, R);
        sketch.ellipse(...end, R);
        for (const [i, path] of paths.entries()) {
            let w = WIDTH * (i / (paths.length - 1) - .5);
            let vertical_step = SPAN / path.length;
            for (const [i, node] of path.entries()) {
                let y = -SPAN / 2 + vertical_step * (i + 1);
                let x = w * Math.sqrt(1 - Math.pow(2 * y / SPAN, 2));
                sketch.ellipse(CENTER + x, y + MIDDLE, R);
            }
        }
    }
}

const WIDTH = 600;
const CENTER = 400;
const TOP = 20;
const BOTTOM = 800 - TOP;
const MIDDLE = (BOTTOM + TOP) / 2;
const SPAN = (BOTTOM - TOP);
const R = 20;

