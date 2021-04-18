#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
struct node {
  int vertex;
  struct node* next;
};
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}
struct Graph {
  int numVertices;
  int* visited;
  struct node** adjLists;
};
void DFS(struct Graph* graph, int vertex) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("%d ", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}
struct queue
{
  int items[SIZE];
  int front;
  int rear;
};
struct queue* createQueue()
{
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}
int isEmpty(struct queue* q)
{
  if (q->rear == -1)
    return 1;
  else
    return 0;
}
void enqueue(struct queue* q, int value)
{
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}
int dequeue(struct queue* q)
{
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      q->front = q->rear = -1;
    }
  }
  return item;
}
void BFS(struct Graph* graph, int startVertex) {
  struct queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    int currentVertex = dequeue(q);
    printf("%d ", currentVertex);

    struct node* temp = graph->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}
struct Graph* createGraph(int vertices)
 {
  int i;
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));
  for (i = 0; i < vertices; i++)
  {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {

  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

int main() {
  struct Graph* graph1 = createGraph(6);
  addEdge(graph1,0,1);
  addEdge(graph1,0,2);
  addEdge(graph1,0,3);
  addEdge(graph1,1,4);
  addEdge(graph1,1,5);
  addEdge(graph1,2,5);
  printf("Traversal using DFS\n");
  DFS(graph1,1);

  /*        3
            |
            0 - 1 - 4
            |   |
            2 - 5
  */
  struct Graph* graph2 = createGraph(6);
  addEdge(graph2,0,1);
  addEdge(graph2,0,2);
  addEdge(graph2,0,3);
  addEdge(graph2,1,4);
  addEdge(graph2,1,5);
  addEdge(graph2,2,5);
  printf("\nTraversal using BFS\n");
  BFS(graph2,1);

  return 0;
}
