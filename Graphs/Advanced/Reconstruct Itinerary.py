#Solve Again as not yet satisfied. Can also include the backtracking logic from the video. This solution is from neetcode page only. 

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj = {src: [] for src, dst in tickets}
        res = []

        for src, dst in tickets:
            adj[src].append(dst)

        for key in adj:
            adj[key].sort()

        def dfs(adj, result, src):
            if src in adj:
                destinations = adj[src][:]
                while destinations:
                    dest = destinations[0]
                    adj[src].pop(0)
                    dfs(adj, res, dest)
                    destinations = adj[src][:]
            res.append(src)

        dfs(adj, res, "JFK")
        res.reverse()

        if len(res) != len(tickets) + 1:
            return []

        return res
