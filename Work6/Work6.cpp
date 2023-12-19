#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

class Graph {
public:
    std::unordered_map<char, std::vector<char>> vertices;

    // добавляет новую вершину в граф
    void addVertex(char vertex) {
        if (vertices.find(vertex) == vertices.end()) {
            vertices[vertex] = std::vector<char>();
        }
    }

    // добавляет ориентированное ребро между двумя вершинами
    void addDirectedEdge(char fromVertex, char toVertex) {
        vertices[fromVertex].push_back(toVertex);
    }

    // рекурсивная реализация обхода графа в глубину
    void depthFirstSearch(char startVertex, std::unordered_set<char>& visited) {
        visited.insert(startVertex);
        std::cout << startVertex << " ";

        for (char neighbor : vertices[startVertex]) {
            if (visited.find(neighbor) == visited.end()) {
                depthFirstSearch(neighbor, visited);
            }
        }
    }

    // реализация обхода графа в ширину
    void breadthFirstSearch(char startVertex) {
        std::unordered_set<char> visited;
        std::queue<char> queue;

        visited.insert(startVertex);
        queue.push(startVertex);

        while (!queue.empty()) {
            char currentVertex = queue.front();
            queue.pop();
            std::cout << currentVertex << " ";

            for (char neighbor : vertices[currentVertex]) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
    
    // ищет кратчайший путь между двумя вершинами
    std::string shortestPath(char startVertex, char endVertex) {
        std::unordered_set<char> visited;
        std::queue<std::vector<char>> queue;

        if (startVertex == endVertex) {
            return "Кратчайший путь: " + std::string(1, startVertex);
        }

        queue.push({ startVertex });

        while (!queue.empty()) {
            std::vector<char> path = queue.front();
            queue.pop();
            char currentVertex = path.back();

            for (char neighbor : vertices[currentVertex]) {
                if (visited.find(neighbor) == visited.end()) {
                    std::vector<char> newPath = path;
                    newPath.push_back(neighbor);
                    queue.push(newPath);

                    if (neighbor == endVertex) {
                        std::string result = "Кратчайший путь: ";
                        for (char vertex : newPath) {
                            result += vertex;
                            result += " -> ";
                        }
                        result.erase(result.length() - 4);  // Удаляем последний " -> "
                        return result;
                    }

                    visited.insert(neighbor);
                }
            }
        }

        return "Путь не найден";
    }

    // Проверка связанности ориентированного графа
    bool isStronglyConnected() {
        for (const auto& vertex : vertices) {
            std::unordered_set<char> visited;
            depthFirstSearch(vertex.first, visited);
            if (visited.size() != vertices.size()) {
                return false;
            }
        }
        return true;
    }

    // Нахождение наименьшего покрытия графа
    std::unordered_set<char> minimumVertexCover() {
        std::unordered_set<char> result;
        std::unordered_set<char> visited;

        // Для каждой вершины в графе
        for (const auto& vertex : vertices) {
            // Если вершина не посещена, добавляем ее в результат и отмечаем смежные вершины как посещенные
            if (visited.find(vertex.first) == visited.end()) {
                result.insert(vertex.first);
                visited.insert(vertex.first);

                for (char neighbor : vertex.second) {
                    visited.insert(neighbor);
                }
            }
        }

        return result;
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    Graph graph;

    // добавляем вершины
    graph.addVertex('A');
    graph.addVertex('B');
    graph.addVertex('C');
    graph.addVertex('D');
    graph.addVertex('E');


    // добавляем ребра
    graph.addDirectedEdge('A', 'B');
    graph.addDirectedEdge('B', 'C');
    graph.addDirectedEdge('C', 'D');
    graph.addDirectedEdge('D', 'A');
    graph.addDirectedEdge('B', 'E');
    graph.addDirectedEdge('E', 'D');

    // обход графа в глубину
    std::cout << "DFS: ";
    std::unordered_set<char> visitedDFS;
    graph.depthFirstSearch('A', visitedDFS);

    // обход графа в ширину
    std::cout << "\nBFS: ";
    graph.breadthFirstSearch('A');

    std::cout << "\n" << graph.shortestPath('A', 'E') << std::endl;

    // Проверка связанности ориентированного графа
    /*if (graph.isStronglyConnected()) {
        std::cout << "Граф является связанным (strongly connected)." << std::endl;
    }
    else {
        std::cout << "Граф не является связанным (strongly connected)." << std::endl;
    }*/

    // Наименьшее покрытие графа
    std::unordered_set<char> minVertexCover = graph.minimumVertexCover();
    std::cout << "Наименьшее покрытие графа: ";
    for (char vertex : minVertexCover) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;


    return 0;
}
