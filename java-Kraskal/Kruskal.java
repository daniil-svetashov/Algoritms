package ai205.svetashov;

import java.io.ObjectInputFilter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

class Kruskal<T> {
    private int N; // Количество узлов
    public int[][] matrix;  // матрица смежности
    private T[] data;  // Сохраняем данные каждого узла
    public List<Edge> edges = new ArrayList<>();

    public void setData(String[] strings) {
        data = (T[]) strings;
    }

    class Edge {
        int A;  // индекс вершины
        int B;  // индекс вершины

        public Edge(int a, int b) {
            A = a;
            B = b;
        }

        @Override
        public String toString() {
            return data[A] +
                    "-" + data[B] + ":" + matrix[A][B]+" ";
        }
    }

    public Kruskal(int N) {
        this.N = N;
        matrix = new int[N][N];
        ObjectInputFilter.Status[] statuses = new ObjectInputFilter.Status[N];
        data = (T[]) new Object[N];
    }

    public void setMatrix(int from, int to, int weight) {
        matrix[from][to] = weight;
    }

    public void setEdges() {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] > 0) {
                    edges.add(new Edge(i, j));
                }
            }
        }
    }

    private int getEnd(int[] ends, int i) {
        while (ends[i] != 0) {
            i = ends[i];
        }
        return i;
    }

    public void KruskalTree() {

        // конец сохраняет индекс конца каждой вершины при последовательной строчке после удаления каждого ребра
        int[] ends = new int[N];

        // Сортировка весов ребер
        edges.sort(new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return matrix[o1.A][o1.B] - matrix[o2.A][o2.B];
            }
        });
        // Набор ребер, содержащихся в минимальном остовом дереве
        List<Edge> result = new ArrayList<>();

        for (Edge edge : edges) {
            int endOfA = getEnd(ends, edge.A);
            int endOfB = getEnd(ends, edge.B);
            if (endOfA != endOfB) {
                // Устанавливаем конечную точку первой вершины в конечную точку второй вершины
                ends[endOfA] = endOfB;
                result.add(edge);
            }
        }
        System.out.println(result);
    }
}
