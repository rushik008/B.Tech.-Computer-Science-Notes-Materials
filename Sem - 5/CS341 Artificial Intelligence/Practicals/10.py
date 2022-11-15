def water_jug_dfs(jug1, jug2, target, current1, current2, visited, done):

    if done == True:
        return
    if current1 == target_water:
        print((current1, 0))
        done = True
        return

    if current2 == target_water:
        print((0, current2))
        done = True
        return

    print((current1, current2))
    if (jug1, current2) not in visited:
        visited.append((jug1, current2))
        water_jug_dfs(jug1, jug2, target, jug1, current2, visited, done)
    if (current1, jug2) not in visited:
        visited.append((current1, jug2))
        water_jug_dfs(jug1, jug2, target, current1, jug2, visited, done)
    if (0, current2) not in visited:
        visited.append((0, current2))
        water_jug_dfs(jug1, jug2, target, 0, current2, visited, done)
    if (current1, 0) not in visited:
        visited.append((current1, 0))
        water_jug_dfs(jug1, jug2, target, current1, 0, visited, done)

    vacancy2 = min(jug2 - current2, current1)
    if (current1 - vacancy2, vacancy2) not in visited:
        visited.append((current1 - vacancy2, vacancy2))
        water_jug_dfs(jug1, jug2, target, current1 -
                      vacancy2, vacancy2, visited, done)

    vacancy1 = min(jug1 - current1, current2)
    if (vacancy1, current2 - vacancy1) not in visited:
        visited.append((vacancy1, current2 - vacancy1))
        water_jug_dfs(jug1, jug2, target, vacancy1,
                      current2 - vacancy1, visited, done)
    return


def water_jug_bfs(jug1, jug2, target_water, current1, current2):
    queue = []
    queue.append((0, 0))
    visited = [(0, 0)]
    while len(queue) > 0:
        node = queue[0]
        queue.pop(0)

        if node[0] == target_water:
            print((node[0], 0))
            break
        if node[1] == target_water:
            print((0, node[1]))
            break
        print(node)
        if (jug1, node[1]) not in visited:
            visited.append((jug1, node[1]))
            queue.append((jug1, node[1]))
        if (node[0], jug2) not in visited:
            visited.append((node[0], jug2))
            queue.append((node[0], jug2))
        if (0, node[1]) not in visited:
            visited.append((0, node[1]))
            queue.append((0, node[1]))
        if (node[0], 0) not in visited:
            visited.append((node[0], 0))
            queue.append((node[0], 0))

        vacancy2 = min(jug2 - node[1], node[0])
        if (node[0] - vacancy2, vacancy2) not in visited:
            visited.append((node[0] - vacancy2, vacancy2))
            queue.append((node[0] - vacancy2, vacancy2))

        vacancy1 = min(jug1 - node[0], node[1])
        if (vacancy1, node[1] - vacancy1) not in visited:
            visited.append((vacancy1, node[1] - vacancy1))
            queue.append((vacancy1, node[1] - vacancy1))
    return


jug1 = int(input("Enter the capacity of Jug 1 : "))  # 4, 11
jug2 = int(input("Enter the capacity of Jug 2 : "))  # 3, 7
target_water = int(input("Enter the value to fill : "))  # 2, 6

if jug1 < jug2:
    jug1, jug2 = jug2, jug1

current1 = 0
current2 = 0
print("\nSolution with DFS :")
visited_nodes = [(0, 0)]
done = False
water_jug_dfs(jug1, jug2, target_water, current1,
              current2, visited_nodes, done)

current1 = 0
current2 = 0
print("\nSolution with BFS :")
water_jug_bfs(jug1, jug2, target_water, current1, current2)
