#ifndef POLIGONO_H
#define POLIGONO_H

typedef struct {
    double x, y;
} Point;

double calcularAreaPoligono(Point* vertices, int numVertices) {
    double area = 0.0;

    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices;  // Próximo vértice
        area += (vertices[i].x * vertices[j].y) - (vertices[j].x * vertices[i].y);
    }

    area /= 2.0;
    return (area < 0) ? -area : area;  // Valor absoluto da área
}


#endif  // POLIGONO_H
