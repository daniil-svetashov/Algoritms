package ai205.svetashov;

import java.sql.SQLOutput;

public class Prim {//static or public

    final int INF = 999999;
    private int[] selected;
    private int[][] G;
    private int min = INF;
    private int x = 0;
    private int y = 0;

    public Prim(int[][] G) {//constructor
        this.G = new int[G.length][G.length];
        for (int i = 0; i < G.length; i++) {
            for (int j = 0; j < G.length; j++) {
                this.G[i][j] = G[i][j];
            }
        }
    }

    private void emptySelectedArray() {
        for (int i = 0; i < G.length; i++)//inizialize our array with 0, as we don`t have any vertex selected
        {
            selected[i] = 0;
        }
    }

    public void getResult() {
        selected = new int[G.length];//array of selected vertecies
        emptySelectedArray();//we make our array empty
        selected[0] = 1;//we take a random vertex and add it to the selected array
        int noEdge = 0;//number of edges in tree is always V-1
        System.out.println("Edge" + " : " + "Weight");

        while (noEdge < G.length - 1) {

            min = INF;
            x = 0;
            y = 0;

            for (int i = 0; i < G.length; i++)//to get thew rows of adjancy matrix
            {
                if (selected[i] == 1) {//we select a vertex from our array, if(true)
                    for (int j = 0; j < G.length; j++) {//to get threw coloms of adjency matrix
                        if (selected[j] == 0) {//if we are looking at not selected vertex, we compare the G[i][j] with INF on 1st iteretion{
                            if (min > G[i][j]) {
                                min = G[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            selected[y] = 1;
            System.out.println(x + " - " + y + " : " + min);
            noEdge++;
        }
    }
}
