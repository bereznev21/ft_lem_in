let data = "\
#     [start]\n\
#        |  \\n\
#  [5]--[1]  [3]\n\
#   |    |    |\n\
#  [6]  [2]--[4]\n\
#     \  |\n\
#      [end]\n\
#\n\
4\n\
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
3-4\n\
2-4\n\
1-5\n\
6-5\n\
end-6\n\
1-2\n\
2-end\n\
3-start\n\
\n\
L1-1 L2-3\n\
L3-1 L1-5 L4-3 L2-4\n\
L3-5 L1-6 L4-4 L2-2\n\
L3-6 L1-end L4-2 L2-end\n\
L3-end L4-end\n\
";
