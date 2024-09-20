import sys
import sys
def main():
    import sys
    import sys
    sys.setrecursionlimit(1 << 25)
    def input():
        return sys.stdin.read()
    s = sys.stdin.read().strip()
    n = len(s)
    nodes_length = [-1, 0]
    nodes_suffix = [0, 0]
    nodes_count = [0, 0]
    nodes_next = [ [-1] * 26, [-1] * 26 ]
    suffix =1
    s = list(s)
    for i in range(n):
        c = ord(s[i]) - ord('a')
        current = suffix
        while True:
            if i - nodes_length[current] -1 >=0 and s[i - nodes_length[current] -1] == s[i]:
                break
            current = nodes_suffix[current]
        if nodes_next[current][c] != -1:
            suffix = nodes_next[current][c]
            nodes_count[suffix] +=1
        else:
            nodes_length.append(nodes_length[current] + 2)
            nodes_suffix.append(0)
            nodes_count.append(1)
            nodes_next.append([-1]*26)
            new_node = len(nodes_length) -1
            if nodes_length[new_node] ==1:
                nodes_suffix[new_node] =1
            else:
                temp = nodes_suffix[current]
                while True:
                    if i - nodes_length[temp] -1 >=0 and s[i - nodes_length[temp] -1] == s[i]:
                        nodes_suffix[new_node] = nodes_next[temp][c]
                        break
                    temp = nodes_suffix[temp]
            nodes_next[current][c] = new_node
            suffix = new_node
    # Now propagate counts
    if len(nodes_length) ==0:
        print(0)
        sys.exit()
    max_length = max(nodes_length)
    buckets = [[] for _ in range(max_length +1)]
    for node in range(len(nodes_length)):
        l = nodes_length[node]
        if l >=0:
            buckets[l].append(node)
    sorted_nodes = []
    for l in range(max_length, -1, -1):
        if l >=0 and l < len(buckets):
            sorted_nodes.extend(buckets[l])
    for node in sorted_nodes:
        if nodes_suffix[node] != node and nodes_suffix[node] >=0:
            nodes_count[nodes_suffix[node]] += nodes_count[node]
    # Now find max value
    max_value =0
    for i in range(1, len(nodes_length)):
        value = nodes_count[i] * nodes_length[i]
        if value > max_value:
            max_value = value
    print(max_value)

if __name__ == "__main__":
    main()
