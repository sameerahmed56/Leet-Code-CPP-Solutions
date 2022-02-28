// for start node their is no min and max value so it can be any thing thats why INT_MIN and INT_MAX to accept anything,
// for left-side min will still be MIN of above and MAX will get updated as parent node.
// for righ-side max will still be MAX of above and MIN will get updated as parent node.

// firs we construct left side tree and if there is still elements left in prorder ARRAY then we construct left sub tree.
this process is continued untill index < n;
