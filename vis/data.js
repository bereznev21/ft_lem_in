let data = "\
14\n\
##start\n\
start 4 0\n\
1 4 2\n\
2 4 4\n\
3 2 2\n\
4 0 4\n\
5 8 2\n\
6 8 4\n\
##end\n\
end 4 6\n\
start-1\n\
start-2\n\
1-2\n\
1-end\n\
2-3\n\
3-4\n\
4-5\n\
5-6\n\
6-end\n\
\n\
L1-1 L2-2\n\
L3-1 L1-end L4-2 L2-3\n\
L5-1 L3-end L6-2 L4-3 L2-4\n\
L7-1 L5-end L8-2 L6-3 L4-4 L2-5\n\
L9-1 L7-end L10-2 L8-3 L6-4 L4-5 L2-6\n\
L11-1 L9-end L10-3 L8-4 L6-5 L4-6 L2-end\n\
L12-1 L11-end L10-4 L8-5 L6-6 L4-end\n\
L13-1 L12-end L10-5 L8-6 L6-end\n\
L14-1 L13-end L10-6 L8-end\n\
L14-end L10-end\n\
";
