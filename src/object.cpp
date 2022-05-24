// Autor: Jordão Rodrigues Dantas
// Mátricula: 403686
// ///// CHESS BOARD //////

#include "../headers/consts.h"
#include <glm/ext.hpp>
#include "../headers/object.h"
using namespace std;

Cubo::Cubo(){
    //definindo os vértices (cubo centrado na origem de lado 2)
    vertices[0] = glm::vec3(-1,-1,-1);
    vertices[1] = glm::vec3(-1,-1, 1);
    vertices[2] = glm::vec3(-1, 1,-1);
    vertices[3] = glm::vec3(-1, 1, 1);
    vertices[4] = glm::vec3( 1,-1,-1);
    vertices[5] = glm::vec3( 1,-1, 1);
    vertices[6] = glm::vec3( 1, 1,-1);
    vertices[7] = glm::vec3( 1, 1, 1);

    //definindo as faces (o cubo tem 6 faces e cada face 4 vértices)
    faces[0][0] = 0; faces[0][1] = 4; faces[0][2] = 5; faces[0][3] = 1; //face 0 (y negativo)
    faces[1][0] = 0; faces[1][1] = 1; faces[1][2] = 3; faces[1][3] = 2; //face 1 (x negativo)
    faces[2][0] = 0; faces[2][1] = 2; faces[2][2] = 6; faces[2][3] = 4; //face 2 (z negativo)
    faces[3][0] = 4; faces[3][1] = 6; faces[3][2] = 7; faces[3][3] = 5; //face 3 (x positivo)
    faces[4][0] = 5; faces[4][1] = 7; faces[4][2] = 3; faces[4][3] = 1; //face 4 (z positivo)
    faces[5][0] = 2; faces[5][1] = 3; faces[5][2] = 7; faces[5][3] = 6; //face 5 (y positivo)

    //definindo a cor "default" do cubo
    cor = glm::vec3(0.5,1.0,0.5);
}

void Cubo::setCor(float r, float g, float b){
    cor = glm::vec3(r,g,b);
}

void Cubo::desenha(){
    glm::vec3 v;

    //desenhando as faces do cubo
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    glColor3f(cor.r,cor.g,cor.b);
    glBegin(GL_QUADS);
        for(int i = 0 ; i < 6 ; i++){ //laço passando por cada face
            for(int j = 0 ; j < 4 ; j++){ //laço passando por cada vértice de uma face
                int vid = faces[i][j];
                v = vertices[vid];
                glVertex3f(v.x, v.y, v.z);
            }
        }
    glEnd();

    //desenhando as arestas do cubo em preto (sem iluminação, fica difícil perceber objetos 3D)
    //WIREFRAME
    glColor3f(0.0,0.0,0.0);
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glBegin(GL_QUADS);
        for(int i = 0 ; i < 6 ; i++){ //laço passando por cada face
            for(int j = 0 ; j < 4 ; j++){ //laço passando por cada vértice de uma face
                int vid = faces[i][j];
                v = vertices[vid];
                glVertex3f(v.x, v.y, v.z);
            }
        }
    glEnd();

}

