Disjoint Set (Union-Find):

Example:

This program demonstrates a Disjoint Set (Union-Find) data structure in C++.
It’s used to group elements into sets and quickly check if two elements belong to the same group.


🧩 What it does:
Starts with n elements, each in its own set.
Supports two main operations:
Find(x) → Finds which group x belongs to.
Unite(x, y) → Joins the groups that contain x and y.


⚙️ How it works:
Path Compression: Speeds up find() by pointing each node directly to the root.
Union by Rank: Keeps the tree balanced by attaching the smaller tree under the larger one.


🧠 Example in this code
DisjointSet ds(5);
ds.unite(0, 2);
ds.unite(4, 2);
ds.unite(3, 1);


Now:
0, 2, and 4 are in the same group.
1 and 3 are in another group.

Output:
Yes  //4 and 0 are connected
No   //1 and 0 are not connected