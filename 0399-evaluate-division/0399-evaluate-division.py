class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(list)

        for (u,j), val in zip(equations, values):
            graph[u].append((j, val))
            graph[j].append((u, 1/val))

        
        def bfs(st, end):
            if st not in graph or end not in graph:
                return -1.0
            if st == end  : return 1.0    
            q = deque([(st,1)])
            visited = set()
             
            while q  :    
                node, val  = q.popleft()

                if node == end : 
                    return val
                visited.add(node)
                for nei, v in graph[node] : 
                    if nei not in visited:
                        q.append((nei, v*val))  
            return -1.0

        return[ bfs(u,v) for u,v in queries]


            


        