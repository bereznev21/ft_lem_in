new p5(function (sketch) {
    let lem_in;
    sketch.setup = () => {
        sketch.createCanvas(800, 800);
        sketch.background(0);
        sketch.stroke(220);
        sketch.strokeWeight(3);
        sketch.fill(255);
        // sketch.smooth();
        sketch.ellipseMode(sketch.CENTER);
        lem_in = new LemIn(data);
    };
    sketch.draw = () => {
        sketch.background(0);
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

class Node {
    constructor(name) {
        this.name = name;
        this.x = 0;
        this.y = 0;
    }

    set_pos(x, y) {
        this.x = x;
        this.y = y;
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

class Graph {
    constructor(data) {
        this.nodes = [];
        this.nodes_per_name = {};
        this.edges = [];
        this.start = "";
        this.end = "";
        let is_start = false;
        let is_end = false;
        for (const line of data.split("\n").slice(1)) {
            if (line.startsWith("##start"))
                is_start = true;
            if (line.startsWith("##end"))
                is_end = true;
            if (line.startsWith("#"))
                continue;
            let split = line.split(" ");
            if (split.length === 3) {
                let node = new Node(split[0]);
                if (is_start) {
                    is_start = false;
                    this.start = node.name;
                }
                if (is_end) {
                    is_end = false;
                    this.end = node.name;
                }
                this.nodes.push(node);
                this.nodes_per_name[node.name] = node;
                continue;
            }
            this.edges.push(line.split("-"));
        }
    }

    init_path_nodes(paths) {
        let nodes = this.nodes_per_name;
        nodes[this.start].set_pos(CENTER, TOP);
        nodes[this.end].set_pos(CENTER, BOTTOM);
        for (const [i, path] of paths.entries()) {
            let w = WIDTH * (i / (paths.length - 1) - .5);
            let vertical_step = SPAN / path.length;
            for (const [i, node_name] of path.entries()) {
                let y = -SPAN / 2 + vertical_step * (i + 1);
                let x = w * Math.sqrt(1 - Math.pow(2 * y / SPAN, 2));
                nodes[node_name].set_pos(CENTER + x, y + MIDDLE);
            }
        }
    }

    draw(sketch) {
        for (const e of this.edges) {
            let [a, b] = e;
            let n1 = this.nodes_per_name[a];
            let n2 = this.nodes_per_name[b];
            if (!n1.x)
                continue;
            if (!n2.x)
                continue;
            sketch.line(n1.x, n1.y, n2.x, n2.y);
        }
        for (const node of this.nodes) {
            if (!node.x)
                continue;
            sketch.ellipse(node.x, node.y, R);
        }
    }

}

class LemIn {
    constructor(data) {
        let graph_data;
        let moves_data;
        [graph_data, moves_data] = data.split("\n\n");
        this.moves = new Moves(moves_data);
        this.graph = new Graph(graph_data);
        this.paths = [];
        for (let move of this.moves.lines[0])
            this.paths.push(this.moves.moves_per_ant[move.ant]);
        this.graph.init_path_nodes(this.paths);
    }

    draw(sketch) {
        this.graph.draw(sketch);
    }
}

const WIDTH = 600;
const CENTER = 400;
const TOP = 20;
const BOTTOM = 800 - TOP;
const MIDDLE = (BOTTOM + TOP) / 2;
const SPAN = (BOTTOM - TOP);
const R = 20;

